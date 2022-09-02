#pragma once
#include <type_traits>
#include <concepts>
#include <cmath>
#include <ostream>

namespace deen{
    template<typename T>
    concept arithmetic = std::is_arithmetic_v<T>;


    template<arithmetic T>
    struct BaseVector{
        inline virtual T magnitude_sqr() const = 0;
        inline T magnitude() const { return std::sqrt(magnitude_sqr()); };
    };


    template<arithmetic T = double>
    struct Vector2 : public BaseVector<T>
    {
        inline Vector2() : x(0), y(0) {}
        inline Vector2(T a, T b) : x(a), y(b) {}
        T x;
        T y;

        inline T magnitude_sqr() const { return x * x + y * y; }
        inline T dot_product(const Vector2 &rhs) const { return x * rhs.x + y * rhs.y; }
        inline Vector2<T> normalized() const { return Vector2<T>(x/Vector2<T>::magnitude(), y/Vector2<T>::magnitude()); }
        inline Vector2<T> perpendicular() const { return Vector2<T>(-y, x); }
    };


    template<arithmetic T>
    struct Vector3 : public BaseVector<T>
    {
        inline Vector3() : x(0), y(0), z(0) {}
        inline Vector3(T a, T b, T c) : x(a), y(b), z(c) {}

        T x;
        T y;
        T z;

        inline T magnitude_sqr() const { return x * x + y * y + z * z; }
        inline T dot_product(const Vector3<T> &rhs) const { return x * rhs.x + y * rhs.y + z * rhs.z; }
        inline Vector3<T> normalized() const { return Vector3<T>(x/Vector3<T>::magnitude(), y/Vector3<T>::magnitude(), z/Vector3<T>::magnitude()); }
    };


    template<arithmetic T>
    struct Vector4 : public BaseVector<T>
    {
        inline Vector4() : x(0), y(0), z(0), w(0) {}
        inline Vector4(T a, T b, T c, T d) : x(a), y(b), z(c), w(d) {}

        T x;
        T y;
        T z;
        T w;

        inline T magnitude_sqr() const {return x * x + y * y + z * z + w * w; }
        inline T dot_product(const Vector4<T> &rhs) const { return x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w; }
        inline Vector4<T> normalized() const { return Vector4<T>(x/Vector4<T>::magnitude(), y/Vector4<T>::magnitude(), z/Vector4<T>::magnitude(), w/Vector4<T>::magnitude()); }
    };


    typedef Vector2<int> Vec2i;
    typedef Vector2<double> Vec2d;
    typedef Vector2<float> Vec2f;

    typedef Vector3<int> Vec3i;
    typedef Vector3<double> Vec3d;
    typedef Vector3<float> Vec3f;

    typedef Vector4<int> Vec4i;
    typedef Vector4<double> Vec4d;
    typedef Vector4<float> Vec4f;


    template<arithmetic T>
    Vector2<T> operator+(const Vector2<T> &lhs, const Vector2<T> &rhs)
    { 
        return Vector2(lhs.x + rhs.x, lhs.y + rhs.y);
    }
    template<arithmetic T>
    Vector3<T> operator+(const Vector3<T> &lhs, const Vector3<T> &rhs)
    { 
        return Vector3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
    }
    template<arithmetic T>
    Vector4<T> operator+(const Vector4<T> &lhs, const Vector4<T> &rhs)
    { 
        return Vector4(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w);
    }


    template<arithmetic T>
    Vector2<T> operator-(const Vector2<T> &lhs, const Vector2<T> &rhs)
    { 
        return Vector2(lhs.x - rhs.x, lhs.y - rhs.y);
    }
    template<arithmetic T>
    Vector3<T> operator-(const Vector3<T> &lhs, const Vector3<T> &rhs)
    { 
        return Vector3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
    }
    template<arithmetic T>
    Vector4<T> operator-(const Vector4<T> &lhs, const Vector4<T> &rhs)
    { 
        return Vector4(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w);
    }


    template<arithmetic T>
    Vector2<T>& operator+=(Vector2<T> &lhs, const Vector2<T> &rhs)
    {
        lhs.x += rhs.x;
        lhs.y += rhs.y;
        return lhs;
    }
    template<arithmetic T>
    Vector3<T>& operator+=(Vector3<T> &lhs, const Vector3<T> &rhs)
    { 
        lhs.x += rhs.x;
        lhs.y += rhs.y;
        lhs.z += rhs.z;
        return lhs;
    }
    template<arithmetic T>
    Vector4<T>& operator+=(Vector4<T> &lhs, const Vector4<T> &rhs)
    { 
        lhs.x += rhs.x;
        lhs.y += rhs.y;
        lhs.z += rhs.z;
        lhs.w += rhs.w;
        return lhs;
    }


    template<arithmetic T>
    Vector2<T>& operator-=(Vector2<T> &lhs, const Vector2<T> &rhs)
    {
        lhs.x -= rhs.x;
        lhs.y -= rhs.y;
        return lhs;
    }
    template<arithmetic T>
    Vector3<T>& operator-=(Vector3<T> &lhs, const Vector3<T> &rhs)
    { 
        lhs.x -= rhs.x;
        lhs.y -= rhs.y;
        lhs.z -= rhs.z;
        return lhs;

    }
    template<arithmetic T>
    Vector4<T>& operator-=(Vector4<T> &lhs, const Vector4<T> &rhs)
    { 
        lhs.x -= rhs.x;
        lhs.y -= rhs.y;
        lhs.z -= rhs.z;
        lhs.w -= rhs.w;
        return lhs;
    }


