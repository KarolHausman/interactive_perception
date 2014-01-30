/*
 * FullReconstruction.h
 *
 *  Created on: Oct 31, 2012
 *      Author: Karol Hausman
 */

#ifndef FULLRECONSTRUCTION_H_
#define FULLRECONSTRUCTION_H_

#include <pcl/point_types.h>
#include <pcl/PointIndices.h>

namespace interactive_perception_interface {

template<typename PointType>
class FullReconstruction {
public:
    typedef typename pcl::PointCloud<PointType> PointCloud;
    typedef typename PointCloud::Ptr PointCloudPtr;
    typedef typename PointCloud::ConstPtr PointCloudConstPtr;

    FullReconstruction(){};
    virtual ~FullReconstruction(){};

    /*
     * reconstructs full models of segmented objects. To be called after TrajectoryClustering
     */
    virtual void reconstruct(const PointCloudConstPtr &input_cloud,
                             const std::vector<pcl::PointIndices> &clustered_features,
                             std::vector<PointCloudPtr> &reconstructed_models) = 0;
};

} /* namespace interactive_perception_interface */
#endif /* FULLRECONSTRUCTION_H_ */
