a)	 Kruth-Morris-Pratt:
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> computeLSPTable(const string &pat) {
    int n = pat.length();
    vector<int> lsp(n);
    lsp[0] = 0;
    int i = 1;
    int len = 0; // length of the previous longest prefix suffix
    while (i < n) {
        if (pat[i] == pat[len]) {
            len++;
            lsp[i] = len;
            i++;
        } else {
            if (len > 0) {
                len = lsp[len - 1];
            } else {
                lsp[i] = 0;
                i++;
            }
        }
    }
    return lsp;
}

void searchKMP(const string &text, const string &pat) {
    int n = text.length();
    int m = pat.length();
    vector<int> lsp = computeLSPTable(pat);
    int i = 0; // index for text
    int j = 0; // index for pattern
    while (i < n) {
        if (text[i] == pat[j]) {
            i++;
            j++;
            if (j == m) {
                cout << "Pattern found at index " << i - j << endl;
                j = lsp[j - 1]; // Shift the pattern using LSP table
            }
        } else {
            if (j > 0) {
                j = lsp[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    string text, pattern;
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern to search: ";
    getline(cin, pattern);
    searchKMP(text, pattern);
    return 0;
}
