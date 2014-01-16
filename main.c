//
//  main.c
//  R_TCP_SCANNER
//
//  Created by RocKK on 16/01/14.
//  Copyright (c) 2014 RocKK.
//  All rights reserved.
//
//  Redistribution and use in source and binary forms are permitted
//  provided that the above copyright notice and this paragraph are
//  duplicated in all such forms and that any documentation,
//  advertising materials, and other materials related to such
//  distribution and use acknowledge that the software was developed
//  by the RocKK.  The name of the
//  RocKK may not be used to endorse or promote products derived
//  from this software without specific prior written permission.
//  THIS SOFTWARE IS PROVIDED ''AS IS'' AND WITHOUT ANY EXPRESS OR
//  IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
//  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h> 

int main(int argc, char **argv)
{
   int   sd;//socket descriptor
   int   port;//port number
   int   start;//start port
   int   end;//end port
   int   rval;//socket descriptor for connect   
   char response[1024];//to receive data
   char *message="shell";//data to send
   struct hostent *hostaddr;//To be used for IPaddress
   struct sockaddr_in servaddr;//socket structure
    
   if (argc < 4 )
   {
      printf("Usage: ./main <IPaddress> <Start Port> <End Port>\n");
      return 0;
   }
   start = atoi(argv[2]);
   end   = atoi(argv[3]);
   for (port=start; port<=end; port++)
   {
 
      //port number is ascii to int second argument     
      sd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP); //created the tcp socket
      if (sd == -1)
      {
         perror("Socket()\n");
         return (errno);
      }   
 
      memset( &servaddr, 0, sizeof(servaddr));
      servaddr.sin_family = AF_INET;
      servaddr.sin_port = htons(port); //set the port number
    
      hostaddr = gethostbyname( argv[1] ); //get the ip 1st argument
      memcpy(&servaddr.sin_addr, hostaddr->h_addr, hostaddr->h_length);   
      
      //below connects to the specified ip in hostaddr
      rval = connect(sd, (struct sockaddr *) &servaddr, sizeof(servaddr));
      if (rval == -1)
      {
         printf("Port %d is open\n", port);
         close(sd);
      }
      else
         printf("Port %d is closed\n",port);
       
      close(sd); //socket descriptor
   }
    
}
