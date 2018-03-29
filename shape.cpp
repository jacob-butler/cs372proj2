#include "shape.h"


Shape::Shape(double width, double height):m_width(width), m_height(height){}

double Shape::get_width() { return m_width; }
double Shape::get_height() { return m_height; }

std::string Circle::to_postscript()
{
	//postScript code stuff
}