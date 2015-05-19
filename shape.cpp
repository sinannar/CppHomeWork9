#include "shape.h"
#include<string>
#include<iostream>

using namespace std;

/*WITHOUT virtual KEYWORD THEY ACTING LIKE virtual*/
double Shape::calculateArea()
{
    /*
    out function pointer show a function that is specify to calculate area
    in this case,if points NULL,its basic shape and return 0
    */
    if(_area==NULL)
        return 0;
    return (_area(this));
}

double Shape::calculatePerimeter()
{
    /*
    out function pointer show a function that is specify to calculate perimeter
    in this case,if points NULL,its basic shape and return 0
    */
    if(_perimeter==NULL)
        return 0;
    return (_perimeter(this));
}

double Shape::calculateNumberOfCorners()
{
    /*
    out function pointer show a function that is specify to calculate corner
    in this case,if points NULL,its basic shape and return 0
    */
    if(_corner==NULL)
        return 0;
    return (_corner(this));
}

string Shape::calculateShapeName()
{
    /*
    out function pointer show a function that is specify to take name
    in this case,if points NULL,its basic shape and return 0
    */
    if(_name==NULL)
        return 0;
    return (_name(this));
}


/*constructers*/
Shape::Shape()
{
    nameOfShape="-";

    /*here is the big deal when implementing polymorphism*/
    _area=NULL;
    _perimeter=NULL;
    _corner=NULL;
    _name=NULL;
}

Shape::Shape(string name)
{
    nameOfShape=name;

    /*here is the big deal when implementing polymorphism*/
    _area=NULL;
    _perimeter=NULL;
    _corner=NULL;
    _name=NULL;
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
