#include <stdio.h>

int main(){
    float v; //initialize variables
    float t;
    float a;
    printf("Enter initial velocity:\n");
    scanf("%f", &v); //ask for user for a float and assign it to its corresponding variable
    printf("Enter time elapsed:\n");
    scanf("%f", &t);
    printf("Enter acceleration:\n");
    scanf("%f", &a);
    printf("\n");
    float d = v*t + (a*(t*t))*.5; //run calculation by doing velocity*time+((acceleration*t^2)/2)
    printf("Initial velocity:\t%f\n" , v);//print user inputs
    printf("Time elapsed:\t\t%f\n" , t); //double tab to line up outputs
    printf("Acceleration:\t\t%f\n" , a);
    printf("Distance travelled:\t%f\n" , d);
    printf("\n");
    printf("Distance travelled correct to 2 decimal places is %.2f.", d); //print the calculation


}
