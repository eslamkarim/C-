#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
int main(void)
{
    int i=0,m=0;
    string name=get_string();
    //check for the null character
    while(name[i]!='\0'){
       //loop over the whole string
        for(int j=0, n=strlen(name); j<n ; j++){
    //check the first character of the string
    if(name[m]!=32 && m==0){
    printf("%c",toupper(name[0]));
    m=1;
    }
    //check for spaces if exsist 
    if(name[i]==' '){
        i++; //iterate i then check the next character
        if(name[i] !=32 && name[i] !=0 )
        printf("%c",toupper(name[i]));
    }
     else
     i++;
    }
    printf("\n");
}
}