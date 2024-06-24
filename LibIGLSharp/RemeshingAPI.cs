using System.Reflection;
using System.Runtime.InteropServices;
using static LibIGLSharp.IGLMeshAPI;

namespace LibIGLSharp
{
    public sealed class RemeshingFunctions
    {
        private RemeshingFunctions() { }


        public static bool DecimateMesh(IGLMeshHandle meshHandle, int TargetTriangleCount, out IGLMeshInfo resultMeshInfo) {
            resultMeshInfo = new();
            if (meshHandle.IsValid == false) return false;
            try {
                IGLMeshAPI.mesh_info meshInfo = new();
                IGLRemeshingAPI.libigl_decimate_mesh(meshHandle.handle, TargetTriangleCount, ref meshInfo);
                resultMeshInfo = new IGLMeshInfo(meshInfo);
                return true;
            } catch(Exception) {}
            return false;
        }

        public static bool LoopSubdivideMesh(IGLMeshHandle meshHandle, int SubdivideIterations, out IGLMeshInfo resultMeshInfo) {
            resultMeshInfo = new();
            if (meshHandle.IsValid == false) return false;
            try {
                IGLMeshAPI.mesh_info meshInfo = new();
                IGLRemeshingAPI.libigl_loop_subdivide_mesh(meshHandle.handle, SubdivideIterations, ref meshInfo);
                resultMeshInfo = new IGLMeshInfo(meshInfo);
                return true;
            } catch(Exception) {}
            return false;
        }

    }


    internal sealed partial class IGLRemeshingAPI
    {
        // this only works if the dll has already been loaded using NativeLibrary.Load(), or
        // if it's in the standard search paths
        const string CPPLibraryPath = LibIGLSharp.CppDLLName;

        [LibraryImport(CPPLibraryPath, StringMarshalling = StringMarshalling.Utf8)]
        internal static partial int libigl_decimate_mesh(IntPtr meshHandle, int TargetTriangleCount, ref mesh_info meshInfoOut);

        [LibraryImport(CPPLibraryPath, StringMarshalling = StringMarshalling.Utf8)]
        internal static partial int libigl_loop_subdivide_mesh(IntPtr meshHandle, int SubdivideIterations, ref mesh_info meshInfoOut);
    }

}
