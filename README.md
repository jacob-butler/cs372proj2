
# cs372proj2 ~ UAF CS 372 Project 2 (C++ to PostScript)

This is a repository intended to implement a library named CPS, which allows for high level abstractions of PostScript shape drawing.
CPS consists of:
- A shape language.
- A shape to PostScript translator.

# Big Tasks As Mentioned in BlackBoard

- The source for our shape objects is in shape.cpp and shape.hpp
- All the scripts for testing are located in the tests directory.
  - catch_main.cpp and catch_suite.cpp are for testing of general features of shapes objects such as width and height
  - visual_output_tests.cpp runs manual tests for cheching that outputs are correct
  - cached_output_tests.cpp runs comparison tests between the files created by visual_output_test and newly created files
- visual_output_tests.cpp, cached_output_tests.cpp, and the catch file can be compiled from the command line to create an executables to test the CPS language.

# Discussion

While the shape language and its abstractions are fairly well designed, the language itself feels limiting. The largest limitation is the inability to specifiy the location where the shape should be drawn on the postscript canvous. The fact that the only way to change a shape's location is by using spaces makes the language unnecessary cumbersome. 

If we were to design the language from scratch, The biggest change we would make is to having the location of the origin of the shape to drawn specified as a parameter to the shape.

