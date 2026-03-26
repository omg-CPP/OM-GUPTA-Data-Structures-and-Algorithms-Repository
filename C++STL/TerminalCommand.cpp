
#include <iostream>
using namespace std;

int main() {
    int x;
    cout<<"Enter a integer number: ";
    cin>>x;
    cout<<"The number you entered is: "<<x<<endl;
}

// .\  -> current directory
// ..\ -> parent directory

// -> cd C++STL
// -> g++ TerminalCommand.cpp -o .\TerminalCommandOutputFile.exe
// -> .\TerminalCommandOutputFile.exe

//    Enter a integer number: 41
//    The number you entered is: 



// 🔍 What Each Means

// 🔹 ./C++STL/TerminalCommand.cpp
// ./ → current directory (Unix/Linux style)
// / → forward slash path separator
// Used in Git Bash, Linux, macOS

// 🔹 .\C++STL\TerminalCommand.cpp
// .\ → current directory (Windows style)
// \ → backslash path separator
// Used in PowerShell / CMD