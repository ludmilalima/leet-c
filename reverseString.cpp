#include <iostream>
#include <chrono>
#include <algorithm>
#include <vector>
using namespace std;

void measureExecutionTime(void (*func)(vector<char>&), vector<char>& s) {
    auto start = chrono::high_resolution_clock::now();
    func(s);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    cout << "Execution time: " << duration << " nanoseconds" << endl;
}

void reverseFor(vector<char>& s) {
    for (int i = 0; i < s.size() / 2; ++i) {
        swap(s[i], s[s.size() - i - 1]);
    }
};

void reverseWhile(vector<char>& s) {
    int i = 0;
    while (i < s.size() / 2) {
        swap(s[i], s[s.size() - i - 1]);
        ++i;
    }
};

//best results
void reverseDoWhile(vector<char>& s) {
    int i = 0;
    do {
        swap(s[i], s[s.size() - i - 1]);
        ++i;
    } while (i < s.size() / 2);
};

void reverseForEach(vector<char>& s) {
    std::for_each(s.begin(), s.begin() + s.size() / 2, [&](char& c) {
        swap(c, s[s.size() - (&c - &s[0]) - 1]);
    });

};

int main() {
    vector<char> str = {'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '!', '!', '!', '!', '!'};

    measureExecutionTime(reverseFor, str);
    measureExecutionTime(reverseWhile, str);
    measureExecutionTime(reverseDoWhile, str);
    measureExecutionTime(reverseForEach, str);
    for (char c : str) {
        std::cout << c;
    }
    std::cout << std::endl;

    return 0;
};