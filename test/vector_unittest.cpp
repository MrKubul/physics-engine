#include "../src/math/vector.hpp"
#include <gtest/gtest.h>

using vector_types_to_test = testing::Types<int, double, long long>;

template<dziekan::arithmetic T>
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
    dziekan::Vector2<TypeParam> x(this->a1, this->a2), y(this->b1, this->b2);
    dziekan::Vector2<TypeParam> z = x + y;
    EXPECT_EQ(z.x, this->a1 + this->b1);
    EXPECT_EQ(z.y, this->a2 + this->b2);
}

TYPED_TEST(VectorTest, testing_vec2_plusequals)
{
    dziekan::Vector2<TypeParam> x(this->a1, this->a2), y(this->b1, this->b2);
    x += y;
    EXPECT_EQ(x.x, this->a1 + this->b1);
    EXPECT_EQ(x.y, this->a2 + this->b2);
}

TYPED_TEST(VectorTest, testing_vec3_plus)
{
    dziekan::Vector3<TypeParam> x(this->a1, this->a2, this->a3), y(this->b1, this->b2, this->b3);
    dziekan::Vector3<TypeParam> z = x + y;
    EXPECT_EQ(z.x, this->a1 + this->b1);
    EXPECT_EQ(z.y, this->a2 + this->b2);
    EXPECT_EQ(z.z, this->a3 + this->b3);
}

TYPED_TEST(VectorTest, testing_vec3_plusequals)
{
    dziekan::Vector3<TypeParam> x(this->a1, this->a2, this->a3), y(this->b1, this->b2, this->b3);
    x += y;
    EXPECT_EQ(x.x, this->a1 + this->b1);
    EXPECT_EQ(x.y, this->a2 + this->b2);
    EXPECT_EQ(x.z, this->a3 + this->b3);
}

TYPED_TEST(VectorTest, testing_vec4_plus)
{
    dziekan::Vector4<TypeParam> x(this->a1, this->a2, this->a3, this->a4), y(this->b1, this->b2, this->b3, this->b4);
    dziekan::Vector4<TypeParam> z = x + y;
    EXPECT_EQ(z.x, this->a1 + this->b1);
    EXPECT_EQ(z.y, this->a2 + this->b2);
    EXPECT_EQ(z.z, this->a3 + this->b3);
    EXPECT_EQ(z.w, this->a4 + this->b4);
}

TYPED_TEST(VectorTest, testing_vec4_plusequals)
{
    dziekan::Vector4<TypeParam> x(this->a1, this->a2, this->a3, this->a4), y(this->b1, this->b2, this->b3, this->b4);
    x += y;
    EXPECT_EQ(x.x, this->a1 + this->b1);
    EXPECT_EQ(x.y, this->a2 + this->b2);
    EXPECT_EQ(x.z, this->a3 + this->b3);
    EXPECT_EQ(x.w, this->a4 + this->b4);
}

TYPED_TEST(VectorTest, testing_vec2_minus)
{
    dziekan::Vector2<TypeParam> x(this->a1, this->a2), y(this->b1, this->b2);
    dziekan::Vector2<TypeParam> z = x - y;
    EXPECT_EQ(z.x, this->a1 - this->b1);
    EXPECT_EQ(z.y, this->a2 - this->b2);
}

TYPED_TEST(VectorTest, testing_vec2_minusequals)
{
    dziekan::Vector2<TypeParam> x(this->a1, this->a2), y(this->b1, this->b2);
    x -= y;
    EXPECT_EQ(x.x, this->a1 - this->b1);
    EXPECT_EQ(x.y, this->a2 - this->b2);
}

TYPED_TEST(VectorTest, testing_vec3_minus)
{
    dziekan::Vector3<TypeParam> x(this->a1, this->a2, this->a3), y(this->b1, this->b2, this->b3);
    dziekan::Vector3<TypeParam> z = x - y;
    EXPECT_EQ(z.x, this->a1 - this->b1);
    EXPECT_EQ(z.y, this->a2 - this->b2);
    EXPECT_EQ(z.z, this->a3 - this->b3);
}

TYPED_TEST(VectorTest, testing_vec3_minusequals)
{
    dziekan::Vector3<TypeParam> x(this->a1, this->a2, this->a3), y(this->b1, this->b2, this->b3);
    x -= y;
    EXPECT_EQ(x.x, this->a1 - this->b1);
    EXPECT_EQ(x.y, this->a2 - this->b2);
    EXPECT_EQ(x.z, this->a3 - this->b3);
}

