
//Tests for checkers program
//Uses catch framework.
//
//In order to add/ modify tests,
//simply write
//		TEST_CASE(" description ", "[ Test Category ]")
//		{
//			//code to be tested
//		}
//
//Inside of test case, use
//			INFO("description");
//to give user description of current subtest. Use
//			REQUIRE( some boolean );
//fo actual condition being tested.

#define CATCH_CONFIG_FAST_COMPILE
# define M_PI  3.14159265358979323846

#include "catch.hpp"
#include "../shape.hpp"

#include <memory>
#include <utility>

TEST_CASE("Circle set/get", "[set/get]")
{
	INFO("Constructor creation");
	auto circle = std::make_unique<Circle>(5.0);
	REQUIRE(circle->get_height() == 10.0);
	REQUIRE(circle->get_width() == 10.0);

	INFO("Set height");
	circle->set_height(50.0);
	REQUIRE(circle->get_height() == 50.0);
	REQUIRE(circle->get_width() == 10.0);

	INFO("Set width");
	circle->set_width(100.0);
	REQUIRE(circle->get_height() == 50.0);
	REQUIRE(circle->get_width() == 100.0);
}

TEST_CASE("Rectangle set/get", "[set/get]")
{
	INFO("Constructor creation");
	auto rect = std::make_unique<Rectangle>(10.0, 15.0);
	REQUIRE(rect->get_width() == 10.0);
	REQUIRE(rect->get_height() == 15.0);

	INFO("Set height");
	rect->set_height(50.0);
	REQUIRE(rect->get_width() == 10.0);
	REQUIRE(rect->get_height() == 50.0);

	INFO("Set width");
	rect->set_width(100.0);
	REQUIRE(rect->get_width() == 100.0);
	REQUIRE(rect->get_height() == 50.0);
}

TEST_CASE("Spacer set/get", "[set/get]")
{
	INFO("Constructor creation");
	auto space = std::make_unique<Spacer>(50.0, 50.0);
	REQUIRE(space->get_width() == 50.0);
	REQUIRE(space->get_height() == 50.0);

	INFO("Set height");
	space->set_height(200.0);
	REQUIRE(space->get_width() == 50.0);
	REQUIRE(space->get_height() == 200.0);

	INFO("Set width");
	space->set_width(100.0);
	REQUIRE(space->get_width() == 100.0);
	REQUIRE(space->get_height() == 200.0);
}

TEST_CASE("Square set/get", "[set/get]")
{
	INFO("Constructor creation");
	auto square = std::make_unique<Square>(50.0);
	REQUIRE(square->get_width() == 50.0);
	REQUIRE(square->get_height() == 50.0);

	INFO("Set height");
	square->set_height(200.0);
	REQUIRE(square->get_width() == 200.0);
	REQUIRE(square->get_height() == 200.0);

	INFO("Set width");
	square->set_width(100.0);
	REQUIRE(square->get_width() == 100.0);
	REQUIRE(square->get_height() == 100.0);
}

TEST_CASE("Triangle set/get", "[set/get]")
{
	const auto side_length = 50.0;
	const auto num_sides = 3;
	const auto cos_part = std::cos(M_PI / double(3));
	const auto sin_part = std::sin(M_PI / double(3));
	const auto height = side_length*(1 + cos_part) / (2 * sin_part);
	const auto width = (side_length * std::sin(M_PI* (num_sides - 1) / double(2 * num_sides))) / (sin_part);

	INFO("Constructor creation");
	auto tri = std::make_unique<Triangle>(50.0);
	REQUIRE(tri->get_width() == width);
	REQUIRE(tri->get_height() == height);

	INFO("Set height");
	tri->set_height(200.0);
	REQUIRE(tri->get_width() == width);
	REQUIRE(tri->get_height() == 200.0);

	INFO("Set width");
	tri->set_width(100.0);
	REQUIRE(tri->get_width() == 100.0);
	REQUIRE(tri->get_height() == 200.0);
}

TEST_CASE("Rotated set/get", "[set/get]")
{
	auto rect = std::make_unique<Rectangle>(100.0, 200.0);

	INFO("Constructor creation");
	auto rot0 = std::make_unique<Rotated>(std::move(rect), Rotated::QUARTER);
	REQUIRE(rot0->get_width() == 200.0);
	REQUIRE(rot0->get_height() == 100.0);

	INFO("Set height");
	rot0->set_height(300.0);
	REQUIRE(rot0->get_width() == 200.0);
	REQUIRE(rot0->get_height() == 300.0);

	INFO("Set width");
	rot0->set_width(40.0);
	REQUIRE(rot0->get_width() == 40.0);
	REQUIRE(rot0->get_height() == 300.0);

	INFO("Rotate after set_height and set_width with constructor");
	auto rot1 = std::make_unique<Rotated>(std::move(rot0), Rotated::QUARTER);
	REQUIRE(rot1->get_width() == 300.0);
	REQUIRE(rot1->get_height() == 40.0);
}

TEST_CASE("Scaled set/get", "[set/get]")
{
	auto rect0 = std::make_unique<Rectangle>(100.0, 200.0);
	auto rect1 = std::make_unique<Rectangle>(100.0, 200.0);

	INFO("Constructor creation 10 times width and height");
	auto scale0 = std::make_unique<Scaled>(std::move(rect0), 10, 10);
	REQUIRE(scale0->get_width() == 1000.0);
	REQUIRE(scale0->get_height() == 2000.0);

	INFO("Constructor creation 0.5 times width and height");
	auto scale1 = std::make_unique<Scaled>(std::move(rect1), 0.5, 0.5);
	REQUIRE(scale1->get_width() == 50.0);
	REQUIRE(scale1->get_height() == 100.0);
}