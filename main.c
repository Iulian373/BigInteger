#include <stdio.h>
#include <stdlib.h>
#include "bigInteger.h"
///Trebuie de adaudgat posibilitatea de trimitere ca rezultat a unui din parametri

/**Tests format: test_<function_name>()
 * variables: new/from_string/assign/clone
 * to_string
 * compare
 * functions with:
 * 0 and 1 all cases
 * positive and negative numbers all cases
 * print
 * delete
*/
void test_addition() {
    //variable declarations
    BigInteger *zero = bigInteger_new();
    bigInteger_assign(zero, "0");
    BigInteger *unu = bigInteger_from_string("1");
    BigInteger  *minus_unu = bigInteger_from_string("-1");
    BigInteger *suma = bigInteger_new();
    BigInteger *nr_mare = bigInteger_from_string("123456789123456789");
    BigInteger *nr_mare2 = bigInteger_clone(nr_mare);
    BigInteger *minus_nr_mare = bigInteger_from_string("-123456789123456789");
    BigInteger *minus_nr_mare2 = bigInteger_clone(minus_nr_mare);

    char *str = bigInteger_to_string(nr_mare);
    printf("Nr mare ca string: %s\n", str);
    free(str);

    printf("Comparare (nr_mare si minus_nr_mare): %d\n", bigInteger_compare(nr_mare, minus_nr_mare));
    printf("Comparare a valorilor absolute (|nr_mare| si |minus_nr_mare|): %d\n", bigInteger_absolut_compare(nr_mare, minus_nr_mare));

    bigInteger_add(zero, unu, suma);
    printf("Suma (zero + unu): ");
    bigInteger_print(suma);
    BigInteger *suma_new = bigInteger_add_new(unu, zero);
    printf("Suma cu new (unu + zero): ");
    bigInteger_print(suma_new);

    bigInteger_add(zero, minus_unu, suma);
    printf("Suma (zero + minus_unu): ");
    bigInteger_print(suma);
    suma_new = bigInteger_add_new(minus_unu, zero);
    printf("Suma cu new (minus_unu + zero): ");
    bigInteger_print(suma_new);

    bigInteger_add(minus_nr_mare, minus_nr_mare, suma);
    printf("Suma (minus_nr_mare + minus_nr_mare) - acelasi numar: ");
    bigInteger_print(suma);

    bigInteger_add(nr_mare, nr_mare2, suma);
    printf("Suma (nr_mare + nr_mare2): ");
    bigInteger_print(suma);
    suma_new = bigInteger_add_new(nr_mare, minus_nr_mare);
    printf("Suma cu new (nr_mare + minus_nr_mare): ");
    bigInteger_print(suma_new);

    bigInteger_add(minus_nr_mare, minus_nr_mare2, suma);
    printf("Suma (minus_nr_mare + minus_nr_mare2): ");
    bigInteger_print(suma);
    suma_new = bigInteger_add_new(minus_nr_mare, nr_mare2);
    printf("Suma cu new (minus_nr_mare + nr_mare2): ");
    bigInteger_print(suma_new);

    bigInteger_delete(zero);
    bigInteger_delete(unu);
    bigInteger_delete(minus_unu);
    bigInteger_delete(suma);
    bigInteger_delete(nr_mare);
    bigInteger_delete(nr_mare2);
    bigInteger_delete(minus_nr_mare);
    bigInteger_delete(minus_nr_mare2);
    bigInteger_delete(suma_new);
}

