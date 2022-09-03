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
    Matrix T operator+(const &Matrix<T>){
        return getValue(targetRow, targetColumn);
    }

    template<arithmetic T, uint16_t rowNumber, uint16_t columnNumber>
    Matrix T operator-(uint16_t targetRow, uint16_t targetColumn){
        return getValue(targetRow, targetColumn);
    }

    Matrix T operator+=(uint16_t targetRow, uint16_t targetColumn){
        return getValue(targetRow, targetColumn);
    }

    Matrix T operator-=(uint16_t targetRow, uint16_t targetColumn){
        return getValue(targetRow, targetColumn);
    }

    Matrix T operator*(uint16_t targetRow, uint16_t targetColumn){
        return getValue(targetRow, targetColumn);
    }

    Matrix T operator/(uint16_t targetRow, uint16_t targetColumn){
        return getValue(targetRow, targetColumn);
    }

    template<arithmetic T, uint16_t rowNumber, uint16_t colcolumnNumberumns>
    T Matrix::getValue(uint16_t targetRow, uint16_t targetColumn) const
    {
        return values[targetRow * rowNumber + targetColumn];
    }

}