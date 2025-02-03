#include <stdio.h>
#include <stdbool.h>

int main(){
    int ac;
    int r_one;
    int r_two;
    printf("Enter a phone number:\n");
    scanf("(%d) %d-%d", &ac, &r_one , &r_two);
    printf("\nThe phone number you entered is:\n%d.%d.%d.\n" , ac, r_one, r_two);
    printf("The area code %d covers -- " , ac);
    if (ac == 231 )
    {printf("northwestern Michigan, including Traverse City, Cadillac, and Muskegon.");}
    if (ac == 248)
        printf("northern suburbs of Detroit, including Troy, Southfield, and Pontiac.");
    if (ac == 269)
        printf("southwestern Michigan, including Kalamazoo, Battle Creek, and Benton Harbor.");
    if (ac == 313 )
        printf("the city of Detroit and some surrounding areas.");
    if (ac == 517 )
        printf("Central Michigan, including Lansing, Jackson, and East Lansing.");
    if (ac == 586)
        printf("the Eastern suburbs of Detroit, including Warren, Sterling Heights, and Clinton Township.");
    if (ac == 616)
        printf("western Michigan, including Grand Rapids, Holland, and Wyoming.");
    if (ac == 734)
        printf("southeastern Michigan, including Ann Arbor, Ypsilanti, and Monroe.");
    if (ac == 810)
        printf("eastern Michigan, including Flint, Port Huron, and Lapeer.");
    if (ac == 906)
        printf("the Upper Peninsula of Michigan, including Marquette, Sault Ste. Marie, and Escanaba.");
    if (ac == 989)
        printf("central and northeastern Michigan, including Saginaw, Bay City, and Midland.");





}