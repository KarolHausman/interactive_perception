/*
 * PushPointImpl.h
 *
 *  Created on: Nov 19, 2012
 *      Author: Karol Hausman
 */

#ifndef PUSHPOINTIMPL_H_
#define PUSHPOINTIMPL_H_

#include <ros/console.h>
#include <pcl/point_types.h>
#include <pluginlib/class_list_macros.h>
#include <interactive_perception_interface/PushPoint.h>

#include <dynamic_reconfigure/server.h>
#include "../../cfg/cpp/push_point_example/PushPointImplConfig.h"

namespace push_point_example {


class PushPointImpl :public interactive_perception_interface::PushPoint<pcl::PointXYZRGB> {
public:
	PushPointImpl();
	virtual ~PushPointImpl();
	void estimatePushPoint(PointCloudConstPtr &input_cloud,
				PointCloudPtr &push_point_cloud)const;
        double getMaxRadiusSearchDist(){return max_radius_search_dist_;}
        void setMaxRadiusSearchDist(double dist){max_radius_search_dist_=dist;}
private:
        void reconfigCallback (push_point_example::PushPointImplConfig &config,
                 uint32_t level);

        double max_radius_search_dist_;
        ros::NodeHandle nh_;
        dynamic_reconfigure::Server<push_point_example::PushPointImplConfig> reconfig_srv_;
        dynamic_reconfigure::Server<push_point_example::PushPointImplConfig>::CallbackType
                  reconfig_callback_;


};

} /* namespace push_point_example */
#endif /* PUSHPOINTIMPL_H_ */