    template<arithmetic T> 
    Vector2<T> operator*(const T &lhs, const Vector2<T> &rhs) { return Vector2(lhs * rhs.x,lhs * rhs.y); }
    template<arithmetic T> 
    Vector3<T> operator*(const T &lhs, const Vector3<T> &rhs) { return Vector3(lhs * rhs.x,lhs * rhs.y, lhs * rhs.z); }
    template<arithmetic T> 
    Vector4<T> operator*(const T &lhs, const Vector4<T> &rhs) { return Vector4(lhs * rhs.x,lhs * rhs.y, lhs * rhs.z, lhs * rhs.w); }


    template<arithmetic T> 
    Vector2<T> operator*(const Vector2<T> &lhs, const T &rhs) { return Vector2(lhs.x * rhs,lhs.y * rhs); }
    template<arithmetic T> 
    Vector3<T> operator*(const Vector3<T> &lhs, const T &rhs) { return Vector3(lhs.x * rhs,lhs.y * rhs, lhs.z * rhs); }
    template<arithmetic T> 
    Vector4<T> operator*(const Vector4<T> &lhs, const T& rhs) { return Vector4(lhs.x * rhs,lhs.y * rhs, lhs.z * rhs, lhs.w * rhs); }


    template<arithmetic T> 
    Vector2<T> operator/(const Vector2<T> &lhs, const T &rhs) { return Vector2(lhs.x / rhs,lhs.y / rhs); }
    template<arithmetic T> 
    Vector3<T> operator/(const Vector3<T> &lhs, const T &rhs) { return Vector3(lhs.x / rhs,lhs.y / rhs, lhs.z / rhs); }
    template<arithmetic T> 
    Vector4<T> operator/(const Vector4<T> &lhs, const T& rhs) { return Vector4(lhs.x / rhs,lhs.y / rhs, lhs.z / rhs, lhs.w / rhs); }


    template<arithmetic T> 
    Vector2<T>& operator*=(Vector2<T> &lhs, const T &rhs)
    {
        lhs.x *= rhs;
        lhs.y *= rhs;
        return lhs;
    }
    template<arithmetic T> 
    Vector3<T>& operator*=(Vector3<T> &lhs, const T &rhs)
    {
        lhs.x *= rhs;
        lhs.y *= rhs;
        lhs.z *= rhs;
        return lhs;
    }
    template<arithmetic T> 
    Vector4<T>& operator*=(Vector4<T> &lhs, const T& rhs)
    {
        lhs.x *= rhs;
        lhs.y *= rhs;
        lhs.z *= rhs;
        lhs.w *= rhs;
        return lhs;
    }


    template<arithmetic T> 
    Vector2<T>& operator/=(Vector2<T> &lhs, const T &rhs)
    {
        lhs.x /= rhs;
        lhs.y /= rhs;
        return lhs;

    }
    template<arithmetic T> 
    Vector3<T>& operator/=(Vector3<T> &lhs, const T &rhs)
    {
        lhs.x /= rhs;
        lhs.y /= rhs;
        lhs.z /= rhs;
        return lhs;

    }
    template<arithmetic T> 
    Vector4<T>& operator/=(Vector4<T> &lhs, const T& rhs)
    {
        lhs.x /= rhs;
        lhs.y /= rhs;
        lhs.z /= rhs;
        lhs.w /= rhs;
        return lhs;
    }


    template<arithmetic T> 
    bool operator==(const Vector2<T> &lhs, const Vector2<T> &rhs) {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }
    template<arithmetic T> 
    bool operator==(const Vector3<T> &lhs, const Vector3<T> &rhs) {
        return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
    }
    template<arithmetic T> 
    bool operator==(const Vector4<T> &lhs, const Vector4<T> &rhs) {
        return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z && lhs.w == rhs.w;
    }


    template<arithmetic T> 
    Vector2<T> operator-(const Vector2<T> &rhs) { return Vector2(-rhs.x,-rhs.y); }
    template<arithmetic T> 
    Vector3<T> operator-(const Vector3<T> &rhs) { return Vector3(-rhs.x, -rhs.y, -rhs.z); }
    template<arithmetic T> 
    Vector4<T> operator-(const Vector4<T> &rhs) { return Vector4(-rhs.x, -rhs.y, -rhs.z, -rhs.w); }


    template<arithmetic T> 
    std::ostream& operator<< (std::ostream& out, const Vector2<T> &vec)
    {
        return out << vec.x << " " << vec.y;
    }
    template<arithmetic T> 
    std::ostream& operator<< (std::ostream& out, const Vector3<T> &vec)
    {
        return out << vec.x << " " << vec.y << " " << vec.z;
    }
    template<arithmetic T> 
    std::ostream& operator<< (std::ostream& out, const Vector4<T> &vec)
    {
        return out << vec.x << " " << vec.y << " " << vec.z << " " << vec.w;
    }
}
