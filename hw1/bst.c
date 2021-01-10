#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} 
node;

node* insertion(int key, node* root) {
    node* prev = NULL;
    node* ptr = root;
    int i;
    while (ptr != NULL) {
	    if (ptr->data > key) {
	        i = -1;
	    } else if (ptr->data < key) {
	        i = 1;
	    } else {
	        return root;
	    }
	    prev = ptr;
	    if (i < 0) {
	        ptr = ptr->left;
	    } else {
	        ptr = ptr->right;
	    }
    }

    node* nNode = malloc(sizeof(node));
    nNode->data = key;
    nNode->left = NULL;
    nNode->right = NULL;

    if (prev == NULL) {
	    root = nNode;
    } else if (i < 0) {
	    prev->left = nNode;
    } else {
	    prev->right = nNode;
    }
    return root;
}

void print(node* root) {
    if (root == NULL) {
	return;
    }

    print(root->left);
    printf("%d\t", root->data);
    print(root->right);
}

void freeBST(node* root) {
    if (root == NULL) {
	return;
    }

    freeBST(root->left);
    freeBST(root->right);
    free(root);
}

int main(int argc, char** argv) {
    FILE* fp = fopen(argv[1], "r");
    node* root = NULL;
    int key;
    while (fscanf(fp, "i\t%d\n", &key) == 1) {
	    root = insertion(key, root);
    }
    print(root);
    freeBST(root);
    printf("\n");
    fclose(fp);
}

