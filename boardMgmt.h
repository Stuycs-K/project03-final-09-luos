#ifndef BOARD_MGMT_H
#define BOARD_MGMT_H
struct cell {
  char* designation;
  int marker;
};
int update_data(char *dat_path);
int add_data(char *dat_path);
int read_data(char *dat_path);
#endif
