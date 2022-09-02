#include "math/vector.hpp"
#include <gtest/gtest.h>
#include <limits>

using vector_types_to_test = testing::Types<int, double, long long>;

template<deen::arithmetic T>
class VectorTest : public ::testing::Test {
    protected:
        T a1 = 1;
        T a2 = 2;
        T a3 = 3;
        T a4 = 4;
        T b1 = 5;
        T b2 = 6;
        T b3 = 7;
        T b4 = 8;
};

TYPED_TEST_SUITE(VectorTest, vector_types_to_test);

TYPED_TEST(VectorTest, testing_vec2_plus)
{
    deen::Vector2<TypeParam> x(this->a1, this->a2), y(this->b1, this->b2);
    deen::Vector2<TypeParam> z = x + y;
    EXPECT_EQ(z.x, this->a1 + this->b1);
    EXPECT_EQ(z.y, this->a2 + this->b2);
}

TYPED_TEST(VectorTest, testing_vec2_plusequals)
{
    deen::Vector2<TypeParam> x(this->a1, this->a2), y(this->b1, this->b2);
    x += y;
    EXPECT_EQ(x.x, this->a1 + this->b1);
    EXPECT_EQ(x.y, this->a2 + this->b2);
}

TYPED_TEST(VectorTest, testing_vec3_plus)
{
    deen::Vector3<TypeParam> x(this->a1, this->a2, this->a3), y(this->b1, this->b2, this->b3);
    deen::Vector3<TypeParam> z = x + y;
    EXPECT_EQ(z.x, this->a1 + this->b1);
    EXPECT_EQ(z.y, this->a2 + this->b2);
    EXPECT_EQ(z.z, this->a3 + this->b3);
}

TYPED_TEST(VectorTest, testing_vec3_plusequals)
{
    deen::Vector3<TypeParam> x(this->a1, this->a2, this->a3), y(this->b1, this->b2, this->b3);
    x += y;
    EXPECT_EQ(x.x, this->a1 + this->b1);
    EXPECT_EQ(x.y, this->a2 + this->b2);
    EXPECT_EQ(x.z, this->a3 + this->b3);
}

TYPED_TEST(VectorTest, testing_vec4_plus)
{
    deen::Vector4<TypeParam> x(this->a1, this->a2, this->a3, this->a4), y(this->b1, this->b2, this->b3, this->b4);
    deen::Vector4<TypeParam> z = x + y;
    EXPECT_EQ(z.x, this->a1 + this->b1);
    EXPECT_EQ(z.y, this->a2 + this->b2);
    EXPECT_EQ(z.z, this->a3 + this->b3);
    EXPECT_EQ(z.w, this->a4 + this->b4);
}

TYPED_TEST(VectorTest, testing_vec4_plusequals)
{
    deen::Vector4<TypeParam> x(this->a1, this->a2, this->a3, this->a4), y(this->b1, this->b2, this->b3, this->b4);
    x += y;
    EXPECT_EQ(x.x, this->a1 + this->b1);
    EXPECT_EQ(x.y, this->a2 + this->b2);
    EXPECT_EQ(x.z, this->a3 + this->b3);
    EXPECT_EQ(x.w, this->a4 + this->b4);
}

TYPED_TEST(VectorTest, testing_vec2_minus)
{
    deen::Vector2<TypeParam> x(this->a1, this->a2), y(this->b1, this->b2);
    deen::Vector2<TypeParam> z = x - y;
    EXPECT_EQ(z.x, this->a1 - this->b1);
    EXPECT_EQ(z.y, this->a2 - this->b2);
}

TYPED_TEST(VectorTest, testing_vec2_minusequals)
{
    deen::Vector2<TypeParam> x(this->a1, this->a2), y(this->b1, this->b2);
    x -= y;
    EXPECT_EQ(x.x, this->a1 - this->b1);
    EXPECT_EQ(x.y, this->a2 - this->b2);
}

TYPED_TEST(VectorTest, testing_vec3_minus)
{
    deen::Vector3<TypeParam> x(this->a1, this->a2, this->a3), y(this->b1, this->b2, this->b3);
    deen::Vector3<TypeParam> z = x - y;
    EXPECT_EQ(z.x, this->a1 - this->b1);
    EXPECT_EQ(z.y, this->a2 - this->b2);
    EXPECT_EQ(z.z, this->a3 - this->b3);
}

TYPED_TEST(VectorTest, testing_vec3_minusequals)
{
    deen::Vector3<TypeParam> x(this->a1, this->a2, this->a3), y(this->b1, this->b2, this->b3);
    x -= y;
    EXPECT_EQ(x.x, this->a1 - this->b1);
    EXPECT_EQ(x.y, this->a2 - this->b2);
    EXPECT_EQ(x.z, this->a3 - this->b3);
}

