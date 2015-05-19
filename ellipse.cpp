#include "ellipse.h"
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
        Ellipse * p = (Ellipse*) ptr;
        return p->calculateArea();
    }

    double myPerimeter(void * ptr)
    {
        Ellipse * p = (Ellipse*) ptr;
        return p->calculatePerimeter();
    }

    double myCorners(void * ptr)
    {
        Ellipse * p = (Ellipse*) ptr;
        return p->calculateNumberOfCorners();
    }

    string myName(void * ptr)
    {
        Ellipse * p = (Ellipse*) ptr;
        return p->calculateShapeName();
    }

}

/*WITHOUT virtual KEYWORD THEY ACTING LIKE virtual*/
double Ellipse::calculateArea()
{
    return (height*width*PI)/4;
}

double Ellipse::calculatePerimeter()
{
    return ((height+width)*PI)/2;
}

double Ellipse::calculateNumberOfCorners()
{
    return 0;
}

string Ellipse::calculateShapeName()
{
    return ("eliptic "+getNameOfShape());
}


/*constructors*/
Ellipse::Ellipse()
:Shape(),height(0),width(0)
{
    setTypeOfShape("ellipse");

    /*here is the big deal when implementing polymorphism*/
    _area = myArea;
    _perimeter = myPerimeter;
    _corner=myCorners;
    _name=myName;
}

Ellipse::Ellipse(string name)
:Shape(name),height(0),width(0)
{
    setTypeOfShape("ellipse");

    /*here is the big deal when implementing polymorphism*/
    _area = myArea;
    _perimeter = myPerimeter;
    _corner=myCorners;
    _name=myName;
}

Ellipse::Ellipse(string name,double high)
:Shape(name),height(high),width(0)
{
    setTypeOfShape("ellipse");

    /*here is the big deal when implementing polymorphism*/
    _area = myArea;
    _perimeter = myPerimeter;
    _corner=myCorners;
    _name=myName;
}

Ellipse::Ellipse(string name,double high,double widt)
:Shape(name),height(high),width(widt)
{
    setTypeOfShape("ellipse");

    /*here is the big deal when implementing polymorphism*/
    _area = myArea;
    _perimeter = myPerimeter;
    _corner=myCorners;
    _name=myName;
}


/*getters*/
double Ellipse::getHeight()const
{
    return height;
}

double Ellipse::getWidth()const
{
    return width;
}


/*setters*/
void Ellipse::setHeight(double high)
{
    height=high;
}

void Ellipse::setWidth(double widt)
{
    width=widt;
}


/*Big three*/
Ellipse::~Ellipse()
{

}

Ellipse& Ellipse::operator =(const Ellipse& rightSide)
{
    Shape::operator=(rightSide);
    height=rightSide.height;
    width=rightSide.width;
    return *this;
}

Ellipse::Ellipse(const Ellipse& rightSide)
:Shape(rightSide.getNameOfShape()),height(rightSide.getHeight()),width(rightSide.getWidth())
{

}

