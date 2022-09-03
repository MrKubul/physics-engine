#include "math/matrix.hpp"
#include <gtest/gtest.h>
#include <limits>

using vector_types_to_test = testing::Types<int, double, long long>;

template<deen::arithmetic T>
class MatrixTest : public ::testing::Test {
    protected:

};

TYPED_TEST_SUITE(MatrixTest, matrix_types_to_test);

TYPED_TEST(VectorTest, testing_vec2_plus)
{

}
