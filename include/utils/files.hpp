#ifndef FILES_HPP
#define FILES_HPP
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

/**
 * @brief File utilies (saving, opening)
 * 
 */
namespace Utils::Files
{
    /**
     * @brief Reads in the file as a set of lines. Also removes all empty lines.
     * 
     * @param filename 
     * @return std::vector<std::string> 
     */
    auto readFileAsLines(const std::string& filename) -> std::vector<std::string>;

    /**
     * @brief Writes the file from a set of lines, either array or vector.
     * 
     * @param lines 
     * @param filename 
     */
    void writeFileFromLines(const std::vector<std::string>& lines, const std::string& filename);
} // namespace Utils::Files

#endif