using LibIGLSharp;
using System.Diagnostics;


LibIGLSharp.LibIGLSharp.InitializeAPI();


double[] Vertices = new double[] {
        0.0, 0.0, 0.0,
        0.0, 0.0, 1.0,
        0.0, 1.0, 0.0,
        0.0, 1.0, 1.0,
        1.0, 0.0, 0.0,
        1.0, 0.0, 1.0,
        1.0, 1.0, 0.0,
        1.0, 1.0, 1.0 };
int[] Triangles = new int[] {
        0, 6, 4,
        0, 2, 6,
        0, 3, 2,
        0, 1, 3,
        2, 7, 6,
        2, 3, 7,
        4, 6, 7,
        4, 7, 5,
        0, 4, 5,
        0, 5, 1,
        1, 5, 7,
        1, 7, 3
    };


IGLMeshHandle meshHandle = MeshFunctions.CreateMesh(Vertices, Triangles);
Debug.Assert(meshHandle.IsValid);

double[] NewVertices; int[] NewTriangles;
MeshFunctions.GetMeshCopy(meshHandle, out NewVertices, out NewTriangles);
System.Console.WriteLine("NewVertices {0}  Newtriangles {1}", NewVertices.Length, NewTriangles.Length);

MeshFunctions.FreeMesh(ref meshHandle);


