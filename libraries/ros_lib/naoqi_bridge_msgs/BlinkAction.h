#ifndef _ROS_naoqi_bridge_msgs_BlinkAction_h
#define _ROS_naoqi_bridge_msgs_BlinkAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "naoqi_bridge_msgs/BlinkActionGoal.h"
#include "naoqi_bridge_msgs/BlinkActionResult.h"
#include "naoqi_bridge_msgs/BlinkActionFeedback.h"

namespace naoqi_bridge_msgs
{

  class BlinkAction : public ros::Msg
  {
    public:
      naoqi_bridge_msgs::BlinkActionGoal action_goal;
      naoqi_bridge_msgs::BlinkActionResult action_result;
      naoqi_bridge_msgs::BlinkActionFeedback action_feedback;

    BlinkAction():
      action_goal(),
      action_result(),
      action_feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->action_goal.serialize(outbuffer + offset);
      offset += this->action_result.serialize(outbuffer + offset);
      offset += this->action_feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->action_goal.deserialize(inbuffer + offset);
      offset += this->action_result.deserialize(inbuffer + offset);
      offset += this->action_feedback.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "naoqi_bridge_msgs/BlinkAction"; };
    const char * getMD5(){ return "c03ab9992d56528894da7d19c515fc49"; };

  };

}
#endif