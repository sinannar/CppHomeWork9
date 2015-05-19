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

        /*virtuals*/
        virtual double calculateArea() const =0;            //making abstact class
        virtual double calculatePerimeter() const =0;       //making abstact class
        virtual double calculateNumberOfCorners() const =0; //making abstact class
        virtual string calculateShapeName() const =0;       //making abstact class

        /*constructers*/
        Shape();
        Shape(string name);

        /*getter*/
        string getNameOfShape() const;
        string getTypeOfShape() const;

        /*setter*/
        void setNameOfShape(string name);
        void setTypeOfShape(string type);

        /*big three*/
        ~Shape();
        Shape& operator =(const Shape& rightSide);
        Shape(const Shape& rightSide);

    private:
        string nameOfShape;//its special name of shape,like first eliptic
        string typeOfShape;//its identifier of shape

};

/**takes a vector of shape pointers a returns the total areas of the shapes**/
double totalArea(vector<Shape*>&shapes);
/****************************************************************************/

/**takes a vector of shapes and returns the total perimeters of circles and ellipses**/
double totalContiniousPerimeter(vector<Shape*>&shapes);
/*************************************************************************************/


#endif
