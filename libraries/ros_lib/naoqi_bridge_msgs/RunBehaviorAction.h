#ifndef _ROS_naoqi_bridge_msgs_RunBehaviorAction_h
#define _ROS_naoqi_bridge_msgs_RunBehaviorAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "naoqi_bridge_msgs/RunBehaviorActionGoal.h"
#include "naoqi_bridge_msgs/RunBehaviorActionResult.h"
#include "naoqi_bridge_msgs/RunBehaviorActionFeedback.h"

namespace naoqi_bridge_msgs
{

  class RunBehaviorAction : public ros::Msg
  {
    public:
      naoqi_bridge_msgs::RunBehaviorActionGoal action_goal;
      naoqi_bridge_msgs::RunBehaviorActionResult action_result;
      naoqi_bridge_msgs::RunBehaviorActionFeedback action_feedback;

    RunBehaviorAction():
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

    const char * getType(){ return "naoqi_bridge_msgs/RunBehaviorAction"; };
    const char * getMD5(){ return "a6a26afb8ff0902c5587c8bfbdc46892"; };

  };

}
#endif