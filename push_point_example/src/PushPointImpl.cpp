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

     /*   std::vector<std::vector<std::vector<int> > > rounds;
        std::vector<std::vector<int> >tables;
        std::vector<int> excludes;



        for (int round=0;round<4;round++){
            for(int table_nr=0;table_nr<15;table_nr++){
                std::vector<int> table_new;

                for(;;){
                    bool breaking=false;
                    if(table_new.size()>=8)
                        break;
                    int random=rand()%128;
//                    ROS_INFO_STREAM("random= "<<random);
                    table_new.push_back(random);
//                    ROS_INFO_STREAM("size: "<<table_new.size());

                    //people dont sit together again
                    excludes.clear();
                    if(round>0){
                        for(int k=0;k<rounds.size();k++){
                            std::vector<std::vector<int> >tables_temp=rounds[k];
                            for(int g=0;g<tables_temp.size();g++){
                                std::vector<int> table=tables_temp[g];
                                for(int i=0;i<table.size();i++){

                                    if(table[i]==random){
                                        excludes.insert(excludes.begin(),table.begin(),table.end());
                                        break;
                                    }

                                }



                            }


                        }
                        std::sort( excludes.begin(), excludes.end() );
                        excludes.erase( std::unique( excludes.begin(), excludes.end() ), excludes.end() );

//                        ROS_INFO_STREAM("excludes in loop random no: "<<random<<" contains: \n");
//                        for(int j=0;j<excludes.size();j++){
//                            ROS_INFO_STREAM(excludes[j]<<" ");
//                        }

                        //delete excludes
                        int counter=0;
                        for(int b=0;b<table_new.size();b++){
                            for(int a=0;a<excludes.size();a++){

                                if(table_new[b]==excludes[a])
                                    counter++;
                                if(counter>=2){
                                    table_new.erase(table_new.begin()+table_new.size()-1);
                                    breaking=true;
                                    break;
                                }
                            }

                        }
                    }



                    //people dont repeat in a table
                    for(int i=0;i<table_new.size()-1;i++){
                        if(table_new[i]==random){
                            table_new.erase(table_new.begin()+table_new.size()-1);
                            breaking=true;
                            break;
                        }
                    }

                    if(breaking)
                        continue;

                    //people dont repeat in tables
                    for(int j=0;j<tables.size();j++){
                        std::vector<int> table=tables[j];
                        for(int i=0;i<table.size();i++){
                            if(table[i]==random){
                                table_new.erase(table_new.end()-1);
                                break;
                            }
                        }
                    }


                }
                tables.push_back(table_new);


            }
            rounds.push_back(tables);
            tables.clear();

        }
        for(int h=0;h<rounds.size();h++){
            std::vector<std::vector<int> >tables_temp=rounds[h];
            for(int i=0;i<tables_temp.size();i++){
                printf("\n \n round nr %i table nr %i contains: \n",h+1,i+1);
                std::vector<int> table=tables_temp[i];

                for(int j=0;j<table.size();j++)
                    printf(" %i ",table[j]);
            }
        }
//        ROS_INFO_STREAM("excludes contains: \n");
//        for(int j=0;j<excludes.size();j++){
//            ROS_INFO_STREAM(excludes[j]<<" ");
//        }
*/
    }

    void PushPointImpl::reconfigCallback (push_point_example::PushPointImplConfig &config,
                                          uint32_t level){
        setMaxRadiusSearchDist(config.max_radius_search_dist);
        ROS_DEBUG_STREAM("Max radius distance changed.");




    }

} /* namespace push_point_example */
