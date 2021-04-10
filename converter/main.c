#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

char dkey[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ~!@#$%^&*()}{]['/?><.,:;|_-+=1234567890\n ";
char ekey[]="\n0987654321=+-_|;:,.<>?/'[]{})(*&^%$#@!~ZYXWVUTSRQPONMLKJIHGFEDCBAzyxwvutsrqponmlkjihgfedcba ";
int ofd;
int fd;
char ned[10000000];
int found=0;
static void convert(char dte[],int fdc){
      for (int byte=0; byte<strlen(ned);byte++){
         for (int num=0; num<=strlen(dkey);num++){
          if (dte[byte]==dkey[num]){
          write(fdc,&ekey[num],1);
          num=0;
          found=0;
          break;
          }
          else{found=1;}
         }
        if (found==1){write(fdc,&dte[byte],1);}
      }

}
int main(int argc, char *argv[]){

  if (argc<2){printf("%s: Need some Arguments\n",argv[0]); exit(1);}
  ofd=open(argv[2],O_WRONLY|O_TRUNC|O_CREAT,S_IRUSR);
  fd=open(argv[1], O_RDONLY);

  read(fd,ned,sizeof(ned));
  convert(ned,ofd);

  close (fd);
  close (ofd);
  return 0;
}
