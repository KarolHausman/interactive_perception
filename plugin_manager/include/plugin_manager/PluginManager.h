#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include <pluginlib/class_loader.h>
#include <interactive_perception_interface/PushPoint.h>
#include <interactive_perception_interface/StaticSegmentation.h>

#include <dynamic_reconfigure/server.h>
#include "../../cfg/cpp/plugin_manager/PluginManagerConfig.h"

#include <pcl_typedefs/pcl_typedefs.h>


class PluginManager
{
public:
    PluginManager();

    enum Mode{
        INIT=0,
        PUSH_POINT=1,
        STATIC_SEGMENTATION=2
    };

    void estimatePushPoint(PointCloudConstPtr &input_cloud,
                                    PointCloudPtr &push_point_cloud);

    void staticSegment(PointCloudConstPtr &input_cloud,
                  std::vector<pcl::PointIndices> &segmentation_result,
                  std::vector<float> &probabilities);
    Mode mode_;
private:

    void reconfigCallback (plugin_manager::PluginManagerConfig &config,
            uint32_t level);

    dynamic_reconfigure::Server<plugin_manager::PluginManagerConfig> reconfig_srv_;
    dynamic_reconfigure::Server<plugin_manager::PluginManagerConfig>::CallbackType
          reconfig_callback_;
    ros::NodeHandle nh_;

};

#endif // PLUGINMANAGER_H
