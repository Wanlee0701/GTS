#include <stdio.h>
#include <math.h>

#define N 3 // So chieu cua ma tran ( trong VD la 3x3)
#define MAX_ITER 1000 // So lan lap toi da cho phuong phap
#define EPSILON 0.02 // Sai so tuyet doi cho truoc

// Phuong ph�p lap
void jacobi(double A[N][N], double b[N], double x[N]) {
    double x_new[N]; // Vector nghiem moi tam thoi
    int iter = 0;
    double error;

    // Lap cho den khi dat den so lan lap toi da hoac sai so tuyet doi thap hon sai so cho truoc
    do {
        // T�nh to�n vector nghiem moi tam thoi
        for (int i = 0; i < N; i++) {
            x_new[i] = b[i];
            for (int j = 0; j < N; j++) {
                if (i != j) {
                    x_new[i] -= A[i][j] * x[j];
                }
            }
            x_new[i] /= A[i][i];
        }

        // T�nh to�n sai so  tuyet doi
        error = 0.0;
        for (int i = 0; i < N; i++) {
            error += fabs(x_new[i] - x[i]);
        }

        // Cap nhat vector nghiem v� so lan lap
        for (int i = 0; i < N; i++) {
            x[i] = x_new[i];
        }
        iter++;

    } while (error > EPSILON && iter < MAX_ITER);

    // In ket qua sau khi ket th�c lap
    printf("Solution after %d iterations:\n", iter);
    for (int i = 0; i < N; i++) {
        printf("x[%d] = %.12f\n", i, x[i]);
    }
}

int main() {
    // Khoi tao ma tran A v� vector b (v� du)
    double A[N][N] = {{4, 0.24, -0.08},
                      {0.09, 3, -0.15},
                      {0.04, -0.08, 4}};
    double b[N] = {8, 9, 20};

    // Khoi tao vector nghiem x (su dung gi� tri ban dau l� 0)
    double x[N] = {0};

    // Goi h�m Jacobi da giai he phuong tr�nh
    jacobi(A, b, x);

    return 0;
}

