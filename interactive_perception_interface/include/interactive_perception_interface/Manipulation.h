#ifndef MANIPULATION_H
#define MANIPULATION_H

#include <pcl/point_types.h>
#include <pcl/PointIndices.h>

namespace interactive_perception_interface {

template<typename PointType>
class Manipulation {
public:
    typedef typename pcl::PointCloud<PointType> PointCloud;
    typedef typename PointCloud::Ptr PointCloudPtr;
    typedef typename PointCloud::ConstPtr PointCloudConstPtr;

    Manipulation(){};
    virtual ~Manipulation(){};
    virtual void manipulate(const PointCloudConstPtr &push_point_cloud);
    virtual void manipulate(const Eigen::Matrix4d &push_point);
};

} /*namespace interactive_perception_interface */
#endif // MANIPULATION_H
