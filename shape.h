// shape.h
// Project: CPS
// Base class Shape 

#include <string>

class Shape {
public:
    Shape(double width, double height);
    virtual ~Shape() = default;
    virtual std::string to_postscript() const = 0;
	double get_width() const;
	double get_height() const;
	void set_width(double width);
	void set_height(double height);
private:
    double m_width;
    double m_height;
};

class Circle: public Shape
{
public:
	Circle() = default;
	Circle(double radius);
	~Circle() = default;
	std::string to_postscript() const;
private:
	double m_radius;
};

class Polygon : public Shape
{
public:
	Polygon() = default;
	Polygon(int num_sides, double side_length);
	~Polygon() = default;
	std::string to_postscript() const;
private:
	int m_num_sides;
	double m_side_length;
};


class Rectangle : public Shape
{
public:
	Rectangle() = default;
	Rectangle(double width, double height): Shape(width, height){}
	~Rectangle() = default;
	std::string to_postscript() const;
private:
};
