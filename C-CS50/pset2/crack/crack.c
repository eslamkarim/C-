#define _XOPEN_SOURCE 400
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <crypt.h>
int main(int argc, string argv[])
{
    if(argc !=2){
    printf("Usage: ./crack hash\n");
    return 1;}
    else{
    string hash = argv[1];
    string password;
    char pass[]={'\0','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char array[5];
    for(int i=0;i<56;i++){
        for(int j=0;j<56;j++){
           for(int k=0;k<56;k++){
        for(int l=0;l<56;l++){
            array[0]=pass[l];
            array[1]=pass[k];
            array[2]=pass[j];
            array[3]=pass[i];
            array[4]='\0';
            password=crypt(array,"50");
            if(strcmp(password,hash)==0){printf("%s\n",array);
            return 0;
            }}}}}}}