// shape.h
// Project: CPS
// Base class Shape 

class Shape 
{
public:
    Shape(double width, double height);
    virtual ~Shape() = default;
    virtual void to_postscript();
private:
    double m_width;
    double m_height;
}
