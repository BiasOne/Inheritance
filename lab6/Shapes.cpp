#include "Shapes.h"
#include <iostream>
#include <stdio.h>
#include <math.h> 
using namespace std;

const float pi = 3.14159f;

Shape::Shape() {}

Shape::~Shape() {}

void Shape2D::ShowArea() const
{
	cout << "The area of the " << GetName2D() << " is : " << Area() << endl;
}

bool Shape2D::operator>(const Shape2D& rhs) const 
{
	return Area() > rhs.Area();
	
}

bool Shape2D::operator<(const Shape2D& rhs) const 
{
	return Area() < rhs.Area();
	
}

bool Shape2D::operator==(const Shape2D& rhs) const 
{
	return Area() == rhs.Area();
}

	/*	
	*	******
	*/  

Square::Square() 
{
	side = 0.0f;	
}

Square::Square(float side)
{
	this->side = side;
}

 string Square::GetName2D() const
 {
 	return string("Square");
}

float Square::Area() const 
{
	return(pow(side, 2.0f));
}

void Square::Display() const
{
	cout << "The area of the Square is : " << Area() << endl;
	cout << "Length of a side: " << side << endl;
}

void Square::Scale(float scaleFactor)
{
	this->side = side* scaleFactor;
}

	/*
	*	******
	*/

Triangle::Triangle()
{
	base = 0.0f;
	height = 0.0f;

}

Triangle::Triangle(float base, float height)
{
	this->base = base;
	this->height = height;
}

string Triangle::GetName2D() const
{
	return string("Triangle");
}

float Triangle::Area() const
{
	return(.5f * base * height);
}

void Triangle::Display() const
{
	cout << "The area of the Triangle is : " << Area() << endl;
	cout << "Base: " << base << endl;
	cout << "Height: " << height << endl;
}

void Triangle::Scale(float scaleFactor)
{	
	this->base =	base * scaleFactor;
	this->height = height * scaleFactor;
}

	/*
	*	******
	*/

Circle::Circle()
{
	radius = 0.0f;
}

Circle::Circle(float radius)
{
	this->radius = radius;
}

void Circle::Display() const
{
	cout << "The area of the Circle is : " << Area() << endl;
	cout << "Radius: " << radius;
}

float Circle::Area() const
{
	return( pi * pow(radius, 2.0f));
}

void Circle::Scale(float scaleFactor)
{
	this->radius = radius * scaleFactor;
}

string Circle::GetName2D() const
{
	return string("Circle");
}

	/*
	*	******
	*/

void Shape3D::ShowVolume() const 
{
	cout << "The volume of the " << GetName3D() << " is: "<< Volume() << endl;
}

bool Shape3D::operator>(const Shape3D& rhs) const
{
	return Volume() > rhs.Volume();	
}

bool Shape3D::operator<(const Shape3D& rhs) const
{
	return Volume() < rhs.Volume();
}

bool Shape3D::operator==(const Shape3D& rhs) const
{
	return Volume() == rhs.Volume();
}

/*
*	******
*/

TriangularPyramid::TriangularPyramid()
{
	triangleheightP = 0.0f;
	baseLengthTP = 0.0f;
	baseheightP = 0.0f;
}


TriangularPyramid::TriangularPyramid(float triangleheightP, float baseLengthTP, float baseheightP) : Triangle(baseLengthTP, baseheightP)
{
	this->triangleheightP = triangleheightP;
	this->baseLengthTP = baseLengthTP;
	this->baseheightP = baseheightP;
}

float TriangularPyramid::Volume() const
{
	return ((1.0f / 3.0f) * Area() * triangleheightP);
}

void TriangularPyramid::Display() const
{
	cout << "The volume of the TriangularPyramid is : " << Volume() << endl;
	cout << "The height is: " << triangleheightP << endl;
	cout << "The area of the Triangle is : " << this->Area() << endl;
	cout << "Base: " << baseLengthTP << endl;
	cout << "Height: " << baseheightP << endl;
}

void TriangularPyramid::Scale(float scaleFactor)
{
	this->baseLengthTP = baseLengthTP * scaleFactor;
	this->baseheightP = baseheightP * scaleFactor;
	this->triangleheightP = triangleheightP * scaleFactor;
}

string TriangularPyramid::GetName3D() const
{
	return string("TriangularPyramid");;
}

/*
*	*******
*/

Cylinder::Cylinder()
{
	height = 0.0f;

}

Cylinder::Cylinder(float height, float radius) : Circle(radius)
{
	this->height = height;
	
}

float Cylinder::Volume() const 
{
	return (pi * pow(radius, 2.0f) * height);
}

void Cylinder::Display() const
{
	cout << "The volume of the Cylinder is : " << Volume() << endl;
	cout << "The height is: " << height << endl;
	cout << "The area of the Circle is : " << this->Area()  << endl;
	cout << "Radius: " << radius << endl;
}

void Cylinder::Scale(float scaleFactor)
{
	this->height = height * scaleFactor;
	this->radius = radius * scaleFactor;
}

string Cylinder::GetName3D() const
{
	return string("Cylinder");
}

/*
*	******
*/

Sphere::Sphere()
{
	radius = 0.0f;
}

Sphere::Sphere(float radius):Circle(radius)
{
	this->radius = radius;
}

float Sphere::Volume() const
{
	return ((4.0f / 3.0f) * pi * pow(radius, 3.0f));
}

void Sphere::Display() const
{
	cout << "The volume of the Sphere is : " << Volume() << endl;
	cout << "The area of the Circle is : " << this->Area() << endl;
	cout << "Radius: " << radius << endl;
}

void Sphere::Scale(float scaleFactor)
{
	this->radius = radius * scaleFactor;
}

string Sphere::GetName3D() const 
{
	return string("Sphere");
}
