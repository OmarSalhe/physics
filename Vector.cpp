#include "Vector.h"
#include <cmath>

Vector::Vector(double x = 0.0, double y = 0.0, double z = 0.0): xComponent(x), yComponent(y), zComponent(z){}
Vector:: ~Vector(){}

//Setters
void Vector::setX(double newCompnent){
    xComponent = newCompnent;
}
void Vector::setY(double newCompnent){
    yComponent = newCompnent;
}
void Vector::setZ(double newCompnent){
    zComponent = newCompnent;
}

//Getters
double Vector::getX(){
    return xComponent;
}
double Vector::getY(){
    return yComponent;
}
double Vector::getZ(){    
    return zComponent;
}

// Dot Product: The magnitude of vector A's projection over vector B
// <a1, a2, a3> * <b1, b2, b3> = (a1 * b1) + (a2 * b2) + (a3 * b3)
double Vector::dotProduct(Vector& other) const{
    double b1 = other.getX();
    double b2 = other.getY();
    double b3 = other.getZ();

    return (xComponent*b1) + (yComponent*b2) + (zComponent*b3);
}

// Cross Product: A vector orthogonal to both vector A and B
// <a1, a2, a3> x <b1, b2, b3> = <(a2*b3)-(a3*b2), -((a1*b3)-(a3*b1)), (a1*b2)-(a2*b1)>
Vector Vector::crossProduct(Vector& other) const{
    double b1 = other.getX();
    double b2 = other.getY(); 
    double b3 = other.getZ();

    double newX = (yComponent*b3) - (zComponent*b2);
    double newY = (zComponent*b1)-(xComponent*b3);
    double newZ = (xComponent*b2)-(yComponent*b1);

    return Vector(newX, newY, newZ);
}

// Magnitude: a scalar representing how 'long' the vector is
double Vector::magnitude() const{
    double xSquared = std::pow(xComponent, 2);
    double ySquared = std::pow(yComponent, 2);
    double zSquared = std::pow(zComponent, 2);

    return std::sqrt(xSquared+ySquared+zSquared);
}

// Scaling: Adjusting the magnitude of the vector, by some constant k
// k * <a1, a2, a3> = <k*a1, k*a2, k*a3>
Vector Vector::operator*(double k) const{
    return Vector(k * xComponent, k * yComponent, k * zComponent);
}

// Addition: The resultant vector formed when adding two vectors's components
Vector Vector::operator+(Vector& other) const{
    return Vector(xComponent + other.xComponent, 
                  yComponent + other.xComponent, 
                  zComponent + other.zComponent);
}

// Subtraction = Addition: <a1, a2, a3> - <b1, b2, b3> = <a1, a2, a3> + < -1*b1, -1*b2, -1*b3>
Vector Vector::operator-(Vector& other) const{
    return Vector(xComponent - other.xComponent,
                  yComponent - other.yComponent,
                  zComponent - other.zComponent);
}