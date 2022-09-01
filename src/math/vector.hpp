#pragma once
#include <type_traits>
#include <concepts>
#include <cmath>

namespace dziekan{
    // Concept encapsulating all numbers (floats, doubles, ints, long longs, etc)
    template<typename T>
    concept arithmetic = std::is_arithmetic_v<T>;


    template<arithmetic T>
    struct Base_vec{
        virtual T mag_sq() = 0;
        T mag() { return std::sqrt(mag_sq()); };
    };


    template<arithmetic T = double>
    struct Vec2 : Base_vec<T>
    {
        Vec2() : x(0), y(0) {}
        Vec2(T a, T b) : x(a), y(b) {}
        T x;
        T y;

        T mag_sq(){ return x * x + y * y; }
    };


    template<arithmetic T>
    struct Vec3
    {
        Vec3() : x(0), y(0), z(0) {}
        Vec3(T a, T b, T c) : x(a), y(b), z(c) {}

        T x;
        T y;
        T z;

        T mag_sq(){ return x * x + y * y + z * z; }
    };


    template<arithmetic T>
    struct Vec4
    {
        Vec4() : x(0), y(0), z(0), w(0) {}
        Vec4(T a, T b, T c, T d) : x(a), y(b), z(c), w(d) {}

        T x;
        T y;
        T z;
        T w;

        T mag_sq(){ return x * x + y * y + z * z + w * w; }
    };
}
