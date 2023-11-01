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
 * In this simple assignment you are given a number and have to make it negative.
 * But maybe the number is already negative?
 *
 * Examples:
 * make_negative(1);  // return -1
 * make_negative(-5); // return -5
 * make_negative(0);  // return 0
 *
 * Notes:
 * The number can be negative already, in which case no change is required.
 * Zero (0) is not checked for any specific sign. Negative zeros make no mathematical sense.
 */

int make_negative(int number) {
    return number <= 0 ? number : -number;
}

int main() {
    srand(time(NULL));

    for (uint8_t i = 0; i < 10; ++i) {
        int number = rand() % 201 - 100;
        printf("Number: %i\tNegative Number: %i\n", number, make_negative(number));
    }

    return 0;
}

#pragma clang diagnostic pop
