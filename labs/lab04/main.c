#include <stdio.h>
#include<stdbool.h>

int main(){
    printf("Enter an operator <*, /, +, ->:\n");
    char op;
    scanf("%c",&op);
    float num1, num2;
    printf("Enter operand 1:\n");
    scanf("%f",&num1);
    printf("Enter operand 2:\n");
    scanf("%f",&num2);
    float ans;
    switch(op){
    case '*':
      ans = num1 * num2;
      break;
    case '/':
      ans = num1 / num2;
    case '+':
      ans = num1 + num2;
    case '-':
      ans = num1 - num2;
      break;
     default:
      printf('nothing computed');



    }

  if (ans > 0 || ans < 0){
    printf("ans = %.2f\n",ans);
  }





}



