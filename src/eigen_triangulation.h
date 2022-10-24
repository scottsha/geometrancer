//
//

#ifndef PACKNSMASH_EIGEN_TRIANGULATION_H
#define PACKNSMASH_EIGEN_TRIANGULATION_H

#include "Eigen/Dense"

namespace pack_n_smash {

    struct EigenTriangulation {
        using Position = Eigen::MatrixX4d;
        using TriangleVertices = Eigen::MatrixX3i;
        Position position;
        TriangleVertices triangles;

        EigenTriangulation() = default;
        EigenTriangulation(Position& p, TriangleVertices& t) :
            position(std::move(p)),
            triangles(std::move(t))
        {}
    };

} // namespace

#endif //PACKNSMASH_EIGEN_TRIANGULATION_H
