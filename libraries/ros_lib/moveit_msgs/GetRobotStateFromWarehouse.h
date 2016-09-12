#ifndef _ROS_SERVICE_GetRobotStateFromWarehouse_h
#define _ROS_SERVICE_GetRobotStateFromWarehouse_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/RobotState.h"

namespace moveit_msgs
{

static const char GETROBOTSTATEFROMWAREHOUSE[] = "moveit_msgs/GetRobotStateFromWarehouse";

  class GetRobotStateFromWarehouseRequest : public ros::Msg
  {
    public:
      const char* name;
      const char* robot;

    GetRobotStateFromWarehouseRequest():
      name(""),
      robot("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      uint32_t length_robot = strlen(this->robot);
      memcpy(outbuffer + offset, &length_robot, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->robot, length_robot);
      offset += length_robot;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      memcpy(&length_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t length_robot;
      memcpy(&length_robot, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_robot; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_robot-1]=0;
      this->robot = (char *)(inbuffer + offset-1);
      offset += length_robot;
     return offset;
    }

    const char * getType(){ return GETROBOTSTATEFROMWAREHOUSE; };
    const char * getMD5(){ return "dab44354403f811c40b84964e068219c"; };

  };

  class GetRobotStateFromWarehouseResponse : public ros::Msg
  {
    public:
      moveit_msgs::RobotState state;

    GetRobotStateFromWarehouseResponse():
      state()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->state.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->state.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETROBOTSTATEFROMWAREHOUSE; };
    const char * getMD5(){ return "219fdfe7af6da3c7935fb948e6d5c637"; };

  };

  class GetRobotStateFromWarehouse {
    public:
    typedef GetRobotStateFromWarehouseRequest Request;
    typedef GetRobotStateFromWarehouseResponse Response;
  };

}
#endif
