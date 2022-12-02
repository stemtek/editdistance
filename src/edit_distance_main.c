#include "../Resources/unity.h"
#include "../include/edit_distance.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_LENGTH 100

// logic to count words
int count_words(char* path) {
    FILE *fp = fopen(path, "r");
	
    int count = 0;
    char ch;
	
    if( fp == NULL ) {
        printf("\nUnable to open file.\n");
        printf("Please check if file exists and you have read privilege.\n");
        exit(EXIT_FAILURE);
    }
	
    for (ch = getc(fp); ch != EOF; ch = getc(fp)) {
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0')
            count++;
    }
	// close files to release resources
    fclose(fp);
    return count;
}
// i read the data through the two files
char** load_data(char* path) {
    printf("Loading data from file path: %s\n", path);
    FILE *fp = fopen(path, "r");
	
	// check if file opened successfully
    if( fp == NULL ) {
        printf("\nUnable to open file.\n");
        printf("Please check if file exists and you have read privilege.\n");
        exit(EXIT_FAILURE);
    }

    char **tmp;
    int rows = count_words(path);
    int col = MAX_LENGTH;
    tmp = malloc(rows*sizeof*tmp);
    for (int k = 0; k < rows; k++) {
        tmp[k] = malloc(col*sizeof*tmp[k]);
    }

    int j = 0;
    while (!feof(fp)) {
      fscanf(fp,"%s",tmp[j]);
      j++;
    }

    fclose(fp);
    printf("All data was loaded succesfuly\n");
    return tmp;
}

/* The distance method (edit_distance_dyn) is used to compare the data we find inside the two files.
   Every word that we find inside the "correctme" file is compared with the words inside the "dictionary" 
   and finally, all the words with a minimum distance are printed.
   Using the dynamic method (as it was written in the report) the work is done in much less time 
   than the classic method that, if you want you can try.
*/
void edit_distance_load(char* path1, char* path2) {

    char ** dictionary = load_data(path1);
    char ** correctme = load_data(path2);
	
    int rows_dictionary = count_words(path1);
    int rows_correctme = count_words(path2);

    for (int i = 0, min = INT_MAX; i < rows_correctme; i++, min = INT_MAX) {
        printf("\nWord Selected is : %s\n", correctme[i]);

        for (int j = 0; j < rows_dictionary; j++) {
            int tmp = edit_distance_dyn(correctme[i], dictionary[j]);
            if (tmp < min) min = tmp;
        }

        for (int j = 0; j < rows_dictionary; j++) {
            if (edit_distance_dyn(correctme[i], dictionary[j]) == min)
                printf("%s, ", dictionary[j]);
        }
    } printf("\n\nComparison between dictionary.txt and correctme.txt is completed\n");

    for (int k = 0; k < rows_dictionary; k++) {
        free(dictionary[k]);
    }
    free(dictionary);
    for (int k = 0; k < rows_correctme; k++) {
        free(correctme[k]);
    }
    free(correctme);
}

int main(int argc, char *argv[]) {
	if(argc < 3) {
		printf("error while inserting arguments\n");
		exit(EXIT_FAILURE);
  }
	edit_distance_load(argv[1], argv[2]);
	
	return (EXIT_SUCCESS);
}
