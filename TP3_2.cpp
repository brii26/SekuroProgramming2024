#include <iostream>
#include <cmath>

class Shape {
public:
    virtual float calculateArea() = 0;
    virtual float calculateKeliling() = 0;
};

class Rectangle : public Shape {
private:
    float width;
    float length;

public:
    Rectangle(float width, float length) : width(width), length(length) {}

    float calculateArea() override {
        return width * length;
    }

    float calculateKeliling() override {
        return 2 * (width + length);
    }
};

int main() {
    Rectangle rect(5.0, 4.0);
    Shape* shape1 = &rect;

    // memanggil calculateArea() dan calculateKeliling() menggunakan pointer shape1
    std::cout << "Area: " << shape1->calculateArea() << std::endl;
    std::cout << "Keliling: " << shape1->calculateKeliling() << std::endl;

    return 0;
}
