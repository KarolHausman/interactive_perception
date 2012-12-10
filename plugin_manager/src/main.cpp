/*
 * main.cpp
 *
 * Created on: Oct 30, 2012
 * Author: Karol Hausman
 */



#include <plugin_manager/PluginManager.h>
#include <ros/ros.h>

int main(int argc, char** argv) {
  ros::init (argc, argv, "plugin_manager");
		PointCloudConstPtr input_cloud;
		PointCloudPtr output_cloud;

		std::vector<pcl::PointIndices> segmentation_result;
		std::vector<float> probabilities;
                PluginManager manager;

                ros::Rate loop_rate (1000);
                manager.estimatePushPoint(input_cloud,output_cloud);
                manager.staticSegment(input_cloud,segmentation_result,probabilities);

                  while(ros::ok())
                  {
                    if(manager.mode_==PluginManager::PUSH_POINT)
                        manager.estimatePushPoint(input_cloud,output_cloud);
                    if(manager.mode_==PluginManager::STATIC_SEGMENTATION)
                        manager.staticSegment(input_cloud,segmentation_result,probabilities);

                    ros::spinOnce();
                    loop_rate.sleep();
                  }


	return 0;
}
