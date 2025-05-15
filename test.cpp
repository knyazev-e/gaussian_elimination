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
    expected_ans << 2, 3, 1, 4;
    EXPECT_EQ(expected_ans, ans);
}


TEST(GaussEliminationTests, Test3) {
    Eigen::MatrixXd system(6, 7);
    system << 1, 1, 1, 1, 1, 1, 21,
              2, -1, 3, 4, -1, 2, 35,
              -1, 2, -1, 1, 2, -1, 17,
              3, 1, 2, -1, 1, 3, 33,
              1, -1, 1, 2, 3, 1, 28,
              2, 3, -1, 1, -2, 4, 40;
    Eigen::VectorXd ans = gauss_elimination(system);
    Eigen::VectorXd expected_ans(6);
    expected_ans << 2, 3, 1, 4, 5, 6;
    EXPECT_EQ(expected_ans, ans);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
