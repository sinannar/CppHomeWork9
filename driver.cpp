#include<string>
#include<iostream>

#include "triangle.h"
#include "square.h"
#include "shape.h"
#include "rectangle.h"
#include "ellipse.h"
#include "circle.h"

//#define TESTCIRCLE
//#define TESTELLIPSE
//#define TESTRECTANGLE
//#define TESTSQUARE
//#define TESTTRIANGLE
#define TESTINGPOLYMORPHISMVIAFUNCTION
using namespace std;

/**takes a vector of shape pointers a returns the total areas of the shapes**/
double totalArea(vector<Shape*>&shapes);
/****************************************************************************/

/**takes a vector of shapes and returns the total perimeters of circles and ellipses**/
double totalContiniousPerimeter(vector<Shape*>&shapes);
/*************************************************************************************/


int main()
{

#ifdef TESTCIRCLE
    Circle a;
    Circle b("first");
    Circle c("second",1);
    cout<<"radious= "<<c.getRadious()<<endl;
    cout<<"area= "<<c.calculateArea()<<endl;
    cout<<"numofcorners= "<<c.calculateNumberOfCorners()<<endl;
    cout<<"perimeter= "<<c.calculatePerimeter()<<endl;
    cout<<"name= "<<c.calculateShapeName()<<endl;
#endif

#ifdef TESTELLIPSE
    Ellipse a;
    Ellipse b("first");
    Ellipse c("second",1);
    Ellipse d("second",1,1);
    cout<<"height= "<<d.getHeight()<<endl;
    cout<<"width= "<<d.getWidth()<<endl;
    cout<<"area= "<<d.calculateArea()<<endl;
    cout<<"numofcorners= "<<d.calculateNumberOfCorners()<<endl;
    cout<<"perimeter= "<<d.calculatePerimeter()<<endl;
    cout<<"name= "<<d.calculateShapeName()<<endl;
#endif

#ifdef TESTRECTANGLE
    Rectangle a;
    Rectangle b("first");
    Rectangle c("second",1);
    Rectangle d("second",3,1);
    cout<<"edge1= "<<d.getEdgeOne()<<endl;
    cout<<"edge2= "<<d.getEdgeTwo()<<endl;
    cout<<"area= "<<d.calculateArea()<<endl;
    cout<<"numofcorners= "<<d.calculateNumberOfCorners()<<endl;
    cout<<"perimeter= "<<d.calculatePerimeter()<<endl;
    cout<<"name= "<<d.calculateShapeName()<<endl;
#endif

#ifdef TESTSQUARE
    Square a;
    Square b("first");
    Square c("second",1);
    cout<<"edge= "<<c.getEdge()<<endl;
    cout<<"area= "<<c.calculateArea()<<endl;
    cout<<"numofcorners= "<<c.calculateNumberOfCorners()<<endl;
    cout<<"perimeter= "<<c.calculatePerimeter()<<endl;
    cout<<"name= "<<c.calculateShapeName()<<endl;
#endif

#ifdef TESTTRIANGLE
    Triangle a;
    Triangle b("first");
    Triangle c("second",1);
    Triangle d("second",3,1);
    Triangle e("second",3,4,5);
    cout<<"edge1= "<<e.getEdgeOne()<<endl;
    cout<<"edge2= "<<e.getEdgeTwo()<<endl;
    cout<<"edge3= "<<e.getEdgeThree()<<endl;
    cout<<"area= "<<e.calculateArea()<<endl;
    cout<<"numofcorners= "<<e.calculateNumberOfCorners()<<endl;
    cout<<"perimeter= "<<e.calculatePerimeter()<<endl;
    cout<<"name= "<<e.calculateShapeName()<<endl;
#endif

#ifdef TESTINGPOLYMORPHISMVIAFUNCTION
    Circle a("first",1);
    Ellipse b("second",1,1);
    Rectangle c("third",3,1);
    Square d("fourth",1);
    Triangle e("fifth",3,4,5);
    vector<Shape*>shapes(5);
    shapes[0]=&a;
    shapes[1]=&b;
    shapes[2]=&c;
    shapes[3]=&d;
    shapes[4]=&e;
    cout<<"testing totalArea            =>"<<totalArea(shapes)<<endl;
    cout<<"testing ContiniousPerimeter  =>"<<totalContiniousPerimeter(shapes)<<endl;
#endif

    return 0;
}

/**takes a vector of shape pointers a returns the total areas of the shapes**/
double totalArea(vector<Shape*>&shapes)
{
    double totalArea=0;
    for(unsigned int i=0;i<shapes.size();++i)
    {
        switch(shapes[i]->getType())
        {
            case 1: //shape
            {
                totalArea+=0;
            }break;

            case 2: //circle
            {
                totalArea+= (reinterpret_cast<Circle*>(shapes[i]))->calculateArea();
            }break;

            case 3: //ellipse
            {
                totalArea+= (reinterpret_cast<Ellipse*>(shapes[i]))->calculateArea();
            }break;

            case 4: //rectangle
            {
                totalArea+= (reinterpret_cast<Rectangle*>(shapes[i]))->calculateArea();
            }break;

            case 5: //square
            {
                totalArea+= (reinterpret_cast<Square*>(shapes[i]))->calculateArea();
            }break;

            case 6: //triangle
            {
                totalArea+= (reinterpret_cast<Triangle*>(shapes[i]))->calculateArea();
            }break;
        }

    }
    return totalArea;
}


/**takes a vector of shapes and returns the total perimeters of circles and ellipses**/
double totalContiniousPerimeter(vector<Shape*>&shapes)
{
    double totalPerimeter=0;
    for(unsigned i=0;i<shapes.size();++i)
    {
        if(shapes[i]->getType()==2 || shapes[i]->getType()==3)
        switch(shapes[i]->getType())
        {
            case 2: //circle
            {
                totalPerimeter+= (reinterpret_cast<Circle*>(shapes[i]))->calculatePerimeter();
            }break;

            case 3: //ellipse
            {
                totalPerimeter+= (reinterpret_cast<Ellipse*>(shapes[i]))->calculatePerimeter();
            }break;
        }
    }
    return totalPerimeter;
}
