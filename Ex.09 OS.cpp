#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
int main() {
    int shmid;
    key_t key = ftok("shared_memory_example", 65);
    shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    char* shared_memory = (char*)shmat(shmid, (void*)0, 0);
    sprintf(shared_memory, "Hello from the parent process!");
    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }
    if (pid == 0) {
        char* child_shared_memory = (char*)shmat(shmid, (void*)0, 0);
        printf("Child process: %s\n", child_shared_memory);
        shmdt(child_shared_memory);
    } else {
        wait(NULL);
        shmdt(shared_memory);
        shmctl(shmid, IPC_RMID, NULL);
    }
    return 0;
}