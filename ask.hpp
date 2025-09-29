#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdint>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include "users.hpp"
#include "questions.hpp"




class askSystem{
public:
    void run();
    void access_system();
    void load_data_bases();
    void login();
    void sign_up(); 
    
private:        
    UsersManager    user_manager; 
    QuestionManager question_manager;
};

const std::vector<std::string> &readFromFile(const std::string &source_file);
void writeToFile(const std::vector<std::string> &lines, const std::string &source_file, bool apend = true);
int printMenu(const std::vector<std::string>&);
std::vector<std::string> splitString(std::string str, const std::string &dilem=",");
int toInt(const std::string &str);
int readInt(int low, int high);
