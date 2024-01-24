#include "ros/ros.h"
#include "package/count_magnitude.h"
#include <cstdlib>

int main(int argc, char **argv) {
    // Inisialisasi node
    ros::init(argc, argv, "service_client");

    // Inisialisasi handler node
    ros::NodeHandle nh;

    // Membuat client untuk memanggil service
    ros::ServiceClient client = nh.serviceClient<package::count_magnitude>("count_magnitude");

    // Membuat objek pesan untuk request
    package::count_magnitude srv;

    // input user
    std::cout << "input komponen X: ";
    std::cin >> srv.request.komponenx;

    std::cout << "input komponen Y: ";
    std::cin >> srv.request.komponeny;

    std::cout << "input komponen Z: ";
    std::cin >> srv.request.komponenz;

    
    if (client.call(srv)) {
        ROS_INFO("Magnitude : %f", srv.response.magnitude);
    } else {
        ROS_ERROR("Service call failed");
        return 1;
    }

    return 0;
}
