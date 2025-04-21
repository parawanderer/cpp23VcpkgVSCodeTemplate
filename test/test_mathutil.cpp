#include <gtest/gtest.h>
#include <fmt/core.h>

#include "mathutil.h"

// See: https://google.github.io/googletest/quickstart-cmake.html
// and https://google.github.io/googletest/reference/testing.html

struct AddTestParams {
    int a;
    int b;
    int expected;
};
class MathUtilAddTest : public testing::TestWithParam<AddTestParams> {};


TEST(MathUtilTest, BasicAssertions) {
    // GIVEN
    mathutil::MyAddAndSub instance(4);
    fmt::print("Instantiated MyAddAndSub\n");

    // WHEN + THEN
    EXPECT_EQ(3, instance.add(1, 2));
    EXPECT_EQ(4, instance.diff(5, 1));
    EXPECT_EQ(6, instance.addToState(2));
    fmt::print("Test cases are finished\n");
}


// Parameterized test
INSTANTIATE_TEST_SUITE_P(
    AddTests,
    MathUtilAddTest,
    testing::Values(
        AddTestParams{1, 2, 3},
        AddTestParams{2, 3, 5},
        AddTestParams{3, 4, 7},
        AddTestParams{4, 5, 9},
        AddTestParams{-5, -3, -8},
        AddTestParams{-1, 1, 0},
        AddTestParams{0, 0, 0}
    )
);
// ^ will be used below v

TEST_P(MathUtilAddTest, TestAddParametrizedExample) {
    // GIVEN
    AddTestParams params = GetParam();
    mathutil::MyAddAndSub instance(10);

    // WHEN
    int result = instance.add(params.a, params.b);

    // THEN
    EXPECT_EQ(params.expected, result);
}