#include <stdio.h>
#include <stdlib.h>
#include "bigInteger.h"

void test1 () {
    BigInteger *bigInt1 = bigInteger_from_string("123456789");
    BigInteger *bigInt2 = bigInteger_new();
    bigInteger_assign(bigInt2, "123456789");
    BigInteger *bigInt3 = bigInteger_new();
    bigInteger_add(bigInt2, bigInt1, bigInt3);
    printf("Suma (bigInt2 + bigInt1): ");
    bigInteger_print(bigInt3);

    BigInteger *bigInt1_1 = bigInteger_clone(bigInt1);
    BigInteger *bigInt3_1 = bigInteger_clone(bigInt3);
    BigInteger *treis = bigInteger_new();
    bigInteger_assign(treis, "3");
    bigInteger_add(bigInt3_1, treis, bigInt3);
    printf("Clona numarului 1: ");
    bigInteger_print(bigInt1_1);

    bigInteger_delete(bigInt1);
    bigInteger_print(bigInt1);

    char *number_string = bigInteger_to_string(bigInt2);
    printf("Numarul 2 ca string: %s\n", number_string);
    printf("Comparatie (bigInt2 si bigInt3): %d\n", bigInteger_compare(bigInt2, bigInt3));
    BigInteger *bigInt4 = bigInteger_new();
    bigInteger_subtract(bigInt1_1, bigInt2, bigInt4);
    printf("Diferenta (bigInt1_1 - bigInt2): ");
    bigInteger_print(bigInt4);
    BigInteger *bigInt5 = bigInteger_add_new(bigInt2, bigInt3);
    printf("Suma (bigInt2 + bigInt3): ");
    bigInteger_print(bigInt5);
    BigInteger *bigInt6 = bigInteger_subtract_new(bigInt1_1, bigInt2);
    printf("Diferenta cu new (bigInt1_1 - bigInt2): ");
    bigInteger_print(bigInt6);
    printf("Comparatie (bigInt2 si bigInt6): %d\n", bigInteger_compare(bigInt2, bigInt6));
    BigInteger *cinci = bigInteger_from_string("5");
    BigInteger *trei = bigInteger_from_string("3");
    BigInteger *bigInt13 = bigInteger_subtract_new(cinci, trei);
    printf("Diferenta (cinci - trei): ");
    bigInteger_print(bigInt13);
    BigInteger *bigInt14 = bigInteger_new();
    bigInteger_multiply(cinci, trei, bigInt14);
    printf("Produs (cinci * trei): ");
    bigInteger_print(bigInt14);
    BigInteger *bigInt15 = bigInteger_multiply_new(cinci, trei);
    printf("Produscu new (cinci * trei): ");
    bigInteger_print(bigInt15);
    BigInteger  *cinci2 = bigInteger_from_string("-5");
    BigInteger  *trei2 = bigInteger_from_string("-3");
    BigInteger  *bigInt18 = bigInteger_new();
//    bigInteger_subtract(bigInt16, bigInt17, bigInt16); eroare, nu se poate rescrie in unul dintre parametri
//    printf("Diferenta (bigInt16 si bigInt17): ");  aaaaaaa, pentru asta trebuie sa facem clona!!!
//    bigInteger_print(bigInt16);
    bigInteger_divide(trei2, cinci2, bigInt18);
    printf("Catul impartirii (trei2 / cinci2): ");
    bigInteger_print(bigInt18);
    BigInteger *bigInt19 = bigInteger_divide_new(cinci2, trei2);
    printf("Catul impartirii cu new (cinci2 / trei2): ");
    bigInteger_print(bigInt19);
    BigInteger *bigInt20 = bigInteger_new();
    bigInteger_modulo(trei2, cinci2, bigInt20);
    printf("Restul impartirii (trei2 %% cinci2): ");
    bigInteger_print(bigInt20);
    BigInteger *bigInt21 = bigInteger_modulo_new(cinci2, trei2);
    printf("Restul impartirii cu new (cinci2 %% trei2): ");
    bigInteger_print(bigInt21);
    BigInteger *zero = bigInteger_from_string("0");
    BigInteger *unu = bigInteger_from_string("1");
    BigInteger *bigInt24 = bigInteger_subtract_new(zero, unu);
    printf("Diferenta (zero - unu): ");
    bigInteger_print(bigInt24);
    BigInteger *bigInt25 = bigInteger_add_new(zero, unu);
    printf("Suma (zero + unu): ");
    bigInteger_print(bigInt25);
    BigInteger *bigInt26 = bigInteger_multiply_new(zero, unu);
    printf("Produs (zero * unu): ");
    bigInteger_print(bigInt26);
    BigInteger *bigInt27 = bigInteger_divide_new(zero, unu);
    printf("Catul impartirii (zero / unu): ");
    bigInteger_print(bigInt27);
    BigInteger *bigInt28 = bigInteger_modulo_new(zero, bigInt1_1);
    printf("Restul impartirii (zero %% unu): ");
    bigInteger_print(bigInt28);
}

int main() {
    test1();
    return 0;
}
