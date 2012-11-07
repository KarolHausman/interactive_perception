/*
 * main_test.cpp
 *
 *  Created on: Oct 31, 2012
 *      Author: Karol Hausman
 */

#include <ros/ros.h>
#include "interactive_perception_interface/StaticSegmentation.h"
#include "interactive_perception_interface/FeatureExtraction.h"
#include "interactive_perception_interface/FullReconstruction.h"
#include "interactive_perception_interface/PushPoint.h"
#include "interactive_perception_interface/Tracker.h"

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>


int main(int argc, char **argv) {

	ros::init(argc, argv, "push_point");

	interactive_perception_interface::StaticSegmentation<pcl::PointXYZ>* stat;

	return 0;

}


