#include "PhysicsObject.h"
#include "Vector.h"

PhysicsObject::PhysicsObject(double t, double m, Vector pos, Vector vel, Vector acc, Vector net): mass(mass), time(t), position(pos), velocity(vel), acceleration(acc), netForce(net){}

PhysicsObject::~PhysicsObject(){}

void PhysicsObject::updatePosition(){
    double h = .001;
    double k1x, k1y, k1z, k2x, k2y, k2z, k3x, k3y, k3z, k4x, k4y, k4z;
    double x = position.getX(), y = position.getY(), z = position.getZ();

    // from the dx/dt = v:
    double k1x = 0;


}