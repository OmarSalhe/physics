#ifndef PHYSICSOBJECT_H
#define PHYSICSOBJECT_H
#include "Vector.h"

class PhysicsObject {
    public:
        PhysicsObject(double mass, double time = 0, Vector position, Vector velocity, Vector acceleration, Vector netForce);
        ~PhysicsObject();

        void applyForce(Vector force);
        void update();

        Vector getPosition() const;

    private:
        double mass, time;
        Vector position, velocity, acceleration, netForce;

        void rungeKutta();
        void clearForce();

        Vector calculateMomentum() const;
        double calculateKineticEnergy() const;
        Vector velocityFromKineticEnergy(double KE);
};

#endif

