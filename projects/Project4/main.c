#include <stdio.h>
#include <stdbool.h>

int main(){
  int choice;
  float ans;
  int credits;
  float freshman_per_credit = 537.5;
  float freshman_flat_rate = 8059.00;

  float sophomore_flat_rate = 8254.00;
  float sophomore_per_credit = 550.25;

  float junior_flat_rate = 9536.00;
  float junior_per_credit = 635.5;

  float senior_flat_rate = 9536.00;
  float senior_per_credit = 635.5;
  printf("College of Engineering Fees Calculator.\n\n");
  printf("Enter <1> for freshman.\n");
  printf("Enter <2> for sophomore.\n");
  printf("Enter <3> for junior.\n");
  printf("Enter <4> for senior.\n");
  printf("Enter your choice:\n");
  scanf("%d",&choice);
  printf("Enter no. of credits:\n");
  scanf("%d",&credits);
  if(choice == 1){
    if(credits >= 6 && credits < 11){
      ans = freshman_per_credit * credits + 21 + 5 + 7.5;
      }
    else if (credits < 6)  {
      ans = freshman_per_credit * credits + 21 + 5;
      }
    else if (credits > 12 && credits <= 18){
        ans = (freshman_flat_rate) + 21 + 5 + 7.5;
      }
    else if (credits >= 19){
        ans = freshman_flat_rate + (freshman_per_credit * (credits-18)) + 21 + 7.5 + 5;
        }
  }
  if(choice == 2) {
    if(credits >= 6 && credits < 11){
      ans = sophomore_per_credit * credits + 21 + 5 + 7.5;
    }
    else if (credits < 6)  {
      ans = sophomore_per_credit * credits + 21 + 5;
    }
    else if (credits > 12 && credits < 18){
      ans = sophomore_flat_rate + 21 + 5 + 7.5;
    }
    else if (credits >= 19){
      ans = sophomore_flat_rate + (sophomore_per_credit * (credits-18)) + 21 + 7.5 + 5;
    }
  }
  if(choice == 3) {
    if(credits >= 6 && credits < 11){
      ans = junior_per_credit * credits + 21 + 5 + 7.5;
    }
    else if (credits < 6)  {
      ans = junior_per_credit * credits + 21 + 5;
    }
    else if (credits > 12 && credits < 18){
      ans = junior_flat_rate + 21 + 5 + 7.5;
    }
    else if (credits >= 19){
      ans = junior_flat_rate + (junior_per_credit * (credits-18)) + 21 + 7.5 + 5;
    }
  }
  if(choice == 4){
    if(credits >= 6 && credits < 11){
      ans = senior_per_credit * credits + 21 + 5 + 7.5;
    }
    else if (credits < 6)  {
      ans = senior_per_credit * credits + 21 + 5;
    }
    else if (credits > 12 && credits < 18){
      ans = senior_flat_rate + 21 + 5 + 7.5;
    }
    else if (credits >= 19){
      ans = senior_flat_rate + (senior_per_credit * (credits-18)) + 21 + 7.5 + 5;
    }
  }
printf("Your fee is: %.2f." , ans);

  }