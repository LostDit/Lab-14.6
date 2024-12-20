#include <iostream>
#include <vector>
#include <string>

// Функция для отображения игрового поля
void displayField(const std::vector<std::vector<char>>&field) {
    std::cout << "  0 1 2\n"; // Нумерация столбцов
    for (int i = 0; i < 3; ++i) {
        std::cout << i << " "; // Нумерация строк
        for (int j = 0; j < 3; ++j) {
            std::cout << field[i][j];
            if (j < 2) std::cout << "|"; // Разделитель между клетками
        }
        std::cout << "\n";
        if (i < 2) std::cout << "  -----\n"; // Разделитель между строками
    }
    std::cout << std::endl;
}

// Функция для проверки победы
bool checkWin(const std::vector<std::vector<char>>& field, char player) {
    // Проверка горизонталей и вертикалей
    for (int i = 0; i < 3; ++i) {
        if ((field[i][0] == player && field[i][1] == player && field[i][2] == player) || // Горизонталь
            (field[0][i] == player && field[1][i] == player && field[2][i] == player))  // Вертикаль
            return true;
    }
    return false;
}

int main() {
    setlocale(LC_ALL,"Russian");
    std::vector<std::vector<char>> field(3, std::vector<char>(3, ' ')); // Игровое поле 3x3
    char currentPlayer = 'X'; // Начинаем с игрока X
    int movesLeft = 9;        // Всего 9 ходов

    std::cout << "Добро пожаловать в игру \"Крестики-нолики\"!\n";
    displayField(field);

    while (movesLeft > 0) {
        int row, col;
        std::cout << "Ход игрока " << currentPlayer << ". Введите координаты (строка и столбец): ";
        std::cin >> row >> col;

        // Проверка корректности координат
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || field[row][col] != ' ') {
            std::cout << "Некорректный ход. Попробуйте снова.\n";
            continue;
        }

        // Установить символ игрока в указанную клетку
        field[row][col] = currentPlayer;
        --movesLeft;

        // Вывод игрового поля
        displayField(field);

        // Проверка на победу
        if (checkWin(field, currentPlayer)) {
            std::cout << "Игрок " << currentPlayer << " победил!\n";
            return 0;
        }

        // Смена игрока
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // Если все клетки заполнены и победителя нет
    std::cout << "Ничья! Игра окончена.\n";
    return 0;
}
