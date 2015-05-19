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
        double calculateArea() ;            //making abstact class
        double calculatePerimeter() ;       //making abstact class
        double calculateNumberOfCorners() ; //making abstact class
        string calculateShapeName() ;       //making abstact class

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

    protected:
        double (*_area)(void *);
        double (*_perimeter)(void *);
        double (*_corner)(void *);
        string (*_name)(void *);

    private:
        string nameOfShape;
        string typeOfShape;

};

/**takes a vector of shape pointers a returns the total areas of the shapes**/
double totalArea(vector<Shape*>&shapes);
/****************************************************************************/

/**takes a vector of shapes and returns the total perimeters of circles and ellipses**/
double totalContiniousPerimeter(vector<Shape*>&shapes);
/*************************************************************************************/


#endif
