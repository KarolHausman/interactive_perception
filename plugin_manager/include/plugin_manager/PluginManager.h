#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include <pluginlib/class_loader.h>
#include <interactive_perception_interface/PushPoint.h>
#include <interactive_perception_interface/StaticSegmentation.h>

#include <dynamic_reconfigure/server.h>
#include "../../cfg/cpp/plugin_manager/PluginManagerConfig.h"

#include <pcl_typedefs/pcl_typedefs.h>
#include <visualizer/Visualizer.h>


class PluginManager
{
public:
    PluginManager();

    enum Mode{
        INIT=0,
        ALL=1,
        PUSH_POINT=2,
        STATIC_SEGMENTATION=3
    };

    Mode getMode(){return mode_;}

    void setMode(Mode mode){mode_=mode;}

    void estimatePushPoint(PointCloudConstPtr &input_cloud,
                           PointCloudPtr &push_point_cloud);

    void loadPointCloud(PointCloudPtr &loaded_point_cloud);

    void staticSegment(PointCloudConstPtr &input_cloud,
                       std::vector<pcl::PointIndices> &segmentation_result,
                       std::vector<float> &probabilities);

    void spinVisualizer();

private:

    void reconfigCallback (plugin_manager::PluginManagerConfig &config,
                           uint32_t level);

    dynamic_reconfigure::Server<plugin_manager::PluginManagerConfig> reconfig_srv_;
    dynamic_reconfigure::Server<plugin_manager::PluginManagerConfig>::CallbackType
    reconfig_callback_;
    ros::NodeHandle nh_;
    std::vector<std::string> push_point_vector_;
    std::string push_point_impl_;
    Mode mode_;
    Visualizer visualizer_;
    std::string cloud_name_;


};

#endif // PLUGINMANAGER_H
