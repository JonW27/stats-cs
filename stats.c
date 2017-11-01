#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

char * getSize(int size){
  char *a = malloc(20);
  if(size < 1000){
    sprintf(a, "%dB", size);
  }
  else if(size < 1000000){
    sprintf(a, "%dkB", size/1000);
  }
  else if(size < 1000000000){
    sprintf(a, "%dMB", size/1000000);
  }
  else{
    sprintf(a, "%dGB", size/1000000000);
  }
  return a;
}

int main(){
  struct stat f;
  stat("foo", &f);

  printf("file size: %d\n", f.st_size);
  printf("permissions: %d\n", f.st_mode);
  printf("last accessed: %s\n", ctime(&f.st_atime));

  
  printf("human readable file size: %s\n", getSize(f.st_size));
  
  
  return 0;
}
