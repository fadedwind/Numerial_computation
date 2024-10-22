#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITER 1000
#define TOLERANCE 1e-6

void gauss_seidel(double **A, double *b, double *x, int n) {
    for (int iter = 0; iter < MAX_ITER; iter++) {
        double error = 0.0;
        for (int i = 0; i < n; i++) {
            double old_xi = x[i];
            x[i] = b[i];
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    x[i] -= A[i][j] * x[j];
                }
            }
            x[i] /= A[i][i];
            error += fabs(x[i] - old_xi);
        }
        if (error < TOLERANCE) {
            break;
        }
    }
}

int main() {
    int n;
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);

    double **A = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        A[i] = (double *)malloc(n * sizeof(double));
    }

    printf("Enter the elements of the matrix A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    double *b = (double *)malloc(n * sizeof(double));
    printf("Enter the elements of the vector b:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &b[i]);
    }

    double *x = (double *)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        x[i] = 0.0;  // Initial guess
    }

    gauss_seidel(A, b, x, n);

    printf("Solution: \n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %.10f\n", i, x[i]);  // 输出10位小数
    }

    for (int i = 0; i < n; i++) {
        free(A[i]);
    }
    free(A);
    free(b);
    free(x);

    return 0;
}