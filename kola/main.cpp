#include <iostream>

#include "cmake-build-debug/figury.h"

int main() {
    Rectangle rectangle(0, 0, 5, 3);
    Square square(0, 0, 4);
    Circle circle(0, 0, 2);

    rectangle.display_name();
    std::cout << "Perimeter: " << rectangle.perimeter() << std::endl;
    std::cout << "Area: " << rectangle.area() << std::endl;

    square.display_name();
    std::cout << "Perimeter: " << square.perimeter() << std::endl;
    std::cout << "Area: " << square.area() << std::endl;

    circle.display_name();
    std::cout << "Perimeter: " << circle.perimeter() << std::endl;
    std::cout << "Area: " << circle.area() << std::endl;

    std::cout << "Number of figures: " << Figure::getNumberOfFigures() << std::endl;

    vector vec1(1, 2);
    vector vec2(3, 4);
    vector vec3(0, 0, 1, 2);
    vector sum = vec1.add(vec2);
    vector difference = vec1.substract(vec2);
    double length1 = vec1.lenght();
    double length2 = vec2.lenght();
    double length3 = vec3.lenght();

    vec1.display();
    vec2.display();
    vec3.display();

    std::cout << "sum: ";
    sum.display();
    std::cout << "difference: ";
    difference.display();
    std::cout << "length of vec1: " << length1 << std::endl;
    std::cout << "length of vec2: " << length2 << std::endl;
    std::cout << "length of vec3: " << length3 << std::endl;

    return 0;
}
