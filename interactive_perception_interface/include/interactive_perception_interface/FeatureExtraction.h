/*
 * FeatureExtraction.h
 *
 *  Created on: Oct 31, 2012
 *      Author: Karol Hausman
 */

#ifndef FEATUREEXTRACTION_H_
#define FEATUREEXTRACTION_H_

#include <pcl/point_types.h>
#include <pcl/PointIndices.h>

namespace interactive_perception_interface {

template<typename PointType>
class FeatureExtraction {
public:
    typedef typename pcl::PointCloud<PointType> PointCloud;
    typedef typename PointCloud::Ptr PointCloudPtr;
    typedef typename PointCloud::ConstPtr PointCloudConstPtr;

    FeatureExtraction(){};
    virtual ~FeatureExtraction(){};

    /*
     * extracts 3D features in a given point cloud
     */
    virtual void extractFeatures(const PointCloudConstPtr &input_cloud,
                                 std::vector<pcl::PointIndices> &features) = 0;
};

} /*namespace interactive_perception_interface */
#endif /* FEATUREEXTRACTION_H_ */
