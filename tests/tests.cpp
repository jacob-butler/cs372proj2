//#include "../shape.hpp"
//
//#include <iostream>
//#include <memory>
//
//enum {
//    postscript_test,
//    catch_test
//};
//
//// SETTING FOR MAIN MODE **********
//// ********************************
//int main_mode = catch_test;
//// ********************************
//// ********************************
//
//
//int main()
//{
//    // Polygon test2(3,90);
//    auto test1 = std::make_unique<Polygon>(3, 50);
//    // auto test2 = std::make_unique<Layered>(std::move(test1), 4,4);
//    auto test3 = std::make_unique<Circle>(3.);
//    auto test4 = std::make_unique<Polygon>(7,50);
//    auto test5 = std::make_unique<Spacer>(100,100);
//    auto test2 = std::make_unique<Horizontal>(std::initializer_list<std::shared_ptr<Shape>>{std::move(test1), std::move(test3), std::move(test5), std::move(test4)});
//    // std::cout << test1.to_postscript() << std::endl;
//    test2->generate_postscript_file("tests");
//    return 0;
//}
