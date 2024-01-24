/// @file Inheritance
/// @brief Demonstration of inheritance using one base class to make two derived classes
/// @author Erik Fryanov

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

double const PI = 3.141592653589793; 

//Base abstract class for all shapes
class Shape
{
public:
    Shape(double dHeight, double dWidth);
    virtual ~Shape();
    virtual void scale(double dScaleFactor) = 0; //Scales by factor of dScaleFactor
    virtual double area() = 0;                   //Computes area
    virtual double perimeter() = 0;              //Computes perimeter
    virtual void displayProperties();            //Displays all properties of the shape

protected:
    double m_dHeight;
    double m_dWidth;
    string m_strType;

};

//Base Shape Class Constructor
Shape::Shape(double dHeight, double dWidth) : m_dHeight(dHeight), m_dWidth(dWidth), m_strType("Shape") {}

//Base Shape Class Destructor
Shape::~Shape() { cout << "Shape destructor called" << endl; }

//Displays the type, height, and width of the shape
void Shape::displayProperties()
{
	cout << "Shape Type: " << this->m_strType << ", Height: " << this->m_dHeight;
    cout << ", Width: " << this->m_dWidth << endl;
}

//
/**************************************************************************************************/
//

//Derived class Rectangle
class Rectangle : public Shape
{
public:    
    Rectangle(double dHeight, double dWidth);
    ~Rectangle();
    void scale(double dScaleFactor);
    double area();
    double perimeter();
};

//Rectangle constructor
Rectangle::Rectangle(double dHeight, double dWidth) : Shape(dHeight, dWidth) 
{
    this->m_strType = "Rectangle";
}

//Rectangle destructor
Rectangle::~Rectangle() { cout << "Rectangle destructor called" << endl; }

//Scales a shape by a factor of dScaleFactor
void Rectangle::scale(double dScaleFactor)
{
    this->m_dHeight = this->m_dHeight * dScaleFactor;
    this->m_dWidth = this->m_dWidth * dScaleFactor;
}

//Returns the area of a rectangle
double Rectangle::area()
{
    return (this->m_dWidth * this->m_dHeight);
}

//Returns the perimeter of a rectangle
double Rectangle::perimeter()
{
    return 2.0 * (this->m_dWidth + this->m_dHeight);
}

//
/**************************************************************************************************/
//

//Derived class Circle
class Circle : public Shape
{
public:    
    Circle(double dHeight, double dWidth);
    ~Circle();
    void scale(double dScaleFactor);
    double area();
    double perimeter();
};

//Circle constructor
Circle::Circle(double dHeight, double dWidth) : Shape(dHeight, dWidth) 
{
    this->m_strType = "Circle";
}

//Circle destructor
Circle::~Circle() { cout << "Circle destructor called" << endl; }

//Scales a shape by a factor of dScaleFactor
void Circle::scale(double dScaleFactor)
{
    this->m_dHeight = this->m_dHeight * dScaleFactor;
    this->m_dWidth = this->m_dWidth * dScaleFactor;
}

//Returns the area of a circle
double Circle::area()
{
    return 0.25 * PI * pow(m_dWidth, 2.0);
}

//Returns the perimeter(circumference) of a circle
double Circle::perimeter()
{
    return PI * m_dWidth;
}


int main() {
	Rectangle* p_shapeRectangle = new Rectangle(2.0, 3.0);
    Circle* p_shapeCircle = new Circle(2.0, 2.0);

    Shape* p_shapes[2];

    p_shapes[0] = p_shapeCircle;
    p_shapes[1] = p_shapeRectangle;

    //Output properties, area, and perimeter of each shape.
    //Repeats with a scaling of 2 applied.
    for(int i = 0; i < 2; ++i) {
        p_shapes[i]->displayProperties();
        cout << "Area: " << p_shapes[i]->area() << "; ";
        cout << "Perimeter: " << p_shapes[i]->perimeter() << endl;

        //Apply scaling
        cout << "Scaling by 2..." << endl;
        p_shapes[i]->scale(2.0);
        p_shapes[i]->displayProperties();
        cout << "Area: " << p_shapes[i]->area() << "; ";
        cout << "Perimeter: " << p_shapes[i]->perimeter() << endl << endl;
    }

    //Delete pointers
    delete p_shapeRectangle;
    delete p_shapeCircle;

	return 0;
}