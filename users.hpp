#pragma once
#include "ask.hpp"

class User {

public:
    User();
    User(std::string user_info);
    std::string to_string() const;
    int get_user_id() const;
    int get_anonymose() const;
    const std::string &get_user_name() const;
    const std::string &get_name() const;       
    const std::string &get_user_email() const;
    const std::string &get_user_password() const;
    void set_user_id(int _id);
    void set_is_anonymose(int _is_anonymose);
    void set_user_name(const std::string &_user_name);
    void set_name(const std::string &_name);
    void set_user_email(const std::string &_user_email);
    void set_password(const std::string &_user_password); 
    void print_user_info()const;

private:
    int id;
    int allow_anonymose;
    std::string u_name;
    std::string name;
    std::string email;
    std::string password;        
};

class UsersManager {

public:
    void add_user();
    void print_users();
    void login();
    void fill_users_login_info();   

private:
    std::map<std::string, User> users_login_info;
    User cur_user;
    int last_id;
};

