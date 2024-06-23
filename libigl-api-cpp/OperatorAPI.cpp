#include "OperatorAPI.h"
#include "igl_types.h"

#pragma warning( push )
#pragma warning( disable : 4244 4267 4018 )
#include <igl/decimate.h>
#include <igl/loop.h>
#pragma warning( pop )


int libigl_decimate_mesh(
	void* meshHandle,
	int TargetTriangleCount,
	mesh_info* resultMeshInfoOut)
{
	initialize_mesh_info(resultMeshInfoOut);
	iglmesh* mesh = (iglmesh*)meshHandle;

	iglmesh newmesh; Eigen::VectorXi mappedFaces;
	if (igl::decimate(mesh->Vertices, mesh->Triangles, TargetTriangleCount, newmesh.Vertices, newmesh.Triangles, mappedFaces))
	{
		mesh->Vertices = std::move(newmesh.Vertices);
		mesh->Triangles = std::move(newmesh.Triangles);
		set_mesh_info(resultMeshInfoOut, *mesh);
		return 1;
	}
	return 0;
}


int libigl_loop_subdivide_mesh(
	void* meshHandle,
	int Iterations,
	mesh_info* resultMeshInfoOut)
{
	initialize_mesh_info(resultMeshInfoOut);
	iglmesh* mesh = (iglmesh*)meshHandle;

	iglmesh newmesh; 
	igl::loop(mesh->Vertices, mesh->Triangles, newmesh.Vertices, newmesh.Triangles, Iterations);

	mesh->Vertices = std::move(newmesh.Vertices);
	mesh->Triangles = std::move(newmesh.Triangles);
	set_mesh_info(resultMeshInfoOut, *mesh);
	return 1;
}