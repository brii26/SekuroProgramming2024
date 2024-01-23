#include "ros/ros.h"
#include "package/topic.h"

void messageCallback(const package::topic::ConstPtr &msg) {

    ROS_INFO("PESAN : ");
    ROS_INFO("Nama = %s", msg->nama.c_str());
    ROS_INFO("Usia = %ld", msg->usia);
    ROS_INFO("Tinggi = %f", msg->tinggi);
    ROS_INFO("Kehadiran = %s\n", msg->kehadiran ? "hadir" : "tidak hadir");
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "subscriber_node_cpp");

    ros::NodeHandle nh;

    ros::Subscriber data_subscriber = nh.subscribe("cpp_topic", 1000, messageCallback);

    ros::spin();

    return 0;
}
