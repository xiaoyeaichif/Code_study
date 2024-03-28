#include <iostream>
#include <vector>
#include <cmath>

// 定义状态转移矩阵大小
const int N = 4;

// 定义状态转移矩阵
double transition_matrix[N][N] = {
    {0.1, 0.3, 0.3, 0.3},
    {0.1, 0.3, 0.3, 0.3},
    {0.1, 0.3, 0.3, 0.3},
    {0.1, 0.3, 0.3, 0.3}
};

// 函数：计算两个向量的欧几里得范数
double norm(const std::vector<double>& v1, const std::vector<double>& v2) {
    double result = 0.0;
    for (int i = 0; i < N; ++i) {
        result += pow(v1[i] - v2[i], 2);
    }
    return sqrt(result);
}

// 函数：寻找平稳分布
std::vector<double> find_stationary_distribution(double matrix[N][N], double tol = 1e-10, int max_iter = 1000) {
    std::vector<double> pi(N, 1.0 / N); // 初始概率分布

    for (int iter = 0; iter < max_iter; ++iter) {
        std::vector<double> new_pi(N, 0.0);

        // 应用状态转移矩阵
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                new_pi[j] += pi[i] * matrix[i][j];
            }
        }

        // 归一化向量
        double total = 0.0;
        for (int i = 0; i < N; ++i) {
            total += new_pi[i];
        }
        for (int i = 0; i < N; ++i) {
            new_pi[i] /= total;
        }

        // 判断是否收敛
        if (norm(new_pi, pi) < tol) {
            return new_pi;
        }
        pi = new_pi;
    }

    return pi;
}

int main0122() {
    std::vector<double> stationary_distribution = find_stationary_distribution(transition_matrix);

    std::cout << "平稳分布：";
    for (int i = 0; i < N; ++i) {
        std::cout << stationary_distribution[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
