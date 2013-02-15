#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#include<fcntl.h>

int main()
{
	int file_fd,rd;
	char buffer[30];
        pid_t pid;
	
 while(1)
 {	
                write(1,"Waiting for signal",18); 	
		while(1)
	{
		file_fd=open("/var/www/rao/signal.txt",O_RDONLY);
		if(file_fd==-1)
                {	write(1,".",1);
			sleep(2);	}
		else
		{	break;
		}
	}

	rd=read(file_fd,buffer,30);
	
	printf("%s",buffer);
        if(!strncmp(buffer,"REMOTE_DRIVER_ON",16))
	{
		write(1,"\nLED_ON\n",8);		
		pid=fork();
		if(pid==0)
		{
			execv("/home/karthic/mydata/codes/project/remoteserver/gui_client/execs/exec3",0);
                }
         }
        else if(!strncmp(buffer,"REMOTE_DRIVER_OFF",17))
	{
		write(1,"\nLED_OFF\n",9);		
		pid=fork();
		if(pid==0)
		{
			execv("/home/karthic/mydata/codes/project/remoteserver/gui_client/execs/exec4",0);
                }
        }    
        else
	{
		printf("\nWrong String\n");
	}

	
	system("rm /var/www/rao/signal.txt");	
 }	
 return 0;
}
	
			

