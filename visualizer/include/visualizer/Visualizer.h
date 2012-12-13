#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <ros/ros.h>
//#include <pcl/visualization/pcl_visualizer.h>

//template<typename PointType>
class Visualizer
{
public:
//    typedef pcl::PointCloud<PointType> Cloud;
//    typedef typename Cloud::Ptr CloudPtr;
//    typedef typename Cloud::ConstPtr CloudConstPtr;

    Visualizer():
        point_cloud_number_(0)
    {
//        viewer_.initCameraParameters();
//        viewer_.setBackgroundColor (0, 0, 0);
    }


//    void addPointCloud(CloudConstPtr input_cloud);

private:
//    pcl::visualization::PCLVisualizer viewer_;
    std::string point_cloud_name_;
    int point_cloud_number_;
};

#endif // VISUALIZER_H
