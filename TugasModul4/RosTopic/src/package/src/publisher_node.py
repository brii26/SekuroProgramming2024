#!/usr/bin/env python

import rospy
from package.msg import topic

def publisher_node_py():
    rospy.init_node('publisher_node_py', anonymous=True)

    pub_data = rospy.Publisher('py_topic', topic, queue_size=1000)

    loop_rate = rospy.Rate(1)

    while not rospy.is_shutdown():
        send = topic()
        send.usia = 18
        send.tinggi = 1.68
        send.nama = "Brian Ricardo Tamin"
        send.kehadiran = True

        rospy.loginfo("nama: %s", send.nama)
        rospy.loginfo("usia: %d", send.usia)
        rospy.loginfo("tinggi: %f", send.tinggi)
        rospy.loginfo("kehadiran: %s\n", "hadir" if send.kehadiran else "tidak hadir")

        pub_data.publish(send)

        loop_rate.sleep()

if __name__ == '__main__':
    try:
        publisher_node_py()
    except rospy.ROSInterruptException:
        pass
