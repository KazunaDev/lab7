
//1. Напишіть функцію, яка приймає в якості параметрів два цілих числа та повертає їх суму.


int add(int a, int b) {
    return a + b;
}

//2. Створіть функцію, яка приймає в якості параметрів три числа типу double та обчислює їх середнє арифметичне.


double average(double a, double b, double c) {
    return (a + b + c) / 3;
}

//3. Реалізуйте функцію типу void, яка приймає в якості параметрів коефіцієнти квадратного рівняння та обчислює корені.


void solveQuadraticEquation(double a, double b, double c) {
    double d = b * b - 4 * a * c;

    if (d > 0) {
        double x1 = (-b + sqrt(d)) / (2 * a);
        double x2 = (-b - sqrt(d)) / (2 * a);

        cout << "Корені квадратного рівняння: " << x1 << ", " << x2 << endl;
    }
    else if (d == 0) {
        double x = -b / (2 * a);

        cout << "Корінь квадратного рівняння: " << x << endl;
    }
    else {
        cout << "Квадратне рівняння не має коренів." << endl;
    }
}

//4. Створіть рекурсивну функцію, яка виводить ряд чисел Фібоначчі від 1 до числа, що передається функції в якості параметра.


int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

//5. Створіть функцію, яка приймає покажчик на масив та його розмір, і змінює значення всіх елементів масиву на їх квадрати.


void squareArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = array[i] * array[i];
    }
}
