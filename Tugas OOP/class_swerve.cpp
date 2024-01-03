#include <iostream>
#include <vector>

class Swerve {
private:
    std::vector<std::vector<double>> velocityMatrix;
    double r_n = 0.26363;
    double x = 0.0;
    double y = 0.0;
    double theta = 0.0;

public:
    Swerve() : velocityMatrix(8, std::vector<double>(3, 0.0)) {}

    void velocityCommand(float vx, float vy, float omega) {
        velocityMatrix = {
            {vx, vy, omega},
            {vx, vy, omega},
            {vx, vy, omega},
            {vx, vy, omega},
            {vx, vy, omega},
            {vx, vy, omega},
            {vx, vy, omega},
            {vx, vy, omega}
        };
    }

    void updatePose(float deltaTime) {
        if (velocityMatrix.size() == 8 && velocityMatrix[0].size() == 3) {
            for (int i = 0; i < 8; ++i) {
                x += velocityMatrix[i][0] * deltaTime;
                y += velocityMatrix[i][1] * deltaTime;
                theta += velocityMatrix[i][2] * deltaTime;
            }

            std::cout << "Updated Pose (x, y, theta): " << x << " " << y << " " << theta << std::endl;
        } else {
            std::cerr << "Invalid velocityMatrix dimensions." << std::endl;
        }
    }
};

int main() {
    Swerve swerveRobot;
    swerveRobot.velocityCommand(1.0, 0.5, 0.2);
    swerveRobot.updatePose(0.1);

    return 0;
}
