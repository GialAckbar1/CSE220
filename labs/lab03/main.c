#include <stdio.h>
#include <stdbool.h>
    int main()
{
    int n1;
    int n2;
    int n3;
    int n4;
    int n5;
    int max = 0;
    printf("Enter 5 integers:\n");
    scanf("%d",&n1);
    scanf("%d",&n2);
    scanf("%d",&n3);
    scanf("%d",&n4);
    scanf("%d",&n5);
    if (n1 > n2){
      max = n1;
    }
    if(max < n3)
      {
      max = n3;
      }
    if(max < n4)
      {
      max = n4;
      }
    if(max < n5)
      {
       max = n5;
      }
    printf("Largest number, max, is: %d.\n" , max);
    bool d2 = true;
    bool d3 = true;
    bool d5 = true;
    bool d7 = true;
    if(max % 2 == 0) {
      d2 = true;
      printf("%d is divisible by 2\n" , max);
    } else {d2 = false;}
    if(max % 3 == 0) {
      printf("%d is divisible by 3\n" , max);
      d3 = true;
    }else {d3 = false;}
    if(max % 5 == 0) {
      printf("%d is divisible by 5\n" , max);
      d5 = true;
    }else {d5 = false;}
    if(max % 7 == 0) {
      printf("%d is divisible by 7\n" , max);
      d7 = true;
    }else {d7 = false;}
    if(!d2 && !d3 && !d5 && !d7) {
      printf("%d is not divisible by any prime number from 2 to 7");

    } else{printf("nothing else");}



  return 0;
  }
