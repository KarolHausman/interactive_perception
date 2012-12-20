/*
 * StaticSegmentation.h
 *
 *  Created on: Oct 31, 2012
 *      Author: Karol Hausman
 */

#ifndef STATICSEGMENTATION_H_
#define STATICSEGMENTATION_H_

#include <pcl/point_types.h>
#include <pcl/PointIndices.h>

namespace interactive_perception_interface {

template<typename PointType>
class StaticSegmentation {
public:
    typedef typename pcl::PointCloud<PointType> PointCloud;
    typedef typename PointCloud::Ptr PointCloudPtr;
    typedef typename PointCloud::ConstPtr PointCloudConstPtr;
    StaticSegmentation(){}
    virtual ~StaticSegmentation(){}

    virtual void segment(const PointCloudConstPtr &input_cloud,
                         std::vector<pcl::PointIndices> &segmentation_result,
                         std::vector<float> &probabilities){}

    virtual void segment(const PointCloudConstPtr &input_cloud,
                         std::vector<pcl::PointIndices> &segmentation_result){}
};

} /* namespace interactive_perception_interface */
#endif /* STATICSEGMENTATION_H_ */
