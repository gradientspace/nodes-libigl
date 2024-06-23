#include "MeshAPI.h"
#include "igl_types.h"



void* libigl_create_mesh(
	int num_vertices,
	const double* mesh_vertices,
	int num_triangles,
	const int* mesh_triangles)
{
	iglmesh* mesh = new iglmesh;

	// should investigate how to do this the fastest

	// note weirdness here, have to use (3xN).transpose()   (probably has to do w/ how buffer is being interpreted...)
	//typedef Eigen::Matrix<double, 3, Eigen::Dynamic> VertexListDynamic;
	//Eigen::Map<const VertexListDynamic> MappedVertices(mesh_vertices, 3, num_vertices);
	//mesh->Vertices = MappedVertices.transpose();

	int i = 0;
	mesh->Vertices = Eigen::MatrixXd(num_vertices, 3);
	for (int k = 0; k < num_vertices; ++k)
	{
		mesh->Vertices(k, 0) = mesh_vertices[i++];
		mesh->Vertices(k, 1) = mesh_vertices[i++];
		mesh->Vertices(k, 2) = mesh_vertices[i++];
	}

	//typedef Eigen::Matrix<int, 3, Eigen::Dynamic> TriListDynamic;
	//Eigen::Map<const TriListDynamic> MappedTris(mesh_triangles, 3, num_triangles);
	//mesh->Triangles = MappedTris.transpose();

	i = 0;
	mesh->Triangles = Eigen::MatrixXi(num_triangles, 3);
	for (int k = 0; k < num_triangles; ++k)
	{
		mesh->Triangles(k, 0) = mesh_triangles[i++];
		mesh->Triangles(k, 1) = mesh_triangles[i++];
		mesh->Triangles(k, 2) = mesh_triangles[i++];
	}

	return mesh;
}


void libigl_free_mesh(void* meshHandle)
{
	iglmesh* mesh = (iglmesh*)meshHandle;
	delete mesh;
}


int libigl_query_mesh_info(void* meshHandle, mesh_info* meshInfoOut)
{
	initialize_mesh_info(meshInfoOut);
	iglmesh* mesh = (iglmesh*)meshHandle;
	set_mesh_info(meshInfoOut, *mesh);
	return 1;
}


int libigl_query_mesh(
	void* meshHandle,
	int vertex_buffer_size,
	double* vertex_buffer,
	int triangle_buffer_size,
	int* triangle_buffer)
{
	iglmesh* mesh = (iglmesh*)meshHandle;
	int NumTris = (int)mesh->Triangles.rows();
	int NumVerts = (int)mesh->Vertices.rows();
	if (triangle_buffer_size < (NumTris*3) ||
		vertex_buffer_size < (NumVerts*3))
		return 0;

	// it's possible this is not doing things in the right order...

	int i = 0;
	for (int vi = 0; vi < NumVerts; ++vi)
	{
		vertex_buffer[i++] = mesh->Vertices(vi, 0);
		vertex_buffer[i++] = mesh->Vertices(vi, 1);
		vertex_buffer[i++] = mesh->Vertices(vi, 2);
	}
	i = 0;
	for (int ti = 0; ti < NumTris; ++ti)
	{
		triangle_buffer[i++] = mesh->Triangles(ti, 0);
		triangle_buffer[i++] = mesh->Triangles(ti, 1);
		triangle_buffer[i++] = mesh->Triangles(ti, 2);
	}
	// doesn't work, row/col is backwards somehow
	//NumVerts *= 3; NumTris *= 3;
	//for (int vi = 0; vi < NumVerts; ++vi)
	//	vertex_buffer[vi] = mesh->Vertices(vi);
	//for (int ti = 0; ti < NumTris; ++ti)
	//	triangle_buffer[ti] = mesh->Triangles(ti);

	return 1;
}