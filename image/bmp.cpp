#include "bmp.h"

#include <iostream>
#include <fstream>

Image::Image(int16_t width, int16_t height, uint64_t** pixels)
    : width_(width), height_(height), pixels_(pixels)
{}

Image::~Image() {}

void Image::Export(int name, const char *path) const {
    std::string bmp_path = path + std::to_string(name) + ".bmp";

    std::ofstream bmp_file;
    bmp_file.open(bmp_path);
    
    if (!bmp_file.is_open()) {
        std::cout << "File could not be opened\n";
        exit(EXIT_FAILURE);
    }
    
    const int kPaddingAmount = (kPadding - ((width_ + 1) / 2) % kPadding) % kPadding;
    const int kFileSize = kFileHeaderSize + kInformationHeaderSize + kPaletteSize + (height_ * width_ + 1) / 2 + kPaddingAmount * width_;

    unsigned char fileHeader[kFileHeaderSize] = {0};
    
    fileHeader[0] = 'B';
    fileHeader[1] = 'M';
    
    fileHeader[2] = kFileSize;
    fileHeader[3] = kFileSize >> kBitsPerBytes;
    fileHeader[4] = kFileSize >> (kBitsPerBytes * 2);
    fileHeader[5] = kFileSize >> (kBitsPerBytes * 3);

    fileHeader[10] = kFileHeaderSize + kInformationHeaderSize + kPaletteSize;
    
    unsigned char informationHeader[kInformationHeaderSize] = {0};
    
    informationHeader[0] = kInformationHeaderSize;
    
    informationHeader[4] = width_;
    informationHeader[5] = width_ >> kBitsPerBytes;
    informationHeader[6] = width_ >> (kBitsPerBytes * 2);
    informationHeader[7] = width_ >> (kBitsPerBytes * 3);
    
    informationHeader[8] = height_;
    informationHeader[9] = height_ >> kBitsPerBytes;
    informationHeader[10] = height_ >> (kBitsPerBytes * 2);
    informationHeader[11] = height_ >> (kBitsPerBytes * 3);
    
    informationHeader[12] = 1;
    
    informationHeader[14] = kPixelSize;
    
    informationHeader[32] = kAmountOfColors;
    
    
    bmp_file.write(reinterpret_cast<char*>(fileHeader), kFileHeaderSize);
    bmp_file.write(reinterpret_cast<char*>(informationHeader), kInformationHeaderSize);
    bmp_file.write(reinterpret_cast<const char*>(kPalette), kPaletteSize);
    
    for (int16_t y = height_ - 1; y >= 0; --y) {
        for (int16_t x = 0; x < width_ - 1; x += 2) {
            bmp_file << static_cast<char>((pixels_[y][x] << kPixelSize) + pixels_[y][x+1]);
        }
        
        if (width_ % 2 == 1) {
            bmp_file << static_cast<char>(pixels_[y][width_-1] << kPixelSize);
        }
        
        for (int k = 0; k < kPaddingAmount; ++k) {
            bmp_file << kPaddingValue;
        }
    }
    
    bmp_file.close();
}
