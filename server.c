#include <string.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<netdb.h>
#include <netinet/in.h>
#include<sys/socket.h>
#include<sys/types.h>
#define MAX 100

void writetofile()
{
FILE *fw;
	char file[100] = "C:/cygwin64/home/Subha/SocketProgramming/";
	char str[MAX];
	fgets(str,MAX,stdin);
	str[strlen(str)-1]='\0';
	strcat(file,str);
	strcat(file,".txt");
	fw = fopen(file, "a"); //opening file in append mode
	if (fw == NULL)
        	return;
	int ct=1;
	int flag=1;
	char w[MAX];
   	while(flag)
   	{	
		switch(ct)
		{
		case 1:		printf("Enter your source word\n");
				fgets(w,MAX,stdin);
				w[strlen(w)-1]='\0';	
					fputs(w, fw); 
					fputs(":", fw);
					break;
		case 2:		printf("Enter your English meaning\n");
				fgets(w,MAX,stdin);
				w[strlen(w)-1]='\0';	
					fputs(w, fw); 
					fputs(":", fw);
					break;
		case 3:		printf("Enter your Hindi meaning\n");
				fgets(w,MAX,stdin);
				w[strlen(w)-1]='\0';	
					fputs(w, fw); 
					fputs(":", fw);
					break;
		case 4:		printf("Enter your German meaning\n");
				fgets(w,MAX,stdin);
				w[strlen(w)-1]='\0';	
					fputs(w, fw); 
					fputs(":", fw);
					break;
		case 5:		printf("Enter your French meaning\n");
				fgets(w,MAX,stdin);
				w[strlen(w)-1]='\0';	
					fputs(w, fw); 
					
					break;
		case 6: fputs("\n",fw);
			break;
   	        }
		ct++;
		if(ct==7)
			{
			int i;
			printf(" press 0 for continue or  1 for exit");
		fgets(w,MAX,stdin);
				w[strlen(w)-1]='\0';
				if(strcmp(w,"1")==0)
			{
					flag=0;
					break;
			}
			else
			{
			ct=1;
				}
			}

}
fclose(fw);
return;
}

int find_lno(char *fname)
{
	FILE*fptr1;
	fptr1=fopen(fname,"r");
	int lno=0;
	if (fptr1 == NULL)
		return 0;
	char w[MAX];
	printf("Enter your word");
	fgets(w,MAX,stdin);
	w[strlen(w)-1]='\0';

	char str[MAX];
	while(1)
	{
	if(fgets(str,MAX,fptr1)==NULL) // feof returns non zero value if it points to end of file
		return 0;	
	str[strlen(str)-1]='\0';

		char *token=strtok(str,":");
		if(strcmp(token,w)==0)
		{
			return lno;
		}
		lno++;	
	}
	
}
void delete()
{
        int lno, ctr = 0;
        char ch;
        FILE *fptr1, *fptr2;
		char fname[MAX];
        char str[MAX], temp[] = "temp.txt";
		printf("\n\n Delete a specific line from a file :\n");
		printf("-----------------------------------------\n"); 
		printf(" Input the file name to be opened : ");
		fgets(fname,MAX,stdin);
		fname[strlen(fname)-1]='\0';	
        fptr1 = fopen(fname, "r");
        if (!fptr1) 
		{
                printf(" File not found or unable to open the input file!!\n");
                return ;
        }
        fptr2 = fopen(temp, "w"); // open the temporary file in write mode 
        if (!fptr2) 
		{
                printf("Unable to open a temporary file to write!!\n");
                fclose(fptr1);
                return ;
        }
        printf(" Input the line you want to remove : ");
      	lno=find_lno(fname);
		lno++;
	printf("\n%d",lno);	
        // copy all contents to the temporary file except the specific line
        while (!feof(fptr1)) 
        {
            strcpy(str, "\0");
            fgets(str, MAX, fptr1);
            if (!feof(fptr1)) 
            {
                ctr++;
                /* skip the line at given line number */
                if (ctr != lno) 
                {
                    fprintf(fptr2, "%s", str);
                }
            }
        }
        fclose(fptr1);
        fclose(fptr2);
        remove(fname);  		// remove the original file 
        rename(temp, fname); 	// rename the temporary file to original name
/*------ Read the file ----------------*/
   fptr1=fopen(fname,"r"); 
            ch=fgetc(fptr1); 
          printf(" Now the content of the file %s is : \n",fname); 
          while(ch!=EOF) 
            { 
                printf("%c",ch); 
                 ch=fgetc(fptr1); 
            }
        fclose(fptr1);
/*------- End of reading ---------------*/
        return ;

}

char*find(char*word,int S,int T)
{
	char str[1024];
	switch(S)
{
case 1:
	FILE *f=fopen("C:/cygwin64/home/Subha/SocketProgramming/English.txt", "r");
	while(1)
	{
	char*fword,*hindi,*german,*french,*english;
	
	if(fgets(str,1024,f)==NULL)
	{
		break;
	}
	else
	{	
	str[strlen(str)-1]='\0';
	fword=strtok(str,":");
	english=strtok(NULL,":");
	hindi=strtok(NULL,":");
	german=strtok(NULL,":");
	french=strtok(NULL,":");
	}
	if(strcmp(word,fword)==0)
	{
	switch(T)
		{
	case 1:strcpy(word,english);
		return word;
	case 2:strcpy(word,hindi);
	       	return word;
	case 3:strcpy(word,german);
		return word;
	case 4:strcpy(word,french);
		return word;
		}

	}

	}
	strcpy(word,"Not found:");
	return word;
case 2:
	FILE *fw=fopen("C:/cygwin64/home/Subha/SocketProgramming/German.txt", "r");
	while(1)
	{
	char*german,*hindi,*english,*french,*fword;
	
	if(fgets(str,1024,fw)==NULL)
	{
		break;
	}
	else
	{	
	str[strlen(str)-1]='\0';
	fword=strtok(str,":");
	english=strtok(NULL,":");
	hindi=strtok(NULL,":");
	german=strtok(NULL,":");
	french=strtok(NULL,":");
	}
	if(strcmp(word,fword)==0)
	{
	switch(T)
		{
	case 1:strcpy(word,english);
		return word;
	case 2:strcpy(word,hindi);
	       	return word;
	case 3:strcpy(word,german);
		return word;
	case 4:strcpy(word,french);
		return word;
		}

	}

	}
	strcpy(word,"Not found:");
	return word;
}

}

char *strrev(char *str)
{	
	
	char*word=strtok(str,":");
	char*sl=strtok(NULL,":");
	char*tl=strtok(NULL,":");	
	int S = atoi(sl);
	int T = atoi(tl);
	find(word,S,T);
	/*switch(T)
{
 case 1:strcpy(str,"नमस्ते");
	break;
case 2: strcpy(str,"hola");
    	break;
}*/
        return word;
}

int main(int argc, char * argv[])
{
	char ct[100];
	printf("1:login \n 2:run\n");
	fgets(ct,100,stdin);
	ct[strlen(ct)-1]='\0';
	if(strcmp(ct,"1")==0)
	{
	char LoginId[100];
        char Password[100];        
        printf("Welcome to the Login_System\n");
        printf("Please Enter your LoginID\n");
        fgets(LoginId,100,stdin);
	LoginId[strlen(LoginId)-1]='\0';
        printf("Please Enter your Password\n");
        fgets(Password,100,stdin);
	Password[strlen(Password)-1]='\0';
        if(strcmp(LoginId,"User")==0)
	{
            if(strcmp(Password,"12345")==0)
	{
	while(1)
	{
                printf("\n1 :add new language\n 2 : add/modify words\n 3: delete words\n 4: exit\n");
		char *choice;
		printf("enter your choice\n");
		gets(choice);
		int n=atoi(choice);
		switch(n)
		{
			case 1:	writetofile();
				break;
		/*	case 2: add_words();
				break;*/
			case 3: delete();
				break;	
			case 4: return 0 ;	
            	}
        }
	}
        else{
            printf("Try Again!!\n");
        }
}
}
	int sockfd, newsockfd, portno, n;
	struct sockaddr_in serv_addr, client_addr;
	char buffer[1024], nbuff[1024];
	socklen_t len;

	if(argc<2)
	{
		printf("Provide required command line inputs as- <filename.c> <serverip_addr> <port_no>");
		exit(1);
	}

	portno= atoi(argv[1]);
	sockfd= socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd<0)
	{
		printf("Error in opening socket");
		exit(1);
	}

	serv_addr.sin_family= AF_INET;
	serv_addr.sin_addr.s_addr= INADDR_ANY;
	serv_addr.sin_port= htons(portno);

	if(bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr))<0)
		printf("Error in binding Socket");
	
	listen(sockfd,5);
	len=sizeof(client_addr);
	
	newsockfd= accept(sockfd, (struct sockaddr *) &client_addr, &len);

	if(newsockfd<0)
	{
		printf("Error in accepting request");
		exit(1);
	}

	while(1)
	{
		bzero(buffer, 1024);
		n=read(newsockfd, buffer, 1024);
		if(n<0)
		{
			printf("Error in reading");
			exit(1);
		}

		printf("\nClient ----> %s", buffer);
		char *nbuff = strrev(buffer);

		//bzero(buffer, 1024);
		//fgets(buffer,1024, stdin);
		n=write(newsockfd, nbuff, 1024);
		bzero(buffer, 1024);

		if(n<0)
		{
			printf("Error in writing....");
			exit(1);
		}

		if(!strncmp("bye",buffer,3))
		{
			break;
		}

	}

	close(newsockfd);
	close(sockfd);
	return 0;
}


