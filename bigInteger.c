#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bigInteger.h"

///It could be another bigInteger or one of the parameters. Did not implement this part!!! Have to do it later

struct _BigInteger {
    int *digits;
    int sign;
    int size;
};

BigInteger *bigInteger_new() {
    BigInteger *bigInt = malloc(sizeof(BigInteger));
    bigInt->digits = malloc(sizeof(int) * 1); //initial size is 1, but it will be changed later
    bigInt->size = 1; //it is for me to know that the size is 1
    bigInt->sign = 1; //default sign is positive
    for (int i = 0; i < bigInt->size; i++) {
        bigInt->digits[i] = 0;  //initialization with zeros
    }
    return bigInt;
}

void bigInteger_delete(BigInteger *bigInteger) {
    free(bigInteger->digits);
    free(bigInteger);// or bigInteger->size = 0;
}

BigInteger *bigInteger_from_string(const char *numberAsString) {
    int size = strlen(numberAsString);
    if (size == 0) {
        return NULL;
    }
    BigInteger *bigInt = malloc(sizeof(BigInteger));
    if (numberAsString[0] == '-' || numberAsString[0] == '+') {
        size--;
    }
    bigInt->sign = numberAsString[0] == '-' ? -1 : 1; //if number is negative, sign is -1, else 1
    bigInt->digits = malloc(sizeof(int) * size);
    bigInt->size = size;
    for (int i = 0; i < size; i++) {
        int x = (numberAsString[0] == '-' || numberAsString[0] == '+') ? 0 : 1; //if there is sign in the string,we have to begin with the end of the string
        bigInt->digits[i] = numberAsString[size - i - x] - '0'; //convert char to int
    }
    bigInteger_leading_zeros(bigInt);
    return bigInt;
}

void bigInteger_assign(BigInteger *bigInteger, const char *numberAsString) {
    int size = strlen(numberAsString);
    if (numberAsString[0] == '-' || numberAsString[0] == '+') {
        size--;
    }
    bigInteger->sign = numberAsString[0] == '-' ? -1 : 1;
    bigInteger->digits = realloc(bigInteger->digits, sizeof(int) * size);
    bigInteger->size = size;
    for (int i = 0; i < size; i++) {
        int x = (numberAsString[0] == '-' || numberAsString[0] == '+') ? 0 : 1;
        bigInteger->digits[i] = numberAsString[size - i - x] - '0';
    }
}

BigInteger *bigInteger_clone(BigInteger *bigInteger) {
    BigInteger *clone = malloc(sizeof(BigInteger));
    clone->digits = malloc(sizeof(int) * bigInteger->size);
    clone->size = bigInteger->size;
    clone->sign = bigInteger->sign;
    for (int i = 0; i < bigInteger->size; i++) {
        clone->digits[i] = bigInteger->digits[i];
    }
    return clone;
}

char *bigInteger_to_string(BigInteger *bigInteger) {
    char *string = malloc(sizeof(char) * (bigInteger->size + 2));
    int i = 0;
    if (bigInteger->sign == -1) {
        string[i++] = '-';
    } else {
        string[i++] = '+';
    }
    for (int j = bigInteger->size - 1; j >= 0; j--) {
        string[i++] = bigInteger->digits[j] + '0';
    }
    string[i] = '\0';
    return string;
}

int bigInteger_compare(BigInteger *bigInteger1, BigInteger *bigInteger2) {
    if (bigInteger1->sign == -1 && bigInteger2->sign == 1) {
        return -1;
    } else if (bigInteger1->sign == 1 && bigInteger2->sign == -1) {
        return 1;
    } else if (bigInteger1->sign == -1 && bigInteger2->sign == -1) {
        if (bigInteger1->size > bigInteger2->size) {
            return -1;
        } else if (bigInteger1->size < bigInteger2->size) {
            return 1;
        } else {
            for (int i = bigInteger1->size - 1; i >= 0; i--) {
                if (bigInteger1->digits[i] > bigInteger2->digits[i]) {
                    return -1;
                } else if (bigInteger1->digits[i] < bigInteger2->digits[i]) {
                    return 1;
                }
            }
            return 0;
        }
    } else {
        if (bigInteger1->size > bigInteger2->size) {
            return 1;
        } else if (bigInteger1->size < bigInteger2->size) {
            return -1;
        } else {
            for (int i = bigInteger1->size - 1; i >= 0; i--) {
                if (bigInteger1->digits[i] > bigInteger2->digits[i]) {
                    return 1;
                } else if (bigInteger1->digits[i] < bigInteger2->digits[i]) {
                    return -1;
                }
            }
            return 0;
        }
    }
}

int bigInteger_absolut_compare(BigInteger *bigInteger1, BigInteger *bigInteger2) {
    int x = bigInteger1->sign;
    int y = bigInteger2->sign;
    bigInteger1->sign = 1;
    bigInteger2->sign = 1;
    if (bigInteger1->size > bigInteger2->size) {
        bigInteger1->sign = x;
        bigInteger2->sign = y;
        return 1;
    } else if (bigInteger1->size < bigInteger2->size) {
        bigInteger1->sign = x;
        bigInteger2->sign = y;
        return -1;
    } else {
        for (int i = bigInteger1->size - 1; i >= 0; i--) {
            if (bigInteger1->digits[i] > bigInteger2->digits[i]) {
                bigInteger1->sign = x;
                bigInteger2->sign = y;
                return 1;
            } else if (bigInteger1->digits[i] < bigInteger2->digits[i]) {
                bigInteger1->sign = x;
                bigInteger2->sign = y;
                return -1;
            }
        }
        bigInteger1->sign = x;
        bigInteger2->sign = y;
        return 0;
    }
}

void bigInteger_add(BigInteger *bigInteger1, BigInteger *bigInteger2, BigInteger *result) {///trebuie sa fac cu posibilitatea de trimitere a aceluiasi parametru
    if (bigInteger1->sign == bigInteger2->sign) {
        result->sign = bigInteger1->sign;
        int size = bigInteger1->size > bigInteger2->size ? bigInteger1->size : bigInteger2->size;
        size++;
        result->digits = realloc(result->digits, sizeof(int) * size);
        result->size = size;
        for (int i = 0; i < size; i++) {
            result->digits[i] = 0;
        }
        for (int i = 0; i < bigInteger1->size; i++) {
            result->digits[i] += bigInteger1->digits[i];
        }
        for (int i = 0; i < bigInteger2->size; i++) {
            result->digits[i] += bigInteger2->digits[i];
        }
        int carry = 0;
        for (int i = 0; i < size; i++) {
            result->digits[i] += carry;
            carry = result->digits[i] / 10;
            result->digits[i] %= 10;
        }
        result->digits[size - 1] = carry;
        bigInteger_leading_zeros(result);
    } else {
        if (bigInteger1->sign == -1) {
            bigInteger1->sign = 1;
            bigInteger_subtract(bigInteger2, bigInteger1, result);
            bigInteger1->sign = -1;
            if (bigInteger_absolut_compare(bigInteger1, bigInteger2) == 1) {
                result->sign = -1;
            } else {
                result->sign = 1;
            }
        } else {
            bigInteger2->sign = 1;
            bigInteger_subtract(bigInteger1, bigInteger2, result);
            bigInteger2->sign = -1;
            int comp = bigInteger_absolut_compare(bigInteger1, bigInteger2);
            if (comp == 1 || comp == 0) {
                result->sign = 1;
            } else {
                result->sign = -1;
            }
        }
    }
}

void bigInteger_print(BigInteger *bigInteger) {
    if (bigInteger == NULL || bigInteger->size == 0) {
        printf("There is no number to print!\n");
        return;
    }
    if (bigInteger->sign == -1) {
        printf("-");
    }
    for (int i = bigInteger->size - 1; i >= 0; i--) {
        printf("%d", bigInteger->digits[i]);
    }
    printf("\n");
}

void bigInteger_subtract(BigInteger *bigInteger1, BigInteger *bigInteger2, BigInteger *result) {///trebuie sa fac cu posibilitatea de trimitere a aceluiasi parametru
    if (bigInteger1->sign == bigInteger2->sign) {
        if (bigInteger_absolut_compare(bigInteger1, bigInteger2) == 1) {
            result->sign = bigInteger1->sign;
            int size = bigInteger1->size;
            result->digits = realloc(result->digits, sizeof(int) * size);
            result->size = size;
            for (int i = 0; i < size; i++) {
                result->digits[i] = 0;
            }
            for (int i = 0; i < bigInteger1->size; i++) {
                result->digits[i] += bigInteger1->digits[i];
            }
            for (int i = 0; i < bigInteger2->size; i++) {
                result->digits[i] -= bigInteger2->digits[i];
            }
            int carry = 0;
            for (int i = 0; i < size; i++) {
                result->digits[i] += carry;
                carry = result->digits[i] / 10;
                result->digits[i] %= 10;
                if (result->digits[i] < 0) {
                    result->digits[i] += 10;
                    carry--;
                }
            }
            bigInteger_leading_zeros(result);
        } else if (bigInteger_absolut_compare(bigInteger1, bigInteger2) == -1) {
            result->sign = bigInteger2->sign * (-1);
            int size = bigInteger2->size;
            result->digits = realloc(result->digits, sizeof(int) * size);
            result->size = size;
            for (int i = 0; i < size; i++) {
                result->digits[i] = 0;
            }
            for (int i = 0; i < bigInteger2->size; i++) {
                result->digits[i] += bigInteger2->digits[i];
            }
            for (int i = 0; i < bigInteger1->size; i++) {
                result->digits[i] -= bigInteger1->digits[i];
            }
            int carry = 0;
            for (int i = 0; i < size; i++) {
                result->digits[i] += carry;
                carry = result->digits[i] / 10;
                result->digits[i] %= 10;
                if (result->digits[i] < 0) {
                    result->digits[i] += 10;
                    carry--;
                }
            }
            bigInteger_leading_zeros(result);
        } else {
            result->sign = 1;
            result->digits = realloc(result->digits, sizeof(int));
            result->size = 1;
            result->digits[0] = 0;
        }
    } else {
        if (bigInteger1->sign == -1) { //daca primul numar e negativ si al doilea pozitiv
            bigInteger1->sign = 1;
            bigInteger_add(bigInteger1, bigInteger2, result);
            bigInteger1->sign = -1;
            result->sign = -1;
        } else { //daca primul numar e pozitiv si al doilea negativ
            bigInteger2->sign = 1;
            bigInteger_add(bigInteger1, bigInteger2, result);
            bigInteger2->sign = -1;
            result->sign = 1;
        }
    }
}

BigInteger *bigInteger_add_new(BigInteger *bigInteger1, BigInteger *bigInteger2) {
    BigInteger *result = malloc(sizeof(BigInteger));
    result->digits = malloc(sizeof(int));
    result->size = 1;
    result->digits[0] = 0; //initialization with zero
    bigInteger_add(bigInteger1, bigInteger2, result);
    return result;
}

BigInteger *bigInteger_subtract_new(BigInteger *bigInteger1, BigInteger *bigInteger2) {
    BigInteger *result = malloc(sizeof(BigInteger));
    result->digits = malloc(sizeof(int));
    result->size = 1;
    result->digits[0] = 0;
    bigInteger_subtract(bigInteger1, bigInteger2, result);
    return result;
}

void bigInteger_multiply(BigInteger *bigInteger1, BigInteger *bigInteger2, BigInteger *result) {///trebuie sa fac cu posibilitatea de trimitere a aceluiasi parametru
    if (bigInteger1->size == 0 || bigInteger2->size == 0) {
        result->size = 0;
        return;
    } else if (bigInteger1->size == 1 && bigInteger1->digits[0] == 0) {
        result->size = 1;
        result->sign = 1;
        result->digits[0] = 0;
        return;
    } else if (bigInteger2->size == 1 && bigInteger2->digits[0] == 0) {
        result->size = 1;
        result->sign = 1;
        result->digits[0] = 0;
        return;
    }
    result->sign = bigInteger1->sign * bigInteger2->sign;
    int size = bigInteger1->size + bigInteger2->size;
    result->digits = realloc(result->digits, sizeof(int) * size);
    result->size = size;
    for (int i = 0; i < size; i++) {
        result->digits[i] = 0;
    }
    for (int i = 0; i < bigInteger1->size; i++) {
        for (int j = 0; j < bigInteger2->size; j++) {
            result->digits[i + j] += bigInteger1->digits[i] * bigInteger2->digits[j];
        }
    }
    int carry = 0;
    for (int i = 0; i < size; i++) {
        result->digits[i] += carry;
        carry = result->digits[i] / 10;
        result->digits[i] %= 10;
    }
    bigInteger_leading_zeros(result);
}

BigInteger *bigInteger_multiply_new(BigInteger *bigInteger1, BigInteger *bigInteger2) {
    BigInteger *result = malloc(sizeof(BigInteger));
    result->digits = malloc(sizeof(int));
    result->size = 1;
    result->digits[0] = 0;
    bigInteger_multiply(bigInteger1, bigInteger2, result);
    return result;
}

void bigInteger_shift_left(BigInteger *bigInteger, int shift) {
    if (bigInteger->size == 1 && bigInteger->digits[0] == 0) {
        return;
    }
    int size = bigInteger->size + shift;
    bigInteger->digits = realloc(bigInteger->digits, sizeof(int) * size);
    bigInteger->size = size;
    for (int i = size - 1; i >= shift; i--) {
        bigInteger->digits[i] = bigInteger->digits[i - shift];
    }
    for (int i = 0; i < shift; i++) {
        bigInteger->digits[i] = 0;
    }
}

