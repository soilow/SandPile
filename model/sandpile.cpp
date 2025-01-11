#include "sandpile.h"

SandPile::SandPile(uint64_t** matrix, int16_t width, int16_t height) {
    matrix_ = matrix;
    width_ = width;
    height_ = height;
    is_stable_ = false;
}

SandPile::~SandPile() {
    for (int y = 0; y < height_; ++y) {
        delete [] matrix_[y];
        matrix_[y] = nullptr;
    }
    matrix_ = nullptr;
}

inline bool SandPile::IsOutOfBounds(const int16_t& x, const int16_t& y) const {
    return (x < 0 || x >= width_ || y < 0 || y >= height_);
}

void SandPile::Resize(int16_t& x_actual, int16_t& y_actual, int16_t& x_ref, int16_t& y_ref) {
    bool top = (y_actual < 0);
    bool bottom = (y_actual >= height_);
    bool left = (x_actual < 0);
    bool right = (x_actual >= width_);
    uint64_t** tempArray = new uint64_t*[height_ + top + bottom];
    
    if (top) {
        ++y_actual;
        ++y_ref;
    }
    if (left) {
        ++x_actual;
        ++x_ref;
    }
    
    if (top) {
        tempArray[0] = new uint64_t[width_ + left + right]();
    }
    if (left || right) {
        for (int16_t y = 0; y < height_; ++y) {
            tempArray[y+top] = new uint64_t[width_ + left + right];
            if (left) {
                tempArray[y+top][0] = 0;
            }
            for (int x = 0; x < width_; ++x) {
                tempArray[y+top][x+left] = matrix_[y][x];
            }
            if (right) {
                tempArray[y+top][(width_-1)+left+right] = 0;
            }
            delete [] matrix_[y];
        }
    }
    else {
        for (int16_t y = 0; y < width_; ++y) {
            *&tempArray[y+top] = *&matrix_[y];
        }
    }
    if (bottom) {
        tempArray[(height_-1)+top+bottom] = new uint64_t[width_+left+right]();
    }
    
    height_ += bottom + top;
    width_ += left + right;
    
    matrix_ = tempArray;
}

void SandPile::AddGrain(int16_t x, int16_t y, int16_t& x_ref, int16_t& y_ref) {
    if (IsOutOfBounds(x, y)) {
        Resize(x, y, x_ref, y_ref);
    }
    
    matrix_[y][x] += 1;
}
    
void SandPile::Toppling(int16_t& x, int16_t& y) {
    matrix_[y][x] -= 4;
    
    AddGrain(x, y - 1, x, y);
    AddGrain(x + 1, y, x, y);
    AddGrain(x, y + 1, x, y);
    AddGrain(x - 1, y, x, y);
}

void SandPile::Iteration(){
    bool temp_stable = true;
    
    for (int16_t y = 0; y < height_; ++y) {
        for (int16_t x = 0; x < width_; ++x) {
            if (matrix_[y][x] >= kMaxGrains) {
                temp_stable = false;
                Toppling(x, y);
            }
        }
    }
    
    is_stable_ = temp_stable;
}

void SandPile::Stabilize(const int& freq, const int& max_iters, const char* output_path) {
    int counter = 1;
    
    while (!is_stable_ && counter < max_iters) {
        Iteration();
        if (freq != 0 && counter % freq == 0 && !is_stable_) {
            Save(counter, output_path);
        }
        
        ++counter;
    }
    
    Save(counter, output_path);
}

void SandPile::Save(const int& name, const char* path) const {
    Image image(width_, height_, matrix_);
    image.Export(name, path);
}
