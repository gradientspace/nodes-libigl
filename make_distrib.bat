rmdir /s /q distrib
mkdir distrib
mkdir LibIGLNodes
mkdir distrib\LibIGLNodes\Debug
copy LibIGLSharp\bin\Debug\net8.0\libigl-api-cpp.* distrib\LibIGLNodes\Debug
copy LibIGLSharp\bin\Debug\net8.0\LibIGLSharp.* distrib\LibIGLNodes\Debug
copy LibIGLNodes\bin\Debug\net8.0\LibIGLNodes.* distrib\LibIGLNodes\Debug

mkdir distrib\LibIGLNodes\Release
copy LibIGLSharp\bin\Release\net8.0\libigl-api-cpp.* distrib\LibIGLNodes\Release
copy LibIGLSharp\bin\Release\net8.0\LibIGLSharp.* distrib\LibIGLNodes\Release
copy LibIGLNodes\bin\Release\net8.0\LibIGLNodes.* distrib\LibIGLNodes\Release

exit /b 0





