/*
 * PushPoint.h
 *
 *  Created on: Oct 31, 2012
 *      Author: Karol Hausman
 */

#ifndef PUSHPOINT_H_
#define PUSHPOINT_H_

#include <pcl/point_types.h>


namespace interactive_perception_interface {

template<typename PointType>
class PushPoint {
public:
	typedef typename pcl::PointCloud<PointType> PointCloud;
	typedef typename PointCloud::Ptr PointCloudPtr;
	typedef typename PointCloud::ConstPtr PointCloudConstPtr;
	PushPoint(){};
	virtual ~PushPoint(){};
	virtual void estimatePushPoint(PointCloudConstPtr &input_cloud,
			PointCloudPtr &push_point_cloud) const =0;
};

} /* namespace interactive_perception_interface */
#endif /* PUSHPOINT_H_ */
