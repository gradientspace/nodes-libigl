rmdir /s /q distrib
mkdir distrib

mkdir distrib\Debug
copy LibIGLSharp\bin\Debug\net8.0\libigl-api-cpp.* distrib\Debug
copy LibIGLSharp\bin\Debug\net8.0\LibIGLSharp.* distrib\Debug
copy LibIGLNodes\bin\Debug\net8.0\LibIGLNodes.* distrib\Debug

mkdir distrib\Release
copy LibIGLSharp\bin\Release\net8.0\libigl-api-cpp.* distrib\Release
copy LibIGLSharp\bin\Release\net8.0\LibIGLSharp.* distrib\Release
copy LibIGLNodes\bin\Release\net8.0\LibIGLNodes.* distrib\Release





