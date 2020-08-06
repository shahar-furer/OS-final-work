#include <errno.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>

pid_t p_id;
int main(int argc, char* argv[])  
{ 
    p_id = atoi(argv[1]);
 if(kill(p_id ,0)==-1){
     if(errno==EPERM) {
         printf("Process %d exists but we have no permission.\n" , p_id);
         return 0;
     }

     else if(errno==ESRCH) {
         printf("Process %d does not exist\n" , p_id);
         return 0;
     }
 }

 printf("process %d exists\n" , p_id) ;
   
    return 0; 
} 