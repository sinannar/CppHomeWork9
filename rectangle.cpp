#include "rectangle.h"
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
        Rectangle * p = (Rectangle*) ptr;
        return p->calculateArea();
    }

    double myPerimeter(void * ptr)
    {
        Rectangle * p = (Rectangle*) ptr;
        return p->calculatePerimeter();
    }

    double myCorners(void * ptr)
    {
        Rectangle * p = (Rectangle*) ptr;
        return p->calculateNumberOfCorners();
    }

    string myName(void * ptr)
    {
        Rectangle * p = (Rectangle*) ptr;
        return p->calculateShapeName();
    }

}

/*WITHOUT virtual KEYWORD THEY ACTING LIKE virtual*/
double Rectangle::calculateArea()
{
    return edgeOne*edgeTwo;
}

double Rectangle::calculatePerimeter()
{
    return (edgeOne+edgeTwo)*2.0;
}

double Rectangle::calculateNumberOfCorners()
{
    return 4.0;
}

string Rectangle::calculateShapeName()
{
    return ("rectanglistic "+getNameOfShape());
}


/*constructors*/
Rectangle::Rectangle()
:Shape(),edgeOne(0),edgeTwo(0)
{
    setTypeOfShape("rectangle");

    /*here is the big deal when implementing polymorphism*/
    _area = myArea;
    _perimeter = myPerimeter;
    _corner=myCorners;
    _name=myName;
}

Rectangle::Rectangle(string name)
:Shape(name),edgeOne(0),edgeTwo(0)
{
    setTypeOfShape("rectangle");

    /*here is the big deal when implementing polymorphism*/
    _area = myArea;
    _perimeter = myPerimeter;
    _corner=myCorners;
    _name=myName;
}

Rectangle::Rectangle(string name,double edge1)
:Shape(name),edgeOne(edge1),edgeTwo(0)
{
    setTypeOfShape("rectangle");

    /*here is the big deal when implementing polymorphism*/
    _area = myArea;
    _perimeter = myPerimeter;
    _corner=myCorners;
    _name=myName;
}

Rectangle::Rectangle(string name,double edge1,double edge2)
:Shape(name),edgeOne(edge1),edgeTwo(edge2)
{
    setTypeOfShape("rectangle");

    /*here is the big deal when implementing polymorphism*/
    _area = myArea;
    _perimeter = myPerimeter;
    _corner=myCorners;
    _name=myName;
}


/*getters*/
double Rectangle::getEdgeOne() const
{
    return edgeOne;
}

double Rectangle::getEdgeTwo() const
{
    return edgeTwo;
}


/*setters*/
void Rectangle::setEdgeOne(double edge)
{
    edgeOne=edge;
}

void Rectangle::setEdgeTwo(double edge)
{
    edgeTwo=edge;
}


/*Big three*/
Rectangle::~Rectangle()
{

}

Rectangle& Rectangle::operator =(const Rectangle& rightSide)
{
    Shape::operator=(rightSide);
    edgeOne=rightSide.edgeOne;
    edgeTwo=rightSide.edgeTwo;
    return *this;
}

Rectangle::Rectangle(const Rectangle& rightSide)
:Shape(rightSide.getNameOfShape()),edgeOne(rightSide.getEdgeOne()),edgeTwo(rightSide.getEdgeTwo())
{

}

