#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <stdint.h>
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr,"Usage: ./recover image\n");
        return 1;
    }
    FILE *card;
    card= fopen(argv[1],"r");
    if (card == NULL)
    {
     fprintf(stderr, "Could not open .\n");
        return 2;
    }
    char name[8];
    int count=0;
    bool jpg_start=false;
    uint8_t buffer[512];
    FILE *img=NULL;
    while(fread(buffer,1,512,card)!=0){
    
    if(buffer[0]==0xff&&buffer[1]==0xd8&&buffer[2]==0xff&&(buffer[3]&0xf0)==0xe0){
            if (img != NULL)
            {
                fclose(img);
            }
                sprintf(name,"%03i.jpg",count);
                img=fopen(name,"w");
                count++;
        fwrite(&buffer,1,512,img);
        jpg_start=true;
        }
    else {
        if (img != NULL)    
            fwrite(&buffer,1,512,img);
    }}
    fclose(card);
    if(img !=NULL)
    fclose(img);
   return 0;
}