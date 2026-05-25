#include <iostream>
#include <cmath>

struct ChessField {
    char letter;
    int number;
};

// Функція перевірки ходу ферзя
bool can_queen_move(ChessField from, ChessField to) {
    int deltaX = std::abs(from.letter - to.letter);
    int deltaY = std::abs(from.number - to.number);
    
    // Ферзь ходить як тура (один із дельт дорівнює 0) або як слон (дельти рівні)
    return (deltaX == 0 || deltaY == 0 || deltaX == deltaY);
}

int main() {
    ChessField start = {'e', 4};
    ChessField end = {'h', 7}; // діагональний хід

    if (can_queen_move(start, end)) {
        std::cout << "Ферзь МОЖЕ перейти на це поле.\n";
    } else {
        std::cout << "Ферзь НЕ може перейти на це поле.\n";
    }
    return 0;
}
