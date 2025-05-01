#include <stdio.h>
#include <string.h>

char* reverseString(char* s, int sSize) {
    int halfSize = sSize / 2;
    int forwardsPointer = 0;
    int backwardsPointer = sSize - 1;
    for (int i = 0; i < halfSize; i++) {
        char front = s[forwardsPointer];
        s[forwardsPointer] = s[backwardsPointer];
        s[backwardsPointer] = front;
        forwardsPointer++;
        backwardsPointer--;
    }
    return s;
}

int main() {
    // Declare the string as a writable array
    char str[] = "Hello, World!!";
    int strSize = strlen(str);

    printf("Original String: %s\n", str);
    reverseString(str, strSize);
    printf("Reversed String: %s\n", str);

    return 0;
}