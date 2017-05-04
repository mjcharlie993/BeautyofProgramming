#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int large = 100000;

template<typename T>
void rerank(T m[], int length) {
    for (int i = length - 1; i != 0; i--) {
        for (int j = 0; j < i; j++) {
            if (m[j] > m[j + 1]) {
                T temp;
                temp = m[j + 1];
                m[j + 1] = m[j];
                m[j] = temp;
            }
        }
    }
}

double Min(double a, double b, double c, double d, double e) {
    double nn[5] = {a, b, c, d, e};
    rerank(nn, 5);

    return nn[0];
}

double find_BestSol(int x1, int x2, int x3, int x4, int x5) {
    int n[5] = {x1, x2, x3, x4, x5};
    rerank(n, 5);
    x1 = n[0];
    x2 = n[1];
    x3 = n[2];
    x4 = n[3];
    x5 = n[4];

    // x1 < x2 < x3 < x4 < x5
    if (n[0] > 0) {
        return Min(8.0 + find_BestSol(x1, x2, x3, x4, x5 - 1), 
                   2 * 8 * 0.95 + find_BestSol(x1, x2, x3, x4 - 1, x5 - 1),
                   3 * 8 * 0.90 + find_BestSol(x1, x2, x3 - 1, x4 - 1, x5 - 1),
                   4 * 8 * 0.80 + find_BestSol(x1, x2 - 1, x3 - 1, x4 - 1, x5 - 1),
                   5 * 8 * 0.75 + find_BestSol(x1 - 1, x2 - 1, x3 - 1, x4 - 1, x5 - 1));
    } else if (n[0] == 0 && n[1] > 0) {
        return Min(8.0 + find_BestSol(x1, x2, x3, x4, x5 - 1),
                   2 * 8 * 0.95 + find_BestSol(x1, x2, x3, x4 - 1, x5 - 1),
                   3 * 8 * 0.90 + find_BestSol(x1, x2, x3 - 1, x4 - 1, x5 - 1),
                   4 * 8 * 0.80 + find_BestSol(x1, x2 - 1, x3 - 1, x4 - 1, x5 - 1),
                   large);
    } else if (n[0] == 0 && n[1] == 0 && n[2] > 0) {
        return Min(8.0 + find_BestSol(x1, x2, x3, x4, x5 - 1),
                   2 * 8 * 0.95 + find_BestSol(x1, x2, x3, x4 - 1, x5 - 1),
                   3 * 8 * 0.90 + find_BestSol(x1, x2, x3 - 1, x4 - 1, x5 - 1),
                   large,
                   large);
    } else if (n[0] == 0 && n[1] == 0 && n[2] == 0 && n[3] > 0) {
        return Min(8.0 + find_BestSol(x1, x2, x3, x4, x5 - 1),
                   2 * 8 * 0.95 + find_BestSol(x1, x2, x3, x4 - 1, x5 - 1),
                   large,
                   large,
                   large);
    } else if (n[0] == 0 && n[1] == 0 && n[2] == 0 && n[3] == 0 && n[4] > 0) {
        return 8.0 + find_BestSol(x1, x2, x3, x4, x5 - 1);

    } else {
        return 0;
    }
}

int main() {
    int n1[5] = {2, 2, 2, 1, 1};
    double solution = find_BestSol(n1[0], n1[1], n1[2], n1[3], n1[4]);
    cout << "The min cost is: " << solution << endl;
}