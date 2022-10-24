#include "assimp/scene.h"
#include "assimp/Importer.hpp"
#include "assimp/Exporter.hpp"
#include "assimp/postprocess.h"
#include "assimp/commonMetaData.h"

#include "io_utilities.h"


namespace pack_n_smash {

//    void CopyNodesWithMeshes( aiNode node, Assimp::SceneObject targetParent, Matrix4x4 accTransform) {
//        SceneObject parent;
//        Matrix4x4 transform;
//
//        // if node has meshes, create a new scene object for it
//        if( node.mNumMeshes > 0) {
//            SceneObjekt newObject = new SceneObject;
//            targetParent.addChild( newObject);
//            // copy the meshes
//            CopyMeshes( node, newObject);
//
//            // the new object is the parent for all child nodes
//            parent = newObject;
//            transform.SetUnity();
//        } else {
//            // if no meshes, skip the node, but keep its transformation
//            parent = targetParent;
//            transform = node.mTransformation * accTransform;
//        }
//
//        // continue for all child nodes
//        for( all node.mChildren) {
//            CopyNodesWithMeshes( node.mChildren[a], parent, transform);
//        }
//    }

    EigenTriangulation::TriangleVertices get_indices(aiMesh* mesh) {
        EigenTriangulation::TriangleVertices tt(mesh->mNumFaces, 3);
        if (mesh->mVertices == nullptr) return tt;
        for (auto foo=0; foo<mesh->mNumVertices; foo++) {
            auto face = mesh->mFaces[foo];
            for (auto bar=0; bar<face.mNumIndices; bar++) {
                tt(foo,bar) = face.mIndices[bar];
            }
        }
        return tt;
    }

    EigenTriangulation::Position get_vertices(aiMesh* mesh) {
        EigenTriangulation::Position pp(mesh->mNumVertices, 4);
        if (mesh->mVertices == nullptr) return pp;
        for (auto foo=0; foo<mesh->mNumVertices; foo++) {
            auto iter = mesh->mVertices[foo];
            pp.row(foo) = Eigen::Vector4d({
                    iter.x,
                    iter.y,
                    iter.z,
                    1.
            });
        }
        return pp;
    }

    std::vector<EigenTriangulation> read_triangulations(const std::filesystem::path &path) {
        Assimp::Importer importer;
        const aiScene *scene = importer.ReadFile(
                path.string().c_str(),
                aiProcess_ValidateDataStructure  |
                aiProcess_Triangulate            |
                aiProcess_JoinIdenticalVertices
        );
        std::vector<EigenTriangulation> triangs;
        for (auto foo=0; foo<scene->mNumMeshes; foo++) {
            auto mesh_foo = scene->mMeshes[foo];
            EigenTriangulation::Position pp = get_vertices(mesh_foo);
            EigenTriangulation::TriangleVertices tt = get_indices(mesh_foo);
            EigenTriangulation triang_foo(pp,tt);
            triangs.push_back(triang_foo);
        }
        return triangs;
    }
} // namespace
