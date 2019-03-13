#include<stdio.h>
#include<stdlib.h>

unsigned short reverseBits(unsigned short number) {
  unsigned short reversedNumber = 0;
  int i;
  int temp;

  for (i = 0; i < 17; i++) {
       temp = (number & (1 << i));
       if(temp) {
           reversedNumber |= (1 << ((16- 1) - i));
        }
   }

   return reversedNumber;
}

int main(int argc, char** argv){
  if (argc < 2) {
    printf ("Error\n");
    return 0;
  }
  unsigned short number = atoi(argv[1]);
  unsigned short reversedNumber = reverseBits(number);
  if (number == reversedNumber) {
    printf("Is-Palindrome");
    printf("\n");
  }
  else {
    printf("Not-Palindrome");
    printf("\n");
  }
  return 0;
}
