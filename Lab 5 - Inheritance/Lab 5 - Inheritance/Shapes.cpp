#include <iostream>
#include <iomanip>
#include "Shapes.h"
#include <random>
using namespace std;

// Shape2D Class functions
void Shape2D::ShowArea() const {

	cout << "The area of the " << GetName2D() << " is : " << Area() << endl;

}

bool Shape2D::operator> (const Shape2D& rhs) const {

	if (this->Area() > rhs.Area()) {

		return true;

	} else {

		return false;

	}

}

bool Shape2D::operator< (const Shape2D& rhs) const {

	if (this->Area() < rhs.Area()) {

		return true;

	}
	else {

		return false;

	}

}

bool Shape2D::operator== (const Shape2D& rhs) const {

	if (this->Area() == rhs.Area()) {

		return true;

	}
	else {

		return false;

	}

}

// Square Class functions
Square::Square() {

	side = 0;

}

Square::Square(float s) {

	side = s;

}

Square::~Square() {

}

float Square::Area() const {

	float area = side * side;
	return area;

}

string Square::GetName2D() const {

	return "Square";

}

void Square::Scale(float scalefactor) {

	side *= scalefactor;

}

void Square::Display() const {

	cout << "The area of the " << GetName2D() << " is : " << Area() << endl;
	cout << "Length of a side: " << side << endl;

}

// Triangle Class functions
Triangle::Triangle() {

	height = 0;
	base = 0;

}

Triangle::Triangle(float b, float h) {

	height = h;
	base = b;

}

Triangle::~Triangle() {

}

float Triangle::Area() const {

	float area = 0.5 * (base * height);
	return area;

}

string Triangle::GetName2D() const {

	return "Triangle";

}

float Triangle::GetBase() const {

	return base;

}

float Triangle::GetHeight() const {

	return height;

}

void Triangle::Scale(float scalefactor) {

	base *= scalefactor;
	height *= scalefactor;

}

void Triangle::Display() const {

	cout << "The area of the " << GetName2D() << " is : " << Area() << endl;
	cout << "Base: " << base << endl;
	cout << "Height: " << height << endl;


}

// Circle Class functions
Circle::Circle() {

	radius = 0;

}

Circle::Circle(float r) {

	radius = r;

}

Circle::~Circle() {

}

float Circle::Area() const {

	float area = PI * (radius * radius);
	return area;

}

string Circle::GetName2D() const {

	return "Circle";

}

float Circle::GetRadius() const {

	return radius;

}

void Circle::Scale(float scalefactor) {

	radius *= scalefactor;

}

void Circle::Display() const {

	cout << "The area of the " << GetName2D() << " is : " << Area() << endl;
	cout << "Radius: " << radius << endl;

}

// Shape3D Class functions
void Shape3D::ShowVolume() const {

	cout << "The volume of the " << GetName3D() << " is : " << Volume() << endl;

}

bool Shape3D::operator> (const Shape3D& rhs) const {

	if (this->Volume() > rhs.Volume()) {

		return true;

	}
	else {

		return false;

	}

}

bool Shape3D::operator< (const Shape3D& rhs) const {

	if (this->Volume() < rhs.Volume()) {

		return true;

	}
	else {

		return false;

	}

}

bool Shape3D::operator== (const Shape3D& rhs) const {

	if (this->Volume() == rhs.Volume()) {

		return true;

	}
	else {

		return false;

	}

}

// TriangularPyramid Class functions
TriangularPyramid::TriangularPyramid() {

	height = 0;
	length = 0;
	baseHeight = 0;

}

TriangularPyramid::TriangularPyramid(float h, float l, float bh) : Triangle::Triangle(l, bh) {

	height = h;

}

TriangularPyramid::~TriangularPyramid() {

}

float TriangularPyramid::Volume() const {

	float volume = (1.0/3.0) * (Triangle::Area()) * height;
	return volume;

}

string TriangularPyramid::GetName3D() const {

	return "TriangularPyramid";

}

void TriangularPyramid::Scale(float scalefactor) {

	height *= scalefactor;
	Triangle::Scale(scalefactor);

}

void TriangularPyramid::Display() const {

	cout << "The volume of the " << GetName3D() << " is : " << Volume() << endl;
	cout << "The height is: " << height << endl;
	cout << "The area of the " << Triangle::GetName2D() << " is : " << Triangle::Area() << endl;
	cout << "Base: " << Triangle::GetBase() << endl;
	cout << "Height: " << Triangle::GetHeight() << endl;

}

// Cylinder Class functions
Cylinder::Cylinder() {

	height = 0;
	radius = 0;

}

Cylinder::Cylinder(float h, float r) : Circle::Circle(r) {

	height = h;

}

Cylinder::~Cylinder() {

}

float Cylinder::Volume() const {

	float volume = (Circle::Area()) * height;
	return volume;

}

string Cylinder::GetName3D() const {

	return "Cylinder";

}

void Cylinder::Scale(float scalefactor) {

	height *= scalefactor;
	Circle::Scale(scalefactor);

}

void Cylinder::Display() const {

	cout << "The volume of the " << GetName3D() << " is : " << Volume() << endl;
	cout << "The height is: " << height << endl;
	cout << "The area of the " << Circle::GetName2D() << " is : " << Circle::Area() << endl;
	cout << "Radius: " << Circle::GetRadius() << endl;

}

// Sphere Class functions
Sphere::Sphere() {

	height = 0;
	radius = 0;

}

Sphere::Sphere(float r) : Circle::Circle(r) {

}

Sphere::~Sphere() {

}

float Sphere::Volume() const {

	float rad = Circle::GetRadius();

	float volume = (4.0/3.0) * PI * (rad * rad * rad);
	return volume;

}

string Sphere::GetName3D() const {

	return "Sphere";

}

void Sphere::Scale(float scalefactor) {

	Circle::Scale(scalefactor);

}

void Sphere::Display() const {

	cout << "The volume of the " << GetName3D() << " is : " << Volume() << endl;
	cout << "The area of the " << Circle::GetName2D() << " is : " << Circle::Area() << endl;
	cout << "Radius: " << Circle::GetRadius() << endl;

}
