/*
 * FeatureExtraction.h
 *
 *  Created on: Oct 31, 2012
 *      Author: Karol Hausman
 */

#ifndef FEATUREEXTRACTION_H_
#define FEATUREEXTRACTION_H_

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/PointIndices.h>

namespace interactive_perception_interface {

template<typename PointType>
class FeatureExtraction {
public:
	typedef typename pcl::PointCloud<PointType> PointCloud;
	typedef typename PointCloud::Ptr PointCloudPtr;
	typedef typename PointCloud::ConstPtr PointCloudConstPtr;

	FeatureExtraction();
	virtual ~FeatureExtraction();
	virtual void extractFeatures(PointCloudConstPtr &input_cloud,
			std::vector<pcl::PointIndices> &features) const =0;
};

} /*namespace interactive_perception_interface */
#endif /* FEATUREEXTRACTION_H_ */
