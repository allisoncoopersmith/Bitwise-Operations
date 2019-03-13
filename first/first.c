#include<stdio.h>
#include<stdlib.h>

int get (int number, int bitPosition) {
  int getValue = (number >> bitPosition) & 1;
  return getValue;
}

int set (int number, int bitPosition, int set) {
  int setValue;
  if (set == 0) {
    setValue = number & ~(1 << bitPosition);
  }
  else {
    setValue = (1 << bitPosition) | number;
  }
  return setValue;
}

int comp (int number, int bitPosition) {
  int compValue;
  int compTemp = get(number, bitPosition);
  if (compTemp ==0) {
    compValue = set(number, bitPosition, 1);
  }
  else {
    compValue = set(number, bitPosition, 0);
  }
  return compValue;
}

int main(int argc, char** argv){
  unsigned short num;
  char command[10];
  int firstVal;
  int secondVal;
  unsigned short getValue;

  if (argc < 2) {
    printf ("Error\n");
    return 0;
  }

  FILE* fl;
  fl=fopen(argv[1],"r");

  if (fl == NULL) {
    printf("error\n");
    return 0;
  }

  fscanf(fl,"%hd\n",&num);

  while(fscanf(fl,"%s\t %d\t %d\n",command,&firstVal,&secondVal)!=EOF){
    if (command[0]=='s') {
      num = set(num, firstVal, secondVal);
      printf("%d\n", num);
    }
    if (command[0]=='g') {
      getValue = get(num, firstVal);
      printf("%d\n", getValue);

    }
    if (command[0]=='c') {
      num=comp(num, firstVal);
      printf("%d\n", num);
    }
}
fclose(fl);
return 0;
}
