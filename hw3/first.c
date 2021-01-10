#include<stdio.h>
#include<stdlib.h>
#include <string.h>

//returns the value of the nth bit of the number x
int get(int x, int n) {
    return ((x >> n) & 1);
}
//sets the value of the nth bit to x to its complement
int comp(int x, int n) {
    int val = 1;
    val = val << n;   
    x = x^val;
    return x;
}
//sets the nth bit of the number x to v
int set(int x, int n, int v) {
    return (x & (~(1 << n))) | (v << n);
}

int main(int argc, char* argv[]) {
    int num, n, v, val;
    char line[30], a[10];
    FILE *fp = fopen(argv[1], "r");
    fgets(line, 30, fp);
    sscanf(line, "%d", &num);  
    while(fgets(line, 30, fp)) {
       sscanf(line, "%s %d %d", a, &n, &v); 
       switch(a[0]) {
            case 'g':
                val = 1;      
                printf("%d\n",get(num, n)); 
            break;
            case 's': 
                val = 1;
                val = val << n;
                if(!v)
                {
                    val = ~val;
                    num = num & val;
                }
                else
                {
                    num = num | val;
                }
                printf("%d\n",num);
            break;
            case 'c':     
                val = 1;
                val = val << n;   
                num = num ^ val;
                printf("%d\n",num);
            break;
            default:printf("not defined");
       }
   }
   return 0;
}


    







    





