#include <iostream>
#include <string>

struct SimpleDate {
    int day;
    int month;
    int year;
};

bool is_leap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int days_in_month(int month, int year) {
    int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && is_leap(year)) return 29;
    return days[month];
}

// а) Дата завтрашнього дня
SimpleDate get_tomorrow(SimpleDate d) {
    d.day++;
    if (d.day > days_in_month(d.month, d.year)) {
        d.day = 1;
        d.month++;
        if (d.month > 12) {
            d.month = 1;
            d.year++;
        }
    }
    return d;
}

// б) День тижня (0 = Субота, 1 = Неділя, ..., 6 = П'ятниця) за формулою Зеллера
std::string get_day_of_week(SimpleDate d) {
    int q = d.day;
    int m = d.month;
    int y = d.year;
    if (m < 3) {
        m += 12;
        y--;
    }
    int K = y % 100;
    int J = y / 100;
    int h = (q + 13 * (m + 1) / 5 + K + K / 4 + J / 4 + 5 * J) % 7;
    
    std::string days[] = {"Субота", "Неділя", "Понеділок", "Вівторок", "Середа", "Четвер", "П'ятниця"};
    return days[h];
}

int main() {
    SimpleDate today = {25, 5, 2026};
    SimpleDate tomorrow = get_tomorrow(today);
    
    std::cout << "Завтра: " << tomorrow.day << "." << tomorrow.month << "." << tomorrow.year << "\n";
    std::cout << "День тижня для поточної дати: " << get_day_of_week(today) << "\n";
    return 0;
}
