#include <bits/stdc++.h>
using namespace std;

// Helper function to count the number of invalid parentheses
int countInvalid(string &str) {
    int open = 0, unmatchedClose = 0;
    for (char ch : str) {
        if (ch == '(') {
            open++;
        } else if (ch == ')') {
            if (open > 0) open--;
            else unmatchedClose++;
        }
    }
    return open + unmatchedClose; // Total invalid characters
}

// Recursive function to generate all valid strings
void generateValidStrings(string &str, int goalLen, int index, string &curr, unordered_set<string> &res) {
    if (goalLen < 0) return;

    if (index == str.length()) {
        if (goalLen == 0 && countInvalid(curr) == 0) {
            res.insert(curr);
        }
        return;
    }

    char ch = str[index];

    // Include current character
    curr.push_back(ch);

    // If it's a parenthesis, explore both include and exclude
    if (ch == '(' || ch == ')') {
        generateValidStrings(str, goalLen - 1, index + 1, curr, res); // include
        curr.pop_back();
        generateValidStrings(str, goalLen, index + 1, curr, res);     // exclude
    } else {
        generateValidStrings(str, goalLen - 1, index + 1, curr, res); // always include letters
        curr.pop_back();
    }

    // Pop again if it was pushed before include check
    if (!curr.empty() && curr.back() == ch) curr.pop_back();
}

// Main function
vector<string> removeInvalidParentheses(string &str) {
    int minRemovals = countInvalid(str);          // Step 1: Count invalids
    int goalLength = str.length() - minRemovals;  // Step 2: Target length
    string current = "";
    unordered_set<string> resultSet;

    generateValidStrings(str, goalLength, 0, current, resultSet); // Step 3: Recursively generate

    return vector<string>(resultSet.begin(), resultSet.end());
}
