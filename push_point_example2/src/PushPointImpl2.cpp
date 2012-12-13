/*
 * PushPointImpl2.cpp
 *
 *  Created on: Nov 19, 2012
 *      Author: Karol Hausman
 */

#include "push_point_example2/PushPointImpl2.h"

PLUGINLIB_DECLARE_CLASS(push_point_example2, PushPointImpl2,
		push_point_example2::PushPointImpl2,
		interactive_perception_interface::PushPoint<pcl::PointXYZRGB>)

namespace push_point_example2 {

PushPointImpl2::PushPointImpl2() {

}

PushPointImpl2::~PushPointImpl2() {
}

void PushPointImpl2::estimatePushPoint(PointCloudConstPtr &input_cloud,
				PointCloudPtr &push_point_cloud)const{

	ROS_INFO_STREAM("estimate push point 2nd implementation called");
	}

} /* namespace push_point_example2 */
