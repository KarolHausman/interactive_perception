/*
* StaticSegmentation.h
*
* Created on: Nov 2, 2012
* Author: Karol Hausman
*/

#ifndef STATIC_SEGMENTATION_H_
#define STATIC_SEGMENTATION_H_

#include <interactive_perception_interface/StaticSegmentation.h>

namespace interactive_perception_example
{
  class StaticSegmentationImpl : public interactive_perception_interface::StaticSegmentation
  {
    public:
      StaticSegmentationImpl ();
      virtual ~StaticSegmentationImpl ();

      void segment (PointCloudConstPtr &input_cloud,
			std::vector<pcl::PointIndices> &segmentation_result,
			std::vector<float> &probabilities)const;
  };
};
#endif /* STATIC_SEGMENTATION_H_ */
