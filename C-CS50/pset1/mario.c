#include <stdio.h>
#include <cs50.h>
int main (void){
    int height =-1;
    do{
    printf("height: ");
     height=get_int();
    }while(height<0||height>23);
    int x=height;
    for(int i=1;i<=x;i++){
        for ( int j=height-1;j>0;j--){
            printf(" ");
            
        }
        for(int m=0;m<i;m++){
            printf("#");
        }
        printf("  ");
        height--;
        for(int m=0;m<i;m++){
            printf("#");
        }
        printf("\n");
    }
}