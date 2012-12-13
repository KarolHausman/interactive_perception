
#include "visualizer/VisualizerImpl.h"
#include "visualizer/Visualizer.h"
Visualizer::Visualizer()
{
    Impl = new VisualizerImpl();
}

Visualizer::~Visualizer() { delete Impl; }

void Visualizer::addPointCloud(PointCloudPtr& input_cloud){
    Impl->addPointCloud(input_cloud);
}

void Visualizer::spinOnce(){
    Impl->spinOnce();
}



