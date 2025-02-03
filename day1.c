#include <stdio.h>

int main() {
    float fah;
    printf("Enter the Fahrneheit\n");
    scanf("%f", &fah);
    float cel = (fah-32)*(5/9);
    printf("celsius= %f\n" , cel);

}

