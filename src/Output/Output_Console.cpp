
#include "Output/Output_Console.hpp"

#include <iomanip>
#include <iostream>

Output_Console *Output_Console::GetInstance()
{

    if (singleton_ == nullptr)
    {
        singleton_ = new Output_Console();
    }
    return singleton_;
}
void Output_Console::Print(Level level, const std::string &message, const std::source_location &location)
{
    std::stringstream to_print;
    Append_time(to_print);
    Append_level(to_print, level);
    Append_location(to_print, location);
    Append_function(to_print, location);
    Append_message(to_print, message);
    to_print << std::endl;
    std::cout << to_print.str();
}

void Output_Console::Append_time(std::stringstream &to_print)
{
    time_t currentTime;
    time(&currentTime);

    struct tm *local_time = localtime(&currentTime);

    to_print << local_time->tm_hour << ":"
             << local_time->tm_min << ":"
             << local_time->tm_sec;
}

void Output_Console::Append_level(std::stringstream &to_print, Level level)
{
    std::pair<std::string, std::string> format_code = level_format_codes[level];
    to_print << "[" << format_code.first << std::setw(5) << To_string(level) << format_code.second << "]";
}

void Output_Console::Append_location(std::stringstream &to_print, const std::source_location &location)
{
    to_print << "[" << location.file_name() << ":" << location.line() << "]";
}

void Output_Console::Append_function(std::stringstream &to_print, const std::source_location &location)
{
    to_print << location.function_name();
}

void Output_Console::Append_message(std::stringstream &to_print, const std::string &message)
{
    to_print << message;
}
