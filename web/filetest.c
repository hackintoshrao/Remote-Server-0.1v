#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#include<fcntl.h>

int main()
{
	int file_fd,rd;
	char buffer[30];
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
	pid_t pid;
	printf("%s",buffer);
 return 0;
}
	
			

