#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "boardMgmt.h"

#define SMALL 3
#define LARGE 9

int update_data(char *dat_path) {
  // read_data(dat_path);
  // char line[LINE_SIZE];
  //
  // int index = 0;
  // printf("Entry to update: ");
  // if (fgets(line, LINE_SIZE, stdin) == NULL) {
  //   printf("%s\n",strerror(errno));
  //   return errno;
  // }
  // sscanf(line, "%d", &index);
  //
  // printf("Enter [year] [pop] [boro]: ");
  // if (fgets(line, LINE_SIZE, stdin) == NULL) {
  //   printf("%s\n",strerror(errno));
  //   return errno;
  // }
  // struct pop_entry entry;
  // sscanf(line, "%d %d %s", &(entry.year), &(entry.population), entry.boro);
  //
  // int fd = open(dat_path, O_RDWR | O_CREAT, 0650);
  // lseek(fd, index*sizeof(struct pop_entry), SEEK_SET);
  // int bytes = write(fd, &entry, sizeof(struct pop_entry));
  // if (bytes == -1) {
  //   printf("%s\n",strerror(errno));
  //   return errno;
  // }

  printf("Done!\n");
  return errno;
}


int read_data(char *dat_path) {
  int fd = open(dat_path, O_RDONLY);

  struct stat sB;
  stat(dat_path, &sB);
  int SIZE = sB.st_size / sizeof(struct cell);

  struct cell entries[SIZE];
  int bytes;
  for (int i = 0; i < SIZE; i++) {
    bytes = read(fd, &entries[i], sizeof(struct cell));
    if (bytes == -1) {
      printf("%s\n",strerror(errno));
      return errno;
    }
    printf("%s %d\n", entries[i].designation, entries[i].marker);
  }

  return errno;
}


void setup() {
  // Create the dat file
  int fd = open("board.dat", O_RDWR, 650);

  for (int i = 0; i < SMALL; i++) {
    for (int j = 0; j < SMALL; j++) {
      struct cell;
      // deal with designation
      cell.marker = 0;
    }
  }

}
