#include "ask.h"

Question::Question(const std::string &question_info)
{
    std::vector<std::string> splited_string = splitString(question_info);
    if(splited_string.size()!=7){
        std::cerr << "Error from the Question constructor " << splited_string.size() << "!= 7\n";
        return;
    }
    question_id        = toInt(splited_string[0]);
    parent_question_id = toInt(splited_string[1]);
    from_user_id       = toInt(splited_string[2]);
    to_user_id         = toInt(splited_string[3]);
    is_anonnymose      = toInt(splited_string[4]);
    question_text      = splited_string[5];
    answer             = splited_string[6];
}

std::string Question::to_string() const 
{
    std::ostringstream oss;
    oss << question_id << "," << parent_question_id << "," << from_user_id << "," << to_user_id << "," << is_anonnymose << "," << question_text << "," << answer;
    return oss.str();
}
