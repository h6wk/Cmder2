/******************************************************************************
 * @Author                : h6wk<h6wking@gmail.com>                           *
 * @CreatedDate           : 2023-07-31 20:37:40                               *
 * @LastEditDate          : 2023-11-02 20:35:40                               *
 * @CopyRight             : GNU GPL                                           *
 *****************************************************************************/

#include <iostream>
//#include <stdio.h>
#include <unistd.h>

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

  return 0;
}
