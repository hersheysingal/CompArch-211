#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//this willl see if the character is a vowel
int isVowel(char c) {
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'|| c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
		return 0;
	}
	return -1;
}

int main(int argc, char** argv) {
																															
    int numVowels = 0;
    
	//the outer loop is for each command line word
	for (int i = 1; i <= argc-1 ; i++) {
		//this assigns a pointer to the one word from the command-line
		char* word = argv[i];
		//this loop will go through each letter in the word
		for (int j = 0; j < strlen(word); j++) {
			//this will count the number of vowels in the word
	    	if (isVowel(word[j]) == 0) {
				numVowels++;
	    	}
		}	
    }
	
	//the memory allocation is the amount of bits for one char times the number of vowels plus 1
	//it is plus 1 because the last element in the array is \0
	//vowelWord is the array with only the vowels
    char* vowelWord = malloc(sizeof(char) * (numVowels + 1));
    vowelWord[numVowels] = '\0';
	int counter = 0;

	//the outer loop is for each command line word
    for (int i = 1; i <= argc-1; i++) {
		//this assigns a pointer to the one word from the command-line
		char* word = argv[i];
		//this loop will go through each letter in the word
		for (int j = 0; j < strlen(word); j++) {
	    	//this will put the vowels in the array
			if (isVowel(word[j]) == 0) {
				vowelWord[counter++] = word[j];
	    	}
		}
    }
    printf("%s\n", vowelWord);
    free(vowelWord);
}

