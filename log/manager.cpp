#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include "colors.h"

int file=open("log/log.vcc",O_RDWR|O_APPEND|O_CREAT);

void print(char const t[]){
   write(file, t, strlen(t));
}
void log(char const text[]){
      print (KGRN);
      print ("[+] ");
      print (KBLU);
      print (" ->  ");
      print (KNRM);
      print (text);
      print ("\n");
}

int main(int argc, char const *argv[]){
      int arg=1;
      char msg[200];
      for (arg; arg<argc; arg++){
        strcat(msg, argv[arg]);
        strcat(msg," ");
      }
      strcat(msg,"\0");
      log(msg);
}
