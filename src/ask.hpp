#pragma once
#include <iostream>
#include <sstream>
#include <cstdint>
#include <string>
#include <vector>

class askSystem{
public:
    void run();
    
private:        
    //UserManager m_user_manager;
    //QuestionManager m_question_manager; 
};

std::vector<std::string> readFromFile();
void writeToFile(const std::vector<std::string> &lines, bool apend = true);
std::vector<std::string> splitString(std::string str, const std::string &dilem=",");
int toInt(const std::string &str);
