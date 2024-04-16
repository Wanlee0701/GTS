def cholesky_decomposition(matrix):
    n = len(matrix)
    L = [[0.0] * n for _ in range(n)]

    for i in range(n):
        for j in range(i+1):
            sum_val = sum(L[i][k] * L[j][k] for k in range(j))
            if i == j:
                L[i][j] = (matrix[i][i] - sum_val) ** 0.5
            else:
                L[i][j] = (1.0 / L[j][j] * (matrix[i][j] - sum_val))

    return L

def forward_substitution(L, b):
    n = len(L)
    y = [0.0] * n

    for i in range(n):
        y[i] = (b[i] - sum(L[i][j] * y[j] for j in range(i))) / L[i][i]

    return y

def backward_substitution(L_transpose, y):
    n = len(L_transpose)
    x = [0.0] * n

    for i in range(n - 1, -1, -1):
        x[i] = (y[i] - sum(L_transpose[i][j] * x[j] for j in range(i + 1, n))) / L_transpose[i][i]

    return x

def cholesky_solve(matrix, b):
    L = cholesky_decomposition(matrix)
    y = forward_substitution(L, b)
    L_transpose = list(map(list, zip(*L)))  # Transpose of L
    x = backward_substitution(L_transpose, y)
    return x

# Example usage
# Ma trận hệ số của hệ phương trình
A = [
    [4, 12, -16],
    [12, 37, -43],
    [-16, -43, 98]
]
# Vector bên phải của hệ phương trình
b = [1, 2, 3]

# Giải hệ phương trình bằng phương pháp Cholesky
x = cholesky_solve(A, b)
print("Nghiệm của hệ phương trình:", x)
