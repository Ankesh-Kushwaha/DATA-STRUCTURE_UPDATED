#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Function to compute the LPS array
void computeLPSArray(string pattern, vector<int>& lps) {
    int length = 0; // length of the previous longest prefix suffix
    int i = 1;
    lps[0] = 0; // lps[0] is always 0

    while (i < pattern.size()) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                // Do not increment i
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP pattern search algorithm
int KMPSearch(string str, string pattern) {
    int M = pattern.size();
    int N = str.size();

    // Create lps array to hold the longest prefix suffix values for the pattern
    vector<int> lps(M);
    computeLPSArray(pattern, lps);

    int i = 0; // index for str
    int j = 0; // index for pattern
    int count = 0; // to count occurrences of pattern in str

    while (i < N) {
        if (pattern[j] == str[i]) {
            i++;
            j++;
        }

        if (j == M) {
            count++;
            j = lps[j - 1];
        } else if (i < N && pattern[j] != str[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return count;
}

int main() {
    string str = "aaaaaaac";
    string pattern = "aaac";
    
    // Find and print the number of occurrences of pattern in str
    int occurrences = KMPSearch(str, pattern);
    cout << "Pattern occurs " << occurrences << " times in the string." << endl;
    return 0;
}
