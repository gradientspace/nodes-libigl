#ifndef LIBIGL_MESH_API_HEADER
#define LIBIGL_MESH_API_HEADER

#include "BaseAPI.h"

#ifdef __cplusplus
extern "C"
{
#endif




LIBGL_API
void* libigl_create_mesh(
	int num_vertices,
	const double* mesh_vertices,
	int num_triangles,
	const int* mesh_triangles);



LIBGL_API
void libigl_free_mesh(void* meshHandle);



LIBGL_API
int libigl_query_mesh_info(void* meshHandle, mesh_info* meshInfoOut);


LIBGL_API
int libigl_query_mesh(
	void* meshHandle,
	int vertex_buffer_size,
	double* vertex_buffer,
	int triangle_buffer_size,
	int* triangle_buffer);



#ifdef __cplusplus
}
#endif

#endif
