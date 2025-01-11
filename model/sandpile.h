#include <iostream>
#include "../image/bmp.h"

static const int kMaxGrains = 4;

class SandPile {
public:
    SandPile(uint64_t** matrix, int16_t width, int16_t height);
    ~SandPile();
    
    inline bool IsOutOfBounds(const int16_t& x, const int16_t& y) const;
    void Resize(int16_t& x_actual, int16_t& y_actual, int16_t& x_ref, int16_t& y_ref);
    void AddGrain(int16_t x, int16_t y, int16_t& x_ref, int16_t& y_ref);
    void Toppling(int16_t& x, int16_t& y);
    void Iteration();
    void Stabilize(const int& freq, const int& max_iters, const char* output_path);
    void Save(const int& name, const char* path) const;
        
private:
    uint64_t** matrix_;
    int16_t width_;
    int16_t height_;
    
    bool is_stable_;
    int16_t iters_count_;
};
