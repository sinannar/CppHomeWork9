#include "shape.h"
#include<string>
#include<iostream>

using namespace std;

/*as known virtuals but not really*/
double Shape::calculateArea() const
{

}

double Shape::calculatePerimeter() const
{

}

double Shape::calculateNumberOfCorners() const
{

}

string Shape::calculateShapeName() const
{

}


/*constructers*/
Shape::Shape()
{
    nameOfShape="-";
    type=1;
}

Shape::Shape(string name)
{
    nameOfShape=name;
    type=1;
}


/*getter*/
string Shape::getNameOfShape() const
{
    return nameOfShape;
}

string Shape::getTypeOfShape() const
{
    return typeOfShape;
}

int Shape::getType() const
{
    return type;
}

/*setter*/
void Shape::setNameOfShape(string name)
{
    nameOfShape=name;
}

void Shape::setTypeOfShape(string type)
{
    typeOfShape=type;
}

void Shape::setType(int typE)
{
    type=typE;
}
/*big three*/
Shape::~Shape()
{

}

Shape& Shape::operator =(const Shape& rightSide)
{
    nameOfShape=rightSide.nameOfShape;
    return *this;
}

Shape::Shape(const Shape& rightSide):
nameOfShape(rightSide.getNameOfShape())
{

}

