#ifndef _ROS_naoqi_bridge_msgs_BodyPoseWithSpeedActionGoal_h
#define _ROS_naoqi_bridge_msgs_BodyPoseWithSpeedActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "naoqi_bridge_msgs/BodyPoseWithSpeedGoal.h"

namespace naoqi_bridge_msgs
{

  class BodyPoseWithSpeedActionGoal : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalID goal_id;
      naoqi_bridge_msgs::BodyPoseWithSpeedGoal goal;

    BodyPoseWithSpeedActionGoal():
      header(),
      goal_id(),
      goal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->goal_id.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->goal_id.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "naoqi_bridge_msgs/BodyPoseWithSpeedActionGoal"; };
    const char * getMD5(){ return "32a7ec65212f19c6ff6a3defe7418661"; };

  };

}
#endif