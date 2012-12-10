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
#include <pcl_typedefs/pcl_typedefs.h>
//typedef typename pcl::PointCloud<pcl::PointXYZRGB> PointCloud;
//typedef typename PointCloud::Ptr PointCloudPtr;
//typedef typename PointCloud::ConstPtr PointCloudConstPtr;

namespace interactive_perception_interface {

class StaticSegmentation {
public:
	StaticSegmentation(){};
	virtual ~StaticSegmentation(){};

	virtual void segment(PointCloudConstPtr &input_cloud,
			std::vector<pcl::PointIndices> &segmentation_result,
			std::vector<float> &probabilities) const=0;
};

} /* namespace interactive_perception_interface */
#endif /* STATICSEGMENTATION_H_ */
