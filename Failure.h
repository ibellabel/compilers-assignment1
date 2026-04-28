#ifndef FAILURE_H
#define FAILURE_H

/*
 * failure_function - Computes the failure function f[] for a pattern.
 *
 * pattern : the keyword string (0-indexed C string)
 * n       : length of pattern
 * f       : output array (1-indexed), must have size >= n+1
 *           f[1] = 0 always; f[s] = length of longest proper prefix
 *           of pattern[0..s-1] that is also a suffix.
 */
void failure_function(const char *pattern, int n, int *f);

/*
 * print_failure_table - Pretty-prints the failure table.
 */
void print_failure_table(const char *pattern, int n, int *f);

#endif /* FAILURE_H */