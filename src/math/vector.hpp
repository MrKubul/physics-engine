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
        const virtual T mag_sq() const = 0;
        const T mag() const { return std::sqrt(mag_sq()); };
    };


    template<arithmetic T = double>
    struct Vec2 : public Base_vec<T>
    {
        Vec2() : x(0), y(0) {}
        Vec2(T a, T b) : x(a), y(b) {}
        T x;
        T y;

        const T mag_sq() const { return x * x + y * y; }
        const T dot(const Vec2 &rhs) const { return x * rhs.x + y * rhs.y; }
        const Vec2<T> norm() const { return Vec2<T>(x/Vec2<T>::mag(), y/Vec2<T>::mag()); }
        const Vec2<T> perp() const { return Vec2<T>(-y, x); }
    };


    template<arithmetic T>
    struct Vec3 : public Base_vec<T>
    {
        Vec3() : x(0), y(0), z(0) {}
        Vec3(T a, T b, T c) : x(a), y(b), z(c) {}

        T x;
        T y;
        T z;

        const T mag_sq() const { return x * x + y * y + z * z; }
        const T dot(const Vec3<T> &rhs) const { return x * rhs.x + y * rhs.y + z * rhs.z; }
        const Vec3<T> norm() const { return Vec3<T>(x/Vec3<T>::mag(), y/Vec3<T>::mag(), z/Vec3<T>::mag()); }
    };


    template<arithmetic T>
    struct Vec4 : public Base_vec<T>
    {
        Vec4() : x(0), y(0), z(0), w(0) {}
        Vec4(T a, T b, T c, T d) : x(a), y(b), z(c), w(d) {}

        T x;
        T y;
        T z;
        T w;

        const T mag_sq() const { return x * x + y * y + z * z + w * w; }
        const T dot(const Vec4<T> &rhs) const { return x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w; }
        const Vec4<T> norm() const { return Vec4<T>(x/Vec4<T>::mag(), y/Vec4<T>::mag(), z/Vec4<T>::mag(), w/Vec4<T>::mag()); }
    };

    typedef Vec2<int> Vec2i;
    typedef Vec2<double> Vec2d;
    typedef Vec2<float> Vec2f;

    typedef Vec3<int> Vec3i;
    typedef Vec3<double> Vec3d;
    typedef Vec3<float> Vec3f;

    typedef Vec4<int> Vec4i;
    typedef Vec4<double> Vec4d;
    typedef Vec4<float> Vec4f;
}
