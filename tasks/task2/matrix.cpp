// matrix.cpp

#include <cstddef>
#include "matrix.h"
#include <stdexcept>

// ===== RowMatrix =====

Matrix::RowMatrix::RowMatrix(double* array, size_t size)
    : _array(array), _size(size) {
}

const double& Matrix::RowMatrix::operator[](size_t col) const {
    if (col >= _size) {
        throw std::out_of_range("Column index out of range");
    }
    return _array[col];
}

double& Matrix::RowMatrix::operator[](size_t col) {
    if (col >= _size) {
        throw std::out_of_range("Column index out of range");
    }
    return _array[col];
}

Matrix::RowMatrix::~RowMatrix() = default;

// ===== Matrix =====

Matrix::Matrix()
    : _rows(0), _cols(0), _array(nullptr) {
}

Matrix::Matrix(size_t rows, size_t cols)
    : _rows(rows), _cols(cols), _array(new double[rows * cols]()) {
}

Matrix::Matrix(const Matrix& other)
    : _rows(other._rows), _cols(other._cols), _array(new double[_rows * _cols]) {
    for (size_t i = 0; i < _rows * _cols; ++i) {
        _array[i] = other._array[i];
    }
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) return *this;

    delete[] _array;

    _rows = other._rows;
    _cols = other._cols;
    _array = new double[_rows * _cols];

    for (size_t i = 0; i < _rows * _cols; ++i) {
        _array[i] = other._array[i];
    }

    return *this;
}

const Matrix::RowMatrix Matrix::operator[](size_t row) const {
    if (row >= _rows) {
        throw std::out_of_range("Row index out of range");
    }
    return RowMatrix(_array + row * _cols, _cols);
}

Matrix::RowMatrix Matrix::operator[](size_t row) {
    if (row >= _rows) {
        throw std::out_of_range("Row index out of range");
    }
    return RowMatrix(_array + row * _cols, _cols);
}

Matrix& Matrix::operator*=(double scalar) {
    for (size_t i = 0; i < _rows * _cols; ++i) {
        _array[i] *= scalar;
    }
    return *this;
}

Matrix Matrix::operator*(double scalar) {
    Matrix result(*this);
    result *= scalar;
    return result;
}

bool Matrix::operator==(Matrix& other) {
    if (_rows != other._rows || _cols != other._cols) {
        return false;
    }
    for (size_t i = 0; i < _rows * _cols; ++i) {
        if (_array[i] != other._array[i]) {
            return false;
        }
    }
    return true;
}

bool Matrix::operator!=(Matrix& other) {
    return !(*this == other);
}

size_t Matrix::cols() const {
    return _cols;
}

size_t Matrix::rows() const {
    return _rows;
}

Matrix::~Matrix() {
    delete[] _array;
}