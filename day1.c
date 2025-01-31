
#include <stdio.h>
#include <stdbool.h>
    int main() {

        int i;
        printf("Enter a number: \n");
        scanf("%d", &i);
        bool b = i > 5;
        if(i % 4 == 0 && i % 400== 0 &&) {
            printf("Number is a leap year\n");
        }else
            printf("Number is not a leap year\n");
        return 0;
    }

