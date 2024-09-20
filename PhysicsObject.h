#ifndef PHYSICSOBJECT_H
#define PHYSICSOBJECT_H
#include "Vector.h"

class PhysicsObject {
    public:
        PhysicsObject(double mass, double time = 0, Vector position, Vector velocity, Vector acceleration, Vector netForce);
        ~PhysicsObject();

        Vector getPosition() const;
        Vector getVelocity() const;
        Vector getAcceleration() const;

        void applyForce(Vector force);
        void updatePosition();

    private:
        double mass, time;
        Vector position, velocity, acceleration, netForce;

        void clearForce();
        double calculateVelocity();
        double calculateAcceleration();
        Vector calculateMomentum() const;
        double calculateKineticEnergy() const;
        Vector velocityFromKineticEnergy(double KE);
        void updateVelocity();
};

#endif

