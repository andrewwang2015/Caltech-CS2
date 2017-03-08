/**
@file
@author Ben Yuan
@date 2013
@copyright 2-clause BSD; see License section

@brief
A more complex echo client to validate the network wrapper.

@section License

Copyright (c) 2012-2013 California Institute of Technology.
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

The views and conclusions contained in the software and documentation are those
of the authors and should not be interpreted as representing official policies,
either expressed or implied, of the California Institute of Technology.

*/

#include "client1.hpp"

using namespace CS2Net;

int main(int argc, char ** argv)
{

    REQUIRE(argc == 3, "usage: %s hostname port", argv[0]);

    /* TODO: write this code.
    *
    * This should be a client that connects to a remote server,
    * sends a message of your choice no more than once per second,
    * and echoes any messages it receives in the meantime
    * without having to block on recv.
    *
    **/

    CS2Net::Socket sock;
    std::string hostname(argv[1]);
    uint16_t port = 47001;
    std::string to_send;
	

    int ret = sock.Connect(&hostname, port);
    if(ret < 0)
    {
        
      if(ret == -1)
      {
        ERROR("connect error: %s", strerror(errno));
      }
      else if(ret == -3)
      {
        ERROR("connect error: %s", gai_strerror(errno));
      }
      else
      {
        ERROR("programmer is doing it wrong");
      }
    }
    else
    {
      std::vector<CS2Net::PollFD>poll_vec(1);
      poll_vec[0].sock = &sock;
      poll_vec[0].SetRead(true);


      
      int flag = 0;
      while (true)
      {

      	int poll_err = CS2Net::Poll(&poll_vec, 10);
     	  REQUIRE(poll_err >= 0, "error on poll!?");

        if (poll_vec[0].HasHangup()||poll_vec[0].HasError())
        {
          std::cout << "Error in polling!" << std::endl;
        }

        if (poll_vec[0].CanRead())
        {
          std::string * incoming = sock.Recv(1024, false);
          if(incoming == NULL)
          {
          ERROR("recv error: %s", strerror(errno));
          }
          else
          {
            std::cout << *incoming << std::endl;
          }
	      
        }
        
        if (flag == 1){
        	sleep(1);
        }
        std::string to_send("This is the sent message.");

        int ret = sock.Send(&to_send);

        flag = 1;
        if(ret < 0)
        {
            if(ret == -1)
            {
              ERROR("send error: %s", strerror(errno));
            }
            else
            {
              ERROR("programmer is doing it wrong");
            }
       	}        

    }
}
    

    


    int ret1 = sock.Disconnect();
    if(ret1 < 0)
    {
        // bad stuff happened
        if(ret1 == -1)
        {
            // you might actually be able to ignore these errors
            // but we'll print them anyway
            ERROR("disconnect error: %s", strerror(errno));
        }
        else
        {
            ERROR("programmer is doing it wrong");
        }
    }

      return 0;


}
