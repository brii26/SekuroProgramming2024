#ifndef SWERVE_HPP
#define SWERVE_HPP

#include <iostream>
#include <vector>
#include <cmath>

class Swerve {
private:
    double r_n = 0.26363;
    double x0 = 0.0;
    double y0 = 5.0;

    std::vector<std::vector<double>> velocityMatrix = {
        {1, 0, -r_n},
        {0, 1, r_n},
        {1, 0, -r_n},
        {0, 1, r_n},
        {1, 0, -r_n},
        {0, 1, r_n},
        {1, 0, -r_n},
        {0, 1, r_n}
    };

    std::vector<double> x;
    std::vector<double> y;
    std::vector<double> theta;
    std::vector<double> v1x;
    std::vector<double> v1y;
    std::vector<double> v2x;
    std::vector<double> v2y;
    std::vector<double> v3x;
    std::vector<double> v3y;
    std::vector<double> v4x;
    std::vector<double> v4y;
    std::vector<double> v1;
    std::vector<double> v2;
    std::vector<double> v3;
    std::vector<double> v4;

public:
    void calculateVelocities() {

        v1x.clear();
        v1y.clear();
        v2x.clear();
        v2y.clear();
        v3x.clear();
        v3y.clear();
        v4x.clear();
        v4y.clear();
        
        v1.clear();
        v2.clear();
        v3.clear();
        v4.clear();

        for (double t = 0.01; t <= 6.3; t += 0.01) {
            
            double vx = 48 * cos(t) * sin(t) * sin(t);
            double vy = 4 * sin(4 * t) + 6 * sin(3 * t) + 10 * sin(2 * t) - 13 * sin(t);
            double omega = 0.0;

            v1x.push_back(velocityMatrix[0][0] * vx + velocityMatrix[0][1] * vy + velocityMatrix[0][2] * omega);
            v1y.push_back(velocityMatrix[1][0] * vx + velocityMatrix[1][1] * vy + velocityMatrix[1][2] * omega);
            v2x.push_back(velocityMatrix[2][0] * vx + velocityMatrix[2][1] * vy + velocityMatrix[2][2] * omega);
            v2y.push_back(velocityMatrix[3][0] * vx + velocityMatrix[3][1] * vy + velocityMatrix[3][2] * omega);
            v3x.push_back(velocityMatrix[4][0] * vx + velocityMatrix[4][1] * vy + velocityMatrix[4][2] * omega);
            v3y.push_back(velocityMatrix[5][0] * vx + velocityMatrix[5][1] * vy + velocityMatrix[5][2] * omega);
            v4x.push_back(velocityMatrix[6][0] * vx + velocityMatrix[6][1] * vy + velocityMatrix[6][2] * omega);
            v4y.push_back(velocityMatrix[7][0] * vx + velocityMatrix[7][1] * vy + velocityMatrix[7][2] * omega);

            v1.push_back(sqrt(v1x.back() * v1x.back() + v1y.back() * v1y.back()));
            v2.push_back(sqrt(v2x.back() * v2x.back() + v2y.back() * v2y.back()));
            v3.push_back(sqrt(v3x.back() * v3x.back() + v3y.back() * v3y.back()));
            v4.push_back(sqrt(v4x.back() * v4x.back() + v4y.back() * v4y.back()));
        }
    }

    void updatePose(float deltaTime) {
        
        x.clear();
        y.clear();
        theta.clear();

        
        double x_prev = x0;
        double y_prev = y0;
        double theta_prev = 0.0;

        for (double t = 0.01; t <= 6.3; t += 0.01) {
            
            double vx = v1x.back();
            double vy = v1y.back();
            double omega = 0.0;  

            double x_next = x_prev + vx * t;
            double y_next = y_prev + vy * t;
            double theta_next = theta_prev + omega * t;

            x.push_back(x_next);
            y.push_back(y_next);
            theta.push_back(theta_next);

            x_prev = x_next;
            y_prev = y_next;
            theta_prev = theta_next;
        }
    }

    const std::vector<double>& getX() const {
        return x;
    }

    const std::vector<double>& getY() const {
        return y;
    }
};

#endif
