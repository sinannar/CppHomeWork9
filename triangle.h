#ifndef __HEADER_TRIANGLE_
#define __HEADER_TRIANGLE_

#include "shape.h"

#include<string>
#include<iostream>

using namespace std;

class Triangle : public Shape
{
    public:

        /*virtuals*/
        virtual double calculateArea() const;
        virtual double calculatePerimeter() const;
        virtual double calculateNumberOfCorners() const;
        virtual string calculateShapeName() const;

        /*constructors*/
        Triangle();
        Triangle(string name);
        Triangle(string name,double edge1);
        Triangle(string name,double edge1,double edge2);
        Triangle(string name,double edge1,double edge2,double edge3);

        /*getters*/
        double getEdgeOne() const;
        double getEdgeTwo() const;
        double getEdgeThree() const;

        /*setters*/
        void setEdgeOne(double edge);
        void setEdgeTwo(double edge);
        void setEdgeThree(double edge);

        /*Big three*/
        ~Triangle();
        Triangle& operator =(const Triangle& rightSide);
        Triangle(const Triangle& rightSide);

    private:
        double edgeOne;
        double edgeTwo;
        double edgeThree;

};
#endif
