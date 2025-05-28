#include <gtest/gtest.h>
#include "functions.h"

TEST(GaussEliminationTests, Test1) {
    Eigen::MatrixXd system(2, 3);
    system << 2, 3, 12,
              1, -1, 1;
    Eigen::VectorXd ans = gauss_elimination(system);
    Eigen::VectorXd expected_ans(2);
    expected_ans << 3, 2;
    EXPECT_EQ(expected_ans, ans);
}

TEST(GaussEliminationTests, Test2) {
    Eigen::MatrixXd system(4, 5);
    system << 1, 1, 1, 1, 10,
              2, -1, 3, 4, 20,
              -1, 2, -1, 1, 5,
              3, 1, 2, -1, 15;
    Eigen::VectorXd ans = gauss_elimination(system);
    Eigen::VectorXd expected_ans(4);
    expected_ans << 17.5, 0, -15, 7.5;
    EXPECT_EQ(expected_ans, ans);
}

TEST(GaussEliminationTests, Test3) {
    Eigen::MatrixXd system(6, 7);
    system <<
        4, 1, 0, 0, 0, 1, 12,
        1, 5, 1, 0, 0, 0, 14,
        0, 1, 6, 1, 0, 0, 24,
        0, 0, 1, 7, 1, 0, 36,
        0, 0, 0, 1, 8, 1, 50,
        1, 0, 0, 0, 1, 9, 60;

    Eigen::VectorXd ans = gauss_elimination(system);
    Eigen::VectorXd expected_ans(6);
    expected_ans << 1, 2, 3, 4, 5, 6;
    EXPECT_EQ(expected_ans, ans);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
