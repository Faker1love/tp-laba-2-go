#include <iostream>
#include <string>
#include <vector> // Добавлен заголовок для std::vector
#include <algorithm> // Для std::sort
#include "Sign.h"
#include "reader.h"

void displayMainMenu() {
    std::cout << "Choose a task:\n";
    std::cout << "1. Zodiac Signs Management\n";
    std::cout << "2. Find Longest Word in File\n";
    std::cout << "3. Exit\n";
}

void zodiacTask() {
    std::vector<Sign*> records;
    bool running = true;

    while (running) {
        std::cout << "\nZodiac Signs Management:\n";
        std::cout << "1. Add a new record\n";
        std::cout << "2. Display all records\n";
        std::cout << "3. Search by surname\n";
        std::cout << "4. Back to main menu\n";

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1: {
            Sign* newSign = new Sign();
            std::cin >> *newSign;
            records.push_back(newSign);
            std::sort(records.begin(), records.end(), [](Sign* a, Sign* b) { return *a < *b; });
            break;
        }
        case 2:
            for (const auto& record : records)
                std::cout << *record << "\n";
            break;
        case 3: {
            std::string searchSurname;
            std::cout << "Enter surname to search: ";
            std::cin >> searchSurname;

            bool found = false;
            for (const auto& record : records) {
                if (record->getSurname() == searchSurname) {
                    std::cout << *record << "\n";
                    found = true;
                    break;
                }
            }
            if (!found)
                std::cout << "No record found for the surname.\n";
            break;
        }
        case 4:
            running = false;
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    }

    for (auto& record : records)
        delete record;
}

void longestWordTask() {
    LongestWordFinder finder;
    bool running = true;

    while (running) {
        std::cout << "\nFind Longest Word in File:\n";
        std::cout << "1. Process file\n";
        std::cout << "2. Display result\n";
        std::cout << "3. Back to main menu\n";

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1: { // Обработка файла
            std::string filename;
            std::cout << "Enter the file name: ";
            std::cin.ignore(); // Убираем остатки ввода
            std::getline(std::cin, filename);

            try {
                finder.processFile(filename); // Обработка файла
                std::cout << "File processed successfully.\n";
            }
            catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << "\n";
            }
            break;
        }
        case 2: // Отображение результата
            finder.displayResult();
            break;
        case 3: // Возврат в главное меню
            running = false;
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    }
}

int main() {
    bool running = true;

    while (running) {
        displayMainMenu();

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            zodiacTask();
            break;
        case 2:
            longestWordTask();
            break;
        case 3:
            running = false;
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    }

    std::cout << "Exiting program.\n";
    return 0;
}
