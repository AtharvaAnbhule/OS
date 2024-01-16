#include <stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include <unistd.h>
void forke(){
     int p=fork();
    
    if(p==0){
        printf("Child Process");
    }
    else if(p==-1){
        printf("Invalid");
    }
    else if(p==1){
        printf("Parent process");
    }
}
int main() {
   
   forke();
    return 0;
}
