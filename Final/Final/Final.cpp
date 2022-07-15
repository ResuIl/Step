#include <iostream>
#include "windows.h"
#include <conio.h>
#include <fstream>
#include <string> 
#include <vector>
#include <algorithm>
using namespace std;

#include "Admins.h"
#include "Users.h"
#include "Quizes.h"

// Load Data W.I.P

class Essentials {
private:
    string tempUsername;
    int score = 0;
    int quizCount = 0;
    int selected = 0;
    int quizMenu = 0;
    vector<Admins> admins;
    vector<Users> users;
    vector<Quizes> readyQuizes;
public:

    bool isUsernameValid(string username) {
        int len = users.size();
        for (int i = 0; i < len; i++) {
            if (users[i].getUsername() == username)
                return true;
        }
        return false;
    }

    void CreateQuiz() {
        string filename = "Quiz" + to_string(++quizCount) + ".txt";
        ifstream fin(filename, ios::in);

        if (!fin) { // File Can not Find
            ofstream fout(filename, ios::out);

            if (!fout)
                throw new exception("File can not created");

            system("cls");
            cout << "Enter Question: ";
            string question;
            cin.ignore();
            getline(cin, question);
            Quizes quiz(question);
            fout << question << endl;
        jump:
            bool active = true;
            cout << ">> New Answer\n" << "   Save\n" << "   Cancel";
            while (active) {
                switch (_getch()) {
                case 72:
                    if (quizMenu != 0)
                        quizMenu--;
                    system("cls");
                    break;
                case 80:
                    if (quizMenu + 1 < 3)
                        quizMenu++;
                    system("cls");
                    break;
                case '\r':
                    active = false;
                    break;
                default:
                    system("cls");
                    break;
                }
                if (active) {
                    if (quizMenu == 0)
                        cout << question << "\n>> New Answer\n" << "   Save\n" << "   Cancel";
                    else if (quizMenu == 1)
                        cout << question << "\n   New Answer\n" << ">> Save\n" << "   Cancel";
                    else
                        cout << question << "\n   New Answer\n" << "   Save\n" << ">> Cancel";
                }
            }
            if (quizMenu == 0) {
                string answer;
                cout << "\nIf you want go back type 'goback'" << endl;
                cout << "Enter Answer: ";
                cin >> answer;
                if (answer == "goback") {
                    system("cls");
                    cout << ">> New Answer\n" << "   Save\n";
                    active = true;
                }
                else {
                    quiz.addAnswer(answer);
                    cout << "is it correct answer? Type: y/n" << endl;
                    char flager;
                    cin >> flager;
                    if (flager == 'y') {
                        quiz.setCorrectAnswer(answer);
                        fout << answer << ":correct" << endl;
                        system("cls");
                        goto jump;
                    }
                    fout << answer << endl;
                    system("cls");
                    goto jump;
                }
            }
            else if (quizMenu == 2) {
                fout.close();
                fin.close();
                cout << remove(filename.c_str());
                --quizCount;
            }
            else {
                readyQuizes.push_back(quiz);
                cout << "Quiz Successfully Added" << endl;
            }
        }
        else {
            ++quizCount;
            CreateQuiz();
        }
    }

    void LoadDatas() {
        ifstream fin("Users.txt", ios::in);

        if (!fin)
            throw new exception("File can not find");

        if (!fin.is_open()) {
            throw new exception("File can not opened");
        }

        string data;

        while (!fin.eof())
        {
            try {
                getline(fin, data);
                string delimiter = ":";
                string username = data.substr(0, data.find(delimiter));
                string password = data.substr(username.length() + delimiter.length()).substr(0, data.substr(username.length() + delimiter.length()).find(delimiter));
                string score = data.substr(username.length() + password.length() + delimiter.length() + 1).substr(0, data.substr(username.length() + password.length() + delimiter.length() + 1).find(delimiter));
                string flag = data.erase(username.length(), data.find(delimiter) + delimiter.length());
                string isAdmin = flag.substr(flag.find(delimiter) + 1, flag.length());

                Users user(username, password);
                user.setUserScore(stoi(score));
                users.push_back(user);

                if (isAdmin == "admin") {
                    Admins admin(username, password);
                    admins.push_back(admin);
                }
            }
            catch (...) {}  
            
        }
        fin.close();

        vector<string> Files;
        
        WIN32_FIND_DATA FindFileData;
        HANDLE hFindFile;
        LPCWSTR file = L"Quiz*.txt";
        
        hFindFile = FindFirstFile(file, &FindFileData);
        
        if (INVALID_HANDLE_VALUE != hFindFile) {
            wstring ws(FindFileData.cFileName);
            string str(ws.begin(), ws.end());
            Files.push_back(str);
        }
        
        while (FindNextFile(hFindFile, &FindFileData)) {
            wstring ws(FindFileData.cFileName);
            string str(ws.begin(), ws.end());
            Files.push_back(str);
        }
        
        int len = Files.size();
        
        for (int i = 0; i < len; i++) {
            ifstream fin(Files[i], ios::in);
        
            if (!fin)
                throw new exception("File can not find");
        
            if (!fin.is_open()) {
                fin.close();
                throw new exception("File can not opened");
            }
        
            string data;
            int pos = 0;
            Quizes quiz;
            while (!fin.eof())
            {
                getline(fin, data);
                pos++;
                if (pos == 1) {
                    quiz.setQuiz(data);
                    continue;
                }
                string delimiter = ":";
                string answer = data.substr(0, data.find(delimiter));
                string correctAnswer = data.substr(answer.length());

                if (answer != "") {
                    if (correctAnswer == ":correct") {
                        quiz.addAnswer(answer);
                        quiz.setCorrectAnswer(answer);
                    }
                    else {
                        quiz.addAnswer(answer);
                    }
                }
                
            }

            readyQuizes.push_back(quiz);

            fin.close();     
        }
    }

    void ShowLeaderBoard() {
        int len = users.size();

        vector<int> scores;

        for (int i = 0; i < len; i++) {
            scores.push_back(users[i].getScore());
        }

        sort(scores.begin(), scores.end(), greater<int>());

        cout << "=== LeaderBoard" << " ===" << endl;

        for (auto x : scores) {
            for (int i = 0; i < len; i++) {
                if (users[i].isScore(x)) {
                    cout << users[i].getUsername() << " : " << x << endl;
                }
            }
        }

        cout << "===================" << endl;
    }

    void Play(bool guest) {
        score = 0;
        system("cls");

        if (guest) {
            int len = readyQuizes.size();


            for (int i = 0; i < len; i++) {
                cout << "Quiz: " << readyQuizes[i].getQuiz() << endl;
                auto cavablar = readyQuizes[i].getAnswers().size();
                for (int j = 0; j < cavablar; j++) {
                    cout << j + 1 << ") " << readyQuizes[i].getAnswers()[j].c_str() << endl;
                }
                int answer;
                cin >> answer;
                if (readyQuizes[i].isAnswerCorrect(readyQuizes[i].getAnswers()[answer - 1].c_str())) {
                    score += 10;
                }
                system("cls");
            }
            cout << "Your Score: " << score << endl;
        }
        else {
            int len = readyQuizes.size();
            int usersLen = users.size();

            for (int i = 0; i < len; i++) {
                cout << "Quiz: " << readyQuizes[i].getQuiz() << endl;
                auto cavablar = readyQuizes[i].getAnswers().size();
                for (int j = 0; j < cavablar; j++) {
                    cout << j + 1 << ") " << readyQuizes[i].getAnswers()[j].c_str() << endl;
                }
                int answer;
                cin >> answer;
                if (readyQuizes[i].isAnswerCorrect(readyQuizes[i].getAnswers()[answer - 1].c_str())) {
                    score += 10;
                }
                system("cls");
            }
            for (int i = 0; i < usersLen; i++) {
                if (users[i].getUsername() == tempUsername) {
                    users[i].setUserScore(score);
                    return;
                }
            }
            cout << "Your Score: " << score << " (Saved)" << endl;
        }


        //Quizes quiz("Salam");
        //quiz.addAnswer("1");
        //quiz.addAnswer("2");
        //quiz.addAnswer("3");
        //quiz.addAnswer("4");
        //quiz.setCorrectAnswer("4");
        //
        //Quizes quiz1("Aleykum");
        //quiz1.addAnswer("1");
        //quiz1.addAnswer("2");
        //quiz1.addAnswer("3");
        //quiz1.addAnswer("4");
        //quiz1.setCorrectAnswer("1");

        //readyQuizes.push_back(quiz);
        //readyQuizes.push_back(quiz1);



        cout << score << endl;

    }

