#ifndef PPM_HPP
#define PPM_HPP
#include <iostream>

/**
 * @brief PPM Image Format Class, creates the images and also does some other cool stuff along with it or something
 * like that
 * 
 * Assume 8 bit RGB
 */

class PPM
{
private:
    struct Pixel
    {
        uint8_t r = 0;
        uint8_t g = 0;
        uint8_t b = 0;
    };
    uint16_t height;
    uint16_t width;
    Pixel** data;
public:
    PPM(uint16_t height, uint16_t width);
    PPM(uint16_t height, uint16_t width, Pixel** data);
    ~PPM();

    uint16_t getHeight();
    uint16_t getWidth();
    Pixel** getData();
    void setData(Pixel** data);
    void setPixel(uint16_t x, uint16_t y, uint8_t r, uint8_t g, uint8_t b);
    std::string asText();
};

#endif