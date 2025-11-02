#pragma once
#include "ask.h"


class User {

public:
    User();
    User(std::string user_info);

    // make a string from an object User 
    std::string to_string() const;
    //getters
    int get_user_id() const;
    int get_anonymose() const;
    const std::string &get_user_name() const;
    const std::string &get_name() const;       
    const std::string &get_user_email() const;
    const std::string &get_user_password() const;
    //setters
    void set_user_id(int _id);
    void set_is_anonymose(int _is_anonymose);
    void set_user_name(const std::string &_user_name);
    void set_name(const std::string &_name);
    void set_user_email(const std::string &_user_email);
    void set_password(const std::string &_user_password); 

    void print_user_info()const;

private:
    int id;
    std::string u_name;
    std::string password;        
    std::string name;
    std::string email;
    int allow_anonymose;
};

class UsersManager {

public:
    void access_system(std::vector<std::string> &menu);
    void login();
    void sign_up();   
    void add_user(User);
    const User &get_cur_user() const;
    const std::map<std::string, User> &get_users_login_info() const;

private:
    std::map<std::string, User> users_login_info;
    User cur_user;
    int last_id;
};

