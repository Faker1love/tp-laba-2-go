#include "Sign.h"

Sign::Sign() {
    std::cout << "Default constructor called for Sign\n";
    surname = "";
    name = "";
    zodiac = "";
    birthDate[0] = birthDate[1] = birthDate[2] = 0;
}

Sign::Sign(const std::string& surname, const std::string& name, const std::string& zodiac, int day, int month, int year) {
    std::cout << "Parameterized constructor called for Sign\n";
    this->surname = surname;
    this->name = name;
    this->zodiac = zodiac;
    birthDate[0] = day;
    birthDate[1] = month;
    birthDate[2] = year;
}

Sign::Sign(const Sign& other) {
    std::cout << "Copy constructor called for Sign\n";
    surname = other.surname;
    name = other.name;
    zodiac = other.zodiac;
    birthDate[0] = other.birthDate[0];
    birthDate[1] = other.birthDate[1];
    birthDate[2] = other.birthDate[2];
}

Sign::~Sign() {
    std::cout << "Destructor called for Sign\n";
}

void Sign::setSurname(const std::string& surname) { this->surname = surname; }
void Sign::setName(const std::string& name) { this->name = name; }
void Sign::setZodiac(const std::string& zodiac) { this->zodiac = zodiac; }
void Sign::setBirthDate(int day, int month, int year) {
    birthDate[0] = day;
    birthDate[1] = month;
    birthDate[2] = year;
}

std::string Sign::getSurname() const { return surname; }
std::string Sign::getName() const { return name; }
std::string Sign::getZodiac() const { return zodiac; }
void Sign::getBirthDate(int& day, int& month, int& year) const {
    day = birthDate[0];
    month = birthDate[1];
    year = birthDate[2];
}

std::ostream& operator<<(std::ostream& os, const Sign& sign) {
    os << "Name: " << sign.name << " " << sign.surname << "\n"
        << "Zodiac: " << sign.zodiac << "\n"
        << "Birth Date: " << sign.birthDate[0] << "/" << sign.birthDate[1] << "/" << sign.birthDate[2];
    return os;
}

std::istream& operator>>(std::istream& is, Sign& sign) {
    std::cout << "Enter surname: ";
    is >> sign.surname;
    std::cout << "Enter name: ";
    is >> sign.name;
    std::cout << "Enter zodiac: ";
    is >> sign.zodiac;
    std::cout << "Enter birth date (day month year): ";
    is >> sign.birthDate[0] >> sign.birthDate[1] >> sign.birthDate[2];
    return is;
}

bool Sign::operator<(const Sign& other) const {
    if (birthDate[2] != other.birthDate[2])
        return birthDate[2] < other.birthDate[2];
    if (birthDate[1] != other.birthDate[1])
        return birthDate[1] < other.birthDate[1];
    return birthDate[0] < other.birthDate[0];
}