#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mov(int x, int y){
    y = x;
    return y;
}
int add(int x, int y){
    y = y + x;
    return y;
}
int sub(int x, int y){
    y = y - x;
    return y;
}
int mul(int x, int y){
    y = y * x;
    return y;
}
int divi(int x, int y){
    y = x / y;
    return y;
}

int main(int argc, char* argv[]){
    char instructions[1000][1000];
    FILE* fp = fopen(argv[1], "r");
    if(fp == NULL) {
        printf("error\n");
        return 0;
    }
    short ax, bx, cx, dx;
    int i = 0;
    int numLines = 0;
    char action[1000]; 
    char action1[1000]; 
    char regHolder[100];
    char register1[10];
    char register2[10];
    char register3[10];
    char registerA[10];
    char registerB[10];
    char registerC[10];
    char holder[10];
    
    while(fgets(instructions[i], 1000, fp)){
        i++;
    }
    numLines = i; 
    
    for(int j = 0; j < numLines; j++){
        int numofVar = sscanf(instructions[j], "%s %s %s %s" , action1, registerA, registerB, registerC);

        if(numofVar == 2){
            sscanf(instructions[j], "%s %s" , action, register1);
            strcpy(register2, " ");
            strcpy(register3, " ");
            if(strcmp(action, "read") == 0){    
                if(strcmp(register1, "ax") == 0){
                    scanf("%s", regHolder);
                    ax = atoi(regHolder);
                }
                if(strcmp(register1, "bx") == 0){
                    scanf("%s", regHolder);
                    bx = atoi(regHolder);
                }
                if(strcmp(register1, "cx") == 0){
                    scanf("%s", regHolder);
                    cx = atoi(regHolder);
                }
                if(strcmp(register1, "dx") == 0){
                    scanf("%s", regHolder);
                    dx = atoi(regHolder);
                    //printf("%d\n", dx);
                }
            }
            if(strcmp(action, "jmp") == 0){    
                int lineNum = atoi(register1);
                j = lineNum - 1;
            }
            if(strcmp(action, "print") == 0){
               if(strcmp(register1, "ax") == 0){
                    printf("%d", ax);
                }
                else if(strcmp(register1, "bx") == 0){
                    printf("%d", bx);
                }
                else if(strcmp(register1, "cx") == 0){
                    printf("%d", cx);
                }
                else if(strcmp(register1, "dx") == 0){
                    printf("%d", dx);
                }
                else{
                    int val = atoi(register1);
                    printf("%d", val);
                } 
            }   
        }
        if(numofVar == 3){
            sscanf(instructions[j], "%s %s %s" , action, register1, register2);
            strcpy(register3, " ");
            if(strcmp(action, "mov") == 0){
                if(strcmp(register1, "ax") == 0){
                    if(strcmp(register2, "ax") == 0){
                        ax = mov(ax,ax);
                    }
                    else if(strcmp(register2, "bx") == 0){
                        bx = mov(ax,bx);
                    }
                    else if(strcmp(register2, "cx") == 0){
                        cx = mov(ax,cx);
                    }
                    else if(strcmp(register2, "dx") == 0){
                        dx = mov(ax,dx);
                    }
                }
                 else if(strcmp(register1, "bx") == 0){
                    if(strcmp(register2, "ax") == 0){
                        ax = mov(bx,ax);
                    }
                    else if(strcmp(register2, "bx") == 0){
                        bx = mov(bx,bx);
                    }
                    else if(strcmp(register2, "cx") == 0){
                        cx = mov(bx,cx);
                    }
                    else if(strcmp(register2, "dx") == 0){
                        dx = mov(bx,dx);
                    }
                }
                else if(strcmp(register1, "cx") == 0){
                    if(strcmp(register2, "ax") == 0){
                        ax = mov(cx,ax);
                    }
                    else if(strcmp(register2, "bx") == 0){
                        bx = mov(cx,bx);
                    }
                    else if(strcmp(register2, "cx") == 0){
                        cx = mov(cx,cx);
                    }
                    else if(strcmp(register2, "dx") == 0){
                        dx = mov(cx,dx);
                    }
                }
                else if(strcmp(register1, "dx") == 0){
                    if(strcmp(register2, "ax") == 0){
                        ax = mov(dx,ax);
                    }
                    else if(strcmp(register2, "bx") == 0){
                        bx = mov(dx,bx);
                    }
                    else if(strcmp(register2, "cx") == 0){
                        cx = mov(dx,cx);
                    }
                    else if(strcmp(register2, "dx") == 0){
                        dx = mov(dx,dx);
                    }
                }
                else{
                    int val = atoi(register1);
                    if(strcmp(register2, "ax") == 0){
                        ax = mov(val,ax);
                    }
                    else if(strcmp(register2, "bx") == 0){
                        bx = mov(val,bx);
                    }
                    else if(strcmp(register2, "cx") == 0){
                        cx = mov(val,cx);
                    }
                    else if(strcmp(register2, "dx") == 0){
                        dx = mov(val,dx);
                    }
                }
            }
            if(strcmp(action, "add") == 0){
                if(strcmp(register1, "ax") == 0){
                    if(strcmp(register2, "ax") == 0){
                        ax = add(ax,ax);
                    }
                    else if(strcmp(register2, "bx") == 0){
                        bx = add(ax,bx);
                    }
                    else if(strcmp(register2, "cx") == 0){
                        cx = add(ax,cx);
                    }
                    else if(strcmp(register2, "dx") == 0){
                        dx = add(ax,dx);
                    }
                }
                else if(strcmp(register1, "bx") == 0){
                    if(strcmp(register2, "ax") == 0){
                        ax = add(bx,ax);
                    }
                    else if(strcmp(register2, "bx") == 0){
                        bx = add(bx,bx);
                    }
                    else if(strcmp(register2, "cx") == 0){
                        cx = add(bx,cx);
                    }
                    else if(strcmp(register2, "dx") == 0){
                        dx = add(bx,dx);
                    }
                }
                else if(strcmp(register1, "cx") == 0){
                    if(strcmp(register2, "ax") == 0){
                        ax = add(cx,ax);
                    }
                    else if(strcmp(register2, "bx") == 0){
                        bx = add(cx,bx);
                    }
                    else if(strcmp(register2, "cx") == 0){
                        cx = add(cx,cx);
                    }
                    else if(strcmp(register2, "dx") == 0){
                        dx = add(cx,dx);
                    }
                }
                else if(strcmp(register1, "dx") == 0){
                    if(strcmp(register2, "ax") == 0){
                        ax = add(dx,ax);
                    }
                    else if(strcmp(register2, "bx") == 0){
                        bx = add(dx,bx);
                    }
                    else if(strcmp(register2, "cx") == 0){
                        cx = add(dx,cx);
                    }
                    else if(strcmp(register2, "dx") == 0){
                        dx = add(dx,dx);
                    }
                }
                else {
                    int val = atoi(register1);
                    if(strcmp(register2, "ax") == 0){
                        ax = add(val,ax);
                    }
                    else if(strcmp(register2, "bx") == 0){
                        bx = add(val,bx);
                    }
                    else if(strcmp(register2, "cx") == 0){
                        cx = add(val,cx);
                    }
                    else if(strcmp(register2, "dx") == 0){
                        dx = add(val,dx);
                    }
                }
            }
            if(strcmp(action, "sub") == 0){
                if(strcmp(register1, "ax") == 0){
                    if(strcmp(register2, "ax") == 0){
                        ax = sub(ax,ax);
                    }
                    else if(strcmp(register2, "bx") == 0){
                        bx = sub(ax,bx);
                    }
                    else if(strcmp(register2, "cx") == 0){
                        cx = sub(ax,cx);
                    }
                    else if(strcmp(register2, "dx") == 0){
                        dx = sub(ax,dx);
                    }
                }
                else if(strcmp(register1, "bx") == 0){
                    if(strcmp(register2, "ax") == 0){
                        ax = sub(bx,ax);
                    }
                    else if(strcmp(register2, "bx") == 0){
                        bx = sub(bx,bx);
                    }
                    else if(strcmp(register2, "cx") == 0){
                        cx = sub(bx,cx);
                    }
                    else if(strcmp(register2, "dx") == 0){
                        dx = sub(bx,dx);
                    }
                }
                else if(strcmp(register1, "cx") == 0){
                    if(strcmp(register2, "ax") == 0){
                        ax = sub(cx,ax);
                    }
                    else if(strcmp(register2, "bx") == 0){
                        bx = sub(cx,bx);
                    }
                    else if(strcmp(register2, "cx") == 0){
                        cx = sub(cx,cx);
                    }
                    else if(strcmp(register2, "dx") == 0){
                        dx = sub(cx,dx);
                    }
                }
                else if(strcmp(register1, "dx") == 0){
                    if(strcmp(register2, "ax") == 0){
                        ax = sub(dx,ax);
                    }
                    else if(strcmp(register2, "bx") == 0){
                        bx = sub(dx,bx);
                    }
                    else if(strcmp(register2, "cx") == 0){
                        cx = sub(dx,cx);
                    }
                    else if(strcmp(register2, "dx") == 0){
                        dx = sub(dx,dx);
                    }
                }
                else {
                    int val = atoi(register1);
                    if(strcmp(register2, "ax") == 0){
                        ax = sub(val,ax);
                    }
                    else if(strcmp(register2, "bx") == 0){
                        bx = sub(val,bx);
                    }
                    else if(strcmp(register2, "cx") == 0){
                        cx = sub(val,cx);
                    }
                    else if(strcmp(register2, "dx") == 0){
                        dx = sub(val,dx);
                    }
                }
            }
            if(strcmp(action, "mul") == 0){
                if(strcmp(register1, "ax") == 0){
                    if(strcmp(register2, "ax") == 0){
                        ax = mul(ax,ax);
                    }
                    else if(strcmp(register2, "bx") == 0){
                        bx = mul(ax,bx);
                    }
                    else if(strcmp(register2, "cx") == 0){
                        cx = mul(ax,cx);
                    }
                    else if(strcmp(register2, "dx") == 0){
                        dx = mul(ax,dx);
                    }
                }
                else if(strcmp(register1, "bx") == 0){
                    if(strcmp(register2, "ax") == 0){
                        ax = mul(bx,ax);
                    }
                    else if(strcmp(register2, "bx") == 0){
                        bx = mul(bx,bx);
                    }
                    else if(strcmp(register2, "cx") == 0){
                        cx = mul(bx,cx);
                    }
                    else if(strcmp(register2, "dx") == 0){
                        dx = mul(bx,dx);
                    }
                }
                else if(strcmp(register1, "cx") == 0){
                    if(strcmp(register2, "ax") == 0){
                        ax = mul(cx,ax);
                    }
                    else if(strcmp(register2, "bx") == 0){
                        bx = mul(cx,bx);
                    }
                    else if(strcmp(register2, "cx") == 0){
                        cx = mul(cx,cx);
                    }
                    else if(strcmp(register2, "dx") == 0){
                        dx = mul(cx,dx);
                    }
                }
                else if(strcmp(register1, "dx") == 0){
                    if(strcmp(register2, "ax") == 0){
                        ax = mul(dx,ax);
                    }
                    else if(strcmp(register2, "bx") == 0){
                        bx = mul(dx,bx);
                    }
                    else if(strcmp(register2, "cx") == 0){
                        cx = mul(dx,cx);
                    }
                    else if(strcmp(register2, "dx") == 0){
                        dx = mul(dx,dx);
                    }
                }
                else {
                    int val = atoi(register1);
                    if(strcmp(register2, "ax") == 0){
                        ax = mul(val,ax);
                    }
                    else if(strcmp(register2, "bx") == 0){
                        bx = mul(val,bx);
                    }
                    else if(strcmp(register2, "cx") == 0){
                        cx = mul(val,cx);
                    }
                    else if(strcmp(register2, "dx") == 0){
                        dx = mul(val,dx);
                    }
                }
            }
            if(strcmp(action, "div") == 0){
                if(strcmp(register1, "ax") == 0){
                    if(strcmp(register2, "ax") == 0){
                        ax = divi(ax,ax);
                    }
                    else if(strcmp(register2, "bx") == 0){
                        bx = divi(ax,bx);
                    }
                    else if(strcmp(register2, "cx") == 0){
                        cx = divi(ax,cx);
                    }
                    else if(strcmp(register2, "dx") == 0){
                        dx = divi(ax,dx);
                    }
                }
                else if(strcmp(register1, "bx") == 0){
                    if(strcmp(register2, "ax") == 0){
                        ax = divi(bx,ax);
                    }
                    else if(strcmp(register2, "bx") == 0){
                        bx = divi(bx,bx);
                    }
                    else if(strcmp(register2, "cx") == 0){
                        cx = divi(bx,cx);
                    }
                    else if(strcmp(register2, "dx") == 0){
                        dx = divi(bx,dx);
                    }
                }
                else if(strcmp(register1, "cx") == 0){
                    if(strcmp(register2, "ax") == 0){
                        ax = divi(cx,ax);
                    }
                    else if(strcmp(register2, "bx") == 0){
                        bx = divi(cx,bx);
                    }
                    else if(strcmp(register2, "cx") == 0){
                        cx = divi(cx,cx);
                    }
                    else if(strcmp(register2, "dx") == 0){
                        dx = divi(cx,dx);
                    }
                }
                else if(strcmp(register1, "dx") == 0){
                    if(strcmp(register2, "ax") == 0){
                        ax = divi(dx,ax);
                    }
                    else if(strcmp(register2, "bx") == 0){
                        bx = divi(dx,bx);
                    }
                    else if(strcmp(register2, "cx") == 0){
                        cx = divi(dx,cx);
                    }
                    else if(strcmp(register2, "dx") == 0){
                        dx = divi(dx,dx);
                    }
                }
                else {
                    int val = atoi(register1);
                    if(strcmp(register2, "ax") == 0){
                        ax = divi(val,ax);
                    }
                    else if(strcmp(register2, "bx") == 0){
                        bx = divi(val,bx);
                    }
                    else if(strcmp(register2, "cx") == 0){
                        cx = divi(val,cx);
                    }
                    else if(strcmp(register2, "dx") == 0){
                        dx = divi(val,dx);
                    }
                }
            }  
        }
        if(numofVar == 4){
            sscanf(instructions[j], "%s %s %s %s" , action, register1, register2, register3);
            if(strcmp(action, "je") == 0){
                if(strcmp(register2, "ax") == 0){
                    if(strcmp(register3, "ax") == 0){
                        j = atoi(register1)-1;
                    }
                    else if(strcmp(register3, "bx") == 0){
                        if(ax == bx){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "cx") == 0){
                        if(ax == cx){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "dx") == 0){
                        if(ax == dx){
                            j = atoi(register1)-1;
                        }
                    }
                    else{
                        int val = atoi(register3);
                        if(ax == val){
                            j = atoi(register1)-1;
                        }
                    }
                }
                else if(strcmp(register2, "bx") == 0){
                    if(strcmp(register3, "ax") == 0){
                        if(bx == ax){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "bx") == 0){
                            j = atoi(register1)-1;
                    }
                    else if(strcmp(register3, "cx") == 0){
                        if(bx == cx){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "dx") == 0){
                        if(bx == dx){
                            j = atoi(register1)-1;
                        }
                    }
                    else{
                        int val = atoi(register3);
                        if(bx == val){
                            j = atoi(register1)-1;
                        }
                    }
                }
                else if(strcmp(register2, "cx") == 0){
                    if(strcmp(register3, "ax") == 0){
                        if(cx == ax){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "bx") == 0){
                        if(cx == bx){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "cx") == 0){
                            j = atoi(register1)-1;
                    }
                    else if(strcmp(register3, "dx") == 0){
                        if(cx == dx){
                            j = atoi(register1)-1;
                        }
                    }
                    else{
                        int val = atoi(register3);
                        if(cx == val){
                            j = atoi(register1)-1;
                        }
                    }
                }
                else if(strcmp(register2, "dx") == 0){
                    if(strcmp(register3, "ax") == 0){
                        if(dx == ax){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "bx") == 0){
                        if(dx == bx){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "cx") == 0){
                        if(dx == cx){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "dx") == 0){
                            j = atoi(register1)-1;
                    }
                    else{
                        int val = atoi(register3);
                        if(dx == val){
                            j = atoi(register1)-1;
                        }
                    }
                }
                else{
                    int val = atoi(register2);
                    if(strcmp(register3, "ax") == 0){
                        if(ax == val){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "bx") == 0){
                        if(bx == val){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "cx") == 0){
                        if(cx == val){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "dx") == 0){
                        if(dx == val){
                            j = atoi(register1)-1;
                        }
                    }
                    else{
                        int val2 = atoi(register3);
                        if(val == val2){
                            j = atoi(register1)-1;
                        }
                    }
                }
            }
            if(strcmp(action, "jne") == 0){
                if(strcmp(register2, "ax") == 0){
                    if(strcmp(register3, "bx") == 0){
                        if(ax != bx){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "cx") == 0){
                        if(ax != cx){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "dx") == 0){
                        if(ax != dx){
                            j = atoi(register1)-1;
                        }
                    }
                    else{
                        int val = atoi(register3);
                        if(ax != val){
                            j = atoi(register1)-1;
                        }
                    }
                }
                else if(strcmp(register2, "bx") == 0){
                    if(strcmp(register3, "ax") == 0){
                        if(bx != ax){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "cx") == 0){
                        if(bx != cx){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "dx") == 0){
                        if(bx != dx){
                            j = atoi(register1)-1;
                        }
                    }
                    else{
                        int val = atoi(register3);
                        if(bx != val){
                            j = atoi(register1)-1;
                        }
                    }
                }
                else if(strcmp(register2, "cx") == 0){
                    if(strcmp(register3, "ax") == 0){
                        if(cx != ax){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "bx") == 0){
                        if(cx != bx){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "dx") == 0){
                        if(cx != dx){
                            j = atoi(register1)-1;
                        }
                    }
                    else{
                        int val = atoi(register3);
                        if(cx != val){
                            j = atoi(register1)-1;
                        }
                    }
                }
                else if(strcmp(register2, "dx") == 0){
                    if(strcmp(register3, "ax") == 0){
                        if(dx != ax){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "bx") == 0){
                        if(dx != bx){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "cx") == 0){
                        if(dx != cx){
                            j = atoi(register1)-1;
                        }
                    }
                    else{
                        int val = atoi(register3);
                        if(dx != val){
                            j = atoi(register1)-1;
                        }
                    }
                }
                else{
                    int val = atoi(register2);
                    if(strcmp(register3, "ax") == 0){
                        if(ax != val){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "bx") == 0){
                        if(bx != val){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "cx") == 0){
                        if(cx != val){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "dx") == 0){
                        if(dx != val){
                            j = atoi(register1)-1;
                        }
                    }
                    else{
                        int val2 = atoi(register3);
                        if(val != val2){
                            j = atoi(register1)-1;
                        }
                    }
                }
            }
            if(strcmp(action, "jg") == 0){
                if(strcmp(register2, "ax") == 0){
                    if(strcmp(register3, "bx") == 0){
                        if(ax > bx){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "cx") == 0){
                        if(ax > cx){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "dx") == 0){
                        if(ax > dx){
                            j = atoi(register1)-1;
                        }
                    }
                    else{
                        int val = atoi(register3);
                        if(ax > val){
                            j = atoi(register1)-1;
                        }
                    }
                }
                else if(strcmp(register2, "bx") == 0){
                    if(strcmp(register3, "ax") == 0){
                        if(bx > ax){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "cx") == 0){
                        if(bx > cx){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "dx") == 0){
                        if(bx > dx){
                            j = atoi(register1)-1;
                        }
                    }
                    else{
                        int val = atoi(register3);
                        if(bx > val){
                            j = atoi(register1)-1;
                        }
                    }
                }
                else if(strcmp(register2, "cx") == 0){
                    if(strcmp(register3, "ax") == 0){
                        if(cx > ax){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "bx") == 0){
                        if(cx > bx){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "dx") == 0){
                        if(cx > dx){
                            j = atoi(register1)-1;
                        }
                    }
                    else{
                        int val = atoi(register3);
                        if(cx > val){
                            j = atoi(register1)-1;
                        }
                    }
                }
                else if(strcmp(register2, "dx") == 0){
                    if(strcmp(register3, "ax") == 0){
                        if(dx > ax){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "bx") == 0){
                        if(dx > bx){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "cx") == 0){
                        if(dx > cx){
                            j = atoi(register1)-1;
                        }
                    }
                    else{
                        int val = atoi(register3);
                        if(dx > val){
                            j = atoi(register1)-1;
                        }
                    }
                }
                else{
                    int val = atoi(register2);
                    if(strcmp(register3, "ax") == 0){
                        if(val > ax){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "bx") == 0){
                        if(val > bx){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "cx") == 0){
                        if(val > cx){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "dx") == 0){
                        if(val > dx){
                            j = atoi(register1)-1;
                        }
                    }
                    else{
                        int val2 = atoi(register3);
                        if(val > val2){
                            j = atoi(register1)-1;
                        }
                    }
                }
            }
            if(strcmp(action, "jge") == 0){
                if(strcmp(register2, "ax") == 0){
                    if(strcmp(register3, "ax") == 0){
                        j = atoi(register1)-1;
                    }
                    else if(strcmp(register3, "bx") == 0){
                        if(ax >= bx){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "cx") == 0){
                        if(ax >= cx){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "dx") == 0){
                        if(ax >= dx){
                            j = atoi(register1)-1;
                        }
                    }
                    else{
                        int val = atoi(register3);
                        if(ax >= val){
                            j = atoi(register1)-1;
                        }
                    }
                }
                else if(strcmp(register2, "bx") == 0){
                    if(strcmp(register3, "ax") == 0){
                        if(bx >= ax){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "bx") == 0){
                            j = atoi(register1)-1;
                    }
                    else if(strcmp(register3, "cx") == 0){
                        if(bx >= cx){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "dx") == 0){
                        if(bx >= dx){
                            j = atoi(register1)-1;
                        }
                    }
                    else{
                        int val = atoi(register3);
                        if(bx >= val){
                            j = atoi(register1)-1;
                        }
                    }
                }
                else if(strcmp(register2, "cx") == 0){
                    if(strcmp(register3, "ax") == 0){
                        if(cx >= ax){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "bx") == 0){
                        if(cx >= bx){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "cx") == 0){
                            j = atoi(register1)-1;
                    }
                    else if(strcmp(register3, "dx") == 0){
                        if(cx >= dx){
                            j = atoi(register1)-1;
                        }
                    }
                    else{
                        int val = atoi(register3);
                        if(cx >= val){
                            j = atoi(register1)-1;
                        }
                    }
                }
                else if(strcmp(register2, "dx") == 0){
                    if(strcmp(register3, "ax") == 0){
                        if(dx >= ax){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "bx") == 0){
                        if(dx >= bx){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "cx") == 0){
                        if(dx >= cx){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "dx") == 0){
                            j = atoi(register1)-1;
                    }
                    else{
                        int val = atoi(register3);
                        if(dx >= val){
                            j = atoi(register1)-1;
                        }
                    }
                }
                else{
                    int val = atoi(register2);
                    if(strcmp(register3, "ax") == 0){
                        if(ax >= val){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "bx") == 0){
                        if(bx >= val){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "cx") == 0){
                        if(cx >= val){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "dx") == 0){
                        if(dx >= val){
                            j = atoi(register1)-1;
                        }
                    }
                    else{
                        int val2 = atoi(register3);
                        if(val >= val2){
                            j = atoi(register1)-1;
                        }
                    }
                }
            }
            if(strcmp(action, "jl") == 0){
                if(strcmp(register2, "ax") == 0){
                    if(strcmp(register3, "bx") == 0){
                        if(ax < bx){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "cx") == 0){
                        if(ax < cx){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "dx") == 0){
                        if(ax < dx){
                            j = atoi(register1)-1;
                        }
                    }
                    else{
                        int val = atoi(register3);
                        if(ax < val){
                            j = atoi(register1)-1;
                        }
                    }
                }
                else if(strcmp(register2, "bx") == 0){
                    if(strcmp(register3, "ax") == 0){
                        if(bx < ax){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "cx") == 0){
                        if(bx < cx){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "dx") == 0){
                        if(bx < dx){
                            j = atoi(register1)-1;
                        }
                    }
                    else{
                        int val = atoi(register3);
                        if(bx < val){
                            j = atoi(register1)-1;
                        }
                    }
                }
                else if(strcmp(register2, "cx") == 0){
                    if(strcmp(register3, "ax") == 0){
                        if(cx < ax){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "bx") == 0){
                        if(cx < bx){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "dx") == 0){
                        if(cx < dx){
                            j = atoi(register1)-1;
                        }
                    }
                    else{
                        int val = atoi(register3);
                        if(cx < val){
                            j = atoi(register1)-1;
                        }
                    }
                }
                else if(strcmp(register2, "dx") == 0){
                    if(strcmp(register3, "ax") == 0){
                        if(dx < ax){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "bx") == 0){
                        if(dx < bx){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "cx") == 0){
                        if(dx < cx){
                            j = atoi(register1)-1;
                        }
                    }
                    else{
                        int val = atoi(register3);
                        if(dx < val){
                            j = atoi(register1)-1;
                        }
                    }
                }
                else{
                    int val = atoi(register2);
                    if(strcmp(register3, "ax") == 0){
                        if(val < ax){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "bx") == 0){
                        if(val < bx){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "cx") == 0){
                        if(val < cx){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "dx") == 0){
                        if(val < dx){
                            j = atoi(register1)-1;
                        }
                    }
                    else{
                        int val2 = atoi(register3);
                        if(val < val2){
                            j = atoi(register1)-1;
                        }
                    }
                }
            }
            if(strcmp(action, "jle") == 0){
                if(strcmp(register2, "ax") == 0){
                    if(strcmp(register3, "ax") == 0){
                        j = atoi(register1)-1;
                    }
                    else if(strcmp(register3, "bx") == 0){
                        if(ax <= bx){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "cx") == 0){
                        if(ax <= cx){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "dx") == 0){
                        if(ax <= dx){
                            j = atoi(register1)-1;
                        }
                    }
                    else{
                        int val = atoi(register3);
                        if(ax <= val){
                            j = atoi(register1)-1;
                        }
                    }
                }
                else if(strcmp(register2, "bx") == 0){
                    if(strcmp(register3, "ax") == 0){
                        if(bx <= ax){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "bx") == 0){
                            j = atoi(register1)-1;
                    }
                    else if(strcmp(register3, "cx") == 0){
                        if(bx <= cx){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "dx") == 0){
                        if(bx <= dx){
                            j = atoi(register1)-1;
                        }
                    }
                    else{
                        int val = atoi(register3);
                        if(bx <= val){
                            j = atoi(register1)-1;
                        }
                    }
                }
                else if(strcmp(register2, "cx") == 0){
                    if(strcmp(register3, "ax") == 0){
                        if(cx <= ax){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "bx") == 0){
                        if(cx <= bx){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "cx") == 0){
                            j = atoi(register1)-1;
                    }
                    else if(strcmp(register3, "dx") == 0){
                        if(cx <= dx){
                            j = atoi(register1)-1;
                        }
                    }
                    else{
                        int val = atoi(register3);
                        if(cx <= val){
                            j = atoi(register1)-1;
                        }
                    }
                }
                else if(strcmp(register2, "dx") == 0){
                    if(strcmp(register3, "ax") == 0){
                        if(dx <= ax){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "bx") == 0){
                        if(dx <= bx){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "cx") == 0){
                        if(dx <= cx){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "dx") == 0){
                            j = atoi(register1)-1;
                    }
                    else{
                        int val = atoi(register3);
                        if(dx <= val){
                            j = atoi(register1)-1;
                        }
                    }
                }
                else{
                    int val = atoi(register2);
                    if(strcmp(register3, "ax") == 0){
                        if(ax <= val){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "bx") == 0){
                        if(bx <= val){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "cx") == 0){
                        if(cx <= val){
                            j = atoi(register1)-1;
                        }
                    }
                    else if(strcmp(register3, "dx") == 0){
                        if(dx <= val){
                            j = atoi(register1)-1;
                        }
                    }
                    else{
                        int val2 = atoi(register3);
                        if(val <= val2){
                            j = atoi(register1)-1;
                        }
                    }
                }
            }  
        }
    }
}