void test_subtraction() {
    //variable declarations
    BigInteger *zero = bigInteger_new();
    bigInteger_assign(zero, "0");
    BigInteger *unu = bigInteger_from_string("1");
    BigInteger *minus_unu = bigInteger_from_string("-1");
    BigInteger *diferenta = bigInteger_new();
    BigInteger *nr_mare = bigInteger_from_string("123456789123456789");
    BigInteger *nr_mare2 = bigInteger_clone(nr_mare);
    BigInteger *minus_nr_mare = bigInteger_from_string("-123456789123456789");
    BigInteger *minus_nr_mare2 = bigInteger_clone(minus_nr_mare);

    char *str = bigInteger_to_string(nr_mare);
    printf("Nr mare ca string: %s\n", str);
    free(str);

    printf("Comparare (nr_mare si minus_nr_mare): %d\n", bigInteger_compare(nr_mare, minus_nr_mare));
    printf("Comparare a valorilor absolute (|nr_mare| si |minus_nr_mare|): %d\n",bigInteger_absolut_compare(nr_mare, minus_nr_mare));

    bigInteger_subtract(zero, unu, diferenta);
    printf("Diferenta (zero - unu): ");
    bigInteger_print(diferenta);
    BigInteger *diferenta_new = bigInteger_subtract_new(unu, zero);
    printf("Diferenta cu new (unu - zero): ");
    bigInteger_print(diferenta_new);

    bigInteger_subtract(zero, minus_unu, diferenta);
    printf("Diferenta (zero - minus_unu): ");
    bigInteger_print(diferenta);
    diferenta_new = bigInteger_subtract_new(minus_unu, zero);
    printf("Diferenta cu new (minus_unu - zero): ");
    bigInteger_print(diferenta_new);

    bigInteger_subtract(minus_nr_mare, minus_nr_mare, diferenta);
    printf("Diferenta (minus_nr_mare - minus_nr_mare) - acelasi numar: ");
    bigInteger_print(diferenta);

    bigInteger_subtract(nr_mare, nr_mare2, diferenta);
    printf("Diferenta (nr_mare - nr_mare2): ");
    bigInteger_print(diferenta);
    diferenta_new = bigInteger_subtract_new(nr_mare, minus_nr_mare);
    printf("Diferenta cu new (nr_mare - minus_nr_mare): ");
    bigInteger_print(diferenta_new);

    bigInteger_subtract(minus_nr_mare, minus_nr_mare2, diferenta);
    printf("Diferenta (minus_nr_mare - minus_nr_mare2): ");
    bigInteger_print(diferenta);
    diferenta_new = bigInteger_subtract_new(minus_nr_mare, nr_mare2);
    printf("Diferenta cu new (minus_nr_mare - nr_mare2): ");
    bigInteger_print(diferenta_new);

    bigInteger_delete(zero);
    bigInteger_delete(unu);
    bigInteger_delete(minus_unu);
    bigInteger_delete(diferenta);
    bigInteger_delete(nr_mare);
    bigInteger_delete(nr_mare2);
    bigInteger_delete(minus_nr_mare);
    bigInteger_delete(minus_nr_mare2);
    bigInteger_delete(diferenta_new);
}

void test_multiplication() {
    //variable declarations
    BigInteger *zero = bigInteger_new();
    bigInteger_assign(zero, "0");
    BigInteger *unu = bigInteger_from_string("1");
    BigInteger *minus_unu = bigInteger_from_string("-1");
    BigInteger *produs = bigInteger_new();
    BigInteger *nr_mare = bigInteger_from_string("123456789123456789");
    BigInteger *nr_mare2 = bigInteger_clone(nr_mare);
    BigInteger *minus_nr_mare = bigInteger_from_string("-123456789123456789");
    BigInteger *minus_nr_mare2 = bigInteger_clone(minus_nr_mare);

    char *str = bigInteger_to_string(nr_mare);
    printf("Nr mare ca string: %s\n", str);
    free(str);

    printf("Comparare (nr_mare si minus_nr_mare): %d\n", bigInteger_compare(nr_mare, minus_nr_mare));
    printf("Comparare a valorilor absolute (|nr_mare| si |minus_nr_mare|): %d\n",bigInteger_absolut_compare(nr_mare, minus_nr_mare));

    bigInteger_multiply(zero, unu, produs);
    printf("Produs (zero * unu): ");
    bigInteger_print(produs);
    BigInteger *produs_new = bigInteger_multiply_new(unu, zero);
    printf("Produs cu new (unu * zero): ");
    bigInteger_print(produs_new);

    bigInteger_multiply(zero, minus_unu, produs);
    printf("Produs (zero * minus_unu): ");
    bigInteger_print(produs);
    produs_new = bigInteger_multiply_new(minus_unu, zero);
    printf("Produs cu new (minus_unu * zero): ");
    bigInteger_print(produs_new);

    bigInteger_multiply(minus_nr_mare, minus_nr_mare, produs);
    printf("Produs (minus_nr_mare * minus_nr_mare) - acelasi numar: ");
    bigInteger_print(produs);

    bigInteger_multiply(nr_mare, nr_mare2, produs);
    printf("Produs (nr_mare * nr_mare2): ");
    bigInteger_print(produs);
    produs_new = bigInteger_multiply_new(nr_mare, minus_nr_mare);
    printf("Produs cu new (nr_mare * minus_nr_mare): ");
    bigInteger_print(produs_new);

    bigInteger_multiply(minus_nr_mare, minus_nr_mare2, produs);
    printf("Produs (minus_nr_mare * minus_nr_mare2): ");
    bigInteger_print(produs);
    produs_new = bigInteger_multiply_new(minus_nr_mare, nr_mare2);
    printf("Produs cu new (minus_nr_mare * nr_mare2): ");
    bigInteger_print(produs_new);

    bigInteger_delete(zero);
    bigInteger_delete(unu);
    bigInteger_delete(minus_unu);
    bigInteger_delete(produs);
    bigInteger_delete(nr_mare);
    bigInteger_delete(nr_mare2);
    bigInteger_delete(minus_nr_mare);
    bigInteger_delete(minus_nr_mare2);
    bigInteger_delete(produs_new);
}

