#include <stdio.h>

#define N 4 // So chieu cua he phuong trinh (vi du nay su dung ma tran 3x3)

// Ham de in ma tran
void inMaTran(double mat[N][N + 1]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N + 1; j++) {
            printf("%.2f\t", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Ham de thuc hien phuong phap Gauss-Jordan
void gaussJordan(double mat[N][N + 1]) {
    for (int i = 0; i < N; i++) {
        // Tim phan tu khong bang 0 o cot i trong cac hang i tro len
        int pivot_row = i;
        while (mat[pivot_row][i] == 0 && pivot_row < N) {
            pivot_row++;
        }

        // dua phan tu khong bang 0 do ve tren cung cua cot
        if (pivot_row != i) {
            for (int j = 0; j < N + 1; j++) {
                double temp = mat[i][j];
                mat[i][j] = mat[pivot_row][j];
                mat[pivot_row][j] = temp;
            }
        }

        // Chia hang i cho phan tu duong cheo de co gia tri 1
        double pivot = mat[i][i];
        for (int j = 0; j < N + 1; j++) {
            mat[i][j] /= pivot;
        }

        // Loai bo cac phan tu khac 0 tai cot i
        for (int k = 0; k < N; k++) {
            if (k != i) {
                double factor = mat[k][i];
                for (int j = 0; j < N + 1; j++) {
                    mat[k][j] -= factor * mat[i][j];
                }
            }
        }
    }
}

int main() {
    // Khoi tao ma tran mo rong cua he phuong trinh (vi du)
    double mat[N][N + 1] = {{1, 1, -3, 2,6},
                             {1, -2, 0, -1,-6},
                             {0, 1, 1, 3,16},
							 {2, -3, 2, 0,6 },};

    printf("Ma tran ban dau:\n");
    inMaTran(mat);

    // Goi phuong phap Gauss-Jordan de giai he phuong trinh
    gaussJordan(mat);

    printf("Ma tran sau khi su dung phuong phap Gauss-Jordan:\n");
    inMaTran(mat);

    // In ra nghiem cua he phuong trinh
    printf("Nghiem cua he phuong trinh:\n");
    for (int i = 0; i < N; i++) {
        printf("x[%d] = %.2f\n", i, mat[i][N]);
    }

    return 0;
}

