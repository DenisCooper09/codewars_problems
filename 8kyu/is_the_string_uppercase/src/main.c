/*
 * Підключаємо потрібні бібліотеки.
 */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

/*
 * Задача:
 * Is the string uppercase?
 *
 * Task
 * Create a method to see whether the string is ALL CAPS.
 *
 * Examples (input -> output)
 * "c" -> False
 * "C" -> True
 * "Hello" -> False
 * "HeLlO" -> False
 * "HELLO" -> True
 *
 * In this Kata, a string is said to be in ALL CAPS
 * whenever it does not contain any lowercase
 * letter so any string containing no letters at all is
 * trivially considered to be in ALL CAPS.
 */

bool is_uppercase(const char *SOURCE) {
    // Дивимось на кожен символ з рядку
    for (unsigned long i = 0; i < strlen(SOURCE); ++i) {
        // Перевіряємо чи цей символ маленька літера. Якщо, так, то повертаємо False.
        if (SOURCE[i] >= 97 && SOURCE[i] <= 122) return false;
    }

    // Не знайшли - повертаємо True
    return true;
}

const char *STRINGS[] = {"Hello", "HeLlO", "HELLO"};

int main() {
    /*
     * Розкоментуйте, щоб вивести ASCII коди англійського алфавіту. (Великі літери)
     */
    /*
    printf("Uppercase ASCII codes: \n");
    for (uint8_t i = 0; i < 26; ++i) {
        printf("%c: %i\n", 'A' + i, 'A' + i);
    }
    */

    /*
     * Розкоментуйте, щоб вивести ASCII коди англійського алфавіту. (Малі літери)
     */
    /*
    printf("Lowercase ASCII codes: \n");
    for (uint8_t i = 0; i < 26; ++i) {
        printf("%c: %i\n", 'a' + i, 'a' + i);
    }
    */

    for (uint32_t i = 0; i < sizeof(STRINGS) / sizeof(const char *); ++i) {
        printf(
                "String: %s | Is uppercase: %s\n",
                STRINGS[i],
                is_uppercase(STRINGS[i]) ? "True" : "False"
        );
    }

    return 0;
}