void bigInteger_divide(BigInteger *bigInteger1, BigInteger *bigInteger2, BigInteger *result) {///trebuie sa fac cu posibilitatea de trimitere a aceluiasi parametru
    if (bigInteger2->size == 1 && bigInteger2->digits[0] == 0) {
        printf("Division by zero!\n");
        return;
    } else if (bigInteger1->size == 1 && bigInteger1->digits[0] == 0) {
        result->sign = 1;
        result->digits = realloc(result->digits, sizeof(int));
        result->size = 1;
        result->digits[0] = 0;
        return;
    } else {
        if (bigInteger_absolut_compare(bigInteger1, bigInteger2) == -1) {
            result->sign = 1;
            result->digits = realloc(result->digits, sizeof(int));
            result->size = 1;
            result->digits[0] = 0;
            return;
        }
    }
    result->sign = bigInteger1->sign * bigInteger2->sign;
    int size = bigInteger1->size;
    result->digits = realloc(result->digits, sizeof(int) * size);
    result->size = size;
    for (int i = 0; i < size; i++) {
        result->digits[i] = 0;
    }
    BigInteger *aux = malloc(sizeof(BigInteger));
    aux->digits = malloc(sizeof(int));
    aux->size = 1;
    aux->sign = 1;
    aux->digits[0] = 0;
    for (int i = bigInteger1->size - 1; i >= 0; i--) {
        bigInteger_shift_left(aux, 1);
        aux->digits[0] = bigInteger1->digits[i];
        int j = 0;
        while (bigInteger_absolut_compare(aux, bigInteger2) != -1) {
            BigInteger *aux2 = bigInteger_clone(aux);
            bigInteger_subtract(aux2, bigInteger2, aux);
            j++;
        }
        result->digits[i] = j;
    }
    bigInteger_leading_zeros(result);
}

BigInteger *bigInteger_divide_new(BigInteger *bigInteger1, BigInteger *bigInteger2) {
    BigInteger *result = malloc(sizeof(BigInteger));
    result->digits = malloc(sizeof(int));
    result->size = 1;
    result->digits[0] = 0;
    bigInteger_divide(bigInteger1, bigInteger2, result);
    return result;
}

void bigInteger_modulo(BigInteger *bigInteger1, BigInteger *bigInteger2, BigInteger *result) {///trebuie sa fac cu posibilitatea de trimitere a aceluiasi parametru
    if (bigInteger2->size == 1 && bigInteger2->digits[0] == 0) {
        printf("Division by zero!\n");
        return;
    } else if (bigInteger1->size == 1 && bigInteger1->digits[0] == 0) {
        result->digits = realloc(result->digits, sizeof(int)*(bigInteger2->size));
        result->sign = 1;
        result->size = bigInteger2->size;
        for (int i = 0; i < bigInteger2->size; i++) {
            result->digits[i] = bigInteger2->digits[i];
        }
        return;
    }
    BigInteger *aux = bigInteger_divide_new(bigInteger1, bigInteger2);
    BigInteger *aux2 = bigInteger_clone(aux);
    bigInteger_multiply(aux2, bigInteger2, aux);
    bigInteger_subtract(bigInteger1, aux, result);
    if (result->sign == -1) {
        int x = bigInteger2->sign;
        bigInteger2->sign = 1;
        BigInteger  *result_aux = bigInteger_clone(result);
        bigInteger_add(result_aux, bigInteger2, result);
        bigInteger2->sign = x;
    }
}

BigInteger *bigInteger_modulo_new(BigInteger *bigInteger1, BigInteger *bigInteger2) {
    BigInteger *result = malloc(sizeof(BigInteger));
    result->digits = malloc(sizeof(int));
    result->size = 1;
    result->digits[0] = 0;
    bigInteger_modulo(bigInteger1, bigInteger2, result);
    return result;
}

void bigInteger_leading_zeros(BigInteger *bigInteger) {
    int size = bigInteger->size;
    while (size > 1 && bigInteger->digits[size - 1] == 0) {
        size--;
        bigInteger->digits = realloc(bigInteger->digits, sizeof(int) * size);
        bigInteger->size = size;
    }
}

void bigInteger_power(BigInteger *bigInteger, int power, BigInteger *result) {///trebuie sa fac cu posibilitatea de trimitere a aceluiasi parametru
    result->digits[0] = 1;
    if (power == 0) {
        result->digits = realloc(result->digits, sizeof(int));
        result->size = 1;
        result->digits[0] = 1;
        return;
    }
    if (power == 1) {
        result->digits = realloc(result->digits, sizeof(int) * bigInteger->size);
        result->size = bigInteger->size;
        for (int i = 0; i < bigInteger->size; i++) {
            result->digits[i] = bigInteger->digits[i];
        }
        return;
    }
    for (int i = 0; i < power; i++) {
        BigInteger *aux = bigInteger_clone(result);
        bigInteger_multiply(aux, bigInteger, result);
    }
}

BigInteger *bigInteger_power_new(BigInteger *bigInteger, int power) {
    BigInteger *result = malloc(sizeof(BigInteger));
    result->digits = malloc(sizeof(int));
    result->size = 1;
    result->digits[0] = 0;
    bigInteger_power(bigInteger, power, result);
    return result;
}