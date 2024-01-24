#!/usr/bin/env python

import rospy
from package.srv import count_magnitude

def count(req):
    # Process and print data
    magnitude = (req.komponenx**2 + req.komponeny**2 + req.komponenz**2)**0.5
    rospy.loginfo("Nilai komponen X : %d" % req.komponenx)
    rospy.loginfo("Nilai komponen Y : %d" % req.komponeny)
    rospy.loginfo("Nilai komponen Z : %d\n" % req.komponenz)
    return magnitude

def count_magnitude_server():
    # Initialize node
    rospy.init_node("server")

    # Initialize server
    s = rospy.Service('count_magnitude', count_magnitude, count)
    rospy.loginfo("Ready to count the magnitude!")
    rospy.spin()

if __name__ == '__main__':
    count_magnitude_server()
