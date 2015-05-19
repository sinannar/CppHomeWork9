#include "circle.h"
#include<string>
#include<iostream>

using namespace std;

/*
I need some global function to use because of function pointers
in this case i use unnamed namespace
*/
namespace{

    double myArea(void * ptr)
    {
        Circle * p = (Circle*) ptr;
        return p->calculateArea();
    }

    double myPerimeter(void * ptr)
    {
        Circle * p = (Circle*) ptr;
        return p->calculatePerimeter();
    }

    double myCorners(void * ptr)
    {
        Circle * p = (Circle*) ptr;
        return p->calculateNumberOfCorners();
    }

    string myName(void * ptr)
    {
        Circle * p = (Circle*) ptr;
        return p->calculateShapeName();
    }

}

/*WITHOUT virtual KEYWORD THEY ACTING LIKE virtual*/
double Circle::calculateArea()
{
    return (PI*radious*radious);
}

double Circle::calculatePerimeter()
{
    return (2*PI*radious);
}

double Circle::calculateNumberOfCorners()
{
    return 0.0;
}

string Circle::calculateShapeName()
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

    /*here is the big deal when implementing polymorphism*/
    _area = myArea;
    _perimeter = myPerimeter;
    _corner=myCorners;
    _name=myName;
}

Circle::Circle(string name,double rad)
:Shape(name),radious(rad)
{
    setTypeOfShape("circle");

    /*here is the big deal when implementing polymorphism*/
    _area = myArea;
    _perimeter = myPerimeter;
    _corner=myCorners;
    _name=myName;
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
