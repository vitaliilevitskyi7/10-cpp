#include <iostream>
#include <cmath>

struct Rational {
    int numerator;
    unsigned int denominator;
};

// Функція знаходження найбільшого спільного дільника (НСД)
long long gcd(long long a, long long b) {
    a = std::abs(a);
    b = std::abs(b);
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

// Зведення до нескоротного вигляду
Rational reduce(Rational r) {
    long long d = gcd(r.numerator, r.denominator);
    r.numerator /= d;
    r.denominator /= d;
    return r;
}

// Додавання
Rational add(Rational r1, Rational r2) {
    Rational res;
    res.numerator = r1.numerator * r2.denominator + r2.numerator * r1.denominator;
    res.denominator = r1.denominator * r2.denominator;
    return reduce(res);
}

// Множення
Rational multiply(Rational r1, Rational r2) {
    Rational res;
    res.numerator = r1.numerator * r2.numerator;
    res.denominator = r1.denominator * r2.denominator;
    return reduce(res);
}

// Порівняння (повертає -1 якщо r1 < r2, 0 якщо рівні, 1 якщо r1 > r2)
int compare(Rational r1, Rational r2) {
    long long diff = 1LL * r1.numerator * r2.denominator - 1LL * r2.numerator * r1.denominator;
    if (diff < 0) return -1;
    if (diff > 0) return 1;
    return 0;
}

int main() {
    Rational r1 = {1, 2}; // 1/2
    Rational r2 = {1, 3}; // 1/3

    Rational sum = add(r1, r2);
    Rational prod = multiply(r1, r2);

    std::cout << "Сума: " << sum.numerator << "/" << sum.denominator << "\n";
    std::cout << "Добуток: " << prod.numerator << "/" << prod.denominator << "\n";
    return 0;
}
