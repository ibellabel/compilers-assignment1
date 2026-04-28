#include <stdio.h>
#include <string.h>
#include "Failure.h"
#include "Kmp.h"

/*
 * solve_exercise - Runs KMP for a given pattern against a text and prints result.
 */
void solve_exercise(const char *label, const char *text, const char *pattern) {
    int n = strlen(pattern);
    int m = strlen(text);
    int f[n + 1];

    printf("\n========================================\n");
    printf("%s\n", label);
    printf("========================================\n");

    /* Step 1: compute and display failure function */
    failure_function(pattern, n, f);
    print_failure_table(pattern, n, f);

    /* Step 2: run KMP search with trace */
    int result = kmp_search(text, m, pattern, n, f);

    printf("\nResult: \"%s\" is%s a substring of \"%s\"\n",
           pattern, result ? "" : " NOT", text);
}

int main(void) {
    printf("================================================\n");
    printf("  KMP Algorithm - Assignment 1\n");
    printf("  Compilers: Principles, Techniques & Tools\n");
    printf("  Section 3.4 - Failure Function & KMP Search\n");
    printf("================================================\n");

    /*
     * Exercise 3.4.3 (page 137):
     * Compute the failure function for the keyword "ababaa"
     * This is the core requirement of the assignment.
     */
    printf("\n\n*** Exercise 3.4.3 ***\n");
    printf("Compute the failure function for keyword: ababaa\n");
    {
        const char *pattern = "ababaa";
        int n = strlen(pattern);
        int f[n + 1];
        failure_function(pattern, n, f);
        print_failure_table(pattern, n, f);

        printf("\nExplanation of each f(i) value:\n");
        printf("  f(1)=0 : 'a'        -> no proper prefix\n");
        printf("  f(2)=0 : 'ab'       -> no prefix == suffix\n");
        printf("  f(3)=1 : 'aba'      -> prefix 'a' == suffix 'a'\n");
        printf("  f(4)=2 : 'abab'     -> prefix 'ab' == suffix 'ab'\n");
        printf("  f(5)=3 : 'ababa'    -> prefix 'aba' == suffix 'aba'\n");
        printf("  f(6)=1 : 'ababaa'   -> prefix 'a' == suffix 'a'\n");
    }

    /*
     * Exercise 3.4.6 (page 137):
     * Apply KMP to test whether "ababaa" is a substring of:
     * a) abababaab
     * b) abababbaa
     */
    printf("\n\n*** Exercise 3.4.6 ***\n");
    printf("Apply KMP: is \"ababaa\" a substring of the following strings?\n");

    solve_exercise(
        "Exercise 3.4.6 a) - Text: abababaab",
        "abababaab",
        "ababaa"
    );

    solve_exercise(
        "Exercise 3.4.6 b) - Text: abababbaa",
        "abababbaa",
        "ababaa"
    );

    printf("\n================================================\n");
    printf("  Done.\n");
    printf("================================================\n");

    return 0;
}