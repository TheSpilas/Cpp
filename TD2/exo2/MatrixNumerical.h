#ifndef MATRIXNUMERICAL_H
#define MATRIXNUMERICAL_H

#include "MatrixBase.h"
#include <type_traits>

template <typename T>
class MatrixNumerical : public MatrixBase<T>
{
public:
    MatrixNumerical() : MatrixBase<T>() {}
    MatrixNumerical(size_t rows, size_t cols) : MatrixBase<T>(rows, cols) {}

    MatrixNumerical<T> operator+(const MatrixNumerical<T>& other) const;
};

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator+(const MatrixNumerical<T>& other) const
{
    if (this->rows != other.rows || this->cols != other.cols)
    {
        throw std::invalid_argument("Matrices must have the same dimensions for addition");
    }

    MatrixNumerical<T> result(this->rows, this->cols);
    for (size_t i = 0; i < this->rows; ++i)
    {
        for (size_t j = 0; j < this->cols; ++j)
        {
            result.data[i][j] = this->data[i][j] + other.data[i][j];
        }
    }
    return result;
}

#endif