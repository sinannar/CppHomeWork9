#include "square.h"
#include<string>
#include<iostream>

using namespace std;

/*as known virtuals but not really*/
double Square::calculateArea() const
{
return static_cast<double>(edge)*edge;
}

double Square::calculatePerimeter() const
{
    return edge*4.0;
}

double Square::calculateNumberOfCorners() const
{
    return 4.0;
}

string Square::calculateShapeName() const
{
    return ("squaristic "+getNameOfShape());
}


/*constructors*/
Square::Square():Shape(),edge(0.0)
{
    setTypeOfShape("square");
    setType(5);
}

Square::Square(string name):Shape(name),edge(0)
{
    setTypeOfShape("square");
    setType(5);
}

Square::Square(string name,double edgE)
:Shape(name),edge(edgE)
{
    setTypeOfShape("square");
    setType(5);
}


/*getters*/
double Square::getEdge() const
{
    return edge;
}


/*setters*/
void Square::setEdge(double edgE)
{
    edge=edgE;
}


/*Big three*/
Square::~Square()
{

}

Square& Square::operator =(const Square& rightSide)
{
    Shape::operator=(rightSide);
    edge=rightSide.edge;
    return *this;
}

Square::Square(const Square& rightSide)
:Shape(rightSide.getNameOfShape()),edge(rightSide.getEdge())
{

}


