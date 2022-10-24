#ifndef PACKNSMASH_IO_UTILITIES_H
#define PACKNSMASH_IO_UTILITIES_H

#include <filesystem>
#include <vector>

#include "eigen_triangulation.h"

namespace pack_n_smash {

    std::vector<EigenTriangulation> read_triangulations(const std::filesystem::path& path);

};

#endif //PACKNSMASH_IO_UTILITIES_H
