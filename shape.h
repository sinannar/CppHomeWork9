#ifndef __HEADER_SHAPE_
#define __HEADER_SHAPE_

#include<string>
#include<iostream>
#include<vector>

using namespace std;

const double PI=3.14;

class Shape
{
    public:

        /*as known virtuals but not really*/
        double calculateArea() const;            //making abstact class
        double calculatePerimeter() const;       //making abstact class
        double calculateNumberOfCorners() const; //making abstact class
        string calculateShapeName() const;       //making abstact class

        /*constructers*/
        Shape();
        Shape(string name);

        /*getter*/
        string getNameOfShape() const;
        string getTypeOfShape() const;
        int getType() const;

        /*setter*/
        void setNameOfShape(string name);
        void setTypeOfShape(string type);
        void setType(int typE);

        /*big three*/
        ~Shape();
        Shape& operator =(const Shape& rightSide);
        Shape(const Shape& rightSide);

    private:
        string nameOfShape;
        string typeOfShape;
        int type;/*normally it is not necessary but i want to use int within comparison two variable*/
        /*
        SHAPE TYPES
        1 -> shape
        2 -> circle
        3 -> ellipse
        4 -> rectangle
        5 -> square
        6 -> triangle
        */

};



#endif
