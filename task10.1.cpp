#include <iostream>
#include <vector>
#include <string>

// а) Дата
struct Date {
    int day;
    std::string month;
    int year;
};

// б) Поле шахової дошки
struct ChessField {
    char letter; // 'a'-'h'
    int number;  // 1-8
};

// Вершина для в)
struct Point {
    double x;
    double y;
};

// в) Прямокутник
struct Rectangle {
    Point topLeft;
    Point bottomRight;
};

// г) Поліном довільного ступеня
struct Polynomial {
    int degree;
    std::vector<double> coefficients; // динамічний масив коефіцієнтів
};

void print_date(const Date& d) {
    std::cout << "Дата: " << d.day << " " << d.month << " " << d.year << "\n";
}

int main() {
    Date d = {25, "Травня", 2026};
    print_date(d);
    return 0;
}
