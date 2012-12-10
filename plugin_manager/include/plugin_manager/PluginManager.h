#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include <pluginlib/class_loader.h>
#include <interactive_perception_interface/PushPoint.h>
#include <interactive_perception_interface/StaticSegmentation.h>
#include <pcl_typedefs/pcl_typedefs.h>


class PluginManager
{
public:
    PluginManager();

    void estimatePushPoint(PointCloudConstPtr &input_cloud,
                                    PointCloudPtr &push_point_cloud);

    void staticSegment(PointCloudConstPtr &input_cloud,
                  std::vector<pcl::PointIndices> &segmentation_result,
                  std::vector<float> &probabilities);
};

#endif // PLUGINMANAGER_H
