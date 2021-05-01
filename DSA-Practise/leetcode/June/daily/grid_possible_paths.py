def print_mat(mat):
    for x in mat:
        print("\t".join([str(i) for i in x]))
def uniquePaths_util(curr, limits, mat ,iter):
    i, j = curr
    m, n = limits
    print("pos", i, j)
    if i == m-1 and j == n-1:
        print("reached dest")
        mat[i][j] = 1
    elif i < m and j < n:
        if mat[i][j] == 0:
            mat[i][j] += uniquePaths_util((i, j+1), (m,n), mat, iter+1) + \
                        uniquePaths_util((i+1, j), (m,n), mat, iter+1)
    else:
        print("out of bounds")
        return 0
    print("iter", iter)
    print_mat(mat)
    return mat[i][j]

def uniquePaths(m,n):
    if m == 0 or n == 0:
        return 0
    if m == 1 or n == 1:
        return 1
    mat = [[0 for _ in range(n)] for _ in range(m)]
    uniquePaths_util((0,0), (m,n), mat, 1)
    return mat[0][0]
if __name__ == "__main__":
    cases = [
        # [2,3],
        [7,3],
        # [4,5]
        [1,1]
    ]
    for m,n in cases:
        mat = uniquePaths(m,n)
        print("*"*100)
        print(mat)