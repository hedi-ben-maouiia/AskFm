#pragma once
#include <iostream>
#include <cstdint>
#include <sstream>
#include <vector>
#include "ask.hpp"

class userData {

public:
    userData();
    userData(std::string user_info);
    std::string to_string() const;

private:
    uint32_t id;
    std::string u_name;
    std::string name;
    std::string email;
    std::string password;
};
