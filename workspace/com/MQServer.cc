/******************************************************************************
 * @Author                : h6wk<h6wking@gmail.com>                           *
 * @CreatedDate           : 2023-09-01 19:37:01                               *
 * @LastEditDate          : 2023-09-01 20:46:16                               *
 * @CopyRight             : GNU GPL                                           *
 *****************************************************************************/

#include <com/MQServer.h>

#include <zmq.hpp>

#include <iostream>

namespace cmder::com
{
  MQServer::MQServer()
  {
    // context_t (int io_threads_, int max_sockets_=ZMQ_MAX_SOCKETS_DFLT)
    zmq::context_t context (2);
    zmq::socket_t socket (context, zmq::socket_type::rep);
    socket.bind ("tcp://*:5555");

    while (true) {
      zmq::message_t request;

      //  Wait for next request from client
      (void)socket.recv(request, zmq::recv_flags::none);
      std::cout << "Received Hello" << std::endl;

      //  Do some 'work'
      sleep(1);

      //  Send reply back to client
      zmq::message_t reply (5);
      memcpy(reply.data(), "World", 5);
      socket.send (reply, zmq::send_flags::none);
    }
  }

}
