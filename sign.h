#ifndef SIGN_H
#define SIGN_H

#include <iostream>
#include <string>

class Sign {
private:
    std::string surname;
    std::string name;
    std::string zodiac;
    int birthDate[3]; // [day, month, year]

public:
    Sign();
    Sign(const std::string& surname, const std::string& name, const std::string& zodiac, int day, int month, int year);
    Sign(const Sign& other);
    ~Sign();

    void setSurname(const std::string& surname);
    void setName(const std::string& name);
    void setZodiac(const std::string& zodiac);
    void setBirthDate(int day, int month, int year);

    std::string getSurname() const;
    std::string getName() const;
    std::string getZodiac() const;
    void getBirthDate(int& day, int& month, int& year) const;

    friend std::ostream& operator<<(std::ostream& os, const Sign& sign);
    friend std::istream& operator>>(std::istream& is, Sign& sign);

    bool operator<(const Sign& other) const;
};

#endif // SIGN_H