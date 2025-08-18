#include "users.hpp"

userData::userData(std::string user_info){
    userData user;
    std::vector<std::string> splited_string = splitString(user_info);
    user.id         = toInt(splited_string[0]);
    user.u_name     = splited_string[1];
    user.name       = splited_string[2];
    user.email      = splited_string[3];
    user.password   = splited_string[4];
}
std::string userData::to_string() const
{
    userData user;
    std::ostringstream os;
    os << user.id << "," <<user.u_name << "," << user.name << "," << user.email << "," << user.password << "\n";
    return os.str();
}


