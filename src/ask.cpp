#include "ask.hpp"


/*------------------ Helper function ------------------*/
// 
std::vector<std::string> splitString(std::string str, const std::string &dilem)
{
    std::vector<std::string> ret;
    std::string s;
    int pos = 0;
    while((pos = str.find(dilem)) != -1){
        s = str.substr(0,pos);
        ret.push_back(s);
        str.erase(0, pos + dilem.length());
    }
    ret.push_back(str);
    return ret;
}

int toInt(const std::string &str)
{
    int _ret;
    std::istringstream iss(str);
    iss >> _ret;
    return _ret;
}

/*-------------------------------------------------------*/

int main()
{
    std::cout << toInt("222");
    return 0;
}