TYPED_TEST(VectorTest, testing_vec4_minus)
{
    deen::Vector4<TypeParam> x(this->a1, this->a2, this->a3, this->a4), y(this->b1, this->b2, this->b3, this->b4);
    deen::Vector4<TypeParam> z = x - y;
    EXPECT_EQ(z.x, this->a1 - this->b1);
    EXPECT_EQ(z.y, this->a2 - this->b2);
    EXPECT_EQ(z.z, this->a3 - this->b3);
    EXPECT_EQ(z.w, this->a4 - this->b4);
}

TYPED_TEST(VectorTest, testing_vec4_minusequals)
{
    deen::Vector4<TypeParam> x(this->a1, this->a2, this->a3, this->a4), y(this->b1, this->b2, this->b3, this->b4);
    x -= y;
    EXPECT_EQ(x.x, this->a1 - this->b1);
    EXPECT_EQ(x.y, this->a2 - this->b2);
    EXPECT_EQ(x.z, this->a3 - this->b3);
    EXPECT_EQ(x.w, this->a4 - this->b4);
}

TYPED_TEST(VectorTest, testing_vec2_multiply)
{
    deen::Vector2<TypeParam> x(this->a1, this->a2);
    deen::Vector2<TypeParam> y = x * this->b1;
    EXPECT_EQ(y.x, this->a1 * this->b1);
    EXPECT_EQ(y.y, this->a2 * this->b1);
}

TYPED_TEST(VectorTest, testing_vec2_multiplyequals)
{
    deen::Vector2<TypeParam> x(this->a1, this->a2);
    x *= this->b1;
    EXPECT_EQ(x.x, this->a1 * this->b1);
    EXPECT_EQ(x.y, this->a2 * this->b1);
}

TYPED_TEST(VectorTest, testing_vec3_multiply)
{
    deen::Vector3<TypeParam> x(this->a1, this->a2, this->a3);
    deen::Vector3<TypeParam> y = x * this->b1;
    EXPECT_EQ(y.x, this->a1 * this->b1);
    EXPECT_EQ(y.y, this->a2 * this->b1);
    EXPECT_EQ(y.z, this->a3 * this->b1);
}

TYPED_TEST(VectorTest, testing_vec3_multiplyequals)
{
    deen::Vector3<TypeParam> x(this->a1, this->a2, this->a3);
    x *= this->b1;
    EXPECT_EQ(x.x, this->a1 * this->b1);
    EXPECT_EQ(x.y, this->a2 * this->b1);
    EXPECT_EQ(x.z, this->a3 * this->b1);
}

TYPED_TEST(VectorTest, testing_vec4_multiply)
{
    deen::Vector4<TypeParam> x(this->a1, this->a2, this->a3, this->a4);
    deen::Vector4<TypeParam> y = x * this->b1;
    EXPECT_EQ(y.x, this->a1 * this->b1);
    EXPECT_EQ(y.y, this->a2 * this->b1);
    EXPECT_EQ(y.z, this->a3 * this->b1);
    EXPECT_EQ(y.w, this->a4 * this->b1);
}

TYPED_TEST(VectorTest, testing_vec4_multiplyequals)
{
    deen::Vector4<TypeParam> x(this->a1, this->a2, this->a3, this->a4);
    x *= this->b1;
    EXPECT_EQ(x.x, this->a1 * this->b1);
    EXPECT_EQ(x.y, this->a2 * this->b1);
    EXPECT_EQ(x.z, this->a3 * this->b1);
    EXPECT_EQ(x.w, this->a4 * this->b1);
}

TYPED_TEST(VectorTest, testing_vec2_multiplyrev)
{
    deen::Vector2<TypeParam> x(this->a1, this->a2);
    deen::Vector2<TypeParam> y = this->b1 * x;
    EXPECT_EQ(y.x, this->b1 * this->a1);
    EXPECT_EQ(y.y, this->b1 * this->a2);
}

TYPED_TEST(VectorTest, testing_vec3_multiplyrev)
{
    deen::Vector3<TypeParam> x(this->a1, this->a2, this->a3);
    deen::Vector3<TypeParam> y = this->b1 * x;
    EXPECT_EQ(y.x, this->b1 * this->a1);
    EXPECT_EQ(y.y, this->b1 * this->a2);
    EXPECT_EQ(y.z, this->b1 * this->a3);
}

TYPED_TEST(VectorTest, testing_vec4_multiplyrev)
{
    deen::Vector4<TypeParam> x(this->a1, this->a2, this->a3, this->a4);
    deen::Vector4<TypeParam> y = this->b1 * x;
    EXPECT_EQ(y.x, this->b1 * this->a1);
    EXPECT_EQ(y.y, this->b1 * this->a2);
    EXPECT_EQ(y.z, this->b1 * this->a3);
    EXPECT_EQ(y.w, this->b1 * this->a4);
}

