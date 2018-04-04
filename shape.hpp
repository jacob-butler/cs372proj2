// shape.h
// Project: CPS
// Base class Shape 

#include <string>
#include <memory>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

class Shape {
public:
    Shape(double width, double height);
    virtual ~Shape() = default;
	virtual Shape* clone() const = 0;
    virtual std::string to_postscript() const = 0;
	double get_width() const;
	double get_height() const;
	void set_width(double width);
	void set_height(double height);
	void generate_postscript_file(std::string file_name);
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
	virtual Circle* clone() const { return new Circle(*this); }
	std::string to_postscript() const;
private:
	double m_radius;
};

class Polygon : public Shape
{
public:
	Polygon() = default;
	Polygon(int num_sides, double side_length);
	virtual ~Polygon() = default;
	virtual Polygon* clone() const { return new Polygon(*this); }
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
	virtual Rectangle* clone() const { return new Rectangle(*this); }
	std::string to_postscript() const;
private:
};

class Rotated : public Shape
{
public:
	enum RotationAngle { QUARTER = 90, HALF = 180, THREE_QUARTER = 270 };
	Rotated() = default;
	Rotated(std::unique_ptr<Shape> shape, RotationAngle rotation_angle);
	~Rotated() = default;
	Rotated(const Rotated&);
	virtual Rotated* clone() const { return new Rotated(*this); }
	std::string to_postscript() const;
private:
	RotationAngle m_rot;
	Shape* m_shape;
};

class Scaled : public Shape
{
public:
	Scaled() = default;
	Scaled(std::unique_ptr<Shape> shape, double fx, double fy);
	~Scaled() = default;
	Scaled(const Scaled&);
	virtual Scaled* clone() const { return new Scaled(*this); }
	std::string to_postscript() const;
private:
	std::unique_ptr<Shape> m_shape;
	double m_fx, m_fy;
};

class Layered : public Shape
{
public:
	Layered() = default;
	Layered(std::vector<std::unique_ptr<Shape>> shapes);
	~Layered() = default;
	Layered(const Layered&);
	virtual Layered* clone() const { return new Layered(*this); }
	std::string to_postscript() const;
private:
	std::vector<std::unique_ptr<Shape>> m_shapes;
};
