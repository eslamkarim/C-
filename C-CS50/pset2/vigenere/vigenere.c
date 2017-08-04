#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main (int argc , string argv[])
{
     int j=0;

    if(argc ==2)
    {
      for (int g=0,f=strlen(argv[1]);g<f;g++){
          if((65<=(int)argv[1][g]&&(int)argv[1][g]<= 90)||(97<=(int)argv[1][g]&& (int)argv[1][g]<= 122)){
              j=0;
          }
          else{
            printf("usage: ./vigenere k\n");
            return 1;
}}
printf("plaintext: ");

      string text=get_string();
      printf("ciphertext: ");

      for(int i=0 , n = strlen(text) ; i<n ; i++ )
      {
          if(argv[1][j] ==0)
              {
              j=0;   
              }
          
          if(65<=(int)argv[1][j] && (int)argv[1][j] <= 90)
          {
              
           int encrypt= (int) argv[1][j] + (int) text[i] - 65;
            if(encrypt>90){
             encrypt-=26;}
             printf("%c",encrypt);
             j++;
             }
            else if(97<=(int)text[i] && (int)text[i]<= 122)
            {
              
           int encrypt= (int) argv[1][j] + (int) text[i] - 97;
             if(encrypt>122){
             encrypt-=26;}
             printf("%c",encrypt);
             j++;
             }
          else 
            printf("%c",text[i]);
         
          
      }
     
    }
    else {
    printf("usage: ./vigenere k\n");
    return 1;
        
    }
    printf("\n");
}
   