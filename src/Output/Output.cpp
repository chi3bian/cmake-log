#include "Output/Output.hpp"

std::map<Level,std::pair<std::string,std::string>> Output::level_format_codes{
    {Level::Debug, {"\x1b[0;34;49m", "\x1b[0m"}},
    {Level::Info, {"\x1b[0;32;49m", "\x1b[0m"}},
    {Level::Warn, {"\x1b[0;31;49m", "\x1b[0m"}},
    {Level::Error, {"\x1b[1;31;49m", "\x1b[0m"}},
    {Level::Fatal, {"\x1b[0;31;49m", "\x1b[0m"}}};