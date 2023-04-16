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
///Poate fac un header aparte pentru testare
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

    bigInteger_divide(minus_nr_mare, minus_nr_mare, cat);
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

void test_modulo() {
    //variable declarations
    BigInteger *zero = bigInteger_new();
    bigInteger_assign(zero, "0");
    BigInteger *unu = bigInteger_from_string("1");
    BigInteger *minus_unu = bigInteger_from_string("-1");
    BigInteger *rest = bigInteger_new();
    BigInteger *cinci = bigInteger_from_string("5");
    BigInteger *minus_cinci = bigInteger_from_string("-5");
    BigInteger *trei = bigInteger_from_string("3");
    BigInteger *minus_trei = bigInteger_from_string("-3");

    bigInteger_modulo(zero, unu, rest);
    printf("Rest (zero %% unu): ");
    bigInteger_print(rest);
    BigInteger *rest_new = bigInteger_modulo_new(unu, zero);
    printf("Rest cu new (unu %% zero): ");
    bigInteger_print(rest_new);

    bigInteger_modulo(zero, minus_unu, rest);
    printf("Rest (zero %% minus_unu): ");
    bigInteger_print(rest);
    rest_new = bigInteger_modulo_new(minus_unu, zero);
    printf("Rest cu new (minus_unu %% zero): ");
    bigInteger_print(rest_new);

    bigInteger_modulo(cinci, trei, rest);
    printf("Rest (cinci %% trei): ");
    bigInteger_print(rest);
    rest_new = bigInteger_modulo_new(cinci, minus_trei);
    printf("Rest cu new (cinci %% minus_trei): ");
    bigInteger_print(rest_new);

    bigInteger_modulo(minus_cinci, trei, rest);
    printf("Rest (minus_cinci %% trei): ");
    bigInteger_print(rest);
    rest_new = bigInteger_modulo_new(minus_cinci, minus_trei);
    printf("Rest cu new (minus_cinci %% minus_trei): ");
    bigInteger_print(rest_new);

    bigInteger_delete(zero);
    bigInteger_delete(unu);
    bigInteger_delete(minus_unu);
    bigInteger_delete(rest);
    bigInteger_delete(rest_new);
    bigInteger_delete(cinci);
    bigInteger_delete(minus_cinci);
    bigInteger_delete(trei);
    bigInteger_delete(minus_trei);
}

void test_power() {
    //variable declarations
    BigInteger *zero = bigInteger_new();
    bigInteger_assign(zero, "0");
    BigInteger *unu = bigInteger_from_string("1");
    BigInteger *minus_unu = bigInteger_from_string("-1");
    BigInteger *putere = bigInteger_new();
    BigInteger *nr_mare = bigInteger_from_string("123456789123456789");
    BigInteger *minus_nr_mare = bigInteger_from_string("-123456789123456789");

    bigInteger_power(zero, 1, putere);
    printf("Putere (zero la puterea unu): ");
    bigInteger_print(putere);
    BigInteger *putere_new = bigInteger_power_new(unu, 0);
    printf("Putere cu new (unu la puterea zero): ");
    bigInteger_print(putere_new);

    putere_new = bigInteger_power_new(minus_unu, 3);
    printf("Putere cu new (minus_unu la puterea trei): ");
    bigInteger_print(putere_new);

    bigInteger_power(nr_mare, 100, putere);
    printf("Putere (nr_mare la puterea 100): ");
    bigInteger_print(putere);

    printf("\n");
    putere_new = bigInteger_power_new(minus_nr_mare, 91);
    printf("Putere cu new (minus_nr_mare la puterea 91): ");
    bigInteger_print(putere_new);

    bigInteger_delete(zero);
    bigInteger_delete(unu);
    bigInteger_delete(minus_unu);
    bigInteger_delete(putere);
    bigInteger_delete(nr_mare);
    bigInteger_delete(minus_nr_mare);
    bigInteger_delete(putere_new);
}

void test_auxiliar() {

    BigInteger *zero = bigInteger_new();
    bigInteger_assign(zero, "000");
    BigInteger *unu = bigInteger_from_string("001");
    BigInteger *minus_unu = bigInteger_from_string("-01");
    BigInteger *nr_mare = bigInteger_from_string("123456789123456789");
    BigInteger *minus_nr_mare = bigInteger_from_string("-123456789123456789");

    char *str_zero = bigInteger_to_string(zero);
    char *str_unu = bigInteger_to_string(unu);
    char *str_minus_unu = bigInteger_to_string(minus_unu);
    char *str_nr_mare = bigInteger_to_string(nr_mare);
    char *str_minus_nr_mare = bigInteger_to_string(minus_nr_mare);
    printf("Nr zero ca string: %s\n", str_zero);
    printf("Nr unu ca string: %s\n", str_unu);
    printf("Nr minus_unu ca string: %s\n", str_minus_unu);
    printf("Nr nr_mare ca string: %s\n", str_nr_mare);
    printf("Nr minus_nr_mare ca string: %s\n", str_minus_nr_mare);
    free(str_unu);
    free(str_zero);
    free(str_minus_unu);
    free(str_nr_mare);
    free(str_minus_nr_mare);

    bigInteger_leading_zeros(unu);
    printf("Nr unu fara zerouri in fata: ");
    bigInteger_print(unu);
    bigInteger_leading_zeros(minus_unu);
    printf("Nr minus_unu fara zerouri in fata: ");
    bigInteger_print(minus_unu);

    printf("Comparare (nr_mare si minus_nr_mare): %d\n", bigInteger_compare(nr_mare, minus_nr_mare));
    printf("Comparare a valorilor absolute (|nr_mare| si |minus_nr_mare|): %d\n", bigInteger_absolut_compare(nr_mare, minus_nr_mare));

    bigInteger_shift_left(unu, 1);
    printf("Shift left (unu << 1): ");
    bigInteger_print(unu);
    bigInteger_shift_left(minus_unu, 2);
    printf("Shift left (minus_unu << 2): ");
    bigInteger_print(minus_unu);

    bigInteger_delete(zero);
    bigInteger_delete(unu);
    bigInteger_delete(minus_unu);
    bigInteger_delete(nr_mare);
    bigInteger_delete(minus_nr_mare);
}

int main() {
    test_auxiliar();
    return 0;
}
