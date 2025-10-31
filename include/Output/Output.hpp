#pragma once
#include <source_location>
#include <map>
#include <string>

#include "../Log/Log_Info.hpp"

class Output
{
protected:
static std::map<Level,std::pair<std::string,std::string>> level_format_codes;

public:
virtual void Print(Level level, const std::string &message, const std::source_location &location){}
};