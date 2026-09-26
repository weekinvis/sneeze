#include "file.h"
#include <string>
#include <fstream>
#include <vector>

std::vector<std::string> readfile(const std::string& f_name)
{
    std::ifstream file(f_name);
    std::vector<std::string> lines;
    std::string line;

    if(file.is_open())
    {
        while(std::getline(file, line))
        {
            lines.push_back(line);
        }
    }

    return lines;
}