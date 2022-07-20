#pragma once

class Users {
    string _username;
    string _password;
    int _score;
public:

    Users(string username, string password) : _username(username), _password(password), _score() {};

    void signUp() {
        ofstream fout("Users.txt", ios_base::app);

        if (!fout)
            throw new exception("File can not created");

        if (!fout.is_open()) {
            fout.close();
            throw new exception("File can not opened");
        }

        fout << _username << ":" << _password << endl;

        fout.close();

        ofstream fout1("Leadboard.txt", ios_base::app);

        if (!fout1)
            throw new exception("File can not created");

        if (!fout1.is_open()) {
            fout1.close();
            throw new exception("File can not opened");
        }

        fout1 << _username << ":" << _score << endl;

        fout1.close();
    }

    void setUserScore(int score) {
        _score = score;
    }

    void setAndSaveUserScore(int score) {
        fstream file("Leadboard.txt", ios::in);
        string replace = _username;
        string replace_with = _username + ":" + to_string(score);
        string line;
        vector<string> lines;

        while (getline(file, line)) {

            string::size_type pos = 0;

            while ((pos = line.find(replace, pos)) != string::npos) {
                line.replace(pos, line.size(), replace_with);
                pos += replace_with.size();
            }

            lines.push_back(line);
        }

        file.close();
        file.open("Leadboard.txt", ios::out | ios::trunc);


        for (const auto& i : lines) {
            file << i << std::endl;
        }

        _score = score;
    }

    int getScore() { return _score; }

    string getUsername() {
        return _username;
    }

    bool isScore(int score) { return _score == score; }

    bool canLogin(string username, string password) {
        return username == _username && _password == password;
    }

};