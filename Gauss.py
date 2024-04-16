def gaussian_elimination(matrix):
    # Số hàng, số cột của ma trận
    rows = len(matrix)
    cols = len(matrix[0])
#Bước thuận
    for i in range(rows):
        '''# Tìm hàng có phần tử không bằng 0 ở cột thứ i
        for j in range(i, rows):
            if matrix[j][i] != 0:
                # Đặt hàng j thành hàng đầu tiên
                matrix[i], matrix[j] = matrix[j], matrix[i]
                break
            else:
            # Nếu không tìm thấy hàng phù hợp, điều này có nghĩa là ma trận không có nghiệm duy nhất
                print("Hệ phương trình không có nghiệm duy nhất.")
                return
        print(matrix) '''
        # Đặt phần tử đường chéo chính (ở cột thứ i) thành 1 bằng cách chia mỗi phần tử trong hàng cho giá trị của phần tử đó
        pivot = matrix[i][i]
        for j in range(cols):
            matrix[i][j] /= pivot
        print(matrix)
        # Loại bỏ các giá trị của biến đang xét trong các hàng khác
        for k in range(i + 1, rows):
            factor = matrix[k][i]
            for j in range(cols):
                matrix[k][j] -= factor * matrix[i][j]
        print(matrix)
# Bước nghịch
    solutions = [0] * rows
    for i in range(rows - 1, -1, -1): #Duyệt từ dưới lên
        solutions[i] = matrix[i][cols - 1] #Gán giá trị biến cuối
        for j in range(i + 1, cols - 1):
            solutions[i] -= matrix[i][j] * solutions[j]
    print(matrix)
    return solutions

# Example usage
# Ma trận mở rộng của hệ phương trình (ví dụ)
# Định dạng: [[a1, b1, c1, d1], [a2, b2, c2, d2], [a3, b3, c3, d3], ...]
# Ví dụ: 2x + 3y - z = 5, 3x - 2y + 4z = 7, x + 4y + 2z = 3
matrix = [
    [4, 0.24, -0.08, 8],
    [0.09, 3, -0.15, 9],
    [0.04, -0.08, 4, 20]
]

solutions = gaussian_elimination(matrix)
print("Nghiệm của hệ phương trình:", solutions)
