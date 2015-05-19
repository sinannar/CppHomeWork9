#include "triangle.h"
#include<string>
#include<iostream>
#include<cmath>

using namespace std;

/*
I need some global function to use because of function pointers
in this case i use unnamed namespace
*/
namespace{

    double myArea(void * ptr)
    {
        Triangle * p = (Triangle*) ptr;
        return p->calculateArea();
    }

    double myPerimeter(void * ptr)
    {
        Triangle * p = (Triangle*) ptr;
        return p->calculatePerimeter();
    }

    double myCorners(void * ptr)
    {
        Triangle * p = (Triangle*) ptr;
        return p->calculateNumberOfCorners();
    }

    string myName(void * ptr)
    {
        Triangle * p = (Triangle*) ptr;
        return p->calculateShapeName();
    }

}

/*virtuals*/
double Triangle::calculateArea()
{
    double u=(edgeOne+edgeTwo+edgeThree)/2;
    return sqrt( u*(u-edgeOne)*(u-edgeTwo)*(u-edgeThree) );
}

double Triangle::calculatePerimeter()
{
    return edgeOne+edgeTwo+edgeThree;
}

double Triangle::calculateNumberOfCorners()
{
    return 3.0;
}

string Triangle::calculateShapeName()
{
    return (getNameOfShape());
}


/*constructors*/
Triangle::Triangle()
:Shape(),edgeOne(0),edgeTwo(0),edgeThree(0)
{
    setTypeOfShape("triangle");

    /*here is the big deal when implementing polymorphism*/
    _area = myArea;
    _perimeter = myPerimeter;
    _corner=myCorners;
    _name=myName;
}

Triangle::Triangle(string name)
:Shape(name),edgeOne(0),edgeTwo(0),edgeThree(0)
{
    setTypeOfShape("triangle");

    /*here is the big deal when implementing polymorphism*/
    _area = myArea;
    _perimeter = myPerimeter;
    _corner=myCorners;
    _name=myName;
}

Triangle::Triangle(string name,double edge1)
:Shape(name),edgeOne(edge1),edgeTwo(0),edgeThree(0)
{
    setTypeOfShape("triangle");

    /*here is the big deal when implementing polymorphism*/
    _area = myArea;
    _perimeter = myPerimeter;
    _corner=myCorners;
    _name=myName;
}

Triangle::Triangle(string name,double edge1,double edge2)
:Shape(name),edgeOne(edge1),edgeTwo(edge2),edgeThree(0)
{
    setTypeOfShape("triangle");

    /*here is the big deal when implementing polymorphism*/
    _area = myArea;
    _perimeter = myPerimeter;
    _corner=myCorners;
    _name=myName;
}

Triangle::Triangle(string name,double edge1,double edge2,double edge3)
:Shape(name),edgeOne(edge1),edgeTwo(edge2),edgeThree(edge3)
{
    setTypeOfShape("triangle");

    /*here is the big deal when implementing polymorphism*/
    _area = myArea;
    _perimeter = myPerimeter;
    _corner=myCorners;
    _name=myName;
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

Triangle::Triangle(const Triangle& rightSide)
:Shape(rightSide.getNameOfShape()),edgeOne(rightSide.getEdgeOne()),edgeTwo(rightSide.getEdgeTwo()),edgeThree(rightSide.getEdgeThree())
{

}

