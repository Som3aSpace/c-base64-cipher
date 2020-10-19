#include <stdio.h>
#include <stdlib.h>
#include "base64.h"

readObj_t *front=NULL,*end=NULL;
int z=0;
char x[8]={0};

extern char charArr[];


void scan()
{

    printf("enter the message\n");
    char temp;
    fflush(stdin);
    while(1)
    {
        struct READ *newNode;
        newNode=malloc(sizeof(readObj_t));

        scanf("%c",&temp);
        if (temp=='\n')
        {
            break;
        }
        newNode->input=temp;
        newNode->next=NULL;
        if(front==NULL)
            {
                front=end=newNode;
            }
        else
        {
            end->next=newNode;
            end=newNode;
        }
        z++;

    }






}

void display(){

    struct READ *temp=front;
     if(front==NULL){
        printf("the queue is empty\n");
    }
    else{
    while(temp->next != NULL){
        printf("%c > ",temp->input);
        temp=temp->next;
    }
printf("%c",temp->input);
}
}




//////////////////
void encryption()
{
    printf("z=%d\n",z);
    int i,j,k,d,temp,f,index=0,q=0;
    long int temp1=0;
    char bitArr[24];



    for(d=0;d<z;d=d+3)
        {
            for(f=0;f<24;f++)
            {
                bitArr[f]=0;
            }
            f=0;
            for(j=0;j<3;j++)
                {
                    q++;
                    if(q>z)
                    {
                        break;
                    }
                    temp=front->input;
              //      printf("%d",temp);
                //    printf("\n");
                    front=front->next;
                    decToBin(temp);
                    for(k=7;k>=0;k--)
                    {
                        bitArr[f]=x[k];
                        f++;
                    }


                }

                printf("bitArr");
        for(i=0;i<24;i++)
        {
            printf("%d",bitArr[i]);
        }
        printf("\n");

        k=0;
        for (i=0;i<4;i++)
        {
            temp1=0;
            for (j=6;j>0;j--)
            {

                //printf("\nbitArr=%d\n",bitArr[k]);
                temp1=temp1+ bitArr[k]*power(10,(j-1));
                k++;
                //printf("\ntemp1=%ld\n",temp1);
               // printf("k=%d\n",k);
                //printf("\nbitArr=%d\n",bitArr[k]);
            }
               // printf("%ld\n",temp1);
                index=binToDec(temp1);
                printf("temp1=%ld index=%d",temp1,index);//index is wrong
               printf("%c",charArr[index]);
        }



        }



}

void decToBin(int temp)
{
    int i=0,j=0;
if (temp==0) //to check if user entered zero
        {
            return;
        }
    else
        {

            for (i=0;temp!=0;i++)
        {
            if (temp%2==0)
            {
             x[i]=0;
             temp=temp/2;
            }
        else
        {
            x[i]=1;
            temp=temp/2;
        }
        }
        /*for (j=i-1;j>=0;j--)
        {
            printf("%d",x[j]);
        }*/
    }
}


int binToDec(long int temp)
{
    int dec=0,k;
                                   // printf("tempdecinput=%ld\n",temp);

    for (k=0;temp!=0;k++)
        {
                                //printf("tempdec=%ld\n",temp);

            if (temp%2==1)
            {
                dec=dec+pow(2,k);
                temp=temp/10;
            }
            else
            {
               temp=temp/10;
            }
                    printf("dec=%d\n",dec);

        }

    return dec;
}


int power(int x,int p){
if(p==0)
    return 1;
return x*power(x,p-1);
}
