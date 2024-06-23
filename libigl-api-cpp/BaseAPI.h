#ifndef LIBIGL_BASE_API_HEADER
#define LIBIGL_BASE_API_HEADER

#ifdef LIBIGLAPICPP_EXPORTS
#define LIBGL_API __declspec(dllexport)
#else
#define LIBGL_API __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C"
{
#endif


struct cvector3d
{
	double values[3];
};


//#pragma pack(push, 8)
struct mesh_info
{
	int VertexCount;
	int FaceCount;
};
//#pragma pop








#ifdef __cplusplus
}
#endif

#endif




