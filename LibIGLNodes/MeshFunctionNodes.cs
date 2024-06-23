using Gradientspace.NodeGraph;
using g3;
using LibIGLSharp;

namespace LibIGLNodes
{
    [GraphNodeFunctionLibrary("LibIGL.MeshFunctions")]
    public static class LibIGLMeshFunctionLibrary
    {
        [NodeFunction]
        [NodeReturnValue(DisplayName = "MeshHandle")]
        //[NodeParameter("Path", DisplayName = "PathX", DefaultValue ="c:\\scratch\\bunny.obj")]
        public static IGLMeshHandle IGLCreateMesh(DMesh3 SourceMesh)
        {
            double[] Vertices = SourceMesh.VerticesBuffer.ToArray();
            int[] Triangles = SourceMesh.TrianglesBuffer.ToArray();
            return MeshFunctions.CreateMesh(Vertices, Triangles);
        }

        [NodeFunction]
        public static bool IGLFreeMesh(IGLMeshHandle MeshHandle)
        {
            return MeshFunctions.FreeMesh(ref MeshHandle);
        }

        [NodeFunction]
        [NodeReturnValue(DisplayName = "Mesh")]
        public static DMesh3 IGLReadMesh(IGLMeshHandle MeshHandle)
        {
            double[] Vertices; int[] Triangles;
            if (MeshFunctions.GetMeshCopy(MeshHandle, out Vertices, out Triangles))
                return DMesh3Builder.Build<double, int, double>(Vertices, Triangles);
            return new DMesh3();
        }


    }
}
