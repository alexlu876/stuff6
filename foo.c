#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>

int generate(){
  int fd;
  fd = open("/dev/random", O_RDONLY);
  int ip;
  read(fd, &ip, 4);
  close(fd);
  return ip;
}

int main(){
  int array[10];
  int i;
  printf("Randomly generated data:\n");
  for(i = 0; i < 10; i++){
    array[i] = generate();
    printf("random %d: %d\n", i, array[i]);
  }
  int filed;
  filed = open("bar", O_CREAT | O_RDWR | O_TRUNC, 0777);
  write(filed, array, 40);
  close(filed);
  printf("\n");
  printf("Data written to new file\n");
  int filed2;
  filed2 = open("bar", O_RDONLY, 0777);
  int *a;
  a = (int *)calloc(10, 4);
  read(filed2, a, 40);
  printf("\n");
  printf("Data read from created file\n");
  printf("\n");
  printf("Data, once again:\n");
  int k;
  for(k = 0; k < 10; k++){
    printf("random %d: %d\n", k, a[k]);
  }
  free(a);
  printf("\n");
  printf("It's the same! Woohoo!\n");
  return 0;
}
