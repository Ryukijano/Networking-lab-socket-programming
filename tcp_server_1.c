/* C program to demonstrate Socket programming */
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string.h>

main()
{
    int sockfd,fd1,length,i,x,y,sum;
    char buff[100],p[3];/*buff is used to store the message from the server*/
    struct sockaddr_in sa,tal;
    /*Opening a socket*/
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    /*Initializing the socket address*/
    sa.sin_family=AF_INET;
    /*IP address*/
    sa.sin_addr.s_addr=INADDR_ANY;
    /*Port number*/
    sa.sin_port=60018;
    /*Binding the socket to the address*/
    i=bind(sockfd,(struct sockaddr*)&sa,sizeof(sa));
    printf("test %d%d\n",sockfd,id);
    /*listening for the connection*/
    listen(sockfd,5);
    /*Accepting the connection*/
    length=sizeof(sa);
    fd1=accept(sockfd,(struct sockaddr*)&tal,&length);
    /*Send the message to the client*/
    for(i=0;i<100;i++) buff[i]='\0';
    {
        recv(fd1,buff,100,0);
        printf("%s\n",buff);
    }
    close(fd1);
    
}