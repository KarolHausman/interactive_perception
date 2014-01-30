/*
 * Tracker.h
 *
 *  Created on: Oct 31, 2012
 *      Author: Karol Hausman
 */

#ifndef TRACKER_H_
#define TRACKER_H_

#include <pcl/point_types.h>
#include <pcl/PointIndices.h>

namespace interactive_perception_interface {

template<typename PointType>
class Tracker {
public:
    typedef typename pcl::PointCloud<PointType> PointCloud;
    typedef typename PointCloud::Ptr PointCloudPtr;
    typedef typename PointCloud::ConstPtr PointCloudConstPtr;

    Tracker(){};
    virtual ~Tracker(){};

    /*
     * tracks features in the given point cloud. Outputs a matrix of features tracked over time
     */
    virtual void track(const PointCloudConstPtr &input_cloud,
                       const std::vector<pcl::PointIndices> &input_features,
                       std::vector<std::vector<pcl::PointIndices>  >&features_over_time) = 0;
};

} /* namespace interactive_perception_interface */
#endif /* TRACKER_H_ */
