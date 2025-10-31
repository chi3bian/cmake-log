#pragma once
#include<string>
enum class Level
{
    Debug,
    Info,
    Warn,
    Error,
    Fatal
};
inline std::string To_string(Level level)
{
    switch (level)
    {
    case Level::Debug:
        return "Debug";
        break;
    case Level::Info:
        return "Info";
        break;
    case Level::Warn:
        return "Warn";
        break;
    case Level::Error:
        return "Error";
        break;
    case Level::Fatal:
        return "Fatal";
        break;
    default:
        return "";
    }
}