TYPED_TEST(VectorTest, testing_vec4_minus)
{
    dziekan::Vector4<TypeParam> x(this->a1, this->a2, this->a3, this->a4), y(this->b1, this->b2, this->b3, this->b4);
    dziekan::Vector4<TypeParam> z = x - y;
    EXPECT_EQ(z.x, this->a1 - this->b1);
    EXPECT_EQ(z.y, this->a2 - this->b2);
    EXPECT_EQ(z.z, this->a3 - this->b3);
    EXPECT_EQ(z.w, this->a4 - this->b4);
}

TYPED_TEST(VectorTest, testing_vec4_minusequals)
{
    dziekan::Vector4<TypeParam> x(this->a1, this->a2, this->a3, this->a4), y(this->b1, this->b2, this->b3, this->b4);
    x -= y;
    EXPECT_EQ(x.x, this->a1 - this->b1);
    EXPECT_EQ(x.y, this->a2 - this->b2);
    EXPECT_EQ(x.z, this->a3 - this->b3);
    EXPECT_EQ(x.w, this->a4 - this->b4);
}

TYPED_TEST(VectorTest, testing_vec2_multiply)
{
    dziekan::Vector2<TypeParam> x(this->a1, this->a2);
    dziekan::Vector2<TypeParam> y = x * this->b1;
    EXPECT_EQ(y.x, this->a1 * this->b1);
    EXPECT_EQ(y.y, this->a2 * this->b1);
}

TYPED_TEST(VectorTest, testing_vec2_multiplyequals)
{
    dziekan::Vector2<TypeParam> x(this->a1, this->a2);
    x *= this->b1;
    EXPECT_EQ(x.x, this->a1 * this->b1);
    EXPECT_EQ(x.y, this->a2 * this->b1);
}

TYPED_TEST(VectorTest, testing_vec3_multiply)
{
    dziekan::Vector3<TypeParam> x(this->a1, this->a2, this->a3);
    dziekan::Vector3<TypeParam> y = x * this->b1;
    EXPECT_EQ(y.x, this->a1 * this->b1);
    EXPECT_EQ(y.y, this->a2 * this->b1);
    EXPECT_EQ(y.z, this->a3 * this->b1);
}

TYPED_TEST(VectorTest, testing_vec3_multiplyequals)
{
    dziekan::Vector3<TypeParam> x(this->a1, this->a2, this->a3);
    x *= this->b1;
    EXPECT_EQ(x.x, this->a1 * this->b1);
    EXPECT_EQ(x.y, this->a2 * this->b1);
    EXPECT_EQ(x.z, this->a3 * this->b1);
}

TYPED_TEST(VectorTest, testing_vec4_multiply)
{
    dziekan::Vector4<TypeParam> x(this->a1, this->a2, this->a3, this->a4);
    dziekan::Vector4<TypeParam> y = x * this->b1;
    EXPECT_EQ(y.x, this->a1 * this->b1);
    EXPECT_EQ(y.y, this->a2 * this->b1);
    EXPECT_EQ(y.z, this->a3 * this->b1);
    EXPECT_EQ(y.w, this->a4 * this->b1);
}

TYPED_TEST(VectorTest, testing_vec4_multiplyequals)
{
    dziekan::Vector4<TypeParam> x(this->a1, this->a2, this->a3, this->a4);
    x *= this->b1;
    EXPECT_EQ(x.x, this->a1 * this->b1);
    EXPECT_EQ(x.y, this->a2 * this->b1);
    EXPECT_EQ(x.z, this->a3 * this->b1);
    EXPECT_EQ(x.w, this->a4 * this->b1);
}

TYPED_TEST(VectorTest, testing_vec2_multiplyrev)
{
    dziekan::Vector2<TypeParam> x(this->a1, this->a2);
    dziekan::Vector2<TypeParam> y = this->b1 * x;
    EXPECT_EQ(y.x, this->b1 * this->a1);
    EXPECT_EQ(y.y, this->b1 * this->a2);
}

TYPED_TEST(VectorTest, testing_vec3_multiplyrev)
{
    dziekan::Vector3<TypeParam> x(this->a1, this->a2, this->a3);
    dziekan::Vector3<TypeParam> y = this->b1 * x;
    EXPECT_EQ(y.x, this->b1 * this->a1);
    EXPECT_EQ(y.y, this->b1 * this->a2);
    EXPECT_EQ(y.z, this->b1 * this->a3);
}

