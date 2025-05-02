#include <stdio.h>
#include <string.h>
#include <time.h>

void swap (char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverseFor(char* s, int sSize) {

    for (int i = 0; i < sSize/2; i++) {
        swap(&s[i], &s[sSize - 1 - i]);
    }
}

void reverseWhile(char* s, int sSize) {
    int forwards = 0;
    while (forwards < sSize - 1 - forwards) {
        swap(&s[forwards], &s[sSize - 1 - forwards]);
        forwards++;
    }
}

void reverseDoWhile(char* s, int sSize) {
    int forwards = 0;
    do {
        swap(&s[forwards], &s[sSize - 1 - forwards]);
        forwards++;
    } while (forwards < sSize - 1 - forwards);
}

void printCallTime(void (*function)(char*, int), char* s, int sSize) {
    clock_t start = clock(); // Start time
    function(s, sSize);
    clock_t end = clock(); // End time

    // Calculate and print execution time in seconds
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Execution Time: %f seconds\n", time_taken);
}

int main() {
    // Declare the string as a writable array
    char str[] = "Hello, World!!!";
    int strSize = strlen(str);

    printf("ReverseFor\n");
    printCallTime(reverseFor, str, strSize);

    printf("ReverseWhile\n");
    printCallTime(reverseWhile, str, strSize);

    printf("ReverseDoWhile\n");
    printCallTime(reverseDoWhile, str, strSize);    

    return 0;
}