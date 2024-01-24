#include <iostream>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<double>> data;
    int rows;
    int cols;

public:
    // Constructor untuk menerima input dalam bentuk array 2D
    Matrix(const std::vector<std::vector<double>>& inputArray) : data(inputArray), rows(inputArray.size()), cols(inputArray[0].size()) {}

    // Constructor untuk menerima input baris dan kolom
    Matrix(int numRows, int numCols) : rows(numRows), cols(numCols), data(std::vector<std::vector<double>>(numRows, std::vector<double>(numCols, 0.0))) {}

    // Constructor untuk mengopy objek dengan class yang sama
    Matrix(const Matrix& Matrix2) : data(Matrix2.data), rows(Matrix2.rows), cols(Matrix2.cols) {}

    // Operator overloading untuk penjumlahan matriks
    Matrix operator+(const Matrix& Matrix2) const {
        if (rows != Matrix2.rows || cols != Matrix2.cols) {
            std::cerr << "The matrix dimensions are not valid for addition!" << std::endl;
            return Matrix(1, 1); // return 0 if matrix is 1x1
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + Matrix2.data[i][j];
            }
        }
        return result;
    }

    // Operator overloading untuk pengurangan matriks
    Matrix operator-(const Matrix& Matrix2) const {
        if (rows != Matrix2.rows || cols != Matrix2.cols) {
            std::cerr << "The matrix dimensions are not valid for subtraction!" << std::endl;
            return Matrix(1, 1); // return 0 if matrix is 1x1
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] - Matrix2.data[i][j];
            }
        }
        return result;
    }

    // Operator overloading untuk perkalian matriks
    Matrix operator*(const Matrix& Matrix2) const {
        if (cols != Matrix2.rows) {
            std::cerr << "Multiplication cannot be done. The number of columns in the first matrix should be equal to the number of rows in the second." << std::endl;
            return Matrix(1, 1); // Return 0 if matrix is 1x1
        }

        int final_rows = rows;
        int final_cols = Matrix2.cols;
        Matrix result(final_rows, final_cols);

        for (int i = 0; i < final_rows; ++i) {
            for (int j = 0; j < final_cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * Matrix2.data[k][j];
                }
            }
        }

        return result;
    }

    // menampilkan matrix
    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

// main function
int main() {
    Matrix A({{1, 2, 3}, {2, 3, 1}});
    Matrix B({{0, 2, 4}, {1, 2, 5}, {8, 2, 1.2}});
    Matrix C(2, 3);

    std::cout << "Matrix A\n";
    A.display();

    std::cout << "\nMatrix B\n";
    B.display();

    std::cout << "\nMatrix C\n";
    C.display();

    std::cout << '\n';

    Matrix C1 = A + C;
    std::cout << "\nMatrix C1 (A + C)\n";
    C1.display();

    std::cout << '\n';

    Matrix C2 = A - C;
    std::cout << "\nMatrix C2 (A - C)\n";
    C2.display();

    std::cout << '\n';

    Matrix C3 = A * B;
    std::cout << "\nMatrix C3 (A * B)\n";
    C3.display();

    std::cout << '\n';

    Matrix C4 = B * A;
    std::cout << "\nMatrix C4 (B * A)\n";
    C4.display();

    std::cout << '\n';

    return 0;
}
