# Paint
**Paint** is a painting program written in C++ and little bit of C but for MSVC. It was from Windows Server 2003 source code, with 4 patches to make it compatible for MSVC. SDK version is 10.0.17763.0.
## Building & Testing
### Prerequisites
Use **Microsoft Visual Studio** to build Paint.
### Build
**IMPORTANT:** Use the Release configuration as the Debug exe throws Visual C++ debug assertion errors but you can ignore them.
Use `MSBuild` to build the project.
### Testing
Now that your local Paint build is built, run the executable at the binary folder (mspaint.exe).
**Congrats!** Now you have your own Paint build!
