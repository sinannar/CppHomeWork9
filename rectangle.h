#ifndef __HEADER_RECTANGLE_
#define __HEADER_RECTANGLE_

#include "shape.h"

#include<string>
#include<iostream>

using namespace std;

class Rectangle : public Shape
{
    public:

        /*virtuals*/
        virtual double calculateArea() const;
        virtual double calculatePerimeter() const;
        virtual double calculateNumberOfCorners() const;
        virtual string calculateShapeName() const;

        /*constructors*/
        Rectangle();
        Rectangle(string name);
        Rectangle(string name,double edge1);
        Rectangle(string name,double edge1,double edge2);

        /*getters*/
        double getEdgeOne() const;
        double getEdgeTwo() const;

        /*setters*/
        void setEdgeOne(double edge);
        void setEdgeTwo(double edge);

        /*Big three*/
        ~Rectangle();
        Rectangle& operator =(const Rectangle& rightSide);
        Rectangle(const Rectangle& rightSide);

    private:
        double edgeOne;
        double edgeTwo;
};

#endif
