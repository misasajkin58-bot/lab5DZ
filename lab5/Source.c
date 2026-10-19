#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>
#include <math.h>

// Объявление функции расчёта F(x, y)
double calculate_F(double x, double y);

int main()
{
    setlocale(LC_ALL, "RUS");

    calculate_F(1.9, -1.0);
    calculate_F(1.6, -2.3e-6);

    return 0;
}

double calculate_F(double x, double y)
{
    // Инициализация промежуточных переменных
    double term_sqrt = sqrt(1.0 + cos(2.0 * x));      // sqrt(1 + cos(2x))
    double term_exp = exp(y);                         // e^y
    double inside_log = term_sqrt * term_exp + sin(2.0 * x); // выражение под логарифмом

    // Проверка на допустимость аргумента логарифма
    if (inside_log <= 0.0) {
        printf("Ошибка: аргумент логарифма <= 0 при x = %.2f, y = %.6f\n", x, y);
        return 404;
    }

    // Расчёт итогового значения функции
    double result = 2.33 * log(inside_log);

    // Вывод результата
    printf("F(%.2f, %.6f) = %.6f\n", x, y, result);

    return result;
}