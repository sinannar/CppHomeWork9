#include "triangle.h"
#include<string>
#include<iostream>
#include<cmath>

using namespace std;

/*virtuals*/
double Triangle::calculateArea() const
{
    double u=(edgeOne+edgeTwo+edgeThree)/2;
    return sqrt( u*(u-edgeOne)*(u-edgeTwo)*(u-edgeThree) );
}

double Triangle::calculatePerimeter() const
{
    return edgeOne+edgeTwo+edgeThree;
}

double Triangle::calculateNumberOfCorners() const
{
    return 3.0;
}

string Triangle::calculateShapeName() const
{
    return (getNameOfShape());
}


/*constructors*/
Triangle::Triangle()
:Shape(),edgeOne(0),edgeTwo(0),edgeThree(0)
{
    setTypeOfShape("triangle");
}

Triangle::Triangle(string name)
:Shape(name),edgeOne(0),edgeTwo(0),edgeThree(0)
{
    setTypeOfShape("triangle");
}

Triangle::Triangle(string name,double edge1)
:Shape(name),edgeOne(edge1),edgeTwo(0),edgeThree(0)
{
    setTypeOfShape("triangle");
}

Triangle::Triangle(string name,double edge1,double edge2)
:Shape(name),edgeOne(edge1),edgeTwo(edge2),edgeThree(0)
{
    setTypeOfShape("triangle");
}

Triangle::Triangle(string name,double edge1,double edge2,double edge3)
:Shape(name),edgeOne(edge1),edgeTwo(edge2),edgeThree(edge3)
{
    setTypeOfShape("triangle");
}


/*getters*/
double Triangle::getEdgeOne() const
{
    return edgeOne;
}

double Triangle::getEdgeTwo() const
{
    return edgeTwo;
}

double Triangle::getEdgeThree() const
{
    return edgeThree;
}


/*setters*/
void Triangle::setEdgeOne(double edge)
{
    edgeOne=edge;
}

void Triangle::setEdgeTwo(double edge)
{
    edgeTwo=edge;
}

void Triangle::setEdgeThree(double edge)
{
    edgeThree=edge;
}


/*Big three*/
Triangle::~Triangle()
{

}

Triangle& Triangle::operator =(const Triangle& rightSide)
{
    Shape::operator=(rightSide);
    edgeOne=rightSide.edgeOne;
    edgeTwo=rightSide.edgeTwo;
    edgeThree=rightSide.edgeThree;
    return *this;
}

Triangle::Triangle(const Triangle& rightSide):Shape(rightSide.getNameOfShape()),edgeOne(rightSide.getEdgeOne()),edgeTwo(rightSide.getEdgeTwo()),edgeThree(rightSide.getEdgeThree())
{

}

