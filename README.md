# Spreadsheet
This program is an electronic spreadsheet with functionality for working with cells and formulas. The main features of the program include:

* Conversion between cell positions and their string representation
* Support for simple arithmetic operations and formulas in cells
* Processing of references to other cells in formulas
* Processing of various errors, such as division by zero, use of invalid cells, circular dependencies
* Output of the contents of the spreadsheet in text form
* Tracking dependencies between cells

The program is developed using an object-oriented approach and includes the implementation of the SheetInterface, CellInterface and FormulaInterface interfaces, which define the basic operations with the spreadsheet, cells and formulas.
The tests provided in the code cover a wide range of functionality, including basic cell operations, working with formulas, error handling, and printing the contents of the table.
This program is an implementation of a simple but functional electronic spreadsheet processor with the ability to work with formulas and references between cells.
___
<!--A block of information about the repository in badges-->
![Static Badge](https://img.shields.io/badge/Nikolai_Dev-Spreadsheet-blue?style=plastic) ![GitHub License](https://img.shields.io/github/license/nikolai-gromov/cpp-spreadsheet?style=plastic) ![GitHub top language](https://img.shields.io/github/languages/top/nikolai-gromov/cpp-spreadsheet?style=plastic) ![GitHub language count](https://img.shields.io/github/languages/count/nikolai-gromov/cpp-spreadsheet?style=plastic) ![GitHub repo stars](https://img.shields.io/github/stars/nikolai-gromov/cpp-spreadsheet) ![GitHub issues](https://img.shields.io/github/issues/nikolai-gromov/cpp-spreadsheet?style=plastic)

[![Logotype](/docs/logo.jpg)](https://github.com/nikolai-gromov/cpp-spreadsheet/tree/main/spreadsheet)
___


The development was carried out in the Windows Subsystem for Linux (WSL) from Visual Studio Code.
<!--Setting-->
## Setting up the development environment

* [Using C++ and WSL in VS Code](https://code.visualstudio.com/docs/cpp/config-wsl)
* [Get started with CMake Tools on Linux](https://code.visualstudio.com/docs/cpp/cmake-linux)
* Installation of [ANTLR](https://www.antlr.org/)

ANTLR is written in Java, so you will need a [JDK development kit](https://www.oracle.com/java/technologies/downloads/) to run it. You can also use OpenJDK.

The instructions for installing ANTLR can be found on the [antlr.org](https://www.antlr.org/) website. More detailed recommendations are provided in the [Getting Started](https://github.com/antlr/antlr4/blob/master/doc/getting-started.md) guide.

To generate C++ executable files for us, run the following command:

```antlr4 -Dlanguage=Cpp Formula.g4```

The files will work in the main project and do some of the work for us:

Formula.interp, Formula.tokens - auxiliary text files for your convenience;
FormulaLexer.{cpp,h} - lexer code;
FormulaParser.{cpp,h} - parser code;
FormulaListener.{cpp,h}, FormulaBaseListener.{cpp,h} - listener code, a variation of the visitor pattern for the parse tree. It will allow you to traverse the parse tree and build our abstract syntax tree for formula calculation.

You will find the CMake files for its integration below. The generated files will be saved in the [folder](https://github.com/nikolai-gromov/cpp-spreadsheet/tree/main/spreadsheet/build/antlr4cpp_generated_src/Formula):

```spreadsheet\build\antlr4cpp_generated_src\Formula```

The [FindANTLR.cmake](https://github.com/nikolai-gromov/cpp-spreadsheet/blob/main/spreadsheet/FindANTLR.cmake) file contains the commands for generating the ANTLR files. The file itself is connected to [CMakeLists.txt](https://github.com/nikolai-gromov/cpp-spreadsheet/blob/main/spreadsheet/CMakeLists.txt) with the command:

```include(${CMAKE_CURRENT_SOURCE_DIR}/FindANTLR.cmake)```

The project structure should look like this:

```
spreadsheet/
├── antlr4_runtime/
│   └── Contents of the antlr4-cpp-runtime*.zip archive.
├── build/
├── antlr-4.12.0-complete.jar
├── CMakeLists.txt
├── FindANTLR.cmake
├── Formula.g4
├── Other project files
└── ...
```

Place the contents of the antlr4-cpp-runtime*.zip archive in the antlr4_runtime folder.
Perform project generation and build in the build folder.
The version of antlr-4.12.0-complete.jar may differ. In CMakeLists.txt, replace the JAR file version with the current one.