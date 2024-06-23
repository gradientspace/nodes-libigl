// libigl-api-test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "BaseAPI.h"
#include "MeshAPI.h"
#include "OperatorAPI.h"
#include <vector>
#include <iostream>

int main()
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

    void* meshHandle = libigl_create_mesh((int)Vertices.size() / 3, &Vertices[0], (int)Triangles.size() / 3, &Triangles[0]);

    mesh_info meshInfo;
    libigl_query_mesh_info(meshHandle, &meshInfo);
    std::cout << meshInfo.VertexCount << " " << meshInfo.FaceCount << std::endl;

    libigl_loop_subdivide_mesh(meshHandle, 1, &meshInfo);
    std::cout << meshInfo.VertexCount << " " << meshInfo.FaceCount << std::endl;

    libigl_decimate_mesh(meshHandle, 20, &meshInfo);
    std::cout << meshInfo.VertexCount << " " << meshInfo.FaceCount << std::endl;

    std::vector<double> ReadVerts;
    ReadVerts.resize(meshInfo.VertexCount*3);
    std::vector<int> ReadTris;
    ReadTris.resize(meshInfo.FaceCount *3);
    int result = libigl_query_mesh(meshHandle, (int)ReadVerts.size(), &ReadVerts[0], (int)ReadTris.size(), &ReadTris[0]);

    libigl_free_mesh(meshHandle);
}
