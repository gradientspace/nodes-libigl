#pragma once

#pragma warning( push )
#pragma warning( disable : 4244 4267 4018 )
#include <Eigen/Core>
#include <Eigen/Sparse>
#pragma warning( pop )

struct iglmesh
{
	// todo magic number

	Eigen::MatrixXd Vertices;
	Eigen::MatrixXi Triangles;
};



inline static void initialize_mesh_info(mesh_info* info)
{
	if (info != nullptr) {
		info->FaceCount = 0;
		info->VertexCount = 0;
	}
}

inline static void set_mesh_info(mesh_info* info, iglmesh& mesh)
{
	if (info != nullptr) {
		info->VertexCount = (int)mesh.Vertices.rows();
		info->FaceCount = (int)mesh.Triangles.rows();
	}
}

