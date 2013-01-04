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
    virtual void cluster(const std::vector<std::vector<pcl::PointIndices>  >&features_over_time,
                         std::vector<pcl::PointIndices> &clustered_features);
};

} /* namespace interactive_perception_interface */

#endif // TRAJECTORYCLUSTERING_H
