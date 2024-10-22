#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void LU_decomposition(double **A, double **L, double **U, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j < i)
                L[j][i] = 0;
            else {
                L[j][i] = A[j][i];
                for (int k = 0; k < i; k++) {
                    L[j][i] = L[j][i] - L[j][k] * U[k][i];
                }
            }
        }
        for (int j = 0; j < n; j++) {
            if (j < i)
                U[i][j] = 0;
            else if (j == i)
                U[i][j] = 1;
            else {
                U[i][j] = A[i][j] / L[i][i];
                for (int k = 0; k < i; k++) {
                    U[i][j] = U[i][j] - ((L[i][k] * U[k][j]) / L[i][i]);
                }
            }
        }
    }
}

void forward_substitution(double **L, double *b, double *y, int n) {
    for (int i = 0; i < n; i++) {
        y[i] = b[i];
        for (int j = 0; j < i; j++) {
            y[i] -= L[i][j] * y[j];
        }
        y[i] = y[i] / L[i][i];
    }
}

void backward_substitution(double **U, double *y, double *x, int n) {
    for (int i = n - 1; i >= 0; i--) {
        x[i] = y[i];
        for (int j = i + 1; j < n; j++) {
            x[i] -= U[i][j] * x[j];
        }
    }
}

int main() {
    int n;
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);

    double **A = (double **)malloc(n * sizeof(double *));
    double **L = (double **)malloc(n * sizeof(double *));
    double **U = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        A[i] = (double *)malloc(n * sizeof(double));
        L[i] = (double *)malloc(n * sizeof(double));
        U[i] = (double *)malloc(n * sizeof(double));
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

    double *y = (double *)malloc(n * sizeof(double));
    double *x = (double *)malloc(n * sizeof(double));

    LU_decomposition(A, L, U, n);
    forward_substitution(L, b, y, n);
    backward_substitution(U, y, x, n);

    printf("Solution: \n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %f\n", i, x[i]);
    }

    for (int i = 0; i < n; i++) {
        free(A[i]);
        free(L[i]);
        free(U[i]);
    }
    free(A);
    free(L);
    free(U);
    free(b);
    free(y);
    free(x);

    return 0;
}