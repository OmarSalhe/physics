#ifndef VECTOR_H
#define VECTOR_H

class Vector{
    public:
        Vector(double xVal = 0, double yVal = 0, double zVal = 0);
        ~Vector();

        double getX();
        double getY();
        double getZ;

        double dotProduct(Vector& other) const;
        Vector crossProduct(Vector& other) const;
        Vector scale(double k) const;
        double magnitude() const;
        Vector add(Vector& other) const;
        Vector subtract(Vector& other) const;

    private:
        double x, y, z;
};
#endif