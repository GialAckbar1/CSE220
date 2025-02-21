#include <stdio.h>


int main(){
  char c;
  char s[100];
  int i = 0;
  int c_count = 0;
  int word = 0;
  int word_count = 0;
  printf("Enter the character string:\n");
  do {
    c = getchar();
    if (c != '\n') {
      s[i] = c;
      i++;
    }
  }while (c != '\n' && i < 100);
  s[i] = '\0';

  for (int j = 0; j < i; j++) {
    if (s[j] != ' ') {
      c_count++;
      if (!word) {
        word_count++;
        word = 1;
      }
    }else {
      word = 0;
    }


  }
  float average = (word_count > 0) ? (float)c_count / word_count : 0;
  printf("Length of input string = %d.\n", i);
  printf("Sum of characters in all words = %d.\n", c_count);
  printf("Number of words = %d.\n", word_count);
  printf("Average length = %.1f.\n", average);

}
