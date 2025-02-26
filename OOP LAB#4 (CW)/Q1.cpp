#include <iostream>
#include <vector>

class Matrix {
private:
    int rows, cols;
    std::vector<std::vector<int>> mat;

public:
    Matrix(int r, int c) : rows(r), cols(c), mat(r, std::vector<int>(c, 0)) {}

    int getRows() const {
        return rows;
    }

    int getCols() const {
        return cols;
    }

    void setElement(int i, int j, int value) {
        if (i >= 0 && i < rows && j >= 0 && j < cols) {
            mat[i][j] = value;
        } else {
            std::cerr << "Error: Index out of bounds!" << std::endl;
        }
    }

    int getElement(int i, int j) const {
        if (i >= 0 && i < rows && j >= 0 && j < cols) {
            return mat[i][j];
        } else {
            std::cerr << "Error: Index out of bounds!" << std::endl;
            return 0; // Default value instead of -1
        }
    }

    void displayMatrix() const {
        for (const auto& row : mat) {
            for (int val : row) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }

    Matrix add(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            std::cerr << "Error: Matrices can't be added due to dimension mismatch!" << std::endl;
            return Matrix(0, 0);
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.mat[i][j] = mat[i][j] + other.mat[i][j];
            }
        }
        return result;
    }

    Matrix multiply(const Matrix& other) const {
        if (cols != other.rows) {
            std::cerr << "Error: Matrices can't be multiplied due to dimension mismatch!" << std::endl;
            return Matrix(0, 0);
        }

        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                int sum = 0;
                for (int k = 0; k < cols; k++) {
                    sum += mat[i][k] * other.mat[k][j];
                }
                result.mat[i][j] = sum;
            }
        }
        return result;
    }
};

int main() {
    Matrix m1(2, 3);
    m1.setElement(0, 0, 1);
    m1.setElement(0, 1, 2);
    m1.setElement(0, 2, 3);
    m1.setElement(1, 0, 4);
    m1.setElement(1, 1, 5);
    m1.setElement(1, 2, 6);

    Matrix m2(2, 3);
    m2.setElement(0, 0, 7);
    m2.setElement(0, 1, 8);
    m2.setElement(0, 2, 9);
    m2.setElement(1, 0, 10);
    m2.setElement(1, 1, 11);
    m2.setElement(1, 2, 12);

    std::cout << "Matrix 1:\n";
    m1.displayMatrix();

    std::cout << "Matrix 2:\n";
    m2.displayMatrix();

    Matrix sum = m1.add(m2);
    std::cout << "Sum of Matrices:\n";
    sum.displayMatrix();

    Matrix m3(3, 2);
    m3.setElement(0, 0, 1);
    m3.setElement(0, 1, 2);
    m3.setElement(1, 0, 3);
    m3.setElement(1, 1, 4);
    m3.setElement(2, 0, 5);
    m3.setElement(2, 1, 6);

    Matrix product = m1.multiply(m3);
    std::cout << "Product of Matrices:\n";
    product.displayMatrix();

    return 0;
}

