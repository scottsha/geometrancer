//
//
#include <filesystem>

#include "gtest/gtest.h"

#include "io_utilities.h"

#ifndef _T
#define _T(_x) _x
#endif

static const std::filesystem::path kTEST_PATH = _T(UNIT_TEST_DATA_DIR);

TEST(io_utilities, read_in) {
    std::filesystem::path fin = kTEST_PATH / "trex.obj";
    auto triangs = pack_n_smash::read_triangulations(fin);
    EXPECT_EQ(triangs.size(), 1);
    const auto& triang = triangs[0];
    EXPECT_EQ(triang.position.rows(), 6895);
    EXPECT_EQ(triang.triangles.rows(), 13794);
}