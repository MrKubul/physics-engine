#include "../src/math/vector.hpp"
#include <gtest/gtest.h>


class VectorTest : public ::testing::Test {
    protected:
        double a1 = 1;
        double a2 = 2;
        double a3 = 3;
        double a4 = 4;
        double b1 = 5;
        double b2 = 6;
        double b3 = 7;
        double b4 = 8;
};

TEST_F(VectorTest, testing_vec2_plus)
{
    dziekan::Vec2d x(a1, a2), y(b1, b2);
    dziekan::Vec2d z = x + y;
    EXPECT_EQ(z.x, a1 + b1);
    EXPECT_EQ(z.y, a2 + b2);
}

TEST_F(VectorTest, testing_vec2_plusequals)
{
    dziekan::Vec2d x(a1, a2), y(b1, b2);
    x += y;
    EXPECT_EQ(x.x, a1 + b1);
    EXPECT_EQ(x.y, a2 + b2);
}

TEST_F(VectorTest, testing_vec3_plus)
{
    dziekan::Vec3d x(a1, a2, a3), y(b1, b2, b3);
    dziekan::Vec3d z = x + y;
    EXPECT_EQ(z.x, a1 + b1);
    EXPECT_EQ(z.y, a2 + b2);
    EXPECT_EQ(z.z, a3 + b3);
}

TEST_F(VectorTest, testing_vec3_plusequals)
{
    dziekan::Vec3d x(a1, a2, a3), y(b1, b2, b3);
    x += y;
    EXPECT_EQ(x.x, a1 + b1);
    EXPECT_EQ(x.y, a2 + b2);
    EXPECT_EQ(x.z, a3 + b3);
}

TEST_F(VectorTest, testing_vec4_plus)
{
    dziekan::Vec4d x(a1, a2, a3, a4), y(b1, b2, b3, b4);
    dziekan::Vec4d z = x + y;
    EXPECT_EQ(z.x, a1 + b1);
    EXPECT_EQ(z.y, a2 + b2);
    EXPECT_EQ(z.z, a3 + b3);
    EXPECT_EQ(z.w, a4 + b4);
}

TEST_F(VectorTest, testing_vec4_plusequals)
{
    dziekan::Vec4d x(a1, a2, a3, a4), y(b1, b2, b3, b4);
    x += y;
    EXPECT_EQ(x.x, a1 + b1);
    EXPECT_EQ(x.y, a2 + b2);
    EXPECT_EQ(x.z, a3 + b3);
    EXPECT_EQ(x.w, a4 + b4);
}

TEST_F(VectorTest, testing_vec2_minus)
{
    dziekan::Vec2d x(a1, a2), y(b1, b2);
    dziekan::Vec2d z = x - y;
    EXPECT_EQ(z.x, a1 - b1);
    EXPECT_EQ(z.y, a2 - b2);
}

TEST_F(VectorTest, testing_vec2_minusequals)
{
    dziekan::Vec2d x(a1, a2), y(b1, b2);
    x -= y;
    EXPECT_EQ(x.x, a1 - b1);
    EXPECT_EQ(x.y, a2 - b2);
}

TEST_F(VectorTest, testing_vec3_minus)
{
    dziekan::Vec3d x(a1, a2, a3), y(b1, b2, b3);
    dziekan::Vec3d z = x - y;
    EXPECT_EQ(z.x, a1 - b1);
    EXPECT_EQ(z.y, a2 - b2);
    EXPECT_EQ(z.z, a3 - b3);
}

TEST_F(VectorTest, testing_vec3_minusequals)
{
    dziekan::Vec3d x(a1, a2, a3), y(b1, b2, b3);
    x -= y;
    EXPECT_EQ(x.x, a1 - b1);
    EXPECT_EQ(x.y, a2 - b2);
    EXPECT_EQ(x.z, a3 - b3);
}

TEST_F(VectorTest, testing_vec4_minus)
{
    dziekan::Vec4d x(a1, a2, a3, a4), y(b1, b2, b3, b4);
    dziekan::Vec4d z = x - y;
    EXPECT_EQ(z.x, a1 - b1);
    EXPECT_EQ(z.y, a2 - b2);
    EXPECT_EQ(z.z, a3 - b3);
    EXPECT_EQ(z.w, a4 - b4);
}

TEST_F(VectorTest, testing_vec4_minusequals)
{
    dziekan::Vec4d x(a1, a2, a3, a4), y(b1, b2, b3, b4);
    x -= y;
    EXPECT_EQ(x.x, a1 - b1);
    EXPECT_EQ(x.y, a2 - b2);
    EXPECT_EQ(x.z, a3 - b3);
    EXPECT_EQ(x.w, a4 - b4);
}

TEST_F(VectorTest, testing_vec2_multiply)
{
    dziekan::Vec2d x(a1, a2);
    dziekan::Vec2d y = x * b1;
    EXPECT_EQ(y.x, a1 * b1);
    EXPECT_EQ(y.y, a2 * b1);
}

TEST_F(VectorTest, testing_vec2_multiplyequals)
{
    dziekan::Vec2d x(a1, a2);
    x *= b1;
    EXPECT_EQ(x.x, a1 * b1);
    EXPECT_EQ(x.y, a2 * b1);
}

TEST_F(VectorTest, testing_vec3_multiply)
{
    dziekan::Vec3d x(a1, a2, a3);
    dziekan::Vec3d y = x * b1;
    EXPECT_EQ(y.x, a1 * b1);
    EXPECT_EQ(y.y, a2 * b1);
    EXPECT_EQ(y.z, a3 * b1);
}

TEST_F(VectorTest, testing_vec3_multiplyequals)
{
    dziekan::Vec3d x(a1, a2, a3);
    x *= b1;
    EXPECT_EQ(x.x, a1 * b1);
    EXPECT_EQ(x.y, a2 * b1);
    EXPECT_EQ(x.z, a3 * b1);
}

TEST_F(VectorTest, testing_vec4_multiply)
{
    dziekan::Vec4d x(a1, a2, a3, a4);
    dziekan::Vec4d y = x * b1;
    EXPECT_EQ(y.x, a1 * b1);
    EXPECT_EQ(y.y, a2 * b1);
    EXPECT_EQ(y.z, a3 * b1);
    EXPECT_EQ(y.w, a4 * b1);
}

TEST_F(VectorTest, testing_vec4_multiplyequals)
{
    dziekan::Vec4d x(a1, a2, a3, a4);
    x *= b1;
    EXPECT_EQ(x.x, a1 * b1);
    EXPECT_EQ(x.y, a2 * b1);
    EXPECT_EQ(x.z, a3 * b1);
    EXPECT_EQ(x.w, a4 * b1);
}

TEST_F(VectorTest, testing_vec2_multiplyrev)
{
    dziekan::Vec2d x(a1, a2);
    dziekan::Vec2d y = b1 * x;
    EXPECT_EQ(y.x, b1 * a1);
    EXPECT_EQ(y.y, b1 * a2);
}

TEST_F(VectorTest, testing_vec3_multiplyrev)
{
    dziekan::Vec3d x(a1, a2, a3);
    dziekan::Vec3d y = b1 * x;
    EXPECT_EQ(y.x, b1 * a1);
    EXPECT_EQ(y.y, b1 * a2);
    EXPECT_EQ(y.z, b1 * a3);
}

TEST_F(VectorTest, testing_vec4_multiplyrev)
{
    dziekan::Vec4d x(a1, a2, a3, a4);
    dziekan::Vec4d y = b1 * x;
    EXPECT_EQ(y.x, b1 * a1);
    EXPECT_EQ(y.y, b1 * a2);
    EXPECT_EQ(y.z, b1 * a3);
    EXPECT_EQ(y.w, b1 * a4);
}

TEST_F(VectorTest, testing_vec2_divide)
{
    dziekan::Vec2d x(a1, a2);
    dziekan::Vec2d y = x / b1;
    EXPECT_EQ(y.x, a1 / b1);
    EXPECT_EQ(y.y, a2 / b1);
}

TEST_F(VectorTest, testing_vec2_divideequals)
{
    dziekan::Vec2d x(a1, a2);
    x /= b1;
    EXPECT_EQ(x.x, a1 / b1);
    EXPECT_EQ(x.y, a2 / b1);
}

TEST_F(VectorTest, testing_vec3_divide)
{
    dziekan::Vec3d x(a1, a2, a3);
    dziekan::Vec3d y = x / b1;
    EXPECT_EQ(y.x, a1 / b1);
    EXPECT_EQ(y.y, a2 / b1);
    EXPECT_EQ(y.z, a3 / b1);
}

TEST_F(VectorTest, testing_vec3_divideequals)
{
    dziekan::Vec3d x(a1, a2, a3);
    x /= b1;
    EXPECT_EQ(x.x, a1 / b1);
    EXPECT_EQ(x.y, a2 / b1);
    EXPECT_EQ(x.z, a3 / b1);
}

TEST_F(VectorTest, testing_vec4_divide)
{
    dziekan::Vec4d x(a1, a2, a3, a4);
    dziekan::Vec4d y = x / b1;
    EXPECT_EQ(y.x, a1 / b1);
    EXPECT_EQ(y.y, a2 / b1);
    EXPECT_EQ(y.z, a3 / b1);
    EXPECT_EQ(y.w, a4 / b1);
}

TEST_F(VectorTest, testing_vec4_divideequals)
{
    dziekan::Vec4d x(a1, a2, a3, a4);
    x /= b1;
    EXPECT_EQ(x.x, a1 / b1);
    EXPECT_EQ(x.y, a2 / b1);
    EXPECT_EQ(x.z, a3 / b1);
    EXPECT_EQ(x.w, a4 / b1);
}
