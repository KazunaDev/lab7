#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

// Функція для перевірки валідності номера картки
bool validateCreditCard(const string& cardNumber) {
    // Перевірка довжини номера картки та початкових цифр
    int length = cardNumber.length();
    if (length != 13 && length != 16 && length != 15) {
        return false;
    }

    char firstDigit = cardNumber[0];
    char secondDigit = cardNumber[1];

    // Перевірка початкових цифр для кожного типу карти
    if (length == 15 && (firstDigit != '3' || (secondDigit != '4' && secondDigit != '7'))) {
        return false; // American Express
    }
    else if (length == 16 && firstDigit != '4') {
        return false; // Visa
    }
    else if (length == 16 && firstDigit == '5' && (secondDigit < '1' || secondDigit > '5')) {
        return false; // MasterCard
    }

    // Обчислення контрольної суми
    int sum = 0;
    for (int i = length - 2; i >= 0; i -= 2) {
        int digit = (cardNumber[i] - '0') * 2;
        sum += digit / 10 + digit % 10;
    }

    for (int i = length - 1; i >= 0; i -= 2) {
        sum += cardNumber[i] - '0';
    }

    // Перевірка, чи контрольна сума націло ділиться на 10
    return (sum % 10 == 0);
}

int main() {
    // Встановлення кодування 1251
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // Введення номера картки з клавіатури
    string cardNumber;
    cout << "Введіть номер кредитної картки: ";
    cin >> cardNumber;

    // Перевірка валідності та виведення результату
    if (validateCreditCard(cardNumber)) {
        cout << "Картка є валідною." << endl;
    }
    else {
        cout << "Картка не є валідною." << endl;
    }

    return 0;
}

