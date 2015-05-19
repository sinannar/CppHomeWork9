#include "square.h"
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
        Square * p = (Square*) ptr;
        return p->calculateArea();
    }

    double myPerimeter(void * ptr)
    {
        Square * p = (Square*) ptr;
        return p->calculatePerimeter();
    }

    double myCorners(void * ptr)
    {
        Square * p = (Square*) ptr;
        return p->calculateNumberOfCorners();
    }

    string myName(void * ptr)
    {
        Square * p = (Square*) ptr;
        return p->calculateShapeName();
    }

}

/*WITHOUT virtual KEYWORD THEY ACTING LIKE virtual*/
double Square::calculateArea()
{
return static_cast<double>(edge)*edge;
}

double Square::calculatePerimeter()
{
    return edge*4.0;
}

double Square::calculateNumberOfCorners()
{
    return 4.0;
}

string Square::calculateShapeName()
{
    return ("squaristic "+getNameOfShape());
}


/*constructors*/
Square::Square()
:Shape(),edge(0.0)
{
    setTypeOfShape("square");

    /*here is the big deal when implementing polymorphism*/
    _area = myArea;
    _perimeter = myPerimeter;
    _corner=myCorners;
    _name=myName;
}

Square::Square(string name)
:Shape(name),edge(0)
{
    setTypeOfShape("square");

    /*here is the big deal when implementing polymorphism*/
    _area = myArea;
    _perimeter = myPerimeter;
    _corner=myCorners;
    _name=myName;
}

Square::Square(string name,double edgE)
:Shape(name),edge(edgE)
{
    setTypeOfShape("square");

    /*here is the big deal when implementing polymorphism*/
    _area = myArea;
    _perimeter = myPerimeter;
    _corner=myCorners;
    _name=myName;
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


