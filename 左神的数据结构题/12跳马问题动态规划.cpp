#include <iostream>
#include <vector>
using namespace std;
int pick(vector<vector<vector<int>>>& dp, int x, int y, int rest);
int dp(int a, int b, int k) {
    vector<vector<vector<int>>> dp(10, vector<vector<int>>(9, vector<int>(k + 1, 0)));
    //初始化部分
    dp[a][b][0] = 1;
    for (int rest = 1; rest <= k; rest++) {
        for (int x = 0; x < 10; x++) {
            for (int y = 0; y < 9; y++) {
                int ways = pick(dp, x + 2, y + 1, rest - 1);
                ways += pick(dp, x + 1, y + 2, rest - 1);
                ways += pick(dp, x - 1, y + 2, rest - 1);
                ways += pick(dp, x - 1, y - 2, rest - 1);
                ways += pick(dp, x - 2, y - 1, rest - 1);
                ways += pick(dp, x - 2, y + 1, rest - 1);
                ways += pick(dp, x + 1, y - 2, rest - 1);
                ways += pick(dp, x + 2, y - 1, rest - 1);
                dp[x][y][rest] = ways;
            }
        }
    }
    return dp[0][0][k];
}

int pick(vector<vector<vector<int>>>& dp, int x, int y, int rest) {
    if (x < 0 || x >= 10 || y < 0 || y >= 9) {
        return 0;
    }
    return dp[x][y][rest];
}

int main12() {
    int x = 7;
    int y = 7;
    int step = 10;
    cout << "动态规划的方式：" << dp(x, y, step) << endl;
    return 0;
}
