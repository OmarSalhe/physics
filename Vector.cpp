#include "Vector.h"
#include <stdexcept>
#include <cmath>

Vector::Vector(double x = 0.0, double y = 0.0, double z = 0.0): xComponent(x), yComponent(y), zComponent(z){}
Vector:: ~Vector(){}

// Dot Product: The magnitude of vector A's projection over vector B
// <a1, a2, a3> * <b1, b2, b3> = (a1 * b1) + (a2 * b2) + (a3 * b3)
double Vector::dotProduct(Vector& other) const{
    double b1 = other.xComponent;
    double b2 = other.yComponent;
    double b3 = other.zComponent;

    return (xComponent*b1) + (yComponent*b2) + (zComponent*b3);
}

// Cross Product: A vector orthogonal to both vector A and B
// <a1, a2, a3> x <b1, b2, b3> = <(a2*b3)-(a3*b2), -((a1*b3)-(a3*b1)), (a1*b2)-(a2*b1)>
Vector Vector::crossProduct(Vector& other) const{
    double b1 = other.xComponent;
    double b2 = other.yComponent; 
    double b3 = other.zComponent;

    double newX = (yComponent * b3) - (zComponent * b2);
    double newY = (zComponent * b1)-(xComponent * b3);
    double newZ = (xComponent * b2)-(yComponent * b1);

    return Vector(newX, newY, newZ);
}

// Magnitude: a scalar representing how 'long' the vector is
double Vector::magnitude() const{
    double xSquared = std::pow(xComponent, 2);
    double ySquared = std::pow(yComponent, 2);
    double zSquared = std::pow(zComponent, 2);

    return std::sqrt(xSquared + ySquared + zSquared);
}

Vector Vector::normalize() const{
    double norm = magnitude();
    return (norm == 0)? throw std::runtime_error("Cannot normalize a vector of length 0") : *this / norm;
}


// Scaling: Adjusting the magnitude of the vector, by some constant k
// k * <a1, a2, a3> = <k*a1, k*a2, k*a3>
Vector Vector::operator*(double k) const{
    return Vector(k * xComponent,
                  k * yComponent, 
                  k * zComponent);
}

Vector Vector::operator/(double k) const{
    if(k == 0){
        std::invalid_argument("Division by zero");
    }
    return Vector(xComponent / k,
                  yComponent / k,
                  zComponent / k);
}

// Addition: The resultant vector formed when adding two vectors's components
Vector Vector::operator+(const Vector& other) const{
    return Vector(xComponent + other.xComponent, 
                  yComponent + other.yComponent, 
                  zComponent + other.zComponent);
}

// Subtraction = Addition: <a1, a2, a3> - <b1, b2, b3> = <a1, a2, a3> + < -1*b1, -1*b2, -1*b3>
Vector Vector::operator-(const Vector& other) const{
    return Vector(xComponent - other.xComponent,
                  yComponent - other.yComponent,
                  zComponent - other.zComponent);
}
Vector& Vector::operator+=(const Vector& other){
    xComponent += other.xComponent;
    yComponent += other.yComponent;
    zComponent += other.zComponent;

    return *this;
}

Vector& Vector::operator-=(const Vector& other){
    xComponent -= other.xComponent;
    yComponent -= other.yComponent;
    zComponent -= other.zComponent;

    return *this;
}