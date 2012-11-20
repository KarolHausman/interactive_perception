/*
 * PushPointImpl.cpp
 *
 *  Created on: Nov 19, 2012
 *      Author: Karol Hausman
 */

#include "push_point_example/PushPointImpl.h"

PLUGINLIB_DECLARE_CLASS(push_point_example, PushPointImpl,
		push_point_example::PushPointImpl,
		interactive_perception_interface::PushPoint)

namespace push_point_example {

PushPointImpl::PushPointImpl() {

}

PushPointImpl::~PushPointImpl() {
}

void PushPointImpl::estimatePushPoint(PointCloudConstPtr &input_cloud,
				PointCloudPtr &push_point_cloud)const{

	ROS_INFO_STREAM("estimate push point called");
	}

} /* namespace push_point_example */
