#include "gtest/gtest.h"

#include "Eigen/Dense"

TEST(eigen_check, eigen_link_check) {
    Eigen::Matrix3d mat({
            {2.0,  0.0,  0.0},
            {0.0, 2.0,  0.0},
            {0.0,  0.0,  2.0},
    });
    EXPECT_NEAR(mat.determinant(), 8, 1e-8);
}