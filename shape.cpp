#include "shape.h"
#include <cmath>
# define M_PI  3.14159265358979323846


Shape::Shape(double width, double height):m_width(width), m_height(height){}

double Shape::get_width() const { return m_width; }
double Shape::get_height() const { return m_height; }

void Shape::set_width(double width) { m_width = width; }
void Shape::set_height(double height) { m_height = height; }

Circle::Circle(double radius)
	:m_radius(radius), Shape(2 * radius, 2 * radius){}

std::string Circle::to_postscript() const
{
	//postScript code stuff
	return NULL;
}

Polygon::Polygon(int num_sides, double side_length)
	:m_num_sides(num_sides), m_side_length(side_length), Shape(0, 0)
{
	double width;
	double height;
	double cos_part = std::cos(M_PI / ((double)num_sides));
	double sin_part = std::sin(M_PI / ((double)num_sides));
	if (num_sides % 2 == 1)
	{
		height = side_length*(1 + cos_part) / (2 * sin_part);
		width = (side_length * sin(M_PI* (num_sides - 1) / (double)(2 * num_sides))) / (sin_part);
	}
	else if (num_sides % 4 == 0)
	{
		height = side_length*(cos_part) / (sin_part);
		width = (side_length* cos_part) / (sin_part);
	}
	else
	{
		height = side_length*(cos_part) / (sin_part);
		width = side_length / (sin_part);
	}
	set_width(width);
	set_height(height);
}

std::string Polygon::to_postscript() const
{
	//postScript code stuff
	return NULL;
}

std::string Rectangle::to_postscript() const
{
	//postScript code stuff
	return NULL;
}