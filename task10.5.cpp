#include <iostream>
#include <string>
#include <vector>

struct Mountain {
    std::string name;
    double height;
};

// Функція для пошуку найвищої гори
void find_highest(const std::vector<Mountain>& mountains) {
    if (mountains.empty()) return;
    
    int highest_idx = 0;
    for (size_t i = 1; i < mountains.size(); ++i) {
        if (mountains[i].height > mountains[highest_idx].height) {
            highest_idx = i;
        }
    }
    std::cout << "\nНайвища гора: " << mountains[highest_idx].name 
              << " (Висота: " << mountains[highest_idx].height << " м)\n";
}

// Функція для пошуку висоти за назвою
void search_by_name(const std::vector<Mountain>& mountains, const std::string& search_name) {
    bool found = false;
    for (const auto& m : mountains) {
        if (m.name == search_name) {
            std::cout << "Знайдено: гора " << m.name << " має висоту " << m.height << " м.\n";
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Помилка: вершини з назвою \"" << search_name << "\" немає в масиві.\n";
    }
}

int main() {
    int n;
    std::cout << "Введіть кількість гір N: ";
    std::cin >> n;

    std::vector<Mountain> mountains(n);
    for (int i = 0; i < n; ++i) {
        std::cout << "Введіть назву " << i + 1 << "-ї гори: ";
        std::cin >> mountains[i].name;
        std::cout << "Введіть висоту: ";
        std::cin >> mountains[i].height;
    }

    find_highest(mountains);

    std::string search_name;
    std::cout << "\nВведіть назву гори для пошуку висоти: ";
    std::cin >> search_name;
    search_by_name(mountains, search_name);

    return 0;
}
