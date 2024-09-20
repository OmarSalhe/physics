#ifndef VECTOR_H
#define VECTOR_H

class Vector{
    public:
        Vector(double xVal = 0, double yVal = 0, double zVal = 0);
        ~Vector();

        double getX();
        double getY();
        double getZ();

        void setX(double newComponent);
        void setY(double newComponent);
        void setZ(double newComponent);

        double dotProduct(Vector& other) const;
        Vector crossProduct(Vector& other) const;
        double magnitude() const;

        Vector operator+(Vector& other) const;
        Vector operator-(Vector& other) const;
        Vector operator*(double k) const;

    private:
        double xComponent, yComponent, zComponent;
};
#endif