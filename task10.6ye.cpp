#include <iostream>

struct Point2D {
    double x;
    double y;
};

// Варіант є): коло (радіус, координати центру)
struct Circle {
    double radius;
    Point2D center;
};

// Функція введення даних кола
void input_circle(Circle& c) {
    std::cout << "Введіть координати центру кола (x y): ";
    std::cin >> c.center.x >> c.center.y;
    
    do {
        std::cout << "Введіть радіус кола (R > 0): ";
        std::cin >> c.radius;
        if (c.radius <= 0) {
            std::cout << "Помилка: радіус повинен бути додатним числом!\n";
        }
    } while (c.radius <= 0);
}

// Функція виведення даних кола
void print_circle(const Circle& c) {
    std::cout << "\n--- Відомості про коло ---\n";
    std::cout << "Центр кола: O(" << c.center.x << ", " << c.center.y << ")\n";
    std::cout << "Радіус R  : " << c.radius << "\n";
    std::cout << "Рівняння  : (x - " << c.center.x << ")^2 + (y - " << c.center.y << ")^2 = " << c.radius * c.radius << "\n";
}

int main() {
    Circle my_circle;
    
    std::cout << "Реєстрація геометрії об'єкта:\n";
    input_circle(my_circle);
    print_circle(my_circle);
    
    return 0;
}
