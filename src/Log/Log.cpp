#include "Log.hpp"
/**
 * Static methods should be defined outside the class.
 */

Log *Log::GetInstance()
{
    /**
     * This is a safer way to create an instance. instance = new Singleton is
     * dangeruous in case two instance threads wants to access at the same time
     */
    if (singleton_ == nullptr)
    {
        singleton_ = new Log();
    }
    return singleton_;
}

void Log::Print(Level level, const std::string &message, const std::source_location &location)
{
    out->Print(level, message, location);
}

void Log::Debug(const std::string &message, const std::source_location &location)
{
    Log::GetInstance()->Print(Level::Debug, message, location);
}

void Log::Info(const std::string &message, const std::source_location &location)
{
    Log::GetInstance()->Print(Level::Info, message, location);
}

void Log::Warn(const std::string &message, const std::source_location &location)
{
    Log::GetInstance()->Print(Level::Warn, message, location);
}

void Log::Error(const std::string &message, const std::source_location &location)
{
    Log::GetInstance()->Print(Level::Error, message, location);
}

void Log::Fatal(const std::string &message, const std::source_location &location)
{
    Log::GetInstance()->Print(Level::Fatal, message, location);
}
