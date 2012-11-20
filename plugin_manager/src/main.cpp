/*
 * main.cpp
 *
 * Created on: Oct 30, 2012
 * Author: Karol Hausman
 */

/* ** OLD STYLE: (DIRECT DEPENDENCY)

 #include <ros/ros.h>
 #include <interactive_perception_example/StaticSegmentationImpl.h>
 #include <interactive_perception_interface/StaticSegmentation.h>

 int main (int argc, char** argv)
 {
 ros::init (argc, argv, "test");
 ros::NodeHandle nh("~");

 interactive_perception_example::StaticSegmentationImpl seg_obj;
 ros::Rate loop_rate (100);
 PointCloudConstPtr input_cloud;
 std::vector<pcl::PointIndices> segmentation_result;
 std::vector<float> probabilities;
 seg_obj.segment(input_cloud,segmentation_result,probabilities);
 // while (ros::ok ())
 // {
 // ros::spinOnce ();
 // loop_rate.sleep ();
 // }
 return 0;

 }

 ***/

// New style (only plugin loader required)
#include <pluginlib/class_loader.h>
#include <interactive_perception_interface/StaticSegmentation.h>
#include <interactive_perception_interface/PushPoint.h>


int main(int argc, char** argv) {
	pluginlib::ClassLoader<interactive_perception_interface::StaticSegmentation> seg_loader_st_seg(
			"interactive_perception_interface",
			"interactive_perception_interface::StaticSegmentation");

	pluginlib::ClassLoader<interactive_perception_interface::PushPoint> seg_loader_push_point(
			"interactive_perception_interface",
			"interactive_perception_interface::PushPoint");

	interactive_perception_interface::StaticSegmentation* static_seg_impl =
			NULL;

	interactive_perception_interface::PushPoint* push_point_impl =
			NULL;

	try {
		PointCloudConstPtr input_cloud;
		PointCloudPtr output_cloud;

		std::vector<pcl::PointIndices> segmentation_result;
		std::vector<float> probabilities;

		static_seg_impl = seg_loader_st_seg.createClassInstance(
				"static_segmentation_example/StaticSegmentationImpl");
		static_seg_impl->segment(input_cloud, segmentation_result,
				probabilities);

		push_point_impl = seg_loader_push_point.createClassInstance(
				"push_point_example/PushPointImpl");
		push_point_impl->estimatePushPoint(input_cloud,output_cloud);

	} catch (pluginlib::PluginlibException& ex) {
		ROS_ERROR(
				"The plugin failed to load for some reason. Error: %s", ex.what());
	}

	return 0;
}
