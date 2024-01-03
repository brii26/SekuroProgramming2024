#include <iostream>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<double>> data;
    int rows;
    int cols;

public:
    // Constructor menerima array 2D sebagai input
    Matrix(const std::vector<std::vector<double>>& inputArray) : data(inputArray), rows(inputArray.size()), cols(inputArray[0].size()) {}

    // Constructor menerima input banyaknya baris dan kolom
    Matrix(int numRows, int numCols) : rows(numRows), cols(numCols), data(std::vector<std::vector<double>>(numRows, std::vector<double>(numCols, 0.0))) {}

    // Constructor menyalin objek dengan class yang sama
    Matrix(const Matrix& otherMatrix) : data(otherMatrix.data), rows(otherMatrix.rows), cols(otherMatrix.cols) {}

    // Operator overloading untuk penjumlahan matriks
    Matrix operator+(const Matrix& otherMatrix) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + otherMatrix.data[i][j];
            }
        }
        return result;
    }

    // Operator overloading untuk pengurangan matriks
    Matrix operator-(const Matrix& otherMatrix) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] - otherMatrix.data[i][j];
            }
        }
        return result;
    }

    // Operator overloading untuk perkalian matriks
    Matrix operator*(const Matrix& otherMatrix) const {
        int resultRows = rows;
        int resultCols = otherMatrix.cols;
        Matrix result(resultRows, resultCols);

        for (int i = 0; i < resultRows; ++i) {
            for (int j = 0; j < resultCols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * otherMatrix.data[k][j];
                }
            }
        }

        return result;
    }

    // Metode untuk menampilkan matriks
    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Matrix A = {{1, 2, 3}, {2, 3, 1}};
    Matrix B = {{0, 2, 4}, {1, 2, 5}, {8, 2, 1.2}};
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
