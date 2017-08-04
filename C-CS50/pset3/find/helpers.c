/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int first=0,last=n-1,middle=(first+last)/2;
    if(value==values[0])
    return true;
    if (n<0)
    return false;
    
    for(int i=0;i<=n;i++){
        if(value<values[middle])
        {
            last=middle-1;
            
        }
        else if(value > values[middle])
        {
            first=middle+1;
            
        }
        else if (value==values[middle])
        {
            return true;
            
        }
        middle=(first+last)/2;
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int array[65536]={0};
    int s=0;
    for(int i=0;i<n;i++)
    {
        array[values[i]]+=1;
    }
    
    for(int x=0;x<65536;x++){
    
    while(array[x]>0){
        
        values[s]=x;
        array[x]-=1;
        s+=1;
    }
   
}
    return;
}
