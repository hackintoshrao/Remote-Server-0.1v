/*This is an Introduction on building a server application in GNU/LINUX using C socket API's*/
/*Run this program and issue "netstat -ant | grep 7004" in another terminal, you can see the server listening */

/*accept system call doesnot return till either it encounters an error or gets a connection from a client(such system calls are called as blocking system call */
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h> /*for inet_xxxx address format functions*/
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int listen_fd,conn_fd,no_of_char_read,len;
    char buf[50];
    char ClientIP[40];


    struct sockaddr_in servaddr,cliaddr;//socket structure
    listen_fd=socket(AF_INET,SOCK_STREAM,0);/*elementary call in any client server application to create an socket*/

    bzero(&servaddr,sizeof(servaddr));/*Initializing all fields of the socket structure to zero*/
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);/*To assian a WildCard IP to the server*/
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(7004);//port on which the server listens
    bind(listen_fd,(struct sockaddr *)&servaddr,sizeof(servaddr));/*assign the IP and port information to the socket */
    listen(listen_fd,5);/*Listen for incoming coonections */
    len=sizeof(cliaddr);

    conn_fd=accept(listen_fd,(struct sockaddr *)&cliaddr,&len);/*accepts the incoming connections,accept returns a new socket descriptor,which
                                                  can be further used to communicate with the other device with which the connection is established*/
    inet_ntop(AF_INET,&cliaddr.sin_addr,ClientIP,sizeof(ClientIP));
    printf("\n\nConnection succesfully Establised from %s and port number %d\n",ClientIP,ntohs(cliaddr.sin_port));
    write(1,"\nConnection successfully established \n ",40);
    for(;;){
    no_of_char_read=read(conn_fd,buf,sizeof(buf));

    write(1,buf,no_of_char_read);/*writing into the socket*/
    }


    //buf[]={0};

    //printf("\nWritten=%d char\n",len);

    return 0;
}

