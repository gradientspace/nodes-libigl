
#include "MeshAPI.h"
#include "RemeshingAPI.h"
#include <vector>



void test_libigl()
{
    std::vector<double> Vertices = {
        0.0, 0.0, 0.0,
        0.0, 0.0, 1.0,
        0.0, 1.0, 0.0,
        0.0, 1.0, 1.0,
        1.0, 0.0, 0.0,
        1.0, 0.0, 1.0,
        1.0, 1.0, 0.0,
        1.0, 1.0, 1.0 };
    std::vector<int> Triangles = {
        0, 6, 4,
        0, 2, 6,
        0, 3, 2,
        0, 1, 3,
        2, 7, 6,
        2, 3, 7,
        4, 6, 7,
        4, 7, 5,
        0, 4, 5,
        0, 5, 1,
        1, 5, 7,
        1, 7, 3
    };

    void* meshHandle = libigl_create_mesh((int)Vertices.size()/3, &Vertices[0], (int)Triangles.size()/3, &Triangles[0]);

    libigl_decimate_mesh(meshHandle, 5, nullptr);

    libigl_free_mesh(meshHandle);


    //// Inline mesh of a cube
    //const Eigen::MatrixXd V = (Eigen::MatrixXd(8, 3) <<
    //    0.0, 0.0, 0.0,
    //    0.0, 0.0, 1.0,
    //    0.0, 1.0, 0.0,
    //    0.0, 1.0, 1.0,
    //    1.0, 0.0, 0.0,
    //    1.0, 0.0, 1.0,
    //    1.0, 1.0, 0.0,
    //    1.0, 1.0, 1.0).finished();
    //const Eigen::MatrixXi F = (Eigen::MatrixXi(12, 3) <<
    //    0, 6, 4,
    //    0, 2, 6,
    //    0, 3, 2,
    //    0, 1, 3,
    //    2, 7, 6,
    //    2, 3, 7,
    //    4, 6, 7,
    //    4, 7, 5,
    //    0, 4, 5,
    //    0, 5, 1,
    //    1, 5, 7,
    //    1, 7, 3).finished();


}