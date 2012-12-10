/*
 * main.cpp
 *
 * Created on: Oct 30, 2012
 * Author: Karol Hausman
 */



#include <plugin_manager/PluginManager.h>

int main(int argc, char** argv) {

		PointCloudConstPtr input_cloud;
		PointCloudPtr output_cloud;

		std::vector<pcl::PointIndices> segmentation_result;
		std::vector<float> probabilities;


                PluginManager manager;
                manager.estimatePushPoint(input_cloud,output_cloud);
                manager.staticSegment(input_cloud,segmentation_result,probabilities);


	return 0;
}
