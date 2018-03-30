#include "../shape.hpp"
#include <iostream>
#include <memory>

int main()
{
    // Polygon test2(3,90);
    auto test4 = std::make_unique<Polygon>(7,50);
    // std::cout << test1.to_postscript() << std::endl;
    test4->generate_postscript_file("tests");
}