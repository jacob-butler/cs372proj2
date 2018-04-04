#include "../shape.hpp"
#include <iostream>
#include <memory>
#include <string>

bool compare_file_content(std::string cached_file, std::string test_string)
{
    std::fstream open_cache(cached_file + ".ps", std::fstream::in);
    std::fstream open_test(test_string + ".ps", std::fstream::in);
    std::string cache_buffer;
    std::string test_buffer;

	if (!open_cache.is_open()) 
	{
    	std::cout << "file failed to open " << cached_file + ".ps" << std::endl;
  	} 
    if (!open_test.is_open()) 
	{
    	std::cout << "file failed to open " << test_string + ".ps" << std::endl;
  	} 
    std::getline(open_test, test_buffer);
    std::getline(open_cache, cache_buffer);
    while(!open_cache.eof() || !open_test.eof())
    {
        if(test_buffer != cache_buffer)
        {
            return false;
        }
        if(open_cache.eof() == ! open_test.eof())
        {
            return false;
        }
        std::getline(open_test, test_buffer);
        std::getline(open_cache, cache_buffer);
    }
    return true;
}

void test_case(std::string test_name, bool test_value)
{
    std::string test_value_text = "failed";
    if(test_value)
    {
        test_value_text = "passed";
    }
    std::cout << "TEST: " + test_name + "; " + test_value_text << std::endl;
}

int main()
{
    // Testing for Circle
    auto test_circle_radius_0 = std::make_unique<Circle>(0);
    test_circle_radius_0->generate_postscript_file("test_circle_radius_0");
    test_case("circle with radius 0", compare_file_content("cache_circle_radius_0", "test_circle_radius_0"));

    auto test_circle_radius_50 = std::make_unique<Circle>(50);
    test_circle_radius_50->generate_postscript_file("test_circle_radius_50");
    test_case("circle with radius 50", compare_file_content("cache_circle_radius_50", "test_circle_radius_50"));

    auto test_circle_radius_100 = std::make_unique<Circle>(100);
    test_circle_radius_100->generate_postscript_file("test_circle_radius_100");
    test_case("circle with radius 100", compare_file_content("cache_circle_radius_100", "test_circle_radius_100"));


	auto test_sierpinski = std::make_unique<STriangle>(200.,7);
	test_sierpinski->generate_postscript_file("test_sierpinski");

	system("Pause");
}