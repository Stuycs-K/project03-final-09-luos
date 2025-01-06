#ifndef BOARD_MGMT_H
#define BOARD_MGMT_H
struct cell {
  char* designation;
  int marker;
};
int update_data(char *dat_path);
int read_data(char *dat_path);
int read_csv(char *csv_path, char *dat_path);
void setup();
#endif
