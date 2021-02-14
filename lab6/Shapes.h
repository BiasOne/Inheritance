#pragma once

#include <string>

using namespace std;

class Shape
{
public:
	Shape();
	virtual ~Shape();
	
	virtual void Scale(float scaleFactor) = 0;
	virtual void Display() const = 0;	
};

	/*
	*	2D shapes
	*/

class Shape2D : virtual public Shape
{
	
public: 
		virtual float Area() const = 0;
		void ShowArea() const;
		virtual string GetName2D() const = 0;
		bool operator>(const Shape2D& rhs) const;
		bool operator<(const Shape2D& rhs) const;
		bool operator==(const Shape2D& rhs) const;		
};	

class Square : public Shape2D
{
private:
	float side;
	
public:	
		Square();
		Square(float side);
		string GetName2D() const;
		float Area() const;
		void Display() const;
		void Scale(float scaleFactor);	
		
};

class Triangle : public Shape2D
{
private:
	float base, height;

public:
	Triangle();
	Triangle(float base, float height);
	string GetName2D() const;
	float Area() const;
	void Display() const;
	void Scale(float scaleFactor);	
};

class Circle : public Shape2D
{
protected:
	float radius;
	
public:
	Circle();
	Circle(float radius);
	string GetName2D() const;
	float Area() const;
	void Display() const;
	void Scale(float scaleFactor);
};

	/*
	*	3D shapes
	*/

class Shape3D : virtual public Shape
{	
public:
		virtual float Volume() const = 0;
		void ShowVolume() const;
		virtual string GetName3D() const = 0;	
		bool operator>(const Shape3D& rhs) const;
		bool operator<(const Shape3D& rhs) const;
		bool operator==(const Shape3D& rhs) const;
};

class TriangularPyramid : public Shape3D, private Triangle
{
private:
	float triangleheightP, baseLengthTP, baseheightP;
	

public:
	TriangularPyramid();
	TriangularPyramid(float triagnleheightP, float baseLengthTP, float baseheightP);
	string GetName3D() const;
	float Volume() const;
	void Display() const;
	void Scale(float scaleFactor);
	
};

class Cylinder : public Shape3D, private Circle
{
private:
	float height;
	
public:
	Cylinder();
	Cylinder(float height,float radius);
	string GetName3D() const;
	float Volume() const;
	void Display() const;
	void Scale(float scaleFactor);
	
};

class Sphere : public Shape3D, private Circle
{
private:
	float radius;
	
public:
	Sphere();
	Sphere(float radius);
	string GetName3D() const;
	float Volume() const;
	void Display() const;
	void Scale(float scaleFactor);
	
};
