// ******************************* WRITE PART ********************************************
#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include <sys/shm.h>
#include <string.h>

int main()
{
	int i;
    void* shared_memory;
    char buff[100];

    int shmid;
    shmid = shmget((key_t)2345, 1024, 0666|IPC_CREAT);

    printf("key of shared memory is %d\n", shmid);
    shared_memory = shmat(shmid, NULL, 0);

    printf("Process attached at %p \n", shared_memory);
    printf("enter same data to write to shared memory\n");
    read(0, buff, 100);
    strcpy(shared_memory, buff);
    printf("you wrote: %s", (char*)shared_memory);

	return 0;
}




// *********************************** READ PART *****************************************

#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include <sys/shm.h>
#include <string.h>

int main()
{
	int i;
    void* shared_memory;
    char buff[100];

    int shmid;
    shmid = shmget((key_t)2345, 1024, 0666|IPC_CREAT);

    printf("key of shared memory is %d\n", shmid);
    shared_memory = shmat(shmid, NULL, 0);

    printf("Process attached at %p \n", shared_memory);

    printf("data read from shared memory is: %s", (char*)shared_memory);

	return 0;
}