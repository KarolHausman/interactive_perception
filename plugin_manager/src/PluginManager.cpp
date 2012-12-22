#include "plugin_manager/PluginManager.h"
#include <pcl/io/pcd_io.h>


PluginManager::PluginManager():
    nh_("~/plugin_manager"),
    visualizer_()
{
    push_point_vector_.push_back("push_point_example/PushPointImpl");
    push_point_vector_.push_back("push_point_example2/PushPointImpl2");
    push_point_impl_=push_point_vector_[0];

    reconfig_callback_ = boost::bind (&PluginManager::reconfigCallback, this, _1, _2);
    reconfig_srv_.setCallback (reconfig_callback_);
    mode_=PluginManager::INIT;

}

void PluginManager::reconfigCallback (plugin_manager::PluginManagerConfig &config,
                                      uint32_t level){

    cloud_name_=config.cloud_name;

    if(config.manager_mode==1){
        setMode(PluginManager::ALL);
        ROS_INFO("Running all the steps...");

    }
    if(config.manager_mode==2){
        setMode(PluginManager::PUSH_POINT);
        ROS_INFO("Running push point estimation...");
    }
    if(config.manager_mode==3){
        setMode(PluginManager::STATIC_SEGMENTATION);
        ROS_INFO("Running static segmentation...");
    }

    if(config.push_point_mode == 0){
        push_point_impl_=push_point_vector_[0];
    }
    if(config.push_point_mode == 1){
        push_point_impl_=push_point_vector_[1];
    }
    config.manager_mode=0;

}

void PluginManager::loadPointCloud(PointCloudPtr &loaded_point_cloud){
    pcl::io::loadPCDFile(cloud_name_,*loaded_point_cloud);
}

template<typename PointType>
void PluginManager::estimatePushPoint(const typename pcl::PointCloud<PointType>::ConstPtr &input_cloud,
                                      typename pcl::PointCloud<PointType>::Ptr &push_point_cloud){

    pluginlib::ClassLoader<typename interactive_perception_interface::PushPoint<PointType> > seg_loader_push_point(
                "interactive_perception_interface",
                "interactive_perception_interface::PushPoint");


    typename interactive_perception_interface::PushPoint<PointType>* push_point_impl=NULL;
    try{
        push_point_impl = seg_loader_push_point.createClassInstance(
                    push_point_impl_);
        push_point_impl->estimatePushPoint(input_cloud,push_point_cloud);

    } catch (pluginlib::PluginlibException& ex) {
        ROS_ERROR(
                    "The plugin PushPoint failed to load for some reason. Error: %s", ex.what());
    }
    if(mode_!=PluginManager::ALL){
        setMode(PluginManager::INIT);
    }
    visualizer_.addPointCloud(push_point_cloud);
    visualizer_.spinOnce();
}

void PluginManager::spinVisualizer(){
    visualizer_.spinOnce();
}
template<typename PointType>
void PluginManager::staticSegment(const typename pcl::PointCloud<PointType>::ConstPtr &input_cloud,
                                  std::vector<pcl::PointIndices> &segmentation_result,
                                  std::vector<float> &probabilities){


    pluginlib::ClassLoader<typename interactive_perception_interface::StaticSegmentation<PointType> > seg_loader_st_seg(
                "interactive_perception_interface",
                "interactive_perception_interface::StaticSegmentation");

    typename interactive_perception_interface::StaticSegmentation<PointType>* static_seg_impl=NULL;
    try{
        static_seg_impl = seg_loader_st_seg.createClassInstance(
                    "static_segmentation_example/StaticSegmentationImpl");
        static_seg_impl->segment(input_cloud, segmentation_result,
                                 probabilities);
    } catch (pluginlib::PluginlibException& ex) {
        ROS_ERROR(
                    "The plugin failed to load for some reason. Error: %s", ex.what());
    }
    //no if because the last step
    setMode(PluginManager::INIT);

}

template void PluginManager::estimatePushPoint<pcl::PointXYZRGB>(const pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr &input_cloud,
pcl::PointCloud<pcl::PointXYZRGB>::Ptr &push_point_cloud);

template void PluginManager::staticSegment<pcl::PointXYZRGB>(const pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr &input_cloud,
std::vector<pcl::PointIndices> &segmentation_result,
std::vector<float> &probabilities);
