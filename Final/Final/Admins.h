#pragma once

class Admins {
    string _username;
    string _password;
public:

    Admins(string username, string password) : _username(username), _password(password) {};

    bool isAdmin(string username, string password) {
        return username == _username && _password == password;
    }
};