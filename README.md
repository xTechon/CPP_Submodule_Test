Dev Env:
---
Dependencies:
- Git
- LLVM
- Ninja
- vcpkg: https://vcpkg.io/en/index.html
- VS Code and Extensions:
	- C++ Themes: https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-themes
	- C++ Cmake Tools: https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools
	- Clangd: https://marketplace.visualstudio.com/items?itemName=llvm-vs-code-extensions.vscode-clangd
	- Code LLDB https://marketplace.visualstudio.com/items?itemName=vadimcn.vscode-lldb


Install LLVM: https://github.com/llvm/llvm-project/releases/download/llvmorg-16.0.6/LLVM-16.0.6-win64.exe
<br>Install Ninja, use Winget: `Winget install Ninja-build.Ninja`

Clone Repo:
<br>`git clone --recurse-submodules git@github.com:xTechon/CPP_Submodule_Test.git`

Activate VCPKG from project root:
<br>`cmake -B [build directory] -S . -DCMAKE_TOOLCHAIN_FILE=vcpkg/scripts/buildsystems/vcpkg.cmake`

VS Code settings:
<br>Set CMake to use [Clang... ...pc-windows-msvc] and it should lead to the LLVM install path
<br>In Linux, Cmake should be set to use the [Clang... ...pc-linux-gnu] kit
<br>in settings.json, replace <path to repo> with the correct information and makes sure the forward/backslashes match for OS

Make build folder in project root, run in project root:
<br>`cmake --build build`
