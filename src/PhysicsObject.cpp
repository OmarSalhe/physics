#include "PhysicsObject.h"
#include "Vector.h"
#include <cmath>

PhysicsObject::PhysicsObject(double m, Vector pos, Vector vel, Vector acc, Vector net): mass(mass), position(pos), velocity(vel), acceleration(acc), netForce(net){}
PhysicsObject::~PhysicsObject(){}

void PhysicsObject::updatePosition(){
updateVelocity();

// v(x, t) = dx/dt = v + x''(t)*t
double h = .001;

double ax = acceleration.getX();
double ay = acceleration.getY();
double az = acceleration.getZ();

double k1x = velocity.getX();
double k2x = k1x + ax * (h/2);
double k3x = k2x + ax * (h/2);
double k4x = k3x + ax * h;

double k1y = velocity.getX();
double k2y = k1y + ay * (h/2);
double k3y = k2y + ay * (h/2);
double k4y = k3y + ay * h;

double k1z = velocity.getZ();
double k2z = k1z + az * (h/2);
double k3z = k2z + az * (h/2);
double k4z = k3z + az * h;

position.setX(position.getX() + (h/6) * (k1x + 2*k2x + 2*k3x + k4x));
position.setY(position.getY() + (h/6) * (k1y + 2*k2y + 2*k3y + k4y));
position.setY(position.getZ() + (h/6) * (k1z + 2*k2z + 2*k3z + k4z));
}

double PhysicsObject::distanceTo(PhysicsObject& other) const{
    return (position - other.getPosition()).magnitude();
}

void PhysicsObject::updateVelocity(){
    updateAcceleration();
    double h = .001;
    velocity += (acceleration) * h;
}

void PhysicsObject::updateAcceleration(){
    clearForce();
    // calculateForce();
}

void PhysicsObject::clearForce(){
    netForce.setX(0);
    netForce.setY(0);
    netForce.setZ(0);
}