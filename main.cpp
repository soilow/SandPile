#include <iostream>
#include <fstream>

#include "model/sandpile.h"

struct Arguments {
    char* input_file;
    char* output_path;
    int max_iters;
    int freq = 0;
};

Arguments Parsing(int& argc, char* argv[]) {
    Arguments args;
    
    for (int i = 1; i < argc; ++i) {
        if (strcmp("-i", argv[i]) == 0 || strcmp("--input", argv[i]) == 0) {
            ++i;
            args.input_file = argv[i];
        } else if (strcmp("-o", argv[i]) == 0 || strcmp("--output", argv[i]) == 0) {
            ++i;
            args.output_path = argv[i];
        } else if (strcmp("-m", argv[i]) == 0 || strcmp("--max-iter", argv[i]) == 0) {
            ++i;
            args.max_iters = atoi(argv[i]);
        } else if (strcmp("-f", argv[i]) == 0 || strcmp("--freq", argv[i]) == 0) {
            i++;
            args.freq = atoi(argv[i]);
        } else {
            std::cerr << "Read error!\n";
            exit(1);
        }
    }
    
    return args;
}

uint64_t** ParseTSV(char*& input_file, int16_t& height, int16_t& width) {
    std::ifstream file(input_file);
    
    if (!file) {
        std::cerr << "Can't open tsv file!";
        exit(EXIT_FAILURE);
    }
    
    if (file.peek() == EOF) {
        std::cout << "File is empty!\n";
        exit(EXIT_FAILURE);
    }
    
    char temp = '\0';
    std::string line;
    
    while (temp != '\n') {
        file.get(temp);
        
        if (temp != '\t') {
            ++width;
            
            while(temp != '\t' && temp != '\n') {
                file.get(temp);
            }
        }
    }
    
    while (file) {
        std::getline(file, line);
        ++height;
    }
    
    file.clear();
    file.seekg(0);
    
    uint64_t** matrix = new uint64_t*[height]();
    
    for (int i = 0; i < height; ++i) {
        matrix[i] = new uint64_t[width]();
        
        std::getline(file, line);
        char* has = &line[0];
        
        line += '\n';
        
        int j = 0;
        while (*has != '\n') {
            if (isdigit(*has)) {
                matrix[i][j] = atoi(has);
                ++j;
                
                while (isdigit(*has)) {
                    ++has;
                }
            }
            
            ++has;
        }
    }

    file.close();
    
    return matrix;
}

int main(int argc, char* argv[]) {
    int16_t height = 0;
    int16_t width = 0;
    Arguments args = Parsing(argc, argv);
    uint64_t** matrix = ParseTSV(args.input_file, height, width);

    SandPile sandpile(matrix, height, width);
    sandpile.Stabilize(args.freq, args.max_iters, args.output_path);
    
    return 0;
}

