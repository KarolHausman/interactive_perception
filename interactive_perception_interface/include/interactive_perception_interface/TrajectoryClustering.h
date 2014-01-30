#ifndef TRAJECTORYCLUSTERING_H
#define TRAJECTORYCLUSTERING_H

#include <pcl/point_types.h>
#include <pcl/PointIndices.h>

namespace interactive_perception_interface {

template<typename PointType>
class TrajectoryClustering {
public:
    typedef typename pcl::PointCloud<PointType> PointCloud;
    typedef typename PointCloud::Ptr PointCloudPtr;
    typedef typename PointCloud::ConstPtr PointCloudConstPtr;

    TrajectoryClustering(){};
    virtual ~TrajectoryClustering(){};

    /*
     * clusters features that were collected by Tracker
     */
    virtual void cluster(const std::vector<std::vector<pcl::PointIndices> >&features_over_time,
                         std::vector<pcl::PointIndices> &clustered_features) = 0;
};

} /* namespace interactive_perception_interface */

#endif // TRAJECTORYCLUSTERING_H
