#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node* next;
    int data;
} 

node;

node* insertNum(int data, node* front) {
    node *prev = NULL;
    node *ptr = front;
    while (ptr != NULL) {
	    if (((prev == NULL) || (prev != NULL && prev->data <= data)) && data <= ptr->data) {
	        break;
	    }
	    prev = ptr;
	    ptr = ptr->next;
    }
    node* nNode = malloc(sizeof(node));
    nNode->data = data;
    nNode->next = ptr;
    if (prev != NULL) {
	    prev->next = nNode;
    } else {
	    front = nNode;
    }
    return front;
}

node* deleteNum(int data, node* front) {
    node* prev = NULL;
    node* ptr = front;
    while (ptr != NULL) {
	    if (ptr->data == data) {
	        break;
	    }
	    prev = ptr;
	    ptr = ptr->next;
    }
    if (ptr != NULL) {
	    if (prev == NULL) {
	        front = ptr->next;
	    } else {
	        prev->next = ptr->next;
	    }
	free(ptr);
    }
    return front;
}

int sizeList(node* front) {
    node* ptr = front;
    int size = 0;
    while (ptr != NULL) {
	    size++;
	    ptr = ptr->next;
    }
    return size;
}

void print(node* front) {
    node* ptr = front;
    int last;
    while (ptr != NULL) {
	    if (ptr == front || last != ptr->data) {
	        printf("%d", ptr->data);
	        if (ptr->next == NULL) {
		        printf("\n");
	        } else {
		        printf("\t");
	        }
	    }
	    last = ptr->data;
	    ptr = ptr->next;
    }
}

void freeList(node* front) {
    if (front == NULL) return;
    node* ptr = front;
    while (ptr->next != NULL) {
	    node* next = ptr->next;
	    free(ptr);
	    ptr = next;
    }
    free(ptr);
}

int main(int argc, char** argv) {
    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
	    printf("error\n");
    }
    char action;
    int num;
    node* front = NULL;
    while (fscanf(fp, "%c\t%d\n", &action, &num) == 2) {
	    if (action == 'i') {
	        if (front == NULL) {
		        front = malloc(sizeof(node));
		        front->data = num;
		        front->next = NULL;
	        } else {
		        front = insertNum(num, front);
	        }
	    } else if (action == 'd') {
	        front = deleteNum(num, front);
	    }
    }
    int size = sizeList(front);
    printf("%d\n", size);
    if (size > 0) {
	    print(front);
    }
    printf("\n");
    freeList(front);
    fclose(fp);
}