    void Start() {

        LoadDatas();

        WIN32_FIND_DATA FindFileData;
        HANDLE hFindFile;
        LPCWSTR file = L"Quiz*.txt";

        hFindFile = FindFirstFile(file, &FindFileData);

        if (INVALID_HANDLE_VALUE != hFindFile) {
            quizCount++;
        }

        while (FindNextFile(hFindFile, &FindFileData)) {
            quizCount++;
        }

        /*cout << "Loading";
        for (int i = 0; i < 4; i++) {
            Sleep(i * 1000);
            putchar('.');
        }
        system("cls");*/

    main:
        bool active = true;
        selected = 0;
        cout << ">> Login\n" << "   Sign UP\n" << "   Play As Guest\n" << "   Exit\n";
        while (active) {
            switch (_getch()) {
            case 72:
                if (selected != 0)
                    selected--;
                system("cls");
                break;
            case 80:
                if (selected + 1 < 4)
                    selected++;
                system("cls");
                break;
            case '\r':
                if (selected == 3)
                    exit(0);
                else
                    active = false;
                break;
            default:
                system("cls");
                break;
            }
            if (active) {
                if (selected == 0)
                    cout << ">> Login\n" << "   Sign UP\n" << "   Play As Guest\n" << "   Exit\n";
                else if (selected == 1)
                    cout << "   Login\n" << ">> Sign UP\n" << "   Play As Guest\n" << "   Exit\n";
                else if (selected == 2)
                    cout << "   Login\n" << "   Sign UP\n" << ">> Play As Guest\n" << "   Exit\n";
                else
                    cout << "   Login\n" << "   Sign UP\n" << "   Play As Guest\n" << ">> Exit\n";
            }
        }

        if (selected == 0) {

            cout << "Enter Username: ";
            cin >> tempUsername;
            cout << "Enter Password: ";
            string password;
            cin >> password;

            //Admins admin(username, password);
            //admins.push_back(admin);

            int len = users.size();
            for (int i = 0; i < len; i++) {
                if (users[i].canLogin(tempUsername, password)) {
                    int aLen = admins.size();
                    for (int j = 0; j < aLen; j++) {
                        if (admins[j].isAdmin(tempUsername, password)) {

                        adminMain:
                            bool active = true;
                            selected = 0;

                            system("cls");
                            cout << "Available Quizzes: " << quizCount << "\n>> Create Quiz\n" << "   Start Quiz\n" << "   Leader Board\n" << "   Exit\n";
                            while (active) {
                                switch (_getch()) {
                                case 72:
                                    if (selected != 0)
                                        selected--;
                                    system("cls");
                                    break;
                                case 80:
                                    if (selected + 1 < 4)
                                        selected++;
                                    system("cls");
                                    break;
                                case '\r':
                                    if (selected == 3)
                                        exit(0);
                                    else
                                        active = false;
                                    break;
                                default:
                                    system("cls");
                                    break;
                                }
                                if (active) {
                                    if (selected == 0)
                                        cout << "Available Quizzes: " << quizCount << "\n>> Create Quiz\n" << "   Start Quiz\n" << "   Leader Board\n" << "   Exit\n";
                                    else if (selected == 1)
                                        cout << "Available Quizzes: " << quizCount << "\n   Create Quiz\n" << ">> Start Quiz\n" << "   Leader Board\n" << "   Exit\n";
                                    else if (selected == 2)
                                        cout << "Available Quizzes: " << quizCount << "\n   Create Quiz\n" << "   Start Quiz\n" << ">> Leader Board\n" << "   Exit\n";
                                    else cout << "Available Quizzes: " << quizCount << "\n   Create Quiz\n" << "   Start Quiz\n" << "   Leader Board\n" << ">> Exit\n";
                                }
                            }

                            if (selected == 0) {
                                CreateQuiz();
                                goto adminMain;
                            }
                            else if (selected == 1) {
                                if (quizCount == 0) cout << "No Available Quizzes Find Please Create Quizzes" << endl;
                                else {
                                    Play(true);
                                    goto adminMain;
                                }
                            }
                            else if (selected == 2) {
                                ShowLeaderBoard();
                                goto adminMain;
                            }


                            return;
                            // ADMIN
                        }
                    }

                    bool wFlag = true;
                    selected = 0;
                    system("cls");
                jump:
                    cout << "Available Quizzes: " << quizCount << "\n>> Start Quiz\n" << "   Leader Board\n" << "   Exit\n";
                    while (wFlag) {
                        switch (_getch()) {
                        case 72:
                            if (selected != 0)
                                selected--;
                            system("cls");
                            break;
                        case 80:
                            if (selected + 1 < 4)
                                selected++;
                            system("cls");
                            break;
                        case '\r':
                            if (selected == 2)
                                exit(0);
                            else
                                wFlag = false;
                            break;
                        default:
                            system("cls");
                            break;
                        }
                        if (wFlag) {
                            if (selected == 0)
                                cout << "Available Quizzes: " << quizCount << "\n>> Start Quiz\n" << "   Leader Board\n" << "   Exit\n";
                            else if (selected == 1)
                                cout << "Available Quizzes: " << quizCount << "\n   Start Quiz\n" << ">> Leader Board\n" << "   Exit\n";
                            else
                                cout << "Available Quizzes: " << quizCount << "\n   Start Quiz\n" << "   Leader Board\n" << ">> Exit\n";
                        }
                    }

                    if (selected == 0) {
                        Play(false);
                        wFlag = true;
                        selected = 0;
                        goto jump;
                        // Start Quiz
                    }
                    else if (selected == 1) {

                        ShowLeaderBoard();

                        wFlag = true;
                        selected = 0;
                        goto jump;
                    }

                    return;
                }
            }

            cout << "Username or Password incorrect!" << endl;
        }
        else if (selected == 1) {

            cout << "Enter Username: ";
            string username;
            cin >> username;
            cout << "Enter Password: ";
            string password;
            cin >> password;

            if (!isUsernameValid(username)) {
                Users user(username, password);
                user.signUp();
                users.push_back(user);
                cout << "Succesfully Signed Up" << endl;
                goto main;
            }
            else {
                cout << "The username " << username << " is already taken." << endl;
                goto main;
            }
            // Sign up
        }
        else if (selected == 2) {
            system("cls");
        guest:
            selected = 0;
            active = true;
            cout << "Available Quizzes: " << quizCount << endl;
            cout << ">> Start Quiz\n" << "   Leader Board\n" << "   Exit\n";
            while (active) {
                switch (_getch()) {
                case 72:
                    if (selected != 0)
                        selected--;
                    system("cls");
                    break;
                case 80:
                    if (selected + 1 < 4)
                        selected++;
                    system("cls");
                    break;
                case '\r':
                    if (selected == 2)
                        exit(0);
                    else
                        active = false;
                    break;
                default:
                    system("cls");
                    break;
                }
                if (active) {
                    if (selected == 0)
                        cout << "Available Quizzes: " << quizCount << "\n>> Start Quiz\n" << "   Leader Board\n" << "   Exit\n";
                    else if (selected == 1)
                        cout << "Available Quizzes: " << quizCount << "\n   Start Quiz\n" << ">> Leader Board\n" << "   Exit\n";
                    else
                        cout << "Available Quizzes: " << quizCount << "\n   Start Quiz\n" << "   Leader Board\n" << ">> Exit\n";
                }
            }

            if (selected == 0) {
                if (quizCount == 0) cout << "No Available Quizzes Found Please Contact Admin" << endl;
                else Play(true);
            }
            else if (selected == 1) {
                ShowLeaderBoard();
                goto guest;
            }
            // Play As Guest
        }

    }
};

int main()
{
    Essentials Thread;

    //Thread.LoadDatas();
    //Thread.ShowLeaderBoard();
    Thread.Start();

}
