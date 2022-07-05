#include "Image.h"

std::vector<int> Image::getPixelColor(int x, int y) {

    HDC hdc, hdcTemp;
    hdc = GetDC(HWND_DESKTOP);
    COLORREF _color = GetPixel(hdc, x, y);

    int _red = GetRValue(_color);
    int _green = GetGValue(_color);
    int _blue = GetBValue(_color);
    std::vector<int> arr{_red, _green, _blue};
    ReleaseDC(NULL, hdc);
    return arr;
}