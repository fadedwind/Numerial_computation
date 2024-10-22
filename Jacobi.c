#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITER 1000
#define TOLERANCE 1e-6

void jacobi(double **A, double *b, double *x, int n) {
    double *x_new = (double *)malloc(n * sizeof(double));
    for (int iter = 0; iter < MAX_ITER; iter++) {
        for (int i = 0; i < n; i++) {
            x_new[i] = b[i];
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    x_new[i] -= A[i][j] * x[j];
                }
            }
            x_new[i] /= A[i][i];
        }

        double error = 0.0;
        for (int i = 0; i < n; i++) {
            error += fabs(x_new[i] - x[i]);
            x[i] = x_new[i];
        }

        if (error < TOLERANCE) {
            break;
        }
    }
    free(x_new);
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

    jacobi(A, b, x, n);

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