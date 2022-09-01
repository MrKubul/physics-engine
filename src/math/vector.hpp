#pragma once
#include <type_traits>
#include <concepts>
#include <cmath>
#include <ostream>

namespace dziekan{
    // Concept encapsulating all numbers (floats, doubles, ints, long longs, etc)
    template<typename T>
    concept arithmetic = std::is_arithmetic_v<T>;


    template<arithmetic T>
    struct Base_vec{
        inline virtual T mag_sq() const = 0;
        inline T mag() const { return std::sqrt(mag_sq()); };
    };


    template<arithmetic T = double>
    struct Vec2 : public Base_vec<T>
    {
        inline Vec2() : x(0), y(0) {}
        inline Vec2(T a, T b) : x(a), y(b) {}
        T x;
        T y;

        inline T mag_sq() const { return x * x + y * y; }
        inline T dot(const Vec2 &rhs) const { return x * rhs.x + y * rhs.y; }
        inline Vec2<T> norm() const { return Vec2<T>(x/Vec2<T>::mag(), y/Vec2<T>::mag()); }
        inline Vec2<T> perp() const { return Vec2<T>(-y, x); }
    };


    template<arithmetic T>
    struct Vec3 : public Base_vec<T>
    {
        inline Vec3() : x(0), y(0), z(0) {}
        inline Vec3(T a, T b, T c) : x(a), y(b), z(c) {}

        T x;
        T y;
        T z;

        inline T mag_sq() const { return x * x + y * y + z * z; }
        inline T dot(const Vec3<T> &rhs) const { return x * rhs.x + y * rhs.y + z * rhs.z; }
        inline Vec3<T> norm() const { return Vec3<T>(x/Vec3<T>::mag(), y/Vec3<T>::mag(), z/Vec3<T>::mag()); }
    };


    template<arithmetic T>
    struct Vec4 : public Base_vec<T>
    {
        inline Vec4() : x(0), y(0), z(0), w(0) {}
        inline Vec4(T a, T b, T c, T d) : x(a), y(b), z(c), w(d) {}

        T x;
        T y;
        T z;
        T w;

        inline T mag_sq() const {return x * x + y * y + z * z + w * w; }
        inline T dot(const Vec4<T> &rhs) const { return x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w; }
        inline Vec4<T> norm() const { return Vec4<T>(x/Vec4<T>::mag(), y/Vec4<T>::mag(), z/Vec4<T>::mag(), w/Vec4<T>::mag()); }
    };


    // Helpful type definitions
    typedef Vec2<int> Vec2i;
    typedef Vec2<double> Vec2d;
    typedef Vec2<float> Vec2f;

    typedef Vec3<int> Vec3i;
    typedef Vec3<double> Vec3d;
    typedef Vec3<float> Vec3f;

    typedef Vec4<int> Vec4i;
    typedef Vec4<double> Vec4d;
    typedef Vec4<float> Vec4f;


    // ADDITION (a + b)
    template<arithmetic T>
    Vec2<T> operator+(const Vec2<T> &lhs, const Vec2<T> &rhs)
    { 
        return Vec2(lhs.x + rhs.x, lhs.y + rhs.y);
    }
    template<arithmetic T>
    Vec3<T> operator+(const Vec3<T> &lhs, const Vec3<T> &rhs)
    { 
        return Vec3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
    }
    template<arithmetic T>
    Vec4<T> operator+(const Vec4<T> &lhs, const Vec4<T> &rhs)
    { 
        return Vec4(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w);
    }


    // SUBTRACTION (a - b)
    template<arithmetic T>
    Vec2<T> operator-(const Vec2<T> &lhs, const Vec2<T> &rhs)
    { 
        return Vec2(lhs.x - rhs.x, lhs.y - rhs.y);
    }
    template<arithmetic T>
    Vec3<T> operator-(const Vec3<T> &lhs, const Vec3<T> &rhs)
    { 
        return Vec3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
    }
    template<arithmetic T>
    Vec4<T> operator-(const Vec4<T> &lhs, const Vec4<T> &rhs)
    { 
        return Vec4(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w);
    }


    // PLUS_EQUALS (a += b)
    template<arithmetic T>
    Vec2<T>& operator+=(Vec2<T> &lhs, const Vec2<T> &rhs)
    {
        lhs.x += rhs.x;
        lhs.y += rhs.y;
        return lhs;
    }
    template<arithmetic T>
    Vec3<T>& operator+=(Vec3<T> &lhs, const Vec3<T> &rhs)
    { 
        lhs.x += rhs.x;
        lhs.y += rhs.y;
        lhs.z += rhs.z;
        return lhs;
    }
    template<arithmetic T>
    Vec4<T>& operator+=(Vec4<T> &lhs, const Vec4<T> &rhs)
    { 
        lhs.x += rhs.x;
        lhs.y += rhs.y;
        lhs.z += rhs.z;
        lhs.w += rhs.w;
        return lhs;
    }


    // MINUS_EQUALS (a -= b)
    template<arithmetic T>
    Vec2<T>& operator-=(Vec2<T> &lhs, const Vec2<T> &rhs)
    {
        lhs.x -= rhs.x;
        lhs.y -= rhs.y;
        return lhs;
    }
    template<arithmetic T>
    Vec3<T>& operator-=(Vec3<T> &lhs, const Vec3<T> &rhs)
    { 
        lhs.x -= rhs.x;
        lhs.y -= rhs.y;
        lhs.z -= rhs.z;
        return lhs;

    }
    template<arithmetic T>
    Vec4<T>& operator-=(Vec4<T> &lhs, const Vec4<T> &rhs)
    { 
        lhs.x -= rhs.x;
        lhs.y -= rhs.y;
        lhs.z -= rhs.z;
        lhs.w -= rhs.w;
        return lhs;
    }


    // MULTIPLICATION BY A SCALAR (k * a; k ϵ arithmetic)
    template<arithmetic T> 
    Vec2<T> operator*(const T &lhs, const Vec2<T> &rhs) { return Vec2(lhs * rhs.x,lhs * rhs.y); }
    template<arithmetic T> 
    Vec3<T> operator*(const T &lhs, const Vec3<T> &rhs) { return Vec3(lhs * rhs.x,lhs * rhs.y, lhs * rhs.z); }
    template<arithmetic T> 
    Vec4<T> operator*(const T &lhs, const Vec4<T> &rhs) { return Vec4(lhs * rhs.x,lhs * rhs.y, lhs * rhs.z, lhs * rhs.w); }


    // MULTIPLICATION BY A SCALAR (a * k; k ϵ arithmetic)
    template<arithmetic T> 
    Vec2<T> operator*(const Vec2<T> &lhs, const T &rhs) { return Vec2(lhs.x * rhs,lhs.y * rhs); }
    template<arithmetic T> 
    Vec3<T> operator*(const Vec3<T> &lhs, const T &rhs) { return Vec3(lhs.x * rhs,lhs.y * rhs, lhs.z * rhs); }
    template<arithmetic T> 
    Vec4<T> operator*(const Vec4<T> &lhs, const T& rhs) { return Vec4(lhs.x * rhs,lhs.y * rhs, lhs.z * rhs, lhs.w * rhs); }


    // DIVISION BY A SCALAR (a / k; k ϵ arithmetic)
    template<arithmetic T> 
    Vec2<T> operator/(const Vec2<T> &lhs, const T &rhs) { return Vec2(lhs.x / rhs,lhs.y / rhs); }
    template<arithmetic T> 
    Vec3<T> operator/(const Vec3<T> &lhs, const T &rhs) { return Vec3(lhs.x / rhs,lhs.y / rhs, lhs.z / rhs); }
    template<arithmetic T> 
    Vec4<T> operator/(const Vec4<T> &lhs, const T& rhs) { return Vec4(lhs.x / rhs,lhs.y / rhs, lhs.z / rhs, lhs.w / rhs); }


    // MULTIPLY_EQUALS BY A SCALAR (a *= k; k ϵ arithmetic)
    template<arithmetic T> 
    Vec2<T>& operator*=(Vec2<T> &lhs, const T &rhs)
    {
        lhs.x *= rhs;
        lhs.y *= rhs;
        return lhs;
    }
    template<arithmetic T> 
    Vec3<T>& operator*=(Vec3<T> &lhs, const T &rhs)
    {
        lhs.x *= rhs;
        lhs.y *= rhs;
        lhs.z *= rhs;
        return lhs;
    }
    template<arithmetic T> 
    Vec4<T>& operator*=(Vec4<T> &lhs, const T& rhs)
    {
        lhs.x *= rhs;
        lhs.y *= rhs;
        lhs.z *= rhs;
        lhs.w *= rhs;
        return lhs;
    }


    // DIVIDE_EQUALS BY A SCALAR (a /= k; k ϵ arithmetic)
    template<arithmetic T> 
    Vec2<T>& operator/=(Vec2<T> &lhs, const T &rhs)
    {
        lhs.x /= rhs;
        lhs.y /= rhs;
        return lhs;

    }
    template<arithmetic T> 
    Vec3<T>& operator/=(Vec3<T> &lhs, const T &rhs)
    {
        lhs.x /= rhs;
        lhs.y /= rhs;
        lhs.z /= rhs;
        return lhs;

    }
    template<arithmetic T> 
    Vec4<T>& operator/=(Vec4<T> &lhs, const T& rhs)
    {
        lhs.x /= rhs;
        lhs.y /= rhs;
        lhs.z /= rhs;
        lhs.w /= rhs;
        return lhs;
    }


    // EQUALS (a == b)
    template<arithmetic T> 
    bool operator==(const Vec2<T> &lhs, const Vec2<T> &rhs) {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }
    template<arithmetic T> 
    bool operator==(const Vec3<T> &lhs, const Vec3<T> &rhs) {
        return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
    }
    template<arithmetic T> 
    bool operator==(const Vec4<T> &lhs, const Vec4<T> &rhs) {
        return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z && lhs.w == rhs.w;
    }


    // UNARY MINUS (-a)
    template<arithmetic T> 
    Vec2<T> operator-(const Vec2<T> &rhs) { return Vec2(-rhs.x,-rhs.y); }
    template<arithmetic T> 
    Vec3<T> operator-(const Vec3<T> &rhs) { return Vec3(-rhs.x, -rhs.y, -rhs.z); }
    template<arithmetic T> 
    Vec4<T> operator-(const Vec4<T> &rhs) { return Vec4(-rhs.x, -rhs.y, -rhs.z, -rhs.w); }


    // OSTREAM
    template<arithmetic T> 
    std::ostream& operator<< (std::ostream& out, const Vec2<T> &vec)
    {
        return out << vec.x << " " << vec.y;
    }
    template<arithmetic T> 
    std::ostream& operator<< (std::ostream& out, const Vec3<T> &vec)
    {
        return out << vec.x << " " << vec.y << " " << vec.z;
    }
    template<arithmetic T> 
    std::ostream& operator<< (std::ostream& out, const Vec4<T> &vec)
    {
        return out << vec.x << " " << vec.y << " " << vec.z << " " << vec.w;
    }

}
