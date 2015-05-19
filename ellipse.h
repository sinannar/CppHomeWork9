#ifndef __HEADER_ELLIPSE_
#define __HEADER_ELLIPSE_

#include "shape.h"

#include<string>
#include<iostream>

using namespace std;

class Ellipse : public Shape
{
    public:

        /*virtuals*/
        virtual double calculateArea() const;
        virtual double calculatePerimeter() const;
        virtual double calculateNumberOfCorners() const;
        virtual string calculateShapeName() const;

        /*constructors*/
        Ellipse();
        Ellipse(string name);
        Ellipse(string name,double high);
        Ellipse(string name,double high,double width);

        /*getters*/
        double getHeight()const;
        double getWidth()const;

        /*setters*/
        void setHeight(double high);
        void setWidth(double width);

        /*Big three*/
        ~Ellipse();
        Ellipse& operator =(const Ellipse& rightSide);
        Ellipse(const Ellipse& rightSide);

    private:
        double height;
        double width;
};

#endif
