#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int minDistanceRec(string word1, string word2, int i, int j) {
    // ������� 1: ��� i �� j ͬʱ���� -1����ʾ�������ַ������༭����Ϊ 0
    if (i == -1 && j == -1) {
        return 0;
    }

    // ������� 2: ��� i == -1����ʾ word1 �Ѿ������꣬��ʱ�༭����Ϊ j + 1���� word2 ��ɾ���ַ���
    if (i == -1) {
        return j + 1;
    }

    // ������� 3: ��� j == -1����ʾ word2 �Ѿ������꣬��ʱ�༭����Ϊ i + 1���� word1 ��ɾ���ַ���
    if (j == -1) {
        return i + 1;
    }

    // �ݹ����
    if (word1[i] == word2[j]) {
        return minDistanceRec(word1, word2, i - 1, j - 1);
    }
    else {
        int deleteFromWord1 = minDistanceRec(word1, word2, i - 1, j) + 1; // �� word1 ��ɾ���ַ�
        int deleteFromWord2 = minDistanceRec(word1, word2, i, j - 1) + 1; // �� word2 ��ɾ���ַ�
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
