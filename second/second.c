#include<stdio.h>
#include<stdlib.h>

int countBits(unsigned int number) {
  int count=0;
  while (number !=0) {
    number = number >> 1;
    count++;
  }
  return count;
}

int main(int argc, char** argv){
  int allOneCounter=0;
  int oneCounter=0;
  int pairCounter=0;
  if (argc < 2) {
    printf ("Error\n");
    return 0;
  }
  unsigned int number = atoi(argv[1]);
  int bits = countBits(number);

  for (int x=0; x<bits; x++){
    int temp = number;
    if (((temp >> x) & 1)==0) {
      oneCounter = 0;
    }
    else if (((temp >> x) & 1)==1) {
      allOneCounter++;
      oneCounter++;
      if (oneCounter==2) {
        pairCounter++;
        oneCounter=0;
      }
    }
  }
  if (allOneCounter % 2 == 0) {
    printf("Even-Parity");
    printf("\t");
  }
  else {
    printf("Odd-Parity");
    printf("\t");
  }
  printf("%d\n", pairCounter);
  return 0;
}
