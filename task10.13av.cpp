#include <iostream>
#include <vector>
#include <string>
#include <map>

// Структура для збереження дати народження
struct BirthDate {
    int day;
    int month;
    int year;
};

// Структура анкети службовця за умовою завдання
struct Employee {
    std::string surname;
    std::string name;
    std::string gender;
    BirthDate birth;
    std::string position; // Посада (додано для виконання пункту а)
};

// а) Підпрограма пошуку посади, яку обіймає найбільша кількість співробітників
void find_most_popular_position(const std::vector<Employee>& staff) {
    if (staff.empty()) return;

    std::map<std::string, int> position_counts;
    for (const auto& emp : staff) {
        position_counts[emp.position]++;
    }

    std::string popular_pos;
    int max_count = 0;

    for (const auto& pair : position_counts) {
        if (pair.second > max_count) {
            max_count = pair.second;
            popular_pos = pair.first;
        }
    }

    std::cout << "а) Посада з найбільшою кількістю співробітників: " << popular_pos 
              << " (Працює: " << max_count << " осіб)\n";
}

// б) Підпрограма пошуку співробітників з однаковими іменами
void find_duplicate_names(const std::vector<Employee>& staff) {
    std::map<std::string, std::vector<std::string>> name_groups;
    for (const auto& emp : staff) {
        name_groups[emp.name].push_back(emp.surname + " " + emp.name);
    }

    std::cout << "б) Співробітники з однаковими іменами:\n";
    bool found = false;
    for (const auto& pair : name_groups) {
        if (pair.second.size() > 1) {
            found = true;
            std::cout << " * Ім'я '" << pair.first << "': ";
            for (size_t i = 0; i < pair.second.size(); ++i) {
                std::cout << pair.second[i] << (i < pair.second.size() - 1 ? ", " : "");
            }
            std::cout << "\n";
        }
    }
    if (!found) {
        std::cout << " * Співробітників з однаковими іменами не знайдено.\n";
    }
}

// в) Підпрограма пошуку співробітників, прізвища яких починаються із заданої літери
void search_by_first_letter(const std::vector<Employee>& staff, char letter) {
    // Приводимо літеру до верхнього регістру для коректного порівняння
    char upper_letter = std::toupper(static_cast<unsigned char>(letter));
    
    std::cout << "в) Співробітники, прізвища яких починаються на літеру '" << upper_letter << "':\n";
    bool found = false;
    for (const auto& emp : staff) {
        if (!emp.surname.empty() && std::toupper(static_cast<unsigned char>(emp.surname[0])) == upper_letter) {
            std::cout << " * " << emp.surname << " " << emp.name << " (" << emp.position << ")\n";
            found = true;
        }
    }
    if (!found) {
        std::cout << " * Жодного співробітника на цю літеру не знайдено.\n";
    }
}

int main() {
    int n;
    std::cout << "Введіть кількість співробітників N: ";
    std::cin >> n;

    std::vector<Employee> staff(n);
    for (int i = 0; i < n; ++i) {
        std::cout << "\nАнкета №" << i + 1 << ":\n";
        std::cout << " Прізвище: "; std::cin >> staff[i].surname;
        std::cout << " Ім'я: ";     std::cin >> staff[i].name;
        std::cout << " Стать: ";    std::cin >> staff[i].gender;
        std::cout << " Посада: ";   std::cin >> staff[i].position;
        std::cout << " Дата народження (День Місяць Рік через пробіл): ";
        std::cin >> staff[i].birth.day >> staff[i].birth.month >> staff[i].birth.year;
    }

    std::cout << "\n--- РЕЗУЛЬТАТИ АНАЛІЗУ БАЗИ ДАНИХ ---\n";
    find_most_popular_position(staff);
    std::cout << "\n";
    find_duplicate_names(staff);
    std::cout << "\n";

    char target_letter;
    std::cout << "Введіть літеру для пошуку прізвищ (пункт в): ";
    std::cin >> target_letter;
    search_by_first_letter(staff, target_letter);

    return 0;
}
