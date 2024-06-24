using System.Reflection;
using System.Runtime.InteropServices;

namespace LibIGLSharp
{
    public struct IGLMeshHandle
    {
        internal IntPtr handle = IntPtr.Zero;
        public IGLMeshHandle() { }
        internal IGLMeshHandle(IntPtr meshHandle) { this.handle = meshHandle; }
        public bool IsValid { get { return handle != IntPtr.Zero; } }
    }

    public struct IGLMeshInfo
    {
        public int VertexCount = 0;
        public int FaceCount = 0;
        public IGLMeshInfo() { }
        public IGLMeshInfo(int vertexCount, int faceCount) { VertexCount = vertexCount; FaceCount = faceCount; }
        internal IGLMeshInfo(in IGLMeshAPI.mesh_info mi) { VertexCount = mi.VertexCount; FaceCount = mi.FaceCount; }
    }


    public sealed class MeshFunctions
    {
        private MeshFunctions() { }

        public static IGLMeshHandle CreateMesh(double[] MeshVertices, int[] MeshTriangles) {
            try {
                IntPtr handle = IGLMeshAPI.libigl_create_mesh(MeshVertices.Length / 3, MeshVertices, MeshTriangles.Length / 3, MeshTriangles);
                return new IGLMeshHandle(handle);
            } catch(Exception) {}
            return new IGLMeshHandle();
        }

        public static bool FreeMesh(ref IGLMeshHandle meshHandle) { 
            try {
                if (meshHandle.IsValid) { 
                    IGLMeshAPI.libigl_free_mesh(meshHandle.handle);
                    meshHandle.handle = IntPtr.Zero;
                    return true;
                }
            } catch(Exception) {}
            return false;
        }

        public static bool GetMeshCopy(IGLMeshHandle meshHandle, out double[] MeshVertices, out int[] MeshTriangles) { 
            try {
                if (meshHandle.IsValid)
                {
                    IGLMeshAPI.mesh_info meshInfo = new();
                    if ( IGLMeshAPI.libigl_query_mesh_info(meshHandle.handle, ref meshInfo) != 0 ) { 
                        MeshVertices = new double[3 * meshInfo.VertexCount];
                        MeshTriangles = new int[3 * meshInfo.FaceCount];
                        int result = IGLMeshAPI.libigl_query_mesh(meshHandle.handle, MeshVertices.Length, MeshVertices, MeshTriangles.Length, MeshTriangles);
                        return result != 0;
                    }
                }
            } catch(Exception) {}
            MeshVertices = new double[0]; MeshTriangles = new int[0]; return false;
        }



    }


    internal sealed partial class IGLMeshAPI
    {
        // this only works if the dll has already been loaded using NativeLibrary.Load(), or
        // if it's in the standard search paths
        const string CPPLibraryPath = LibIGLSharp.CppDLLName;

        //[StructLayout(LayoutKind.Sequential, Pack = 8)]
        [StructLayout(LayoutKind.Sequential)]
        internal struct mesh_info
        {
            public int VertexCount;
            public int FaceCount;
        };  


        [LibraryImport(CPPLibraryPath, StringMarshalling = StringMarshalling.Utf8)]
        internal static partial IntPtr libigl_create_mesh(int num_vertices, double[] mesh_vertices, int num_triangles, int[] mesh_triangles);

        [LibraryImport(CPPLibraryPath, StringMarshalling = StringMarshalling.Utf8)]
        internal static partial void libigl_free_mesh(IntPtr meshHandle);

        [LibraryImport(CPPLibraryPath, StringMarshalling = StringMarshalling.Utf8)]
        internal static partial int libigl_query_mesh_info(IntPtr meshHandle, ref mesh_info meshInfoOut);

        [LibraryImport(CPPLibraryPath, StringMarshalling = StringMarshalling.Utf8)]
        internal static partial int libigl_query_mesh(IntPtr meshHandle, int vertex_buffer_size, double[] vertex_buffer, int triangle_buffer_size, int[] triangle_buffer);
        
    }

}