TYPED_TEST(VectorTest, testing_vec2_divide)
{
    deen::Vector2<TypeParam> x(this->a1, this->a2);
    deen::Vector2<TypeParam> y = x / this->b1;
    EXPECT_EQ(y.x, this->a1 / this->b1);
    EXPECT_EQ(y.y, this->a2 / this->b1);
}

TYPED_TEST(VectorTest, testing_vec2_divideequals)
{
    deen::Vector2<TypeParam> x(this->a1, this->a2);
    x /= this->b1;
    EXPECT_EQ(x.x, this->a1 / this->b1);
    EXPECT_EQ(x.y, this->a2 / this->b1);
}

TYPED_TEST(VectorTest, testing_vec3_divide)
{
    deen::Vector3<TypeParam> x(this->a1, this->a2, this->a3);
    deen::Vector3<TypeParam> y = x / this->b1;
    EXPECT_EQ(y.x, this->a1 / this->b1);
    EXPECT_EQ(y.y, this->a2 / this->b1);
    EXPECT_EQ(y.z, this->a3 / this->b1);
}

TYPED_TEST(VectorTest, testing_vec3_divideequals)
{
    deen::Vector3<TypeParam> x(this->a1, this->a2, this->a3);
    x /= this->b1;
    EXPECT_EQ(x.x, this->a1 / this->b1);
    EXPECT_EQ(x.y, this->a2 / this->b1);
    EXPECT_EQ(x.z, this->a3 / this->b1);
}

TYPED_TEST(VectorTest, testing_vec4_divide)
{
    deen::Vector4<TypeParam> x(this->a1, this->a2, this->a3, this->a4);
    deen::Vector4<TypeParam> y = x / this->b1;
    EXPECT_EQ(y.x, this->a1 / this->b1);
    EXPECT_EQ(y.y, this->a2 / this->b1);
    EXPECT_EQ(y.z, this->a3 / this->b1);
    EXPECT_EQ(y.w, this->a4 / this->b1);
}

TYPED_TEST(VectorTest, testing_vec4_divideequals)
{
    deen::Vector4<TypeParam> x(this->a1, this->a2, this->a3, this->a4);
    x /= this->b1;
    EXPECT_EQ(x.x, this->a1 / this->b1);
    EXPECT_EQ(x.y, this->a2 / this->b1);
    EXPECT_EQ(x.z, this->a3 / this->b1);
    EXPECT_EQ(x.w, this->a4 / this->b1);
}

TYPED_TEST(VectorTest, testing_vec2_unaryminus)
{
    deen::Vector2<TypeParam> x(this->a1, this->a2);
    x = -x;
    EXPECT_EQ(x.x, -this->a1);
    EXPECT_EQ(x.y, -this->a2);
}

TYPED_TEST(VectorTest, testing_vec3_unaryminus)
{
    deen::Vector3<TypeParam> x(this->a1, this->a2, this->a3);
    x = -x;
    EXPECT_EQ(x.x, -this->a1);
    EXPECT_EQ(x.y, -this->a2);
    EXPECT_EQ(x.z, -this->a3);
}

TYPED_TEST(VectorTest, testing_vec4_unaryminus)
{
    deen::Vector4<TypeParam> x(this->a1, this->a2, this->a3, this->a4);
    x = -x;
    EXPECT_EQ(x.x, -this->a1);
    EXPECT_EQ(x.y, -this->a2);
    EXPECT_EQ(x.z, -this->a3);
    EXPECT_EQ(x.w, -this->a4);
}

TYPED_TEST(VectorTest, testing_vec2_equals)
{
    deen::Vector2<TypeParam> x(this->a1, this->a2);
    deen::Vector2<TypeParam> y(this->a3, this->a4);
    deen::Vector2<TypeParam> z(this->a1, this->a2);
    EXPECT_TRUE(x==z);
    EXPECT_FALSE(x==y);
}

TYPED_TEST(VectorTest, testing_vec2_dot_product)
{
    deen::Vector2<TypeParam> x(this->a1, this->a2);
    deen::Vector2<TypeParam> y(this->b1, this->b2);
    EXPECT_EQ(x.dot_product(y), this->a1 * this->b1 + this->a2 * this->b2);
}

TYPED_TEST(VectorTest, testing_vec3_dot_product)
{
    deen::Vector3<TypeParam> x(this->a1, this->a2, this->a3);
    deen::Vector3<TypeParam> y(this->b1, this->b2, this->b3);
    EXPECT_EQ(x.dot_product(y), this->a1 * this->b1 + this->a2 * this->b2 + this->a3 * this->b3);
}

