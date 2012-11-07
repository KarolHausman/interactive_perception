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

int main(int argc, char** argv) {
	pluginlib::ClassLoader<interactive_perception_interface::StaticSegmentation> seg_loader(
			"interactive_perception_interface",
			"interactive_perception_interface::StaticSegmentation");

	interactive_perception_interface::StaticSegmentation* static_seg_impl1 =
			NULL;

	try {
		PointCloudConstPtr input_cloud;
		std::vector<pcl::PointIndices> segmentation_result;
		std::vector<float> probabilities;

		static_seg_impl1 = seg_loader.createClassInstance(
				"interactive_perception_example/StaticSegmentationImpl");
		static_seg_impl1->segment(input_cloud, segmentation_result,
				probabilities);

	} catch (pluginlib::PluginlibException& ex) {
		ROS_ERROR(
				"The plugin failed to load for some reason. Error: %s", ex.what());
	}

	return 0;
}
