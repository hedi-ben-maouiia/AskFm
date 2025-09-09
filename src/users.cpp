#include "users.hpp"



User::User(std::string user_info){
    std::vector<std::string> splited_string = splitString(user_info);
    id              = toInt(splited_string[0]);
    allow_anonymose = toInt(splited_string[1]);
    u_name          = splited_string[2];
    name            = splited_string[3];
    email           = splited_string[4];
    password        = splited_string[5];
}
std::string User::to_string() const
{
    std::ostringstream os;
    os << id << "," << u_name << "," << name << "," << email << "," << password << "\n";
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
std::string User::get_name() const 
{
    return name;
}
std::string User::get_user_email() const 
{
    return email;
}
std::string User::get_user_password() const 
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

