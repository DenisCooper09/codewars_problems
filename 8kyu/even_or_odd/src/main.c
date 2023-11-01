/*
 * Заспокоїмо CLion, скажемо що з функцією rand все ок.
 * */
#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc50-cpp"
#pragma ide diagnostic ignored "cert-msc51-cpp"

/*
 * Підключаємо потрібні бібліотеки.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

/*
 * Задача:
 * Create a function that takes an integer as an
 * argument and returns "Even" for even numbers
 * or "Odd" for odd numbers.
 * */

const char *even_or_odd(const int *NUMBER) {
    /*
     * Для того, щоб зрозуміти, як працює ця функція, вам потрібно знати, як працюють двійкові числа.
     * Я рекомендую вам почитати про двійкову систему, але якщо коротко, то числа складаються з бітів у той час,
     * як кожен біт може зберігати 1 або 0. Якщо кожному біту ми присвоїмо значення (2^n-біту), то можемо
     * отримати отаку таблицю для 8-розрядних двійкових чисел:
     *
     * Біт             | 7   | 6   | 5   | 4   | 3   | 2   | 1   | 0   |
     * ----------------|-----|-----|-----|-----|-----|-----|-----|-----|
     * Значення Біту   | 128 | 64  | 32  | 16  | 8   | 4   | 2   | 1   |
     * ----------------|-----|-----|-----|-----|-----|-----|-----|-----|
     * Двійкове число  | 0   | 0   | 1   | 1   | 0   | 0   | 0   | 1   |
     * ----------------|-----|-----|-----|-----|-----|-----|-----|-----|
     * Десяткове число | +0  | +0  | +32 | +16 | +0  | +0  | +0  | +1  | Сума: 49
     *
     * Отож число 49 = 00110001
     * Число 49 непарне.
     *
     * У двійковому форматі ТІЛЬКИ числа з останнім встановленим бітом будуть непарними, тому що
     * Значення всіх бітів парні, проте лише останній біт має значення 1, а 1 це непарне число.
     *
     * Тому у даній функції ми перевіряємо - чи встановлено останній біт у числі.
     * Якщо так, то це число буде непарним, тож повертаємо строку "Odd", як і сказано в задачі.
     */
    return *NUMBER & 1 ? "Odd" : "Even";
}

int main() {
    srand(time(NULL));

    for (uint8_t i = 0; i < 10; ++i) {
        int number = rand() % 101;
        printf("Number: %i is %s\n", number, even_or_odd(&number));
    }

    return 0;
}

#pragma clang diagnostic pop
