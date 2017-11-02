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

char * get_single_permission(int n){
  if (n == 7) return "rwx";
  if (n == 6) return "rw-";
  if (n == 5) return "r-x";
  if (n == 4) return "r--";
  if (n == 3) return "-wx";
  if (n == 2) return "-w-";
  if (n == 1) return "--x";
  printf("Something went wrong");
  exit(0);
}



char * get_all_permissions(mode_t p){
  char * permissions = malloc(32);
  //printf("%o\n", p);
  int other = p % 8;
  p = p / 8;
  //printf("%o\n", p);
  int group = p % 8;
  p = p / 8;
  // printf("%o\n", p);
  int user = p % 8;
  // printf("%o\n", p);
  // printf("%d\n", user);
  sprintf(permissions, "%s%s%s", get_single_permission(user), get_single_permission(group), get_single_permission(other));
  return permissions;
}

int main(){
  struct stat f;
  stat("foo", &f);

  printf("file size: %lld\n", f.st_size);
  printf("permissions: %o\n", f.st_mode);
  printf("last accessed: %s\n", ctime(&f.st_atime));


  printf("human readable file size: %s\n", getSize(f.st_size));

  printf("Permissions in ls -l form:\n%s\n", get_all_permissions(f.st_mode));

  return 0;
}
