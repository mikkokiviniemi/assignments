#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>

//Dimensions
struct Dimensions {
    std::size_t height;
    std::size_t width;
};
std::ostream& operator<<(std::ostream& os, const Dimensions& grid) {
    os << "(" << std::to_string(grid.height) << "x" << std::to_string(grid.width) << ")";
    return os;
}

//2D grid
template <typename T>
class Grid_2D {
public:
    //Type alias
    using iterator = typename std::vector<T>::iterator;
    using const_iterator = typename std::vector<T>::const_iterator;

    //Constructor
    Grid_2D(std::size_t rows, std::size_t cols) : rows(rows), cols(cols), data(rows * cols) {}

    //Accessing operators
    T& operator()(std::size_t row, std::size_t col) {return data[row * cols + col];}
    const T& operator()(std::size_t row, std::size_t col) const {return data[row * cols + col];}

    //.at
    const T at(std::size_t row, std::size_t col) const {return data[row * cols + col];}

    //Begin
    iterator begin() {return data.begin();}
    const_iterator begin() const {return data.begin();}
    //End
    iterator end() {return data.end();}
    const_iterator end() const {return data.end();}

    //Size
    Dimensions size() const { 
        Dimensions size = {rows,cols};
        return size;
    }
    //Resize
    void resize(std::size_t width, std::size_t height) {
        rows = width;
        cols = height;
        data.resize(width*height);
    }

    //Printing
    friend std::ostream& operator<<(std::ostream& os, const Grid_2D<T>& grid) {
        for (std::size_t i = 0; i < grid.rows * grid.cols; ++i) {
            if (i == 0) {
                os <<  grid.data[i];
            } else if (i % grid.cols == 0) {
                os << "\n" << grid.data[i];
            } else {
                os << " " << grid.data[i];
            }
        }
        return os;
    }
private:
    std::size_t rows;
    std::size_t cols;
    std::vector<T> data;
};

#endif  