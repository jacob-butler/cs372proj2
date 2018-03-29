// shape.h
// Project: CPS
// Base class Shape 

#include <string>

class Shape {
public:
    Shape(double width, double height);
    virtual ~Shape() = default;
    virtual std::string to_postscript() = 0;
	double get_width();
	double get_height();
private:
    double m_width;
    double m_height;
};

class Circle: public Shape
{
public:
	Circle() = default;
	~Circle() = default;
	std::string to_postscript();
private:
	double m_radius;
};
