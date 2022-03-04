#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<string.h>

main()
{
    int i,sockfd,a,b,p=6,q=7,r;
    char buff[100];
    struct sockaddr_in sa;
    /*Opening a socket*/
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    /*Initializing the socket address*/
    sa.sin_family=AF_INET;;
    /*IP address*/
    sa.sin_addr.s_addr=inet_addr("127.0.0.1"); //loopback address
    /*Port number*/
    sa.sin_port=htons(5000);
    /*Connecting to the server*/
    i=connect(sockfd,(struct sockaddr*)&sa,sizeof(sa));
    /*Checking for error*/
    if(i==-1)
    {
        printf("Error in connecting to the server\n");
        exit(0);
    }
    /*Receiving the message from the server*/
    for(i=0;i<100;i++) buff[i]='\0';
    {
        r=recv(sockfd,buff,100,0);
        printf("%s\n",buff);
        for(i=0;i<100;i++) buff[i]='\0';
        strcpy(buff,"Hello from client");
        send(sockfd,buff,100,0);
    }

    close(sockfd);
 
}