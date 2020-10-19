#include <stdio.h>
#include <stdlib.h>
#include "base64.h"

char charArr[64]={0};

int main()
{
    int i,j,x;


    for(i=0;i<=25;i++)
    {
        charArr[i]=65+i;
        printf("%c",charArr[i]);
    }

    for(j=0,i=26;i<=51;i++,j++)
    {
        charArr[i]=97+j;
        printf("%c",charArr[i]);
    }
        for( j=0,i=52;i<=61;i++,j++)
    {
        charArr[i]=48+j;
        printf("%c",charArr[i]);
    }
    charArr[62]='+';
    charArr[63]='/';

    while(1)
    {
    printf("\n1>enter mess 2>print 3>exit 4>encryption\n");
     fflush(stdin);
    scanf("%d",&x);
    switch (x)
    {
        case 1:scan(); break;
        case 2:display();break;
        case 4:encryption();break;
        case 3:return 0;

            }
    }
    return 0;

}
