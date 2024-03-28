#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int minDistanceRec(string word1, string word2, int i, int j) {
    // 基本情况 1: 如果 i 和 j 同时等于 -1，表示两个空字符串，编辑距离为 0
    if (i == -1 && j == -1) {
        return 0;
    }

    // 基本情况 2: 如果 i == -1，表示 word1 已经遍历完，此时编辑距离为 j + 1（在 word2 中删除字符）
    if (i == -1) {
        return j + 1;
    }

    // 基本情况 3: 如果 j == -1，表示 word2 已经遍历完，此时编辑距离为 i + 1（在 word1 中删除字符）
    if (j == -1) {
        return i + 1;
    }

    // 递归情况
    if (word1[i] == word2[j]) {
        return minDistanceRec(word1, word2, i - 1, j - 1);
    }
    else {
        int deleteFromWord1 = minDistanceRec(word1, word2, i - 1, j) + 1; // 在 word1 中删除字符
        int deleteFromWord2 = minDistanceRec(word1, word2, i, j - 1) + 1; // 在 word2 中删除字符
        return min(deleteFromWord1, deleteFromWord2);
    }
}

int minDistance(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();
    return minDistanceRec(word1, word2, m - 1, n - 1);
}

int main16() {
    string word1 = "sea";
    string word2 = "keazxcvbnm";
    int result = minDistance(word1, word2);
    cout << result << endl;
    return 0;
}
