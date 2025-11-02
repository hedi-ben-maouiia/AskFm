#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdint>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <limits>
#include "users.h"
#include "questions.h"

void readFromFile(const std::string &source_file, std::vector<std::string> &lines);
// const std::vector<std::string> readFromFile(const std::string &source_file);
void writeToFile(const std::vector<std::string> &lines, const std::string &source_file, bool apend = true);
int printMenu(const std::vector<std::string>&);
std::vector<std::string> splitString(std::string str, const std::string &dilem=",");
int toInt(const std::string &str);
int readInt(int low, int high);


class askSystem{
public:
    void run();
    void load_data_base(); 
    void access_system( std::vector<std::string> &menu);        
    UsersManager    user_manager; 
    QuestionManager question_manager;
};

