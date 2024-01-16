#include <stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include <unistd.h>
void forke(){
     int p=fork();
    
    if(p==0){
        printf("\nChild Process\n");
        printf(" \nthe Id of child process  is -: %d",getpid());
    }
    else if(p==-1){
        printf("\nInvalid");
    }
    else if(p==1){
        printf("\nParent process");
        printf(" \nthe Id of Parent process  is -: %d",getpid());
    }
}
int main() {
   
   forke();
   forke();
   printf("\nhello");
   
    return 0;
}
