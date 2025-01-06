#include "boardMgmt.h"

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


int add_data(char *dat_path) {
  // char line[LINE_SIZE];
  // printf("Enter [year] [pop] [boro]: ");
  // if (fgets(line, LINE_SIZE, stdin) == NULL) {
  //   printf("%s\n",strerror(errno));
  //   return errno;
  // }
  // struct pop_entry entry;
  // sscanf(line, "%d %d %s", &(entry.year), &(entry.population), entry.boro);
  //
  // int wT = open(dat_path, O_WRONLY | O_APPEND | O_CREAT, 0650);
  // if (wT == -1) {
  //   printf("%s\n",strerror(errno));
  //   return errno;
  // }
  //
  // int bytes = write(wT, &entry, sizeof(struct pop_entry));
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
