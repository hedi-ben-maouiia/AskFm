#include "ask.hpp"



void askSystem::load_data_bases()
{
    std::vector<std::string> data_users     = readFromFile("databases/users.txt");
    std::vector<std::string> data_questions = readFromFile("databases/questions.txt"); 
    for(auto user : data_users){
        User cur_user(user);
    }
}
void askSystem::run()
{
    access_system();
}
void askSystem::access_system()
{
    bool quite = false;
    load_data_bases();
    while(!quite){
        std::vector<std::string> menu;
        menu.reserve(3);
        menu = {"Login", "SignUp", "Quite"};
        int choice = printMenu(menu); 
        switch(choice){
            case 1: {
                load_data_bases();
                login();
            }break;
            case 2: {   
                sign_up(); 
            }break;
            case 3: {
                quite = true;
            }break;
        }
    }
}
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


int readInt(int low, int high)
{
    std::cout << "Enter a choice between " << low << " & " << high;
    int choice = -1;
    std::cin >> choice;
    if(choice < low && choice > high){
        std::cout << "Error : pleas enter a valid choice!\n";
        return readInt(low, high); 
    }
    return choice;
}
int printMenu(const std::vector<std::string>& menu)
{
    for(int i{0}; i < (int)menu.size(); ++i){
        std::cout << i+1 << "." << menu[i] << "\n";
    }
    return readInt(1, menu.size());
}

void writeToFile(const std::vector<std::string> &lines, const std::string &path_to_file, bool apend)
{
    std::ios::openmode app = std::ios::app;
    if(!apend)
        app = std::ios::trunc;

    std::ofstream out_file(path_to_file, app);
    if(!out_file){
        std::cerr << "Cannot open file to write [" << path_to_file << "]\n";
        return;
    }
    for(const auto &line : lines)
    {
        out_file << line << "\n";
    }
    out_file.close();
}
void readFromFile(const std::string &source_file,  std::vector<std::string> &lines)
{
    std::ifstream in_file(source_file);
    if(!in_file){
        std::cerr << "Cannot open file to read from [" << source_file <<  "]\n" ;
        return;
    }
    std::string line;
    while(std::getline(in_file,line)){
        lines.push_back(line);
    }
    in_file.close();
}


