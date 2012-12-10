/*
 * PushPointImpl.h
 *
 *  Created on: Nov 19, 2012
 *      Author: Karol Hausman
 */

#ifndef PUSHPOINTIMPL_H_
#define PUSHPOINTIMPL_H_

#include <ros/console.h>
#include <pcl/point_types.h>
#include <pluginlib/class_list_macros.h>
#include <interactive_perception_interface/PushPoint.h>


namespace push_point_example {


class PushPointImpl :public interactive_perception_interface::PushPoint<pcl::PointXYZRGB> {
public:
	PushPointImpl();
	virtual ~PushPointImpl();
	void estimatePushPoint(PointCloudConstPtr &input_cloud,
				PointCloudPtr &push_point_cloud)const;
};

} /* namespace push_point_example */
#endif /* PUSHPOINTIMPL_H_ */
