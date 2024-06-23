using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace LibIGLSharp
{
    public class LibIGLSharp
    {
        private static bool bInitialized = false;
        public const string CppDLLName = "libigl-api-cpp.dll";

        public static void InitializeAPI()
        {
            if (bInitialized) return;

            // Look for the C++ dll in the same folder as the C# dll and explicitly load it.
            // This is necessary for the LibraryImport calls below to work, unless the C++ dll
            // can be found in the standard search paths
            string AssemblyLocation = Assembly.GetAssembly(typeof(IGLMeshAPI))?.Location ?? string.Empty;
            if (AssemblyLocation != string.Empty)
            {
                string? assemblyFolder = Path.GetDirectoryName(AssemblyLocation);
                if (assemblyFolder != null)
                {
                    string CPPLibraryPath = Path.Combine(assemblyFolder, CppDLLName);
                    NativeLibrary.Load(CPPLibraryPath);
                }
            }

            bInitialized = true;
        }
    }
}
