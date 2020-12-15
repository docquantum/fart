#include "utils/files.hpp"
#include <string>
#include <fstream>

namespace Utils::Files
{
    template <>
    std::string* readFileAsLines<std::string*>(const std::string& fileName)
    {
        std::ifstream file(fileName);
        
        if(!file.is_open())
            throw "File not found!";
        
        int count = 0;
        std::string line;
        while(std::getline(file, line))
        {
            if(line.empty())
                continue;
            count++;
        }

        std::string* lines = new std::string[count];
        
        count = 0;
        while(std::getline(file, line))
        {
            if(line.empty())
                continue;
            lines[count] = line;
            count++;
        }
        file.close();

        return lines;
    }

    template<>
    std::vector<std::string> readFileAsLines<std::vector<std::string>>(const std::string& fileName)
    {
        std::ifstream file(fileName);
        std::vector<std::string> lines = std::vector<std::string>();
        
        if(!file.is_open())
            throw "File not found!";
        
        lines.reserve(1000);
        
        int count = 0;
        std::string line;
        while(std::getline(file, line))
        {
            if(line.empty())
                continue;
            lines.push_back(line);
            count++;
        }
        file.close();
        lines.resize(count);
        return lines;
    }
}