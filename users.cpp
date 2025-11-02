#include "ask.h"
#include <cstdio>
#include <ios>
#include <limits>
#include <ostream>

User::User() : id(-1) , allow_anonymose(-1){}

User::User(std::string user_info){
    std::vector<std::string> splited_string = splitString(user_info);
    if(splited_string.size() != 6){
        std::cerr << "Error from the User constructor " << splited_string.size() << "!= 6\n";
        return;
    }
    id              = toInt(splited_string[0]);
    u_name          = splited_string[1];
    password        = splited_string[2];
    name            = splited_string[3];
    email           = splited_string[4];
    allow_anonymose = toInt(splited_string[5]);
}
std::string User::to_string() const
{
    std::ostringstream os;
    os << id << "," << u_name << "," << password << "," << name << "," << email << "," << allow_anonymose;
    return os.str();
}

int User::get_user_id() const
{
    return id;
}

int User::get_anonymose() const 
{
    return allow_anonymose; 
}

const std::string &User::get_user_name() const 
{
    return u_name;
}

const std::string &User::get_name() const 
{
    return name;
}

const std::string &User::get_user_email() const 
{
    return email;
}

const std::string &User::get_user_password() const 
{
    return password;
}

void User::set_user_id(int id)
{
    this->id = id;
}

void User::set_is_anonymose(int allow_anonymose)
{
    this->allow_anonymose = allow_anonymose;
}

void User::set_user_name(const std::string &u_name)
{
    this->u_name = u_name;
}

void User::set_name(const std::string &name)
{
   this->name = name; 
}

void User::set_user_email(const std::string &email)
{
    this->email = email;
}

void User::set_password(const std::string &password)
{
    this->password = password;
}

void User::print_user_info()const 
{
    std::cout << "UserID[" << id << "]\t\t Name : ["<< name << "]" <<  "\t\t UserName[" << u_name << "]\n";
}

void UsersManager::access_system(std::vector<std::string> &menu)
{
    std::cout << "Welcom Mr " << cur_user.get_name() << " Nice To See You again!\n";

    menu.clear();
    menu = {"Show questions to me", "Show questions from me", "Show Feed",
            "Ask question", "Answer question", "Delete Question", "Show users", "Logout"};

    int choice = printMenu(menu);
    bool logout = false;
    while(!logout){
        switch(choice)
        {
            case 1: 
                break;
            case 2: 
                break;
            case 3: 
                break;
            case 4: 
                break;
            case 5: 
                break;
            case 6: 
                break;
            case 7: 
                break;
            case 8:
                logout = true;
                break;
        }
    }
}
void UsersManager::login()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string user_name;
    std::string password;
    while(true){  
        std::cout << "Enter user name: ";
        std::getline(std::cin, user_name);
        std::cout << "Enter password: ";
        std::getline(std::cin, password);

        cur_user.set_user_name(user_name);
        cur_user.set_password(password);
        std::cout << cur_user.get_user_name() << " " << cur_user.get_user_password() << "\n";

        if(!users_login_info.count(cur_user.get_user_name())){
            std::cout << "Invalide user name or password\n";
            continue;
        }
        const User &user_exist = users_login_info[cur_user.get_user_name()];
        if(cur_user.get_user_password() != user_exist.get_user_password()){
            std::cout << "Invalide user name or password\n";
            continue;
        } 
        cur_user = user_exist;
        break;
    } 
}

// TODO:  SING_UP
void  UsersManager::sign_up()
{
}
void UsersManager::add_user(User new_user){
    std::string user_name = new_user.get_user_name();
    users_login_info[user_name] = new_user;
}


const User &UsersManager::get_cur_user() const{
    return cur_user;
}
const std::map<std::string, User> &UsersManager::get_users_login_info() const{
    return users_login_info;
}
