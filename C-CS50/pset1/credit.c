#include <stdio.h>
#include <cs50.h>
#include <math.h>
int main(void){
int sum=0,sum2=0;
    printf("Number: ");
    long long number=get_long_long();
    int digits=log10(number)+1;
    if(digits==15){
        if(number/10000000000000==37||number/10000000000000==34){
           
           long long division=10000000000000;
           
            for(int i=0;i<7;i++){
                long long answer=number/division;
                 long long answer2=number*10/division;
            int x=answer%10;
            int x2=answer2%10;
            sum2+=x2;
            x*=2;
           int modulus=x%10;
           int division2=x/10;
                sum=sum+modulus+division2;
               division/=100;
            }
            sum=sum+sum2+number/100000000000000;
           if(sum%10==0)
           printf("AMEX\n");
           else
           printf("INVALID\n");

           
        }
        else
        printf("INVALID\n");
    }
    else if (digits==13){
       if(number/1000000000000==4){
            long long division=100000000000;
           
            for(int i=0;i<6;i++){
                long long answer=number/division;
                 long long answer2=number*10/division;
            int x=answer%10;
            int x2=answer2%10;
            sum2+=x2;
            x*=2;
           int modulus=x%10;
           int division2=x/10;
                sum=sum+modulus+division2;
               division/=100;
            }
            sum=sum+sum2+number/1000000000000;
           if(sum%10==0){
           printf("VISA\n");
           }
        else{
           printf("INVALID\n");
}
           
        }
       
       else{
       printf("INVALID\n");}
    
    }
    else if (digits==16){
        
        if(number/1000000000000000==4){
  long long division=10;           
            for(int i=0;i<8;i++){
                long long answer=number/division;
                 long long answer2=number*10/division;
            int x=answer%10;
            int x2=answer2%10;
            sum2+=x2;
            x*=2;
           int modulus=x%10;
           int division2=x/10;
                sum=sum+modulus+division2;
               division*=100;
            }
            sum=sum+sum2;
           if(sum%10==0){
           printf("VISA\n");
           }
            else{
           printf("INVALID\n");
}
        }
        else if(number/1000000000000000==5){
            if(number/100000000000000==51||number/100000000000000==52||number/100000000000000==54||number/100000000000000==55){
                long long division=10;
           
            for(int i=0;i<8;i++){
                long long answer=number/division;
                 long long answer2=number*10/division;
            int x=answer%10;
            int x2=answer2%10;
            sum2+=x2;
            x*=2;
           int modulus=x%10;
           int division2=x/10;
                sum=sum+modulus+division2;
               division*=100;
    
            }
            sum=sum+sum2;
            
           if(sum%10==0){
           printf("MASTERCARD\n");
           }
            else{
           printf("INVALID\n");
}
            }
            
        }
        else{
        printf("INVALID\n");}
        
        
    }
    else
    printf("INVALID\n");
    
}