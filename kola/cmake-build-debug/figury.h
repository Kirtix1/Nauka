#ifndef FIGURY_H
#define FIGURY_H

#include <iostream>
#include <cmath>

class Figure {
public:
    virtual void display_name() const = 0;
    virtual double perimeter() const = 0;
    virtual double area() const = 0;
    static int getNumberOfFigures();

protected:
    Figure();
    static int numberOfFigures;
};

class Rectangle : public Figure {
public:
    Rectangle(double x, double y, double width, double height);
    void display_name() const override;
    double perimeter() const override;
    double area() const override;

private:
    double x, y, width, height;
};

class Square : public Figure {
public:
    Square(double x, double y, double side);
    void display_name() const override;
    double perimeter() const override;
    double area() const override;

private:
    double x, y, side;
};

class Circle : public Figure {
public:
    Circle(double x, double y, double radius);
    void display_name() const override;
    double perimeter() const override;
    double area() const override;

private:
    double x, y, radius;
};

class vector {
public:
    vector(double x, double y);
    vector(double x1, double y1, double x2, double y2);
    vector add(const vector& other) const;
    vector substract(const vector& other) const;
    double lenght() const;
    void display() const;

private:
    double x, y;
};

#endif // FIGURY_H
