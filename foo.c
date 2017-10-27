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
  for(i = 0; i < 10; i++){
    array[i] = generate();
    printf("random %d: %d\n", i, array[i]);
  }
  int filed;
  filed = open("bar", O_CREAT | O_RDWR | O_TRUNC, 0777);
  write(filed, array, 40);
  int arr[10];
  read(filed, arr, 40);
  int k;
  for(k = 0; k < 10; k++){
    printf("random %d: %d\n", k, arr[k]);
  }
  return 0;
}
  

