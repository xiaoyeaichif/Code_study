#include <iostream>
#include <vector>
#include <cmath>

// ����״̬ת�ƾ����С
const int N = 4;

// ����״̬ת�ƾ���
double transition_matrix[N][N] = {
    {0.1, 0.3, 0.3, 0.3},
    {0.1, 0.3, 0.3, 0.3},
    {0.1, 0.3, 0.3, 0.3},
    {0.1, 0.3, 0.3, 0.3}
};

// ��������������������ŷ����÷���
double norm(const std::vector<double>& v1, const std::vector<double>& v2) {
    double result = 0.0;
    for (int i = 0; i < N; ++i) {
        result += pow(v1[i] - v2[i], 2);
    }
    return sqrt(result);
}

// ������Ѱ��ƽ�ȷֲ�
std::vector<double> find_stationary_distribution(double matrix[N][N], double tol = 1e-10, int max_iter = 1000) {
    std::vector<double> pi(N, 1.0 / N); // ��ʼ���ʷֲ�

    for (int iter = 0; iter < max_iter; ++iter) {
        std::vector<double> new_pi(N, 0.0);

        // Ӧ��״̬ת�ƾ���
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                new_pi[j] += pi[i] * matrix[i][j];
            }
        }

        // ��һ������
        double total = 0.0;
        for (int i = 0; i < N; ++i) {
            total += new_pi[i];
        }
        for (int i = 0; i < N; ++i) {
            new_pi[i] /= total;
        }

        // �ж��Ƿ�����
        if (norm(new_pi, pi) < tol) {
            return new_pi;
        }
        pi = new_pi;
    }

    return pi;
}

int main0122() {
    std::vector<double> stationary_distribution = find_stationary_distribution(transition_matrix);

    std::cout << "ƽ�ȷֲ���";
    for (int i = 0; i < N; ++i) {
        std::cout << stationary_distribution[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
