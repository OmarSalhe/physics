#ifndef PHYSICSOBJECT_H
#define PHYSICSOBJECT_H
#include "Vector.h"

class PhysicsObject {
public:
    PhysicsObject(double mass, Vector position, Vector velocity, Vector acceleration, Vector netForce);
    // Getters
    Vector getPosition() const { return position; }
    Vector getVelocity() const { return velocity; }
    Vector getAcceleration() const { return acceleration; }

    double distanceTo(PhysicsObject& other) const;

    void applyForce(Vector force);
    void updatePosition();

private:
    double mass, time;
    Vector position, velocity, acceleration, netForce;
    void clearForce();
    void updateAcceleration();
    Vector calculateMomentum() const;
    double calculateKineticEnergy() const;
    Vector velocityFromKineticEnergy(double KE);
    void updateVelocity();
};
#endif

