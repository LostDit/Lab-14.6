#include <iostream>

// Функция для сравнения двух матриц
bool areMatricesEqual(const int A[4][4], const int B[4][4]) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (A[i][j] != B[i][j]) {
                return false; // Матрицы не равны
            }
        }
    }
    return true; // Матрицы равны
}

// Функция для преобразования матрицы в диагональную
void makeDiagonal(int matrix[4][4]) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (i != j) {
                matrix[i][j] = 0; // Зануляем элементы вне главной диагонали
            }
        }
    }
}

// Функция для вывода матрицы
void printMatrix(const int matrix[4][4]) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    int A[4][4], B[4][4];

    // Ввод матрицы A
    std::cout << "Введите элементы матрицы A (4x4):\n";
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cin >> A[i][j];
        }
    }

    // Ввод матрицы B
    std::cout << "Введите элементы матрицы B (4x4):\n";
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cin >> B[i][j];
        }
    }

    // Сравнение матриц
    if (areMatricesEqual(A, B)) {
        std::cout << "Матрицы равны. Преобразуем матрицу A в диагональную форму:\n";
        makeDiagonal(A);
        printMatrix(A);
    }
    else {
        std::cout << "Матрицы не равны.\n";
    }

    return 0;
}