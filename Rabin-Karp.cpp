a)	Rabin-Karp:
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#define d 256
const int q = 101; // You can change this to another prime number

unsigned long long calculateStringhash(const string &str, int n) {
    unsigned long long h = 0;
    for (int i = 0; i < n; i++) {
        h = (h * d + str[i]) % q;
    }
    return h;
}

unsigned long long recomputeHash(unsigned long long h, char oldChar, char newChar, int n) {
    return (h + d * (newChar - oldChar) * static_cast<int>(pow(q, n - 1))) % q;
}

void search(const string &text, const string &pattern) {
    int n = pattern.length();
    int m = text.length();
    unsigned long long pattHash = calculateStringhash(pattern, n);
    unsigned long long textHash = calculateStringhash(text, n);
    for (int i = 0; i <= m - n; i++) {
        // Check if the hash values match
        if (pattHash == textHash) {
            bool found = true;
            for (int j = 0; j < n; j++) {
                if (text[i + j] != pattern[j]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                cout << "Pattern found at index " << i << endl;
            }
        }
        if (i < m - n) {
            textHash = recomputeHash(textHash, text[i], text[i + n], n);
        }
    }
}

int main() {
    string text, pattern;
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern to search: ";
    getline(cin, pattern);
    search(text, pattern);
    return 0;
}
