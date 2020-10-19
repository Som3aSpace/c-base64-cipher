#ifndef BASE64_H_INCLUDED
#define BASE64_H_INCLUDED

typedef struct READ
{
    char input;
    struct READ *next;
}readObj_t;


void scan(void);
void display (void);
void encryption(void);
void decToBin(int temp);
int binToDec(long int temp);
int power(int x,int p);
#endif // BASE64_H_INCLUDED
