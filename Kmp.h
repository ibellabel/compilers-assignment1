#ifndef KMP_H
#define KMP_H

/*
 * kmp_search - KMP substring search (Figure 3.20).
 *
 * text    : string to search in (0-indexed)
 * m       : length of text
 * pattern : keyword to search for (0-indexed)
 * n       : length of pattern
 * f       : precomputed failure function (1-indexed, size >= n+1)
 *
 * Returns 1 ("yes") if pattern is found in text, 0 ("no") otherwise.
 */
int kmp_search(const char *text, int m, const char *pattern, int n, int *f);

#endif /* KMP_H */