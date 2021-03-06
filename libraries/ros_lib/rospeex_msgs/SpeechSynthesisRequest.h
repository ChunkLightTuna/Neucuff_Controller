#ifndef _ROS_rospeex_msgs_SpeechSynthesisRequest_h
#define _ROS_rospeex_msgs_SpeechSynthesisRequest_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rospeex_msgs/SpeechSynthesisHeader.h"

namespace rospeex_msgs
{

  class SpeechSynthesisRequest : public ros::Msg
  {
    public:
      rospeex_msgs::SpeechSynthesisHeader header;
      const char* message;
      const char* memo;

    SpeechSynthesisRequest():
      header(),
      message(""),
      memo("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_message = strlen(this->message);
      memcpy(outbuffer + offset, &length_message, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_message);
      offset += length_message;
      uint32_t length_memo = strlen(this->memo);
      memcpy(outbuffer + offset, &length_memo, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->memo, length_memo);
      offset += length_memo;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_message;
      memcpy(&length_message, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message-1]=0;
      this->message = (char *)(inbuffer + offset-1);
      offset += length_message;
      uint32_t length_memo;
      memcpy(&length_memo, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_memo; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_memo-1]=0;
      this->memo = (char *)(inbuffer + offset-1);
      offset += length_memo;
     return offset;
    }

    const char * getType(){ return "rospeex_msgs/SpeechSynthesisRequest"; };
    const char * getMD5(){ return "d242fe3cd0331e15845e8587505019df"; };

  };

}
#endif