#include<stdio.h>
#include<stdlib.h>
#include <string.h>

//returns the value of the nth bit of the number x
int get(int x, int n){
    return (x >> n) & 1;
}

int main(int argc, char* argv[]) {
    for (int i = 1; i<argc; i++) {
        unsigned short x = atoi(argv[i]);       
        unsigned short pair = 0;
        unsigned short one = 0;
        unsigned short bit = 0;
        unsigned short prev = 0;
        while(x) {
            bit = x & 1;
            if(prev && bit){
                pair++;
                prev = 0;
            }
            else{
                prev = bit;
            }
            if(bit){
                one++;
            }
            x >>= 1;
        }
    //prints Even-Parity if the input has an even number of 1 bits
    if(one % 2 == 0)              
        printf("Even-Parity\t%d\n", pair);
    //prints Odd-Parity if the input has an odd number of 1 bits
    else
        printf("Odd-Parity\t%d\n", pair); 
    }
}