void test_division() {
    //variable declarations
    BigInteger *zero = bigInteger_new();
    bigInteger_assign(zero, "0");
    BigInteger *unu = bigInteger_from_string("1");
    BigInteger *minus_unu = bigInteger_from_string("-1");
    BigInteger *cat = bigInteger_new();
    BigInteger *nr_mare = bigInteger_from_string("123456789123456789");
    BigInteger *nr_mare2 = bigInteger_clone(nr_mare);
    BigInteger *minus_nr_mare = bigInteger_from_string("-123456789123456789");
    BigInteger *minus_nr_mare2 = bigInteger_clone(minus_nr_mare);

    char *str = bigInteger_to_string(nr_mare);
    printf("Nr mare ca string: %s\n", str);
    free(str);

    printf("Comparare (nr_mare si minus_nr_mare): %d\n", bigInteger_compare(nr_mare, minus_nr_mare));
    printf("Comparare a valorilor absolute (|nr_mare| si |minus_nr_mare|): %d\n",bigInteger_absolut_compare(nr_mare, minus_nr_mare));

    bigInteger_divide(zero, unu, cat);
    printf("Cat (zero / unu): ");
    bigInteger_print(cat);
    BigInteger *cat_new = bigInteger_divide_new(unu, zero);
    printf("Cat cu new (unu / zero): ");
    bigInteger_print(cat_new);

    bigInteger_divide(zero, minus_unu, cat);
    printf("Cat (zero / minus_unu): ");
    bigInteger_print(cat);
    cat_new = bigInteger_divide_new(minus_unu, zero);
    printf("Cat cu new (minus_unu / zero): ");
    bigInteger_print(cat_new);

    bigInteger_divide(minus_nr_mare, minus_nr_mare, cat);///BUG si la toate la care impartitorul e negativ
    printf("Cat (minus_nr_mare / minus_nr_mare) - acelasi numar: ");
    bigInteger_print(cat);

    bigInteger_divide(nr_mare, nr_mare2, cat);
    printf("Cat (nr_mare / nr_mare2): ");
    bigInteger_print(cat);
    cat_new = bigInteger_divide_new(nr_mare, minus_nr_mare);
    printf("Cat cu new (nr_mare / minus_nr_mare): ");
    bigInteger_print(cat_new);

    bigInteger_divide(minus_nr_mare, minus_nr_mare2, cat);
    printf("Cat (minus_nr_mare / minus_nr_mare2): ");
    bigInteger_print(cat);
    cat_new = bigInteger_divide_new(minus_nr_mare, nr_mare2);
    printf("Cat cu new (minus_nr_mare / nr_mare2): ");
    bigInteger_print(cat_new);

    bigInteger_delete(zero);
    bigInteger_delete(unu);
    bigInteger_delete(minus_unu);
    bigInteger_delete(cat);
    bigInteger_delete(nr_mare);
    bigInteger_delete(nr_mare2);
    bigInteger_delete(minus_nr_mare);
    bigInteger_delete(minus_nr_mare2);
    bigInteger_delete(cat_new);
}

int main() {
    test_division();
    return 0;
}
