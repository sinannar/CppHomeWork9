#ifndef __HEADER_SQUARE_
#define __HEADER_SQUARE_

#include "shape.h"

#include<string>
#include<iostream>

using namespace std;

class Square : public Shape
{
    public:

        /*virtuals*/
        virtual double calculateArea() const;
        virtual double calculatePerimeter() const;
        virtual double calculateNumberOfCorners() const;
        virtual string calculateShapeName() const;

        /*constructors*/
        Square();
        Square(string name);
        Square(string name,double edgE);

        /*getters*/
        double getEdge() const;

        /*setters*/
        void setEdge(double edgE);

        /*Big three*/
        ~Square();
        Square& operator =(const Square& rightSide);
        Square(const Square& rightSide);

    private:
        double edge;
};
#endif
