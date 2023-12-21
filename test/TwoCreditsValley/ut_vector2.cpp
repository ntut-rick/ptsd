#include <gtest/gtest.h>

#include "TwoCreditsValley/Unity/Vector2.hpp"

#include <tuple>

using TwoCreditsValley::Unity::Vector2i;
using TwoCreditsValley::Unity::Vector2f;
using TwoCreditsValley::Unity::Vector2;

template<typename T>
class Vector2Test : public ::testing::TestWithParam<double> {
 protected:
  void SetUp() override {
    vec = {2, 3};
  }
  Vector2<T> vec;
};

using Vector2IntTest = Vector2Test<int>;
using Vector2FloatTest = Vector2Test<float>;

template <typename T>
class MyFixture : public ::testing::TestWithParam<std::tuple<T,T>>  {
 protected:
  void SetUp() override {
    vec = {2, 3};
  }
  Vector2<T> vec;
};

TEST_F(Vector2IntTest, Vector2iAdding) {
    auto result = vec + vec;
    auto compare = Vector2i(
        vec.x + vec.x,
        vec.y + vec.y);
    EXPECT_EQ(result.x, compare.x);
    EXPECT_EQ(result.y, compare.y);
}

TEST_F(Vector2IntTest, Vector2iMultiple) {
    auto result = vec * 1.5;
    auto compare = Vector2i(
        vec.x *1.5,
        vec.y *1.5);
    EXPECT_EQ(result.x, compare.x);
    EXPECT_EQ(result.y, compare.y);
}

TEST_F(Vector2FloatTest, Vector2iAdding) {
    auto result = vec + vec;
    auto compare = Vector2i(
        vec.x + vec.x,
        vec.y + vec.y);
    ASSERT_EQ(result.x, compare.x);
    ASSERT_EQ(result.y, compare.y);
}

TEST_F(Vector2FloatTest, Vector2iMultiple) {
    auto result = vec * 3;
    auto compare = Vector2i(
        vec.x *3,
        vec.y *3);
    ASSERT_EQ(result.x, compare.x);
    ASSERT_EQ(result.y, compare.y);
}