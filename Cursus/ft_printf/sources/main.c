#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/ft_printf.h"
// Incluye tu función ft_printf
// int ft_printf(const char *format, ...);

void test_case(const char *description, int expected_len, int ft_len) {
    if (expected_len == ft_len) {
        printf("✓ %s - Passed\n", description);
    } else {
        printf("✗ %s - Failed (Expected %d, got %d)\n", description, expected_len, ft_len);
    }
}

int main() {
    int original_len, ft_len;

    // Prueba de cadena simple
    original_len = printf("Hello, World!\n");
    ft_len = ft_printf("Hello, World!\n");
    test_case("Simple string", original_len, ft_len);

    // Prueba de cadenas con formato
    original_len = printf("Number: %d, String: %s\n", 42, "Test");
    ft_len = ft_printf("Number: %d, String: %s\n", 42, "Test");
    test_case("Formatted string with int and string", original_len, ft_len);

    // Prueba de puntero NULL
    char *null_str = NULL;
    original_len = printf("Null pointer: %s\n", null_str);
    ft_len = ft_printf("Null pointer: %s\n", null_str);
    test_case("Null pointer", original_len, ft_len);

    // Prueba con caracteres especiales y hexadecimales
    original_len = printf("Special char: %%\n");
    ft_len = ft_printf("Special char: %%\n");
    test_case("Special character and hex", original_len, ft_len);

    // Prueba con valores límite de enteros
    original_len = printf("INT_MAX: %d, INT_MIN: %d\n", INT_MAX, INT_MIN);
    ft_len = ft_printf("INT_MAX: %d, INT_MIN: %d\n", INT_MAX, INT_MIN);
    test_case("Integer limits", original_len, ft_len);

    // Prueba de puntero
    int x = 42;
    int *ptr = &x;
    original_len = printf("Pointer address: %p\n", ptr);
    ft_len = ft_printf("Pointer address: %p\n", ptr);
    test_case("Pointer address", original_len, ft_len);

    // Prueba de hexadecimal con NULL
    original_len = printf("Hex null pointer: %p\n", NULL);
    ft_len = ft_printf("Hex null pointer: %p\n", NULL);
    test_case("Hex null pointer", original_len, ft_len);

    // Prueba de números en diferentes bases
    original_len = printf("Unsigned: %u, Hex: %x\n", 255, 255);
    ft_len = ft_printf("Unsigned: %u, Hex: %x\n", 255, 255);
    test_case("Different bases", original_len, ft_len);

    // Prueba de string vacío
    original_len = printf("Empty string: %s\n", "");
    ft_len = ft_printf("Empty string: %s\n", "");
    test_case("Empty string", original_len, ft_len);

    // Prueba de combinación de todo tipo
    original_len = printf("Mix: %s %c %d %u %x %p\n", "test", 'A', -42, 42,  42, &x);
    ft_len = ft_printf("Mix: %s %c %d %u %x %p\n", "test", 'A', -42, 42,  42, &x);
    test_case("Combination of all types", original_len, ft_len);

    return 0;
}
