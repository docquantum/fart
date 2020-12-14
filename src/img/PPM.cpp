#include "img/PPM.hpp"
#include <iostream>

PPM::PPM(uint16_t height, uint16_t width)
{
    PPM::height = height;
    PPM::width = width;
    PPM::data = new PPM::Pixel*[width];
    for (size_t i = 0; i < height; i++)
        PPM::data[i] = new PPM::Pixel[width];
}

PPM::PPM(uint16_t height, uint16_t width, Pixel** data)
{
    PPM::height = height;
    PPM::width = width;
    PPM::data = data; 
}

PPM::~PPM()
{
    for (size_t i = 0; i < PPM::height; i++)
        delete[] PPM::data[i];
    delete[] PPM::data;
}

uint16_t PPM::getHeight()
{
    return PPM::height;
}

uint16_t PPM::getWidth()
{
    return PPM::width;
}

PPM::Pixel** PPM::getData()
{
    return PPM::data;
}

void PPM::setData(Pixel** data)
{
    PPM::data = data;
}

void PPM::setPixel(uint16_t x, uint16_t y, uint8_t r, uint8_t g, uint8_t b)
{
    PPM::data[x][y].r = r;
    PPM::data[x][y].g = g;
    PPM::data[x][y].b = b;
}

std::string PPM::asText()
{
    // num of rows + whitespace, plus header (P3\nw h\nmax\n)
    size_t size = (PPM::height * PPM::width * (5 * 3 + 3)) + (3 + 5 * 2 + 2 + 4);
    std::string text = std::string();
    text.reserve(size);
    text.append("P3\n" + std::to_string(PPM::height) + ' ' + std::to_string(PPM::width) + "\n256\n");
    for (size_t i = 0; i < PPM::width; i++)
    {
        for (size_t j = 0; j < PPM::height; j++)
        {
            std::string r = std::to_string(PPM::data[i][j].r);
            std::string g = std::to_string(static_cast<int>(PPM::data[i][j].g));
            std::string b = std::to_string(static_cast<int>(PPM::data[i][j].b));
            text.append(r + ' ' + g + ' ' + b + '\n');
        }
    }
    return text;
}