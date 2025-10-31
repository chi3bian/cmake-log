#pragma once
#include "Output.hpp"
#include <ctime>
#include <sstream>

class Output_Console : public Output
{
protected:
    Output_Console()
    {
    }

    inline static Output_Console *singleton_ = nullptr;

public:
    /**
     * Singletons should not be cloneable.
     */
    Output_Console(Output_Console &other) = delete;
    /**
     * Singletons should not be assignable.
     */
    void operator=(const Output_Console &) = delete;
    /**
     * This is the static method that controls the access to the singleton
     * instance. On the first run, it creates a singleton object and places it
     * into the static field. On subsequent runs, it returns the client existing
     * object stored in the static field.
     */

    static Output_Console *GetInstance();

public:
    void Print(Level level, const std::string &message, const std::source_location &location) override;

private:
    void Append_time(std::stringstream &to_print);
    void Append_level(std::stringstream &to_print, Level level);
    void Append_location(std::stringstream &to_print, const std::source_location &location);
    void Append_function(std::stringstream &to_print, const std::source_location &location);
    void Append_message(std::stringstream &to_print, const std::string &message);
};
