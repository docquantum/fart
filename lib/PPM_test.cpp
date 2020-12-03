#include "PPM.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char const *argv[])
{    
    PPM ppm = PPM(256, 256);
    
    // Render out

    for (size_t i = 0; i < ppm.getWidth(); i++)
    {
        for (size_t j = 0; j < ppm.getHeight(); j++)
        {   
            // std::cout << "Setting pixel " << i << ' ' << j << std::endl;
            float r = float(i) / (ppm.getWidth()-1);
            float g = float(j) / (ppm.getHeight()-1);
            float b = 0.25; 
            
            uint8_t ir = static_cast<uint8_t>(255.999 * r);
            uint8_t ig = static_cast<uint8_t>(255.999 * g);
            uint8_t ib = static_cast<uint8_t>(255.999 * b);
            ppm.setPixel(i, j, ir, ig, ib);
        }
    }
    
    if(argc > 1)
    {
        std::ofstream file;
        file.open(argv[1]);
        file << ppm.asText() << std::endl;
        file.close();
    }
    else
    {
        std::cout << ppm.asText() << std::endl;
    }
    return 0;
}
