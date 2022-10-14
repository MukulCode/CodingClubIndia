#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    
    int fd[2], n;
    char buff[100];
    
    pid_t p;
    pipe(fd);
    p = fork();
    
    if(p > 0){      // parent process
        printf("Parent passing value to child\n");
        write(fd[1], "hello\n", 6);     // fd[1] is the write end
        
    }else{         // child process
        
        printf("Child printing the received value\n");
        n=read(fd[0], buff, 100);
        write(1, buff, n);
    }
    return 0;
}