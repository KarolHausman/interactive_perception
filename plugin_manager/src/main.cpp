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
      pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr input_cloud(new pcl::PointCloud<pcl::PointXYZRGB>);
      pcl::PointCloud<pcl::PointXYZRGB>::Ptr output_cloud(new pcl::PointCloud<pcl::PointXYZRGB>);


    std::vector<pcl::PointIndices> segmentation_result;
    std::vector<float> probabilities;
    PluginManager manager;

    manager.loadPointCloud<pcl::PointXYZRGB>(output_cloud);
    ros::Rate loop_rate (1000);

    //run everything once initially - it is not neccessary
    manager.estimatePushPoint<pcl::PointXYZRGB>(input_cloud,output_cloud);
    manager.staticSegment<pcl::PointXYZRGB>(input_cloud,segmentation_result,probabilities);

    while(ros::ok())
    {
        ROS_DEBUG_STREAM("manager mode"<<manager.getMode());
        if((manager.getMode()==PluginManager::PUSH_POINT)||(manager.getMode()==PluginManager::ALL)){
            manager.estimatePushPoint<pcl::PointXYZRGB>(input_cloud,output_cloud);
        }
        if((manager.getMode()==PluginManager::STATIC_SEGMENTATION)||(manager.getMode()==PluginManager::ALL))
            manager.staticSegment<pcl::PointXYZRGB>(input_cloud,segmentation_result,probabilities);

        manager.spinVisualizer();
        ros::spinOnce();
        loop_rate.sleep();
    }


    return 0;
}
