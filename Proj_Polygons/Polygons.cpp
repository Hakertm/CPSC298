/// @file Polygons
/// @brief Example of the concept of inheritance in use
/// @author Erik Fryanov

#include <iostream>
#include <string>
using namespace std;

// //////////////////////////////////////////////////////////////////////////////////////////////
// Base Class Polygon - an Abstract Base Class, can't be instantiated
// //////////////////////////////////////////////////////////////////////////////////////////////
class Polygon {

public:
	Polygon(double dWidth, double dHeight);
	virtual ~Polygon();
	virtual double area() = 0; // Pure virtual member function - no implementation in base class
	virtual void displayProperties();

protected:
	double m_dWidth;
	double m_dHeight;
	string m_strType;
};

Polygon::Polygon(double dWidth, double dHeight) : m_dWidth(dWidth), m_dHeight(dHeight), m_strType("Polygon")
{

}

Polygon::~Polygon()
{
	cout << "Polygon Destructor called" << endl;
}

void Polygon::displayProperties()
{
	cout << "Polygon Type: " << this->m_strType << ", Width: " << this->m_dWidth << ", Height: " << this->m_dHeight << endl;
	return;
}

// //////////////////////////////////////////////////////////////////////////////////////////////
// Derived Class Rectangle ("Concrete" class, can be instantiated)
// //////////////////////////////////////////////////////////////////////////////////////////////
class Rectangle : public Polygon
{
public:
	Rectangle(double dWidth, double dHeight);
	~Rectangle();
	double area();
};

Rectangle::Rectangle(double dWidth, double dHeight) : Polygon(dWidth, dHeight)
{
	this->m_strType = "Rectangle";
}

Rectangle::~Rectangle()
{
	cout << "Rectangle Destructor called" << endl;
}

double Rectangle::area()
{
	return (this->m_dHeight * this->m_dWidth);
}

// //////////////////////////////////////////////////////////////////////////////////////////////
// Derived Class Triangle ("Concrete" class, can be instantiated)
// //////////////////////////////////////////////////////////////////////////////////////////////

class Triangle : public Polygon {
public:
	Triangle(double dWidth, double dHeight);
	~Triangle();
	double area();
};

Triangle::Triangle(double dWidth, double dHeight) : Polygon(dWidth, dHeight) {
	this->m_strType = "Triangle";
}

Triangle::~Triangle() {
	cout << "Triangle Destructor called" << endl;
}

double Triangle::area() {
	return (this->m_dHeight * this->m_dWidth * 0.5);
}


int main() {
	Polygon* p_polygonRectangle = new Rectangle(2.0, 4.0);
	Polygon* p_polygonTriangle = new Triangle(3.0, 6.0);
	Polygon* p_polygon[2]; // You can create pointers to Polygon, but not a Polygon object

	p_polygon[0] = p_polygonRectangle;
	p_polygon[1] = p_polygonTriangle;

	//Output each polygon's area
	for (int i = 0; i < 2; i++) {
		// Polymorphic invocation
		p_polygon[i]->displayProperties(); // take advantage of reuse; use base class function
		double dArea = p_polygon[i]->area();
		cout << "Area: " << dArea << endl;
	}

	//Delete pointers
	delete p_polygonRectangle;
	delete p_polygonTriangle;

	return 0;
}

