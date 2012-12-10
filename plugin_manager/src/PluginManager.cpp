#include "plugin_manager/PluginManager.h"

PluginManager::PluginManager()
{
}

void PluginManager::estimatePushPoint(PointCloudConstPtr &input_cloud,
                                 PointCloudPtr &push_point_cloud){

    pluginlib::ClassLoader<interactive_perception_interface::PushPoint<pcl::PointXYZRGB> > seg_loader_push_point(
                    "interactive_perception_interface",
                    "interactive_perception_interface::PushPoint");


    interactive_perception_interface::PushPoint<PointType>* push_point_impl =
                    NULL;

    try{
        push_point_impl = seg_loader_push_point.createClassInstance(
                        "push_point_example/PushPointImpl");
        push_point_impl->estimatePushPoint(input_cloud,push_point_cloud);

    } catch (pluginlib::PluginlibException& ex) {
        ROS_ERROR(
                        "The plugin PushPoint failed to load for some reason. Error: %s", ex.what());
    }

}

void PluginManager::staticSegment(PointCloudConstPtr &input_cloud,
              std::vector<pcl::PointIndices> &segmentation_result,
              std::vector<float> &probabilities){


    pluginlib::ClassLoader<interactive_perception_interface::StaticSegmentation> seg_loader_st_seg(
                    "interactive_perception_interface",
                    "interactive_perception_interface::StaticSegmentation");

    interactive_perception_interface::StaticSegmentation* static_seg_impl =
                    NULL;
    try{
        static_seg_impl = seg_loader_st_seg.createClassInstance(
                        "static_segmentation_example/StaticSegmentationImpl");
        static_seg_impl->segment(input_cloud, segmentation_result,
                        probabilities);
    } catch (pluginlib::PluginlibException& ex) {
        ROS_ERROR(
                        "The plugin failed to load for some reason. Error: %s", ex.what());
    }


}
