#include <stdio.h>
int main(){
  int days;
  printf("Enter the number of days: \n");
  scanf("%d",&days);
  int years = (days / 365.0);
  int weeks = ((days - (years*365))/7);
  days = (days % 365) - weeks * 7;
  printf("No. of years: %d\n",years);
  printf("No. of weeks: %d\n",weeks);
  printf("No. of days : %d\n",days);
  return 0;
}
