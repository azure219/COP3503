#include <iostream>
#include <iomanip>
#include <random>
using namespace std;

#define PI 3.14159f

class Shape {

	public:

		virtual void Scale(float scalefactor) = 0;
		virtual void Display() const = 0;
		virtual ~Shape() {

		}
		
};

class Shape2D : virtual public Shape {
	
	public:

		virtual float Area() const = 0;
		void ShowArea() const;
		virtual string GetName2D() const = 0;

		bool operator> (const Shape2D& rhs) const;
		bool operator< (const Shape2D& rhs) const;
		bool operator== (const Shape2D& rhs) const;

};

class Square : virtual public Shape2D {

	public: 

		Square();
		Square(float s);

		float Area() const;
		string GetName2D() const;

		void Scale(float scalefactor);
		void Display() const;

		~Square();

	private:

		float side;

};

class Circle : virtual public Shape2D {

	public:

		Circle();
		Circle(float r);

		float Area() const;
		string GetName2D() const;
		float GetRadius() const;

		void Scale(float scalefactor);
		void Display() const;

		~Circle();

	private:

		float radius;

};

class Triangle : virtual public Shape2D {

	public: 

		Triangle();
		Triangle(float h, float b);

		float Area() const;
		string GetName2D() const;
		float GetBase() const;
		float GetHeight() const;

		void Scale(float scalefactor);
		void Display() const;

		~Triangle();

	private:

		float height;
		float base;

};

class Shape3D : virtual public Shape {

	public:

		virtual float Volume() const = 0;
		void ShowVolume() const;
		virtual string GetName3D() const = 0;

		bool operator> (const Shape3D& rhs) const;
		bool operator< (const Shape3D& rhs) const;
		bool operator== (const Shape3D& rhs) const;

};

class TriangularPyramid : virtual public Shape3D, private Triangle {

	public:

		TriangularPyramid();
		TriangularPyramid(float h, float l, float bh);

		float Volume() const;
		string GetName3D() const;

		void Scale(float scalefactor);
		void Display() const;

		~TriangularPyramid();

	private:

		float height;
		float length;
		float baseHeight;

};

class Cylinder : virtual public Shape3D, private Circle {

	public:

		Cylinder();
		Cylinder(float h, float r);

		float Volume() const;
		string GetName3D() const;

		void Scale(float scalefactor);
		void Display() const;

		~Cylinder();

	private:

		float height;
		float radius;

};

class Sphere : virtual public Shape3D, private Circle {

	public:

		Sphere();
		Sphere(float r);

		float Volume() const;
		string GetName3D() const;

		void Scale(float scalefactor);
		void Display() const;

		~Sphere();

	private:

		float height;
		float radius;

};