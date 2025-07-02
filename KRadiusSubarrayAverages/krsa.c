#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

char* read_entire_file(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);
    rewind(file);

    char *buffer = (char *)malloc(filesize + 1);
    if (!buffer) {
        fclose(file);
        return NULL;
    }

    size_t read_size = fread(buffer, 1, filesize, file);
    buffer[read_size] = '\0';

    fclose(file);
    return buffer;
}

int* parse_numbers(const char* content, int* out_count) {
    char* copy = strdup(content);
    if (!copy) {
        *out_count = 0;
        return NULL;
    }

    char* start = strchr(copy, '[');
    char* end = strchr(copy, ']');
    if ((start && end) && (end > start)) {
        *end = '\0';
        start++;
    } else {
        start = copy;
    }

    int count = 0;
    for (char* p = start; *p; ++p) {
        if (*p == ',') count++;
    }
    count++;

    int* nums = (int *)malloc(count * sizeof(int));
    int idx = 0;
    char* token = strtok(start, ",");
    while (token) {
        while (isspace((unsigned char)*token)) token++;
        nums[idx++] = atoi(token);
        token = strtok(NULL, ",");
    }
    *out_count = idx;
    free(copy);
    return nums;
}

int* getAverages(int* nums, int numSize, int K, int* returnSize) {
    int left = 0;
    long accumulate = 0;
    int diff = 0;
    *returnSize = numSize;
    int* result = (int*)malloc(numSize * sizeof(int));

    for (int right = 0; right < numSize; right++) {
        accumulate += nums[right];
        diff = left > 0 ? nums[left - 1] : 0;
        accumulate -= diff;
        result[right] = -1;
        printf("i = %d, accumulate = %d, diff = %d\n", right, accumulate, diff);

        if (right - left == 2 * K) {
            result[left + K] = floor(accumulate / (2 * K + 1));
            left++;
        }
    }
    return result;
}

int main() {
    char* content = read_entire_file("input.txt");
    int* average;
    int returnSize;
    int k = 0;
    if (content) {
        int count = 0;
        int* nums = parse_numbers(content, &count);
        if (nums) {
            average = getAverages(nums, count, k, &returnSize);
            for (int i = 0; i < returnSize; i++) {
                printf("i[%d]: %d\n", i, average[i]);
            }
            free(nums);
        }
        free(average);
        free(content);
    }
    return 0;
}