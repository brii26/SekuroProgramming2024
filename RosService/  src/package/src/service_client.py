#!/usr/bin/env python

import rospy
from package.srv import count_magnitude

def service_client(komponenx, komponeny, komponenz):
    # Inisialisasi ros node
    rospy.init_node('service_client')
    rospy.wait_for_service('count_magnitude')

    try:
    
        count_magnitude_service = rospy.ServiceProxy('count_magnitude', count_magnitude)

        # service request
        request = count_magnitude._request_class()
        request.komponenx = komponenx
        request.komponeny = komponeny
        request.komponenz = komponenz

        # service call
        response = count_magnitude_service(request)

        # result display
        rospy.loginfo("Magnitude : %f" % response.magnitude)

    except rospy.ServiceException as e:
        rospy.logerr("Service call failed %s" % e)

if __name__ == "__main__":
    # input user
    komponenx = int(input("input X: "))
    komponeny = int(input("input Y: "))
    komponenz = int(input("input Z: "))


    service_client(komponenx, komponeny, komponenz)
