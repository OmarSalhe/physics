#ifndef VECTOR_H
#define VECTOR_H

class Vector{
public:
        Vector(double x = 0, double y = 0, double z = 0): xComponent(x), yComponent(y), zComponent(z) {};
        // Getters
        double getX() const { return xComponent; }
        double getY() const { return yComponent; }
        double getZ() const { return zComponent; }

        // Setters
        void setX(double x) { xComponent = x; }
        void setY(double y) { yComponent = y; }
        void setZ(double z) { zComponent = z; }
        
        double dotProduct(const Vector& other) const;
        Vector crossProduct(const Vector& other) const;
        double magnitude() const;

        Vector normalize() const;
        Vector reflect() const;

        Vector operator+(const Vector& other) const;
        Vector operator-(const Vector& other) const;
        Vector operator*(double k) const;
        Vector operator/(double k) const;
        Vector& operator+=(const Vector& other);
        Vector& operator-=(const Vector& other);

private:
        double xComponent;
        double yComponent; 
        double zComponent;
};
#endif