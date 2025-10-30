#pragma once
#include <string>
#include <source_location>

#include "../Output/Output.hpp"
#include "../Output/Output_Console.hpp"
#include "Log_Info.hpp"

class Log
{
private:
    Output *out = Output_Console::GetInstance();

protected:
    Log()
    {
    }

    inline static Log *singleton_ = nullptr;

public:
    /**
     * Singletons should not be cloneable.
     */
    Log(Log &other) = delete;
    /**
     * Singletons should not be assignable.
     */
    void operator=(const Log &) = delete;
    /**
     * This is the static method that controls the access to the singleton
     * instance. On the first run, it creates a singleton object and places it
     * into the static field. On subsequent runs, it returns the client existing
     * object stored in the static field.
     */
    static Log *GetInstance();

private:
    void Print(Level level, const std::string &message, const std::source_location &location);

public:
    static void Debug(const std::string &message, const std::source_location &location = std::source_location::current());
    static void Info(const std::string &message, const std::source_location &location = std::source_location::current());
    static void Warn(const std::string &message, const std::source_location &location = std::source_location::current());
    static void Error(const std::string &message, const std::source_location &location = std::source_location::current());
    static void Fatal(const std::string &message, const std::source_location &location = std::source_location::current());
};
