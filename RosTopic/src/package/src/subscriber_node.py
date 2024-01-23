#!/usr/bin/env python

import rospy
from package.msg import topic

def callback(msg):
    rospy.loginfo("PESAN:")
    rospy.loginfo("Nama= %s", msg.nama)
    rospy.loginfo("Usia= %d", msg.usia)
    rospy.loginfo("Tinggi= %f", msg.tinggi)
    rospy.loginfo("Kehadiran= %s\n", "hadir" if msg.kehadiran else "tidak hadir")

def subscriber_node_py():
    rospy.init_node('subscriber_node_py', anonymous=True)

    rospy.Subscriber('py_topic', topic, callback)

    rospy.spin()

if __name__ == '__main__':
    subscriber_node_py()
