Windows Dev Env:
---
Dependencies:
- Git
- LLVM
- Ninja
- VS Code and Extensions:
	- C++ Themes: https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-themes
	- C++ Cmake Tools: https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools
	- Clangd: https://marketplace.visualstudio.com/items?itemName=llvm-vs-code-extensions.vscode-clangd
	- Code LLDB https://marketplace.visualstudio.com/items?itemName=vadimcn.vscode-lldb
- vcpkg: https://vcpkg.io/en/index.html


Install LLVM: https://github.com/llvm/llvm-project/releases/download/llvmorg-16.0.6/LLVM-16.0.6-win64.exe
Install Ninja, use Winget: `Winget install Ninja-build.Ninja`

VS Code settings:
set CMake to use [Clang... ...pc-windows-msvc] and it should lead to the LLVM install path