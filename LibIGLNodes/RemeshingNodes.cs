using Gradientspace.NodeGraph;
using g3;
using LibIGLSharp;

namespace LibIGLNodes
{
    [GraphNodeFunctionLibrary("LibIGL.RemeshingFunctions")]
    public static class LibIGLRemeshingFunctionLibrary
    {
        [NodeFunction]
        [NodeReturnValue(DisplayName = "MeshHandle")]
        public static IGLMeshHandle IGLDecimateMesh(IGLMeshHandle MeshHandle, int TargetCount = 1000)
        {
            bool bOK = RemeshingFunctions.DecimateMesh(MeshHandle, TargetCount, out IGLMeshInfo meshInfo);
            return MeshHandle;
        }

        [NodeFunction]
        [NodeReturnValue(DisplayName = "MeshHandle")]
        public static IGLMeshHandle IGLLoopSubdivideMesh(IGLMeshHandle MeshHandle, int Iterations = 1)
        {
            bool bOK = RemeshingFunctions.LoopSubdivideMesh(MeshHandle, Iterations, out IGLMeshInfo meshInfo);
            return MeshHandle;
        }


    }
}
