#include <stdio.h>
#include <string.h>
#include "Failure.h"

/*
 * failure_function - Computes the failure function for a given pattern.
 *
 * The failure function f(s) gives the length of the longest proper prefix
 * of the pattern that is also a suffix of the first s characters.
 * This is used by the KMP algorithm to avoid redundant comparisons.
 *
 * Based on Figure 3.19 (page 137) of:
 * Aho, A.V. et al. "Compilers: Principles, Techniques & Tools", 2nd ed.
 *
 * Parameters:
 *   pattern - the keyword/pattern string
 *   n       - length of the pattern
 *   f       - output array of size n+1 (1-indexed: f[1]..f[n])
 */
void failure_function(const char *pattern, int n, int *f) {
    /* f is 1-indexed: f[1]..f[n] */
    /* f[1] = 0 by definition */
    f[1] = 0;

    int t = 0; /* length of current matching prefix */

    for (int s = 2; s <= n; s++) {
        /* While no match and still have prefix to fall back to */
        while (t > 0 && pattern[t] != pattern[s - 1]) {
            t = f[t];
        }
        /* Check if current character extends the prefix */
        if (pattern[t] == pattern[s - 1]) {
            t = t + 1;
        }
        f[s] = t;
    }
}

/*
 * print_failure_table - Prints the failure table in a readable format.
 */
void print_failure_table(const char *pattern, int n, int *f) {
    printf("\n--- Failure Function Table ---\n");
    printf("Pattern: %s\n\n", pattern);

    printf("i    : ");
    for (int i = 1; i <= n; i++) printf("%4d", i);
    printf("\n");

    printf("b[i] : ");
    for (int i = 1; i <= n; i++) printf("%4c", pattern[i - 1]);
    printf("\n");

    printf("f(i) : ");
    for (int i = 1; i <= n; i++) printf("%4d", f[i]);
    printf("\n");
    printf("------------------------------\n");
}