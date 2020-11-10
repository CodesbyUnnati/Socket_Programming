#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>
#include<stdio.h>
#include<netdb.h>
#include<string.h>
int main(int argc,char *argv[])
{
int n,sd,cd;
struct sockaddr_in servaddr,cliaddr;
socklen_t servlen,clilen;
char buff[10000],buff1[10000];
bzero(&servaddr,sizeof(servaddr));
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=inet_addr(argv[1]);
servaddr.sin_port=htons(5000);
sd=socket(AF_INET,SOCK_STREAM,0);
cd=connect(sd,(struct sockaddr*)&servaddr,sizeof(servaddr));
while(1)
{
bzero(&buff,sizeof(buff));
printf("%s\n","Enter the input data:");
fgets(buff,10000,stdin);
send(sd,buff,strlen(buff)+1,0);
printf("%s\n","Data sent");
n=1;
while(n==1)
{
bzero(&buff1,sizeof(buff1));
recv(sd,buff1,sizeof(buff1),0);
printf("Received from the server:%s\n",buff1);
n=n+1;
}
}
return 0;
}


//COMMANDS
/*

gcc exp6client.c -o exp9client
./a.out 127.0.0.1
*/
