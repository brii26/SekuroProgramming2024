#include <iostream>

class LinearLine {
private:
    float x1, y1, x2, y2;

public:
    LinearLine(float x1, float y1, float x2, float y2) {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }
    
    //Menghitung gradien
    float gradient() {
        return (y2 - y1) / (x2 - x1);
    }

    float y_intercept() {
        return y1 - gradient() * x1;
    }

    void operator+(float a) {
        // Geser garis linear sejauh a pada sumbu x
        x1 += a;
        x2 += a;
    }

    void printEquation() {
        std::cout << "y = " << gradient() << "x + " << y_intercept() << std::endl;
    }

    void printPoints() {
        std::cout << "(x1, y1) = (" << x1 << ", " << y1 << ")" << std::endl;
        std::cout << "(x2, y2) = (" << x2 << ", " << y2 << ")" << std::endl;
    }
};

int main() {
    LinearLine line(1.0f, 8.0f, 2.0f, 3.0f);
    int a = 3;

    std::cout << "Sebelum digeser:" << std::endl;
    line.printPoints();
    std::cout << "Gradient = " << line.gradient() << std::endl;
    std::cout << "y_intercept = " << line.y_intercept() << std::endl;
    line.printEquation();

    // Geser garis linear sejauh a pada sumbu x
    line + a;

    std::cout << std::endl <<"Setelah digeser sejauh " << a << " unit:" << std::endl;
    line.printPoints();
    std::cout << "Gradient = " << line.gradient() << std::endl;
    std::cout << "y_intercept = " << line.y_intercept() << std::endl;
    line.printEquation();

    return 0;
}
