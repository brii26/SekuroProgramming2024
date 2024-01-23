#include "ros/ros.h"
#include "package/topic.h"

int main(int argc, char **argv){
    ros::init(argc,argv,"publisher_node_cpp");

    ros::NodeHandle nh;

    ros::Publisher data_publisher = nh.advertise<package::topic>("cpp_topic", 1000);

    ros::Rate loop_rate(1); //1hz

    while(ros::ok()){
        package::topic send;

        send.usia = 18;
        send.tinggi = 1.68;
        send.nama = "Brian Ricardo Tamin";
        send.kehadiran = true;

        ROS_INFO("nama: %s", send.nama.c_str());
        ROS_INFO("usia: %ld", send.usia);
        ROS_INFO("tinggi: %f", send.tinggi);
        ROS_INFO("kehadiran: %s\n", send.kehadiran ? "hadir" : "tidak hadir");

        data_publisher.publish(send);

        ros::spinOnce();
        loop_rate.sleep();
    }


    return 0 ;
}