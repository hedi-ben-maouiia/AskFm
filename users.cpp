#include "users.hpp"
#include "ask.hpp"


User::User() : id(-1) , allow_anonymose(-1){}

User::User(std::string user_info){
    std::vector<std::string> splited_string = splitString(user_info);
    if(splited_string.size() != 6){
        std::cerr << "Error from the User constructor " << splited_string.size() << "!= 6\n";
        return;
    }
    id              = toInt(splited_string[0]);
    name            = splited_string[1];
    password        = splited_string[2];
    u_name          = splited_string[3];
    email           = splited_string[4];
    allow_anonymose = toInt(splited_string[5]);
}
std::string User::to_string() const
{
    std::ostringstream os;
    os << id << "," << u_name << "," << name << "," << email << "," << password;
    return os.str();
}

int         User::get_user_id() const
{
    return id;
}

int         User::get_anonymose() const 
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
    std::cout << "UserID[" << id << "]\t\t Name : ["<< name << "]";
}

void UsersManager::login()
{
    std::string user_name;
    std::string password;
    std::cout << "Enter user name: ";
    getline(std::cin, user_name);
    std::cout << "Enter password: ";
    std::getline(std::cin, password);
    cur_user.set_user_name(user_name);
    cur_user.set_password(password);
    while(true){
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