TYPED_TEST(VectorTest, testing_vec4_multiplyrev)
{
    dziekan::Vector4<TypeParam> x(this->a1, this->a2, this->a3, this->a4);
    dziekan::Vector4<TypeParam> y = this->b1 * x;
    EXPECT_EQ(y.x, this->b1 * this->a1);
    EXPECT_EQ(y.y, this->b1 * this->a2);
    EXPECT_EQ(y.z, this->b1 * this->a3);
    EXPECT_EQ(y.w, this->b1 * this->a4);
}

TYPED_TEST(VectorTest, testing_vec2_divide)
{
    dziekan::Vector2<TypeParam> x(this->a1, this->a2);
    dziekan::Vector2<TypeParam> y = x / this->b1;
    EXPECT_EQ(y.x, this->a1 / this->b1);
    EXPECT_EQ(y.y, this->a2 / this->b1);
}

TYPED_TEST(VectorTest, testing_vec2_divideequals)
{
    dziekan::Vector2<TypeParam> x(this->a1, this->a2);
    x /= this->b1;
    EXPECT_EQ(x.x, this->a1 / this->b1);
    EXPECT_EQ(x.y, this->a2 / this->b1);
}

TYPED_TEST(VectorTest, testing_vec3_divide)
{
    dziekan::Vector3<TypeParam> x(this->a1, this->a2, this->a3);
    dziekan::Vector3<TypeParam> y = x / this->b1;
    EXPECT_EQ(y.x, this->a1 / this->b1);
    EXPECT_EQ(y.y, this->a2 / this->b1);
    EXPECT_EQ(y.z, this->a3 / this->b1);
}

TYPED_TEST(VectorTest, testing_vec3_divideequals)
{
    dziekan::Vector3<TypeParam> x(this->a1, this->a2, this->a3);
    x /= this->b1;
    EXPECT_EQ(x.x, this->a1 / this->b1);
    EXPECT_EQ(x.y, this->a2 / this->b1);
    EXPECT_EQ(x.z, this->a3 / this->b1);
}

TYPED_TEST(VectorTest, testing_vec4_divide)
{
    dziekan::Vector4<TypeParam> x(this->a1, this->a2, this->a3, this->a4);
    dziekan::Vector4<TypeParam> y = x / this->b1;
    EXPECT_EQ(y.x, this->a1 / this->b1);
    EXPECT_EQ(y.y, this->a2 / this->b1);
    EXPECT_EQ(y.z, this->a3 / this->b1);
    EXPECT_EQ(y.w, this->a4 / this->b1);
}

TYPED_TEST(VectorTest, testing_vec4_divideequals)
{
    dziekan::Vector4<TypeParam> x(this->a1, this->a2, this->a3, this->a4);
    x /= this->b1;
    EXPECT_EQ(x.x, this->a1 / this->b1);
    EXPECT_EQ(x.y, this->a2 / this->b1);
    EXPECT_EQ(x.z, this->a3 / this->b1);
    EXPECT_EQ(x.w, this->a4 / this->b1);
}

TYPED_TEST(VectorTest, testing_vec2_unaryminus)
{
    dziekan::Vector2<TypeParam> x(this->a1, this->a2);
    x = -x;
    EXPECT_EQ(x.x, -this->a1);
    EXPECT_EQ(x.y, -this->a2);
}

TYPED_TEST(VectorTest, testing_vec3_unaryminus)
{
    dziekan::Vector3<TypeParam> x(this->a1, this->a2, this->a3);
    x = -x;
    EXPECT_EQ(x.x, -this->a1);
    EXPECT_EQ(x.y, -this->a2);
    EXPECT_EQ(x.z, -this->a3);
}

TYPED_TEST(VectorTest, testing_vec4_unaryminus)
{
    dziekan::Vector4<TypeParam> x(this->a1, this->a2, this->a3, this->a4);
    x = -x;
    EXPECT_EQ(x.x, -this->a1);
    EXPECT_EQ(x.y, -this->a2);
    EXPECT_EQ(x.z, -this->a3);
    EXPECT_EQ(x.w, -this->a4);
}

TYPED_TEST(VectorTest, testing_vec2_equals)
{
    dziekan::Vector2<TypeParam> x(this->a1, this->a2);
    dziekan::Vector2<TypeParam> y(this->a3, this->a4);
    dziekan::Vector2<TypeParam> z(this->a1, this->a2);
    EXPECT_TRUE(x==z);
    EXPECT_FALSE(x==y);
}
int main (int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
