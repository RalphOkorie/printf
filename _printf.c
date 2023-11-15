#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - This is printf function
 * @format: format.
 * Return: Printed chars.
 */

int _printf(const char *format, ...) {
    if (format == NULL)
    {
        // Handle case when format is NULL
        return -1;
    }

    va_list args;
    va_start(args, format);

    int count = 0;  // To keep track of the number of characters printed

    while (*format) {
        if (*format == '%') {
            format++;  // Move past the '%'

            // Handle the space after %
            if (*format == ' ') {
                return -1;  // Return -1 for this case
            }

            // Handle the '\0' after %
            if (*format == '\0') {
                return -1;  // Return -1 for this case
            }

            // Handle the %s specifier
            if (*format == 's') {
                char *str = va_arg(args, char *);
                if (str == NULL) {
                    // Handle NULL string
                    printf("(null)");
                    count += 6;  // Update count for the (null) string
                } else {
                    // Print the string
                    printf("%s", str);
                    count += strlen(str);  // Update count for the printed string
                }
            } else if (*format == 'c') {
                // Handle the %c specifier
                char c = va_arg(args, int);  // char is promoted to int in va_arg
                putchar(c);
                count++;  // Update count for the printed character
            } else if (*format == '%') {
                // Handle the %% specifier
                putchar('%');
                count++;  // Update count for the printed '%'
            } else {
                // Handle unsupported specifier
                putchar('%');
                putchar(*format);
                count += 2;  // Update count for the '%' and the unsupported character
            }
        } else {
            // Print normal characters
            putchar(*format);
            count++;  // Update count for the printed character
        }

        format++;  // Move to the next character in the format string
    }

    va_end(args);

    return count;  // Return the total number of characters printed
}

int main() {
    // Test cases
    printf("OUTPUT: ");
    int result = _printf("% ");
    printf("\nRETURN VALUE: %d\n", result);

    printf("OUTPUT: ");
    result = _printf("%\0");
    printf("\nRETURN VALUE: %d\n", result);

    printf("OUTPUT: ");
    result = _printf(NULL);
    printf("\nRETURN VALUE: %d\n", result);

    printf("OUTPUT: ");
    result = _printf("%s", NULL);
    printf("\nRETURN VALUE: %d\n", result);

    return 0;
}

