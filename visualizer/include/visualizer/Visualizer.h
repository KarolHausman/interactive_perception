#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <pcl_typedefs/pcl_typedefs.h>
#include <ros/ros.h>

class VisualizerImpl;
class Visualizer
{
public:

    Visualizer();
    ~Visualizer();

    void addPointCloud(PointCloudPtr& input_cloud);
    void spinOnce();

private:
    VisualizerImpl * Impl;
};

#endif // VISUALIZER_H
