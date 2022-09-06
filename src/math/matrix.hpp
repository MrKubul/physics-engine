#pragma once

#include <type_traits>
#include <concepts>
#include <cmath>
#include <array>
#include <ostream>

namespace deengine {
    template<typename T>
    concept arithmetic = std::is_arithmetic_v<T>;

    template<arithmetic T, uint16_t rowNumber, uint16_t columnNumber>
    class Matrix {
        private:
            std::array<T, rowNumber * columnNumber> values;
            T getValue(uint16_t row, uint16_t column) const;

        public:
            Matrix();
            Matrix(const &std::array<T> initialValues)

    }

    template<arithmetic T, uint16_t rowNumber, uint16_t columnNumber>
    Matrix::Matrix()
    {

    }

    template<arithmetic T, uint16_t rowNumber, uint16_t columnNumber>
    Matrix::Matrix(const &std::array<T> initialValues)
    {
        values = initialValues;
    }

    template<arithmetic T, uint16_t rowNumber, uint16_t columnNumber>
    Matrix T operator[](uint16_t targetRow, uint16_t targetColumn){
        return getValue(targetRow, targetColumn);
    }

    template<arithmetic T, uint16_t rowNumber, uint16_t columnNumber>
    Matrix T operator+(const &Matrix<T> toAdd){
        // assert equal dimensions
        for(int i = 0; i < rowNumber * columnNumber; ++i)
        {
            values[i] += toAdd[i];
        }
        return *this;
    }

    template<arithmetic T, uint16_t rowNumber, uint16_t columnNumber>
    Matrix T operator-(const &Matrix<T> toAdd){
        // assert equal dimensions
        for(int i = 0; i < rowNumber * columnNumber; ++i)
        {
            values[i] -= toAdd[i];
        }
        return *this;
    }

    template<arithmetic T, uint16_t rowNumber, uint16_t columnNumber>
    Matrix T operator*(const int scalar){
        for(int i = 0; i < rowNumber * columnNumber; ++i)
        {
            values[i] *= scalar;
        }
        return *this;
    }

    template<arithmetic T, uint16_t rowNumber, uint16_t columnNumber>
    Matrix T operator/(const int scalar){
                for(int i = 0; i < rowNumber * columnNumber; ++i)
        {
            values[i] *= scalar;
        }
        return *this;
    }
}