#include "shape.h"
#include<string>
#include<iostream>

using namespace std;

/*virtuals*/
double Shape::calculateArea() const
{
/*NO CODE NECESSARY*/
}

double Shape::calculatePerimeter() const
{
/*NO CODE NECESSARY*/
}

double Shape::calculateNumberOfCorners() const
{
/*NO CODE NECESSARY*/
}

string Shape::calculateShapeName() const
{
/*NO CODE NECESSARY*/
}


/*constructers*/
Shape::Shape()
{
    nameOfShape="-";
}

Shape::Shape(string name)
{
    nameOfShape=name;
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

/*setter*/
void Shape::setNameOfShape(string name)
{
    nameOfShape=name;
}

void Shape::setTypeOfShape(string type)
{
    typeOfShape=type;
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
/*NO MORE CODE NECESSARY*/
}


/**takes a vector of shape pointers a returns the total areas of the shapes**/
double totalArea(vector<Shape*>&shapes)
{
    double totalArea=0;
    for(int i=0;i<shapes.size();++i)
    {
        totalArea+=shapes[i]->calculateArea();
    }
    return totalArea;
}


/**takes a vector of shapes and returns the total perimeters of circles and ellipses**/
double totalContiniousPerimeter(vector<Shape*>&shapes)
{
    double totalPerimeter=0;
    for(int i=0;i<shapes.size();++i)
    {
        if( shapes[i]->getTypeOfShape() == "circle" || shapes[i]->getTypeOfShape() == "ellipse" )
        totalPerimeter+=shapes[i]->calculatePerimeter();
    }
    return totalPerimeter;
}
