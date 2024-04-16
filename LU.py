def LU_decomposition(matrix):
    n = len(matrix)
    L = [[0.0] * n for _ in range(n)]
    U = [[0.0] * n for _ in range(n)]

    for i in range(n):
        # Ma trận tam giác dưới L
        L[i][i] = 1.0
        for j in range(i + 1):
            s1 = sum(U[k][i] * L[j][k] for k in range(j))
            U[j][i] = matrix[j][i] - s1

        # Ma trận tam giác trên U
        for j in range(i, n):
            s2 = sum(U[k][i] * L[j][k] for k in range(i))
            L[j][i] = (matrix[j][i] - s2) / U[i][i]

    return L, U

def forward_substitution(L, b):
    n = len(L)
    y = [0.0] * n

    for i in range(n):
        y[i] = (b[i] - sum(L[i][j] * y[j] for j in range(i))) / L[i][i]

    return y

def backward_substitution(U, y):
    n = len(U)
    x = [0.0] * n

    for i in range(n - 1, -1, -1):
        x[i] = (y[i] - sum(U[i][j] * x[j] for j in range(i + 1, n))) / U[i][i]

    return x

def LU_solve(matrix, b):
    L, U = LU_decomposition(matrix)
    y = forward_substitution(L, b)
    x = backward_substitution(U, y)
    return x

# Example usage
# Ma trận hệ số của hệ phương trình
A = [
    [4, 0.24, -0.08],
    [0.09, 3, -0.15],
    [0.04, -0.08, 4]
]
# Vector bên phải của hệ phương trình
b = [8, 9, 20]

# Giải hệ phương trình bằng phương pháp phân rã LU
x = LU_solve(A, b)
print("Nghiệm của hệ phương trình:", x)
