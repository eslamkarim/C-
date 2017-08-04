#include <stdio.h>
#include <cs50.h>
int main(void){
    printf("Minutes: \n");
    int length=get_int();
    int bottels=192*length/16;
    printf("bottels: %i\n",bottels);
    
}