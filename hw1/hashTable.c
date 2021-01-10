#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node* next;
    int data;
} 

node;
const int tableSize = 10000;
node** hashtable;

void initialize() {
    hashtable = malloc(sizeof(node*) * tableSize);
    for (int i = 0; i < tableSize; i++) {
	    hashtable[i] = NULL;
    }
}

int hash(int num) {
    int x = num % tableSize;
    if (x < 0) {
	    x += tableSize;
    }
    return x;
}

int insert(int num) {
    node* nNode = malloc(sizeof(node));
    nNode->data = num;
    int key = hash(num);
    if (hashtable[key] != NULL) {
	    nNode->next = hashtable[key];
	    hashtable[key] = nNode;
	    return 1;
    }
    nNode->next = NULL;
    hashtable[key] = nNode;
    return 0;
}

int search(int num) {
    int key = hash(num);
    node* ptr = hashtable[key];
    while (ptr != NULL) {
	    if (ptr->data == num) {
	        return 1;
	    }
	    ptr = ptr->next;
    }
    return 0;
}

void freeList(node* front) {
    if (front == NULL){ 
        return;
    }
    node* ptr = front;
    while (ptr->next != NULL) {
	    node* after = ptr->next; 
	    free(ptr);
	    ptr = after;
    }
    free(ptr);
}

void freeTable() {
    for (int i = 0; i < tableSize; i++) {
	    node* ptr = hashtable[i];
	    freeList(ptr);
    }
    free(hashtable);
}

int main(int argc, char** argv) {
    initialize();
    FILE* fp = fopen(argv[1], "r");
    int collisions = 0;
    int searches = 0;
    char action;
    int num;

    while (fscanf(fp, "%c\t%d\n", &action, &num) == 2) {
	    if (action == 'i') {
	        int result = insert(num);
	        if (result) {
		    collisions++;
	        }
	    } else if (action == 's') {
	        int result = search(num);
	        if (result) {
		        searches++;
	        }
	    }
    }
    printf("%d\n%d\n", collisions, searches);
    freeTable();
    fclose(fp);
    return 0;
}

