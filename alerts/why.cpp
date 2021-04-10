#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

void print(char const string[]){
 for (int a=0;a<=strlen(string);a++){
    write(1,&string[a],1);
    system("sleep 0.03");
}

 printf ("\n");
 for (int a=0;a<=strlen(string);a++){
    write (1,"-",1);
    system("sleep 0.01");
}
 sleep(2);
 printf ("\n");
}


int main(){
   print("This tool is for Post Exploitation Purposes, please use it with caution !!!!");
}
