/******************************************************************************
 * @Author                : h6wk<h6wking@gmail.com>                           *
 * @CreatedDate           : 2023-07-31 20:37:40                               *
 * @LastEditDate          : 2023-09-01 21:33:29                               *
 * @CopyRight             : GNU GPL                                           *
 *****************************************************************************/

#include <iostream>
//#include <stdio.h>
#include <unistd.h>

#include <com/MQServer.h>

using namespace cmder::com;

int main(int argc, char *argv[])
{
  int opt;

  while((opt = getopt(argc, argv, "cs")) != -1) { 
    switch(opt) 
    { 
      case 's': 
        printf("mode: server"); 
        break; 
      case 'c': 
        printf("mode: client"); 
        break; 
    } 
  } 


  std::cout << "\nStarting...";

  MQServer mds;

  std::cout << "\nDone\n";
  return 0;
}
