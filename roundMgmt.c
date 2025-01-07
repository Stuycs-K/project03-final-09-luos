#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>

#define SH_KEY 68266667
#define SEM_KEY 45687711
#define LINE_SIZE 500

union semun {
  int val;                  //used for SETVAL
  struct semid_ds *buf;     //used for IPC_STAT and IPC_SET
  unsigned short  *array;   //used for SETALL
  struct seminfo  *__buf;
};

int setupRsrces() {
  int shmid = shmget(SH_KEY, sizeof(int), IPC_CREAT | 0666);
  if(shmid < 0) {
    perror("Failed to get shared memory");
    return errno;
  }

  int semd = semget(SEM_KEY, 1, IPC_CREAT | IPC_EXCL | 0666);
  if(semd < 0) {
    perror("Failed to get semaphore");
    return errno;
  }
}

int connect() {
  printf("\nAttempting to open resource...\n");
  int shmid = shmget(SH_KEY, sizeof(int), 0666);
  if(shmid < 0) {
   perror("Failed to get shared memory");
   return errno;
  }

  int semd = semget(SEM_KEY, 1, 0666);
  if(semd < 0) {
   perror("Failed to get semaphore");
   return errno;
  }

  struct sembuf sb;
  sb.sem_num = 0;
  sb.sem_flg = SEM_UNDO;
  sb.sem_op = -1; //setting the operation to down

  semop(semd, &sb, 1); //perform the operation

  printf("Resource opened.\n");

  //shmat

  sb.sem_op = 1; //set the operation to up
  semop(semd, &sb, 1); //perform the operation

  printf("\nResource closed.\n\n");
}
