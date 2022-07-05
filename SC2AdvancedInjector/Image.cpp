#include "Image.h"
#include "Windows.h"

std::vector<int> Image::getPixelColor(int x, int y) {

    /* Function to get pixelColor . Return a vector with RGB value 
       Ex : 
                std::vector<int> rgb = im.getPixelColor(300, 300);
                for (auto c : rgb) {
                    std::cout << c << std::endl;
                }
    
    */
    HDC hdc, hdcTemp;
    hdc = GetDC(HWND_DESKTOP);
    COLORREF _color = GetPixel(hdc, 300, 300);

    int _red = GetRValue(_color);
    int _green = GetGValue(_color);
    int _blue = GetBValue(_color);
    std::vector<int> arr{_red, _green, _blue};

    ReleaseDC(NULL, hdc);
    return arr;


}