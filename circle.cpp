#include "circle.h"
#include<string>
#include<iostream>

using namespace std;

/*virtuals*/
double Circle::calculateArea() const
{
    return (PI*radious*radious);
}

double Circle::calculatePerimeter() const
{
    return (2*PI*radious);
}

double Circle::calculateNumberOfCorners() const
{
    return 0.0;
}

string Circle::calculateShapeName() const
{
    return ("circlistic "+getNameOfShape());
}


/*constructors*/
Circle::Circle()
:Shape(),radious(0)
{
    setTypeOfShape("circle");
}

Circle::Circle(string name)
:Shape(name),radious(0)
{
    setTypeOfShape("circle");
}

Circle::Circle(string name,double rad)
:Shape(name),radious(rad)
{
    setTypeOfShape("circle");
}


/*getters*/
double Circle::getRadious() const
{
    return radious;
}


/*setters*/
void Circle::setRadious(double rad)
{
    radious=rad;
}


/*Big three*/
Circle::~Circle()
{

}

Circle& Circle::operator =(const Circle& rightSide)
{
    Shape::operator=(rightSide);
    radious=rightSide.radious;
    return *this;
}

Circle::Circle(const Circle& rightSide)
:Shape(rightSide.getNameOfShape()),radious(rightSide.getRadious())
{

}
