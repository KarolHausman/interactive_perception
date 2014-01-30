#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include <pluginlib/class_loader.h>
#include <interactive_perception_interface/PushPoint.h>
#include <interactive_perception_interface/StaticSegmentation.h>
#include <interactive_perception_interface/FeatureExtraction.h>
#include <interactive_perception_interface/Manipulation.h>



#include <dynamic_reconfigure/server.h>
#include "../../cfg/cpp/plugin_manager/PluginManagerConfig.h"

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

    /*
     * estimates the point where a robot needs to push. Implementation is chosen in the Dynamic Reconfigure
     */
    template<typename PointType>
    void estimatePushPoint(const typename pcl::PointCloud<PointType>::ConstPtr &input_cloud,
                           typename pcl::PointCloud<PointType>::Ptr &push_point_cloud);
    /*
     * load the point cloud. Point cloud name is chosen in the Dynamic Reconfigure
     */
    template<typename PointType>
    void loadPointCloud(typename pcl::PointCloud<PointType>::Ptr &loaded_point_cloud);

    /*
     * performs static segmentation of a point cloud. Implementation is chosen in the Dynamic Reconfigure
     */
    template<typename PointType>
    void staticSegment(const typename pcl::PointCloud<PointType>::ConstPtr &input_cloud,
                       std::vector<pcl::PointIndices> &segmentation_result,
                       std::vector<float> &probabilities);

    /*
     * Spins the visualizer
     */
    void spinVisualizer();

private:

    /*
     * Dynamic reconfigure callback
     */
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
