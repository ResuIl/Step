#pragma once

class Users {
    string _username;
    string _password;
    int _score;
public:

    Users(string username, string password) : _username(username), _password(password) {};

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