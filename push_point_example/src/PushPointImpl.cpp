/*
 * PushPointImpl.cpp
 *
 *  Created on: Nov 19, 2012
 *      Author: Karol Hausman
 */

#include "push_point_example/PushPointImpl.h"
#include <pluginlib/class_list_macros.h>


PLUGINLIB_DECLARE_CLASS(push_point_example, PushPointImpl,
                        push_point_example::PushPointImpl,
                        interactive_perception_interface::PushPoint<pcl::PointXYZRGB>)

namespace push_point_example {

    PushPointImpl::PushPointImpl():
        nh_("~/push_point_example"),
        reconfig_srv_(nh_)
    {
        reconfig_callback_ = boost::bind (&PushPointImpl::reconfigCallback, this, _1, _2);
        reconfig_srv_.setCallback (reconfig_callback_);
    }

    PushPointImpl::~PushPointImpl() {
    }

    void PushPointImpl::estimatePushPoint(const PointCloudConstPtr &input_cloud,
                                          PointCloudPtr &push_point_cloud){

        ROS_INFO_STREAM("estimate push point called with radius distance search = "<<max_radius_search_dist_);

    }

    void PushPointImpl::reconfigCallback (push_point_example::PushPointImplConfig &config,
                                          uint32_t level){
        setMaxRadiusSearchDist(config.max_radius_search_dist);
        ROS_DEBUG_STREAM("Max radius distance changed.");




    }

} /* namespace push_point_example */
