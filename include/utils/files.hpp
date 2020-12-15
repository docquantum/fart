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
     * @brief Reads in the file as a set of lines, either array or vector. Also removes all empty lines.
     * 
     * @tparam T 
     * @param fileName 
     * @return T 
     */
    template <typename T>
    auto readFileAsLines(const std::string& fileName) -> T;
} // namespace Utils::Files

#endif