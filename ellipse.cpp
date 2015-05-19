#include "ellipse.h"
#include<string>
#include<iostream>

using namespace std;

/*as known virtuals but not really*/
double Ellipse::calculateArea() const
{
    return (height*width*PI)/4;
}

double Ellipse::calculatePerimeter() const
{
    return ((height+width)*PI)/2;
}

double Ellipse::calculateNumberOfCorners() const
{
    return 0;
}

string Ellipse::calculateShapeName() const
{
    return ("eliptic "+getNameOfShape());
}


/*constructors*/
Ellipse::Ellipse()
:Shape(),height(0),width(0)
{
    setTypeOfShape("ellipse");
    setType(3);
}

Ellipse::Ellipse(string name)
:Shape(name),height(0),width(0)
{
    setTypeOfShape("ellipse");
    setType(3);
}

Ellipse::Ellipse(string name,double high)
:Shape(name),height(high),width(0)
{
    setTypeOfShape("ellipse");
    setType(3);
}

Ellipse::Ellipse(string name,double high,double widt)
:Shape(name),height(high),width(widt)
{
    setTypeOfShape("ellipse");
    setType(3);
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

