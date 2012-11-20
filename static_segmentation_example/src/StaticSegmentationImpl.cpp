/*
 * StaticSegmentationImpl.cpp
 *
 * Created on: Nov 2, 2012
 * Author: Karol Hausman
 */

#include <ros/console.h>
#include "static_segmentation_example/StaticSegmentationImpl.h"
#include <pluginlib/class_list_macros.h>

//Declare the StaticSegmentationImpl as a StaticSegmentation class
PLUGINLIB_DECLARE_CLASS(static_segmentation_example, StaticSegmentationImpl,
		static_segmentation_example::StaticSegmentationImpl,
		interactive_perception_interface::StaticSegmentation)

namespace static_segmentation_example {
StaticSegmentationImpl::StaticSegmentationImpl() {
}

StaticSegmentationImpl::~StaticSegmentationImpl() {
}

void StaticSegmentationImpl::segment(PointCloudConstPtr &input_cloud,
		std::vector<pcl::PointIndices> &segmentation_result,
		std::vector<float> &probabilities) const {
	ROS_INFO_STREAM("static segmentation called");
}
}
;
