#include "../shape.hpp"
#include <iostream>
#include <memory>

int main()
{
    // Polygon test2(3,90);
	auto test1 = std::make_unique<Polygon>(3, 50);
	auto test2 = std::make_unique<Rotated>(std::make_unique<Polygon>(*test1->clone()), Rotated::QUARTER);
    auto test3 = std::make_unique<Circle>(3.);
    auto test4 = std::make_unique<Polygon>(7,50);
    // std::cout << test1.to_postscript() << std::endl;
    test2->generate_postscript_file("tests");
}