#include <stdio.h>
#include <string.h>
#include "Failure.h"
#include "Kmp.h"

/*
 * kmp_search - Tests whether keyword b1b2...bn occurs in string a1a2...am.
 *
 * Based on Figure 3.20 (page 137) of:
 * Aho, A.V. et al. "Compilers: Principles, Techniques & Tools", 2nd ed.
 *
 * The algorithm scans the string left to right maintaining s = number of
 * keyword characters matched so far. When a mismatch occurs after s matches,
 * it "slides" the keyword right by s - f(s) positions using the failure function,
 * so only the first f(s) characters need to be re-examined.
 *
 * Parameters:
 *   text    - the string a1a2...am to search in
 *   m       - length of text
 *   pattern - the keyword b1b2...bn to search for
 *   n       - length of pattern
 *   f       - precomputed failure function array (1-indexed)
 *
 * Returns:
 *   1 if the keyword is found ("yes"), 0 otherwise ("no")
 */
int kmp_search(const char *text, int m, const char *pattern, int n, int *f) {
    int s = 0; /* number of characters matched so far (line 1) */

    printf("\n--- KMP Search Trace ---\n");
    printf("Text:    \"%s\"\n", text);
    printf("Keyword: \"%s\"\n\n", pattern);
    printf("%-5s %-6s %-8s %-8s %-8s\n", "i", "a[i]", "s_before", "action", "s_after");
    printf("--------------------------------------------\n");

    for (int i = 1; i <= m; i++) {  /* line 2: for i = 1; i <= m; i++ */
        char ai = text[i - 1];
        int s_before = s;

        /* line 3: while (s > 0 && a[i] != b[s+1]) s = f(s) */
        while (s > 0 && ai != pattern[s]) {
            s = f[s];
        }

        /* line 4: if (a[i] == b[s+1]) s = s + 1 */
        if (ai == pattern[s]) {
            s = s + 1;
        }

        /* Determine action for trace */
        char action[20];
        if (s == s_before + 1)
            snprintf(action, sizeof(action), "match");
        else if (s == 0 && ai != pattern[0])
            snprintf(action, sizeof(action), "no match");
        else
            snprintf(action, sizeof(action), "fallback->%d", s);

        printf("%-5d %-6c %-8d %-8s %-8d\n", i, ai, s_before, action, s);

        /* line 5: if (s == n) return "yes" */
        if (s == n) {
            printf("--------------------------------------------\n");
            printf("s == n = %d  =>  keyword found at position %d\n", n, i - n + 1);
            return 1;
        }
    }

    /* line 6: return "no" */
    printf("--------------------------------------------\n");
    printf("Keyword NOT found in text.\n");
    return 0;
}