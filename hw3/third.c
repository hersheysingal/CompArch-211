#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <stdbool.h>

//returns the value of the nth bit of the number x
int get(int x, int n) {
    return (x >> n) & 1;
}

//check if the bit representation is a palindrome
bool isPalandrome(unsigned short x) {
    for(int i = 0; i < 8; i++) {
        if(get(x, i) != get(x, 15 - i)) {
           return false;
        }
    }
    return true;
}

//prints either Is-Palindrome or Not-Palindrome
int main(int argc, char* argv[]) {
    for (int i = 1; i < argc; i++) {
        unsigned short x = atoi((argv[i]));
        if (!(isPalandrome(x))) {
            printf("Not-Palindrome\n");
        }
        else {
            printf("Is-Palindrome\n");
        }
    }  
}