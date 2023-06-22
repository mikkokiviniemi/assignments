#include "utils.h"


std::vector<int> pascal_triangle(int num_of_lines, std::vector<int> line = {1}) {
    if (line.size() == num_of_lines) {
        return line;
    } else {

        std::vector<int> new_line;
        
        new_line.push_back(1);
        
        for (int i = 0; i < line.size() - 1; i++) {
            new_line.push_back(line[i] + line[i + 1]);
        }
        
        new_line.push_back(1);
        
        return pascal_triangle(num_of_lines, new_line);
    }
}