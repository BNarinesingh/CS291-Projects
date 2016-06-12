#include<iostream>
#include<math.h>

using namespace std;

//parent class....................................................................................................
class pointType {

public:

	pointType();
	void setpoints(double& a, double& b);
	void setpoints(double& a, double& b, double& c, double& d);
	void printPoints();
	double getXval();
	double getYval();
	double getX1val();
	double getY1val();
private:
	double x, x1;
	double y, y1;
};

pointType::pointType() {
	x = 0.0;
	y = 0.0;
	x1 = 0.0;
	y1 = 0.0;
}

void pointType::setpoints(double& a, double& b) {
	x = a;
	y = b;
}
void pointType::setpoints(double& a, double& b, double& c, double& d) {
	x = a;
	y = b;
	x1 = c;
	y1 = d;
};
void pointType::printPoints() {
	cout << " x value is " << x << endl;
	cout << " y value is " << y << endl;
	cout << " x1 value is" << x1 << endl;
	cout << " y1 value is" << y1 << endl;
	cout << "center is at (" << x << "," << y << ")" << endl;
}
double pointType::getXval() {
	return x;
}
double pointType::getX1val() {
	return x1;
}
double pointType::getYval() {
	return y;
}
double pointType::getY1val() {
	return y1;
}
//child class....................................................................................................
class circleType : public pointType {
public:
	circleType();
	void setradius();
	void printradius();
	double areaC();
	double circumferenceC();
	void areaCncircumferencePrint();

private:
	double radius;
	const double pi = 3.1416;
	double area;
	double circumference;
};
circleType::circleType() {
	radius = 0;
	area = 0;
	circumference = 0;
}

void circleType::setradius() {
	double a, b, c, d, distance;
	a = getXval();
	b = getYval();
	c = getX1val();
	d = getY1val();

	//distance formula is sqrt((x2-x1)sq+(y2-y1)sq)

	a = a - c;
	b = b - d;

	distance = (a*a) + (b*b);

	distance = sqrt(distance);	// we use x1=0,y1=0 the origin as center

	radius = distance;	// the radius is found from the distance from the origin.
}
void circleType::printradius() {
	cout << "The radius of the circle is: " << radius << endl;
}
double circleType::areaC() {

	area = radius*radius;
	area = area*pi;
	return area;
}
double circleType::circumferenceC() {
	circumference = radius*(2 * pi);
	return circumference;
}

void circleType::areaCncircumferencePrint() {
	cout << "The area of the circle is : " << area << endl;
	cout << "The circumference of the circle is : " << circumference << endl;
}

//grandchild class..................................................................................................
class cylinderType : public circleType {
public:
	cylinderType();
	void cylinderVolume();
	void cylinderSurfaceArea();
	void printVolumeSurfaceArea();
	void setheight(double h);
	//	void setradius();  //done via child class unneccessary for grandchild
	//	void setcenter();  //done via parent class unneccessary for grandchild

private:
	double cVolume;
	double cSurfaceArea;
	double height;
};

cylinderType::cylinderType() {
	cVolume = 0;
	cSurfaceArea = 0;
	height = 0;
}
void cylinderType::cylinderVolume() {
	cVolume = height* areaC();
}
void cylinderType::cylinderSurfaceArea() {
	cSurfaceArea = (height*circumferenceC()) + (2 * areaC());
}
void cylinderType::printVolumeSurfaceArea() {
	cout << "Cylinder Volume is: " << cVolume << endl;
	cout << "Cylinder surface area is: " << cSurfaceArea << endl << endl;
}
void cylinderType::setheight(double h) {
	height = h;
}


int main() {

	cout << "\nTesting question 2......................................................." << endl;
	//Tests question 2

	cout << "initializing values\n";
	pointType;
	pointType point1;
	point1.printPoints();

	double pt1, pt2, pt3, pt4;
	//cout << "Enter points x and y to set (x,y) ";
	//cin >> pt1 >> pt2;
	pt1 = 0;
	pt2 = 10;
	pt3 = 0;
	pt4 = 0;
	// these points create a circle at the origin with radius 10.
	pointType point2;
	point2.setpoints(pt1, pt2);
	point2.printPoints();
	cout << "getting x from private to use " << point2.getXval() << endl;
	cout << "getting y from private to use " << point2.getYval() << endl;

	cout << "\nTesting question 3......................................................." << endl;
	//Tests question 3

	circleType;
	circleType circle1;
	circle1.setpoints(pt1, pt2);		//uses parent to set values
	circle1.setradius();				//uses child to set radius
	circle1.printPoints();				//uses parent to set values
	circle1.printradius();
	circle1.areaC();
	circle1.circumferenceC();		//uses child to set area and circumference
	circle1.areaCncircumferencePrint();	//used to print area and circumference

	cout << "\nTesting question 4......................................................." << endl;
	//Tests question 4

	cylinderType;
	cylinderType cylinder1;
	cylinder1.setpoints(pt1, pt2, pt3, pt4);		//uses parent to set values
	cylinder1.setradius();						//uses child to set radius
	cylinder1.printPoints();					//uses parent to set values
	cylinder1.printradius();
	cylinder1.areaC();
	cylinder1.circumferenceC();			    	//uses child to set area and circumference

	double ht;
	ht = 5;
	cylinder1.setheight(ht);
	cylinder1.cylinderVolume();
	cylinder1.cylinderSurfaceArea();
	cylinder1.printVolumeSurfaceArea();		//used to print area and circumference



	cout << "End of program " << endl << endl << endl;

	system("pause");
	return 0;
}