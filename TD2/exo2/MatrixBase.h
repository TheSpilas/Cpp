#ifndef MATRIXBASE_H
#define MATRIXBASE_H

using namespace std;
#include <vector>
#include <cstddef>

template <typename T>
class MatrixBase 
{
protected:
    vector<vector<T>> data;
    size_t rows;
    size_t cols;

public:
    MatrixBase();
    MatrixBase(size_t, size_t);
    void addElement(size_t, size_t, T);
    T getElement(size_t, size_t) const;
    size_t getRows() const;
    size_t getCols() const;

    void display(ostream&) const;
};




template <typename T>
MatrixBase<T>::MatrixBase() : data(1, vector<T>(1)), rows(1), cols(1) {}

template <typename T>
MatrixBase<T>::MatrixBase(size_t rows, size_t cols) : data(rows, vector<T>(cols)), rows(rows), cols(cols) {}

template <typename T>
void MatrixBase<T>::addElement(size_t row, size_t col, T x) 
{
    if (row >= rows || col >= cols) 
    {
        throw out_of_range("Invalid row or column index");
    }
    data[row][col] = x;
}
#endif 