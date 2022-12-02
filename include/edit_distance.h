#ifndef EDIT_DISTANCE_H
#define EDIT_DISTANCE_H

// Functions for calculate the distance between two words
// s1 is the first string
// s2 is the second string
// m is the lenght of the first string
// n is the lenght of the second string

// Edit Distance 
int edit_distance(char* s1, char* s2);

// Edit Distance Recursive
int edit_distance_rec(char* s1, char* s2, int m, int n);

// Edit Distance Dynamic
int edit_distance_dyn(char* s1, char* s2);

// Edit Distance Dynamic Recursive
int edit_distance_dyn_rec(char* s1, char* s2, int m, int n, int** mem);

#endif // EDIT_DISTANCE_H