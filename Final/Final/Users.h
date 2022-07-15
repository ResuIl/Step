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

        fout << _username << ":" << _password << ":" << _score << endl;

        fout.close();
    }

    void setUserScore(int score) {
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
