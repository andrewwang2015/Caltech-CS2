/**
@file
@author Ben Yuan
@date 2013
@copyright 2-clause BSD; see License section

@brief
A multi-user echo server to validate the network wrapper.

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

#include "server1.hpp"

using namespace CS2Net;

int main(int argc, char ** argv)
{
  REQUIRE(argc == 2, "usage: %s port", argv[0]);



  CS2Net::Socket listener;
  int err = listener.Bind(atoi(argv[1]), 1);
  REQUIRE(err == 0, "Failed to bind!");

  std::vector<CS2Net::PollFD>poll_vec(1);


  poll_vec[0].sock = &listener;
  poll_vec[0].SetRead(true);

  int count = 1;
  
  CS2Net::Socket * incoming_conn = NULL;
  std::vector<CS2Net::Socket*> sockets;
  while (true)
  {
    int poll_err = CS2Net::Poll(&poll_vec, 10);
    REQUIRE(poll_err >= 0, "error on poll!?");

    for (int i = 0 ; i < count ; i++){
      if (poll_vec[i].HasHangup()||poll_vec[i].HasError())
      {
        std::cout << "Error in polling!" << std::endl;
      }  

      if (poll_vec[i].CanRead())
      {
        if (i == 0){    
          incoming_conn = listener.Accept();
          REQUIRE(incoming_conn != NULL, "Failed to accept!");
          sockets.push_back(incoming_conn);
          poll_vec.push_back(PollFD());
          poll_vec[count].sock = incoming_conn;
          poll_vec[count].SetRead(true);
          count++;  
        }

        else{

          
          std::string * incoming = sockets[i-1]->Recv(1024, false);

          if(incoming == NULL)
          {
          
          ERROR("recv error: %s", strerror(errno));
          }
          else  
          {
            std::cout<<*incoming<<std::endl;
          }

          for (int j = 1; j < count; j++){
            int ret = sockets[j-1]->Send(incoming);
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
      }    
    }
  }

return 0;

}



