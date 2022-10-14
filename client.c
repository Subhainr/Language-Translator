#include <string.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<netdb.h>
#include <netinet/in.h>
#include<sys/socket.h>
#include<sys/types.h>

int main(int argc, char * argv[])
{
	int sockfd, portno, n;
	struct sockaddr_in serv_addr;
	char buffer[1024];
	char nbuff[1024];
	char mbuff[1024];
	
	
	if(argc<3)
	{
		printf("Provide required command line inputs as- <filename.c> <serverip_addr> <port_no>");
		exit(1);
	}
	
	portno= atoi(argv[2]);
	sockfd= socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd<0)
	{
		printf("Error in opening socket");
		exit(1);
	}

	serv_addr.sin_family= AF_INET;
	serv_addr.sin_port= htons(portno);
	serv_addr.sin_addr.s_addr= inet_addr(argv[1]);
	
	if(connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr))<0)
	{
		printf("Connection failed...!!!");
		exit(1);
	}

	while(1)
	{
		printf("Please enter the message: ");
		bzero(buffer, 1024);
		fgets(buffer,1024, stdin);
		buffer[strlen(buffer)-1]='\0';
		printf("please enter your source language: \n 1:english \n 2:german\nenter your choice: ");
		fgets(nbuff,255,stdin);	
		nbuff[strlen(nbuff)-1]='\0';	
		printf("please enter your target language: \n 1:english \n 2:hindi \n 3:german \n 4:french \nenter your choice: ");
		fgets(mbuff,255,stdin);
		strcat(buffer,":");
		strcat(buffer,nbuff);
		strcat(buffer,":");
		strcat(buffer,mbuff);
		printf("\nSending to SERVER: %s ",buffer);
	
		n=write(sockfd, buffer, 1024);
		if(n<0)
		{
			printf("Error in writing....");
			exit(1);
		}

		bzero(buffer, 1024);
		n=read(sockfd, buffer, 1024);
		if(n<0)
		{
			printf("Error in reading....");
			exit(1);
		}
		printf("\nServer ----> %s", buffer);

		if(!strncmp("bye",buffer,3))
		{
			break;
		}

	}
	close(sockfd);
	return 0;
}