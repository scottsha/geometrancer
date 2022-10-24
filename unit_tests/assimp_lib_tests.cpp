//
//
#include <filesystem>

#include "gtest/gtest.h"

#include "assimp/Importer.hpp"
#include "assimp/Exporter.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"

#ifndef _T
#define _T(_x) _x
#endif

static const std::filesystem::path kTEST_PATH = _T(UNIT_TEST_DATA_DIR);

TEST(assimp_check, try_an_import_export) {
    std::filesystem::path fin = kTEST_PATH / "trex.obj";
    Assimp::Importer importer;
    const aiScene *scene = importer.ReadFile(
            fin.string().c_str(),
            aiProcess_ValidateDataStructure  |
            aiProcess_Triangulate            |
            aiProcess_JoinIdenticalVertices
    );
    std::filesystem::path fout = kTEST_PATH / "rex_out.glb";
    Assimp::Exporter exporter;
    exporter.Export(scene, "glb2", fout.string().c_str());
}