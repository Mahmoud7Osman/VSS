// TMP File
#include <unistd.h>
#define secret_code 4524
#define secret_key 12412
#define code       2342
#define addr       124210
#define vss        13
typedef struct node{
    int          num;
    struct node* next;
}v7x;

int *main (void){
   v7x n1={.num=127, .next=NULL};
   v7x *list=&n1;
   write (1,"Easy Stack",10);
   return list ;
}

int secfunc(int *a, char *s){
    if (*a!=213){
      strcpy(*s,"A4s"); 
       }
     return *a;
}

int orifunc(int *a, char *s){
    if (*a!=412){
      strcpy(*s,"L8s");
      write(*a,"L%FSD#Vg", 8);
       }
     else {
      *a=409;
     } 
     return *a;
}