TYPED_TEST(VectorTest, testing_vec4_dot_product)
{
    deen::Vector4<TypeParam> x(this->a1, this->a2, this->a3, this->a4);
    deen::Vector4<TypeParam> y(this->b1, this->b2, this->b3, this->b4);
    EXPECT_EQ(x.dot_product(y), this->a1 * this->b1 + this->a2 * this->b2 + this->a3 * this->b3 + this->a4 * this->b4);
}

TYPED_TEST(VectorTest, testing_vec2_magnitude)
{
    deen::Vector2<TypeParam> x(this->a1, this->a2);
    EXPECT_EQ(x.magnitude(), std::sqrt(this->a1 * this->a1 + this->a2 * this->a2));
}

TYPED_TEST(VectorTest, testing_vec3_magnitude)
{
    deen::Vector3<TypeParam> x(this->a1, this->a2, this->a3);
    EXPECT_EQ(x.magnitude(), std::sqrt(this->a1 * this->a1 + this->a2 * this->a2 + this->a3 * this->a3));
}

TYPED_TEST(VectorTest, testing_vec4_magnitude)
{
    deen::Vector4<TypeParam> x(this->a1, this->a2, this->a3, this->a4);
    EXPECT_EQ(x.magnitude(), std::sqrt(this->a1 * this->a1 + this->a2 * this->a2 + this->a3 * this->a3 + this->a4 * this->a4));
}

TYPED_TEST(VectorTest, testing_vec2_magnitude_sqr)
{
    deen::Vector2<TypeParam> x(this->a1, this->a2);
    EXPECT_EQ(x.magnitude_sqr(), this->a1 * this->a1 + this->a2 * this->a2);
}

TYPED_TEST(VectorTest, testing_vec3_magnitude_sqr)
{
    deen::Vector3<TypeParam> x(this->a1, this->a2, this->a3);
    EXPECT_EQ(x.magnitude_sqr(), this->a1 * this->a1 + this->a2 * this->a2 + this->a3 * this->a3);
}

TYPED_TEST(VectorTest, testing_vec4_magnitude_sqr)
{
    deen::Vector4<TypeParam> x(this->a1, this->a2, this->a3, this->a4);
    EXPECT_EQ(x.magnitude_sqr(), this->a1 * this->a1 + this->a2 * this->a2 + this->a3 * this->a3 + this->a4 * this->a4);
}



TYPED_TEST(VectorTest, testing_vec2_normalized)
{
    auto doubles_equals_lambda = [](double a, double b)
    {
        return (abs(a - b) <= std::numeric_limits<double>::epsilon());
    };
    deen::Vector2<TypeParam> x(this->a1, this->a2);
    deen::Vector2<double> y = x.normalized();
    EXPECT_TRUE(doubles_equals_lambda(y.magnitude(), 1.0));
    EXPECT_EQ(x.x / x.magnitude(), this->a1 / x.magnitude());
    EXPECT_EQ(x.y / x.magnitude(), this->a2 / x.magnitude());
}

TYPED_TEST(VectorTest, testing_vec3_normalized)
{
    auto doubles_equals_lambda = [](double a, double b)
    {
        return (abs(a - b) <= std::numeric_limits<double>::epsilon());
    };
    deen::Vector3<TypeParam> x(this->a1, this->a2, this->a3);
    deen::Vector3<double> y = x.normalized();
    EXPECT_TRUE(doubles_equals_lambda(y.magnitude(), 1.0));
    EXPECT_EQ(x.x / x.magnitude(), this->a1 / x.magnitude());
    EXPECT_EQ(x.y / x.magnitude(), this->a2 / x.magnitude());
    EXPECT_EQ(x.z / x.magnitude(), this->a3 / x.magnitude());
}

TYPED_TEST(VectorTest, testing_vec4_normalized)
{
    auto doubles_equals_lambda = [](double a, double b)
    {
        return (abs(a - b) <= std::numeric_limits<double>::epsilon());
    };
    deen::Vector4<TypeParam> x(this->a1, this->a2, this->a3, this->a4);
    deen::Vector4<double> y = x.normalized();
    EXPECT_TRUE(doubles_equals_lambda(y.magnitude(), 1.0));
    EXPECT_EQ(x.x / x.magnitude(), this->a1 / x.magnitude());
    EXPECT_EQ(x.y / x.magnitude(), this->a2 / x.magnitude());
    EXPECT_EQ(x.z / x.magnitude(), this->a3 / x.magnitude());
    EXPECT_EQ(x.w / x.magnitude(), this->a4 / x.magnitude());
}

TYPED_TEST(VectorTest, testing_vec2_perpendicular)
{
    deen::Vector2<TypeParam> x(this->a1, this->a2);
    deen::Vector2<TypeParam> y = x.perpendicular();
    EXPECT_EQ(y.x, -this->a2);
    EXPECT_EQ(y.y, this->a1);
}
