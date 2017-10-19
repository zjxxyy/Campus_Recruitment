#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(int arg, char *args[])
{
  int fd1=open("a.txt",O_RDONLY);
  int fd2=open("b.txt",O_RDONLY);
  printf("fd1=%d,fd2=%d\n",fd1,fd2);

  return EXIT_SUCCESS;
}
