#include "rectangle.h"
#include<string>
#include<iostream>

using namespace std;

/*virtuals*/
double Rectangle::calculateArea() const
{
    return static_cast<double>(edgeOne)*edgeTwo;
}

double Rectangle::calculatePerimeter() const
{
    return (edgeOne+edgeTwo)*2.0;
}

double Rectangle::calculateNumberOfCorners() const
{
    return 4.0;
}

string Rectangle::calculateShapeName() const
{
    return ("rectanglistic "+getNameOfShape());
}


/*constructors*/
Rectangle::Rectangle()
:Shape(),edgeOne(0),edgeTwo(0)
{
    setTypeOfShape("rectangle");
}

Rectangle::Rectangle(string name)
:Shape(name),edgeOne(0),edgeTwo(0)
{
    setTypeOfShape("rectangle");
}

Rectangle::Rectangle(string name,double edge1)
:Shape(name),edgeOne(edge1),edgeTwo(0)
{
    setTypeOfShape("rectangle");
}

Rectangle::Rectangle(string name,double edge1,double edge2)
:Shape(name),edgeOne(edge1),edgeTwo(edge2)
{
    setTypeOfShape("rectangle");
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

