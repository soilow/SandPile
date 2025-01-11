#pragma once
#include <iostream>

const int kFileHeaderSize = 14;
const int kInformationHeaderSize = 40;
const int kPadding = 4;
const int kAmountOfColors = 5;
const int kRGBAmountOfColors = 4;
const int kPaletteSize = kAmountOfColors * kRGBAmountOfColors;
const int kBitsPerBytes = 8;
const int kPixelSize = 4;
const char kPaddingValue = static_cast<char>(0);

const unsigned char kPalette[kPaletteSize] = {
    208, 253, 255, 0,
    23, 187, 76, 0,
    36, 195, 246, 0,
    255, 0, 143, 0,
    32, 38, 18, 0
};

class Image {
public:
    Image(int16_t width, int16_t height, uint64_t** pixels);
    ~Image();
    
    void Export(int name, const char* path) const;
private:
    int width_;
    int height_;
    
    uint64_t** pixels_;
};
