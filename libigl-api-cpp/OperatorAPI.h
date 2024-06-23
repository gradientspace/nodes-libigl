#ifndef LIBIGL_OPERATOR_API_HEADER
#define LIBIGL_OPERATOR_API_HEADER

#include "BaseAPI.h"

#ifdef __cplusplus
extern "C"
{
#endif


LIBGL_API
int libigl_decimate_mesh(
	void* meshHandle,
	int TargetTriangleCount,
	mesh_info* resultMeshInfoOut);

LIBGL_API
int libigl_loop_subdivide_mesh(
	void* meshHandle,
	int Iterations,
	mesh_info* resultMeshInfoOut);





#ifdef __cplusplus
}
#endif

#endif

