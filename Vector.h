#ifndef VECTOR_H
#define VECTOR_H

struct Vector{
        double xComponent, yComponent, zComponent;
        Vector(double x = 0, double y = 0, double z = 0): xComponent(x), yComponent(y), zComponent(z) {};

        double dotProduct(Vector& other) const;
        Vector crossProduct(Vector& other) const;
        double magnitude() const;

        Vector normalize() const;
        Vector reflect() const;

        Vector operator+(const Vector& other) const;
        Vector operator-(const Vector& other) const;
        Vector operator*(double k) const;
        Vector operator/(double k) const;
        Vector& operator+=(const Vector& other);
        Vector& operator-=(const Vector& other);
};
#endif