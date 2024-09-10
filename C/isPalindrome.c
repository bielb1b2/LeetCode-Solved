#include <stdio.h>

int main(void) {
  int N = 121;
  char c[12];

  sprintf(c, "%d", N);
  
  int begin = 0;
  int end = -1;
  for (int size = 0; c[size] != '\0'; size++) {
    end++;
  }
  for (; begin < end; begin++, end--) {
    if (c[begin] != c[end]) {
      printf("Not palindrome\n");
      return 1;
    }
  }
  printf("palindrome\n");
  return 0;
}