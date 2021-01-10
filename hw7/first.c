#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    struct node *next;
    void *data;
} node;

typedef enum opType {
    not,
    and,
    or,
    nand,
    nor,
    xor
} opType;

typedef struct operation {
    opType type;
    int in1;
    int in2;
    int out;
} operation;

opType getopType(char* str) {
    if (!strcmp("NOT", str)) {
	    return not;
    }
    if (!strcmp("AND", str)) {
	    return and;
    }
    if (!strcmp("OR", str)) {
	    return or;
    }
    if (!strcmp("NAND", str)) {
	    return nand;
    }
    if (!strcmp("NOR", str)) {
	    return nor;
    }
    return xor;
}

int pow2(int n) {
    return 1 << n;
}

int getBit(int n, int pos) {
    return (n >> pos) & 1;
}

int listSize(node* head) {
    node* ptr = head;
    int size = 0;
    while (ptr != NULL) {
	    size++;
	    ptr = ptr->next;
    }
    return size;
}

node* insertValue(void *data, node* head) {
    node *prev = NULL;
    node *ptr = head;
    while (ptr != NULL) {
	    prev = ptr;
	    ptr = ptr->next;
    }
    node* newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->next = ptr;
    if (prev != NULL) {
	    prev->next = newNode;
    } 
    else {
	    head = newNode;
    }
    return head;
}

int evalOp(opType type, int in1, int in2) {
    switch (type) {
        case not:
	        return !in1;
        case and:
	        return in1 && in2;
        case or:
	        return in1 || in2;
        case nand:
	        return !(in1 && in2);
        case nor:
	        return !(in1 || in2);
        default: // xor
	        return (in1 && !in2) || (!in1 && in2);
    }
}


int* evalInputs(node *head, int numInputs, int temp, int numOutputs, int *inputs) {
    int rowSize = numInputs + numOutputs;
    int *row = (int*)malloc(sizeof(int) * rowSize);
    int *arr = (int*)malloc(sizeof(int) * temp);
    for (int i = 0; i < numInputs; i++) {
	    row[i] = inputs[i];
    }
    node *ptr = head;
    while (ptr != NULL) {
	    operation *op = (operation*)ptr->data;
	    int in1, in2;
	    if (op->in1 < numInputs) {
	        in1 = inputs[op->in1];
	    } else {
	        in1 = arr[op->in1 - numInputs - numOutputs];
	    }
	    if (op->in2 < numInputs) {
	        in2 = inputs[op->in2];
	    } else {
	        in2 = arr[op->in2 - numInputs - numOutputs];
	    }
	    int out = evalOp(op->type, in1, in2);
	    if (op->out >= numInputs && op->out < numInputs + numOutputs) {
	        row[op->out] = out;
	    } else {
	        arr[op->out - numInputs - numOutputs] = out;
	    }
	    ptr = ptr->next;
    }
    free(arr);
    return row;
}

int** evalList(node *head, int numInputs, int temp, int numOutputs) {
    int numCombo = pow2(numInputs);
    int **results = malloc(sizeof(int*) * numCombo);
    for (int i = 0; i < numCombo; i++) {
	    int *inputs = (int*)malloc(sizeof(int) * numInputs);
	    for (int j = 0; j < numInputs; j++) { 
	        inputs[numInputs - j - 1] = getBit(i, j);
	    }
	    int* row = evalInputs(head, numInputs, temp, numOutputs, inputs);
	    free(inputs);	
	    results[i] = row;
    }
    return results;
}

int index_of(char** str_arr, int arr_size, char* str) {
    for (int i = 0; i < arr_size; i++) {
	    if (strcmp(str_arr[i], str) == 0) {
	        return i;
	    }
    }
    return -1;
}

int indexList(node *head, char *str) {
    node *ptr = head;
    int idx = 0;
    while (ptr != NULL) {
	    if (strcmp((char*)ptr->data, str) == 0) {
	        return idx;
	    }
	    idx++;
	    ptr = ptr->next;
    }
    return -1;
}

void freeList(node* head) {
    if (head == NULL){ 
        return;
    }
    node* ptr = head;
    while (ptr->next != NULL) {
	    node* next = ptr->next;
	    free(ptr->data);
	    free(ptr);
	    ptr = next;
    }
    free(ptr->data);
    free(ptr);
}

int main(int argc, char** argv) {
    char* fname = argv[1];
    FILE* fp = fopen(fname, "r");
    if (fp == NULL) {
	    fprintf(stderr, "Error: please enter a valid file name\n");
	    return 0;
    }
    int inputNum, outputNum;
    fscanf(fp, "%*s %d", &inputNum);
    char** inputs = (char**)malloc(sizeof(char*) * inputNum);
    for (int i = 0; i < inputNum; i++) {
	    inputs[i] = (char*)malloc(sizeof(char) * 10);
        memset(inputs[i],0,sizeof(char) * inputNum);
	    fscanf(fp, "%s", inputs[i]);
    }

    fscanf(fp, "%*s %d", &outputNum);
    char** outputs = (char**)malloc(sizeof(char*) * outputNum);
    for (int i = 0; i < outputNum; i++) {
	    outputs[i] = (char*)malloc(sizeof(char) * 10);
        memset(outputs[i],0,sizeof(char) * outputNum);
	    fscanf(fp, "%s", outputs[i]);
    }

    char opName[5];
    char input1[10], input2[10], output[10];
    int count = inputNum + outputNum;
    node *head = NULL;
    node *tempHead = NULL;
    while (1) {
	    int res = fscanf(fp, "%s", opName);
	    if (res != 1) break;

	    operation *op = (operation*)malloc(sizeof(operation));
        memset(op,0,sizeof(operation));

	    opType type = getopType(opName);
	    op->type = type;
	    if (type == not) {
	        fscanf(fp, "%s %s", input1, output);
	        op->in2 = -1;
	    } else {
	        fscanf(fp, "%s %s %s", input1, input2, output);
	    }
	
	    int in1_idx = index_of(inputs, inputNum, input1);
	    if (in1_idx >= 0) {
	        op->in1 = in1_idx;
	    } else {
	        op->in1 = indexList(tempHead, input1) + inputNum + outputNum;
	    }
	    int in2_idx = index_of(inputs, inputNum, input2);
	    if (type != not) {
	        if (in2_idx >= 0) {
		        op->in2 = in2_idx;	
	        } else {
		        op->in2 = indexList(tempHead, input2) + inputNum + outputNum;
	        }
	    }
	    int out_idx = index_of(outputs, outputNum, output);
	    if (out_idx >= 0) {
	        op->out = inputNum + out_idx;
	    } else {
	        char* tempOutput = (char*)malloc((strlen(output) + 1) * sizeof(char));
	        strcpy(tempOutput, output);
	        tempHead = insertValue(tempOutput, tempHead);
	        op->out = count++;
	    }
	    head = insertValue(op, head);
    }

    int** results = evalList(head, inputNum, listSize(tempHead), outputNum);
    int numCombo = pow2(inputNum);
    for (int i = 0; i < numCombo; i++) {
	    for (int j = 0; j < inputNum + outputNum; j++) {
	        printf("%d ", results[i][j]);
	    }
	    printf("\n");
    }
    for (int i = 0; i < inputNum; i++) {
	    free(inputs[i]);
    }
    free(inputs);
    for (int i = 0; i < outputNum; i++) {
	    free(outputs[i]);
    }
    free(outputs);
    freeList(head);
    freeList(tempHead);
    for (int i = 0; i < numCombo; i++) {
	    free(results[i]);
    }
    free(results);
    fclose(fp);

    return 0;
}