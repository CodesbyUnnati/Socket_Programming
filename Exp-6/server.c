#include<sys/types.h>
#include<stdio.h>
#include<netdb.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<netinet/in.h>
#include<string.h>
int main(int argc,char *argv[])
{
int n,sd,ad;
struct sockaddr_in servaddr,cliaddr;
socklen_t clilen,servlen;
char buff[10000],buff1[10000];
bzero(&servaddr,sizeof(servaddr));
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
servaddr.sin_port=htons(5000);
sd=socket(AF_INET,SOCK_STREAM,0);
bind(sd,(struct sockaddr*)&servaddr,sizeof(servaddr));
listen(sd,5);
printf("%s\n","server is running…");
ad=accept(sd,(struct sockaddr*)&cliaddr,&clilen);
while(1)
{
bzero(&buff,sizeof(buff));
recv(ad,buff,sizeof(buff),0);
printf("Receive from the client:%s\n",buff);
n=1;
while(n==1)
{
bzero(&buff1,sizeof(buff1));
printf("%s\n","Enter the input data:");
fgets(buff1,10000,stdin);
send(ad,buff1,strlen(buff1)+1,0);
printf("%s\n","Data sent");
n=n+1;
}
}
return 0;
}

//COMMANDS
/*
gcc exp6server.c -o exp6server
./a.out
*/
