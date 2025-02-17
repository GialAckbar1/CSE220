#include <stdio.h>
#include <stdbool.h>

int main(){
  int n;
  printf("Enter a number:\n");
  scanf("%d", &n);
  int count = 0;
  bool loop = true;
  while(loop){
    if(n % 2 >= 1)
    {
      printf("%d is odd.\n", n);
      n = (n*3)+1;
      printf("Next number is %d.\n", n);
      count++;
    }
    else{
      printf("%d is even.\n", n);
      n = n/2;
      printf("Next number is %d.\n", n);
      count++;
    }
    if(n == 1){
      printf("That took %d steps.", count);
      break;

     }




  }


}
