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
int dshow(char msg[]){
    printf("%s\n",msg);
}
int recvfile(char ip[], int portn){
   dshow ("Waiting For Connection, (It will take maximum 21 seconds)");
   int osfd=socket(AF_INET,SOCK_STREAM,0);
   setsockopt(osfd, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int));
   struct sockaddr_in adr={ .sin_port=htons(portn), .sin_family=AF_INET };
   struct sockaddr_in vct;
   int b=bind(osfd,(struct sockaddr*)&adr, sizeof(adr));
   int l=listen(osfd,1);
   inet_pton(AF_INET,ip, &adr.sin_addr.s_addr);
   int vctl=sizeof(struct sockaddr_in);
   int sfd=accept(osfd,(struct sockaddr*)&vct, (socklen_t*)&vctl);
   if(sfd==-1 | b==-1){printf ("An error Occured\n");return -1;}
   while (1){
   char request[256];
   char dest[256];
   bzero(request, sizeof(request));
   bzero(dest, sizeof(dest));
   printf ("[AID]---> ");
   scanf("%s %s",request,dest);
   strcat(request, "\0");
   strcat(dest,"\0");
   if (strcmp(request, "stop")==0){exit(0);}
   if (strcmp(dest,"")==0){printf ("[-] Choose a Destination\n");continue;}
   send(sfd,request,strlen(request),0);
   char bof_buffer[100];
   char filesize[10];
   int snd =recv(sfd,filesize,sizeof(filesize),0);
   if (atoi(filesize) == -11){printf ("Received Signal File Not Found\n");bzero(filesize, sizeof(filesize));continue;} 
   char data[atoi(filesize)];
   int snd1=recv(sfd,data,atoi(filesize),0);
   printf ("[+] Recieved Data: %d\n",snd1);
   int fsizer=atoi(filesize);
   if (snd1 == -1){printf ("[-] An Error Occured\n");exit(1);}
   int frg=1;
   char frag[snd1+1];
   int snd5=snd1;
   int rba=0;
   while (snd1 < fsizer){
        printf ("[+]| Receiving TCP Fragment Number %d\n",frg);
       frg++;
       bzero(frag, sizeof(frag));
       rba+=recv(sfd, frag,snd1,0);
       strcat(frag, "\0");
       strcat(data, frag);
       printf ("[+]|-------> Current Size: %d\n",rba);
       if (rba==(fsizer-snd1)){
          printf ("[+] Fragments Received (size: %d)\n",rba+snd1);
          break;
       }
   }
   int fn=open(dest, O_WRONLY|O_CREAT|O_TRUNC);
   printf ("[+] W: Writing %s Byte\n",filesize);
   write(fn,data,sizeof(data));
   close(fn);
   printf ("[+] I: File Downloaded\n");
   bzero(request,sizeof(request));
   bzero(data,sizeof(data));
   bzero(filesize,sizeof(filesize));
   }
}
int main(int argc, char *argv[]){
     int res=recvfile(argv[1], atoi(argv[2]));
     return res;
}
