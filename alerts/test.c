// TMP  Header File 

#include <unistd.h>

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
