#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    //read in the file from the command-line
    FILE* fp = fopen(argv[1], "r");
    int totalSize;
    //the first line in the file is the number of elements in the array
    //put that value into the variable totalSize
    fscanf(fp, "%d", &totalSize);
    //allocate memory for an array
    int* array = (int*)malloc(sizeof(int) * totalSize);
    int evenSize = 0;
    int oddSize = 0;
    //this loops counts the number of even and odd number are in the entire array 
    //this loop also puts each number from the file into the array
    for (int i = 0; i < totalSize; i++) {
	    int num;
	    fscanf(fp, "%d", &num);
	    if (num % 2 == 0) {
	        evenSize++;
	    } else {
	        oddSize++;
	    }
	    array[i] = num;
    }
    //this allocates memory for an array
    int* evenArray = (int*)malloc(sizeof(int) * evenSize);
    int evenCount = 0;
    //this loops through the original array and puts the even numbers into an array with only even numbers
    for (int i = 0; i < totalSize; i++) {
 	    if (array[i] % 2 == 0) {
 	        evenArray[evenCount++] = array[i];
	    }
    }
     //this allocates memory for an array
    int* oddArray = (int*)malloc(sizeof(int) * oddSize);
    int oddCount = 0;
    //this loops through the original array and puts the odd numbers into an array with only odd numbers
    for (int i = 0; i < totalSize; i++) {
 	    if (array[i] % 2 != 0) {
 	     oddArray[oddCount++] = array[i];
 	    }
    }

    //this loop puts the even array in ascending order
    for(int i = 0; i < evenSize; i++){
        int temp = evenArray[i];
        int j = i - 1;
        while(j >= 0 && evenArray[j] > temp){
            evenArray[j+1] = evenArray[j];
            j = j - 1;
        }
        evenArray[j + 1] = temp;
    }

    //this loop puts the odd array in descending order
    for(int i = 0; i < oddSize; i++){
        int temp = oddArray[i];
        int j = i - 1;
        while(j >= 0 && oddArray[j] < temp){
            oddArray[j+1] = oddArray[j];
            j = j - 1;
        }
        oddArray[j + 1] = temp;
    }

    //this loop first inputs the even numbers and then the odd numbers
    for(int i = 0; i < totalSize; i++){
        if( i < evenSize) {
            array[i] = evenArray[i];
        }
        else{
            array[i] = oddArray[i - evenSize];
        }
    }
    //this loop prints the final array
    for(int i = 0; i < totalSize; i++){
        printf("%d", array[i]);
        //this statement puts a tab between each number
        if(i != totalSize -1) {
            printf("\t");
        }
    }

    printf("\n");
    free(array);
    free(evenArray);
    free(oddArray);
    fclose(fp);
}
