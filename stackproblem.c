// stackproblem.c - Lab 02 - Ewen, Crawford

#include <stdlib.h>
#include <stdio.h>

int main(void) {
    // Input/output arrays supporting 80 characters plus a terminating null
    // character (initialize to zero to avoid indeterminate values and to 
    // ensure that null characters follow any inputted characters in the array)
    char input[81] = {0};
    char output[81] = {0};
    scanf("%s", input);
    // Walk backwards through the input array to find the last input character 
    // (that precedes the null terminating character) and then start copying to
    // output array in reverse order
    int start_copy = 0;
    int out_idx = 0;
    for (int i = 80; i >= 0; i--) {
        if (start_copy == 0) {
            if (input[i - 1] != '\0') {
                start_copy = 1;
            }
            continue;
        }
        // Start copying array
        output[out_idx] = input[i];
        out_idx++;
    }
    // Print output
    printf("%s \n", output);
    
    return 0;
}