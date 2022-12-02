#include "../include/edit_distance.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

// utility function to find minimum of three numbers
int min(int x, int y, int z) { //find smallest among three numbers
   if(x < y) {
      if(x < z)
         return x;
      else
         return z;
   }else {
      if(y < z)
         return y;
      else
         return z;
   }
}

char* substring(char* s) {
	char* sub = s+1;
	return sub;
}

int edit_distance(char* s1, char* s2) {
	if (s1 == NULL || s2 == NULL)
    return -1;

	int m = strlen(s1);
	int n = strlen(s2);
	return edit_distance_rec(s1, s2, m, n);
}

int edit_distance_rec(char* s1, char* s2, int m, int n) {
	int d_no_op;
	int d_canc;
	int d_ins;

	// if first string is empty, the only option is to insert all characters of second string into first.
    if (m == 0) {
		return n;
	  // if second string is empty, the only option is to remove all characters of first string.
	} else if (n == 0) {
		return m;
	}
	else {
    // if last characters of two strings are same, nothing much to do. 
	// ignore last characters and get count for remaining strings.
    if (s1[0] == s2[0])
        d_no_op = edit_distance(substring(s1),substring(s2));
	else d_no_op = INT_MAX;
	
		d_canc = 1 + edit_distance(s1, substring(s2));
		d_ins = 1 + edit_distance(substring(s1),s2);
	}
	return min(d_canc, d_ins, d_no_op);
 
}

int edit_distance_dyn(char* s1, char* s2) {
	if (s1 == NULL || s2 == NULL)
    return -1;

	int m = strlen(s1);
	int n = strlen(s2);

	// malloc matrix for memoization
	int **mem;
	mem = malloc(m*sizeof*mem);
	for (int k = 0; k < m; k++) {
      mem[k] = malloc(n*sizeof*mem[k]);
	}
	
	// initialize matrix
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			mem[i][j] = -1;
		}
	}

	int dyn = edit_distance_dyn_rec(s1, s2, m - 1, n - 1, mem);

	//free matrix
	for (int k = 0; k < m; k++) {
		free(mem[k]);
	}
	free(mem);

	return dyn;
}

int edit_distance_dyn_rec(char* s1, char* s2, int m, int n, int** mem) {
	int d_no_op;
	int d_canc;
	int d_ins;

	// if first string is empty, the only option is to insert all characters of second string into first.
    if (m == 0) {
		return n;
	  // if second string is empty, the only option is to remove all characters of first string.
	} else if(n == 0) {
		return m;
	} else if (s1[m - 1] == s2[n - 1]) return edit_distance_dyn_rec(s1, s2, m - 1, n - 1, mem);
	
	else {
		d_no_op = s1[m-1] == s2[n-1] ? edit_distance_dyn_rec(s1, s2, m - 1, n - 1, mem) + 1 : INT_MAX;
		d_canc = edit_distance_dyn_rec(s1, s2, m, n - 1, mem) + 1;
		d_ins = edit_distance_dyn_rec(s1, s2, m - 1, n, mem) + 1;
	

		return mem[m - 1][n - 1] = min(d_no_op, d_canc, d_ins);
  	}
}