#include "ros/ros.h"
#include "package/count_magnitude.h"
#include <cmath>

bool add(package::count_magnitude::Request &req,package::count_magnitude::Response &resp) {
    // mengolah data
    resp.magnitude = sqrt(req.komponenx*req.komponenx + req.komponeny*req.komponeny + req.komponenz*req.komponenz);


    // mencetak hasil data
    ROS_INFO("Nilai komponen X : %ld" , (long int) req.komponenx);
    ROS_INFO("Nilai komponen Y : %ld" , (long int) req.komponeny);
    ROS_INFO("Nilai komponen Z : %ld" , (long int) req.komponenz);
    ROS_INFO("Nilai magnitude : %lf\n", (float) resp.magnitude);
    return true;
}

int main(int argc, char **argv){
    // inisialisasi node
    ros::init(argc,argv,"service_server");

    // inisialisasi handler node
    ros::NodeHandle nh;

    // inisialisasi server dari handler
    ros::ServiceServer server = nh.advertiseService("count_magnitude",add);
    ROS_INFO("Ready to count the magnitude.");
    ros::spin();

    return 0;
}
