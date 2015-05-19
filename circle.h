#ifndef __HEADER_CIRCLE_
#define __HEADER_CIRCLE_

#include "shape.h"

#include<string>
#include<iostream>

using namespace std;

class Circle : public Shape
{
    public:

        /*virtuals*/
        double calculateArea() ;
        double calculatePerimeter() ;
        double calculateNumberOfCorners() ;
        string calculateShapeName() ;

        /*constructors*/
        Circle();
        Circle(string name);
        Circle(string name,double rad);

        /*getters*/
        double getRadious() const;

        /*setters*/
        void setRadious(double rad);

        /*Big three*/
        ~Circle();
        Circle& operator =(const Circle& rightSide);
        Circle(const Circle& rightSide);

    private:
        double radious;
};
#endif
