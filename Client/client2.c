//The client program
#include<arpa/inet.h>
#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h>
#include<time.h>
#include<unistd.h>
int main(int argc,char **argv)
{
    int sfd,status,red;
    char buf[50],ack;
    time_t usr_time; 
    struct sockaddr_in servaddr;
     
    sfd=socket(AF_INET,SOCK_STREAM,0);
    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(7004);
    servaddr.sin_addr.s_addr=inet_addr("192.168.1.3");
    status=connect(sfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
    usr_time=time(NULL); 
    printf("\n\n\n\n*******************************************PROJECT REMOTE DRIVER (v0.1)******************************************\n");
    printf("\n\n%s\nWELCOME %s",ctime(&usr_time),getlogin());
     
    if(status==0)
	   printf("\nConnection Established=%d\n",status);
    else
    {
      	   printf("\nConnection not established=%d\n\n\n\n",status);
      	  exit(0);
    }
for(;;){

        write(1,"\nEnter the Control Command: > ",30);
        red=read(1,buf,sizeof(buf));
        write(sfd,buf,red);
                      
        	  
    }
 return 0;
}


