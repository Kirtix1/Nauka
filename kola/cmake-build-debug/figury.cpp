#include "figury.h"

// Initialize static member of Figure class
int Figure::numberOfFigures = 0;

Figure::Figure() {
    numberOfFigures++;
}

int Figure::getNumberOfFigures() {
    return numberOfFigures;
}

Rectangle::Rectangle(double x, double y, double width, double height)
        : x(x), y(y), width(width), height(height) {}

void Rectangle::display_name() const {
    std::cout << "Rectangle" << std::endl;
}

double Rectangle::perimeter() const {
    return 2 * (width + height);
}

double Rectangle::area() const {
    return width * height;
}

Square::Square(double x, double y, double side)
        : x(x), y(y), side(side) {}

void Square::display_name() const {
    std::cout << "Square" << std::endl;
}

double Square::perimeter() const {
    return 4 * side;
}

double Square::area() const {
    return side * side;
}

Circle::Circle(double x, double y, double radius)
        : x(x), y(y), radius(radius) {}

void Circle::display_name() const {
    std::cout << "Circle" << std::endl;
}

double Circle::perimeter() const {
    return 2 * M_PI * radius;
}

double Circle::area() const {
    return M_PI * radius * radius;
}

vector::vector(double x, double y)
        : x(x), y(y) {}

vector::vector(double x1, double y1, double x2, double y2)
        : x(x2 - x1), y(y2 - y1) {}

vector vector::add(const vector& other) const {
    return vector(x + other.x, y + other.y);
}

vector vector::substract(const vector& other) const {
    return vector(x - other.x, y - other.y);
}

double vector::lenght() const {
    return std::sqrt(x * x + y * y);
}

void vector::display() const {
    std::cout << "(" << x << ", " << y << ")" << std::endl;
}
