#include "ask.h"

class Question {
public:
    Question() : 
        question_id(-1), parent_question_id(-1), from_user_id(-1), to_user_id(-1), is_anonnymose(1) {};
    Question(const std::string &str);
    std::string to_string() const;

private:
    int question_id; // the actuale question id 
    int parent_question_id; // if it's -1 then it's a thread question
    int from_user_id;          
    int to_user_id;             
    int is_anonnymose; // it's an anonymose question 

    std::string question_text; // the actual text of the question 
    std::string answer; // if it is empty then no answer yet
};

class QuestionManager{

};
