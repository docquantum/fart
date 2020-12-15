#include "utils/files.hpp"
#include <string>
#include <fstream>

namespace Utils::Files
{
    std::vector<std::string> readFileAsLines(const std::string& filename)
    {
        std::ifstream file(filename);
        
        if(!file.is_open())
            throw "File not found!";
        
        std::vector<std::string> lines = std::vector<std::string>();
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

    void writeFileFromLines(const std::vector<std::string>& lines, const std::string& filename)
    {
        std::ofstream file(filename);

        if(!file.is_open())
            throw "File not able to be oppend!";
        else if(lines.size() == 0)
            throw "Input is of length 0!";
        
        for (auto &&l : lines)
        {
            file << l;
        }
        file.close();
    }
}