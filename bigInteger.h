#pragma once

/**
 * @brief A structure for storing a big integer. There is no limit for how many digits it has.
 *
 */
typedef struct _BigInteger BigInteger;

/**
 * @brief Creates a bigInteger initialized with 0.
 *
 * @return Reference to a bigInteger.
 */
BigInteger *bigInteger_new();

/**
 * @brief Deletes a bigInteger.
 *
 * @param bigInteger Reference to a bigInteger.
 */
void bigInteger_delete(BigInteger *bigInteger);

/**
 * @brief Creates a bigInteger from a string.
 *
 * @param numberAsString A string representation of a integer. Examples: 12345678, 123456789123456789, +123456, -1234874
 * @return Reference to a bigInteger.
 */
BigInteger *bigInteger_from_string(const char *numberAsString);

/**
 * @brief Assigns to the bigInteger the value represented by numberAsString.
 *
 * @param bigInteger Reference to a bigInteger.
 * @param numberAsString A string representation of a integer. Examples: 12345678, 123456789123456789, +123456, -1234874
 */
void bigInteger_assign(BigInteger *bigInteger, const char *numberAsString);

/**
 * @brief Returns a clone of a bigInteger.
 *
 * @param bigInteger Reference to a bigInteger.
 * @return Reference to a bigInteger.
 */
BigInteger *bigInteger_clone(BigInteger *bigInteger);

/**
 * @brief Converts a bigInteger to a string. The caller must free the memory.
 *
 * @param bigInteger Reference to a bigInteger.
 * @return A string representation of the bigInteger.
 */
char *bigInteger_to_string(BigInteger *bigInteger);

/**
 * @brief Compares two bigIntegers.
 *
 * @param bigInteger1 Reference to a bigInteger.
 * @param bigInteger2 Reference to a bigInteger.
 * @return -1 if bigInteger1 < bigInteger2, 0 if they are equal or 1 if bigInteger1 > bigInteger2
 */
int bigInteger_compare(BigInteger *bigInteger1, BigInteger *bigInteger2);

/**
 * @brief Computes bigInteger1 + bigInteger2 and store the result in the result parameter.
 *
 * @param bigInteger1 Reference to a bigInteger.
 * @param bigInteger2 Reference to a bigInteger.
 * @param result Reference to a bigInteger. It could be another bigInteger or one of the parameters.
 */
void bigInteger_add(BigInteger *bigInteger1, BigInteger *bigInteger2, BigInteger *result);

/**
 * @brief Computes bigInteger1 + bigInteger2 and returns a new bigInteger as result.
 *
 * @param bigInteger1 Reference to a bigInteger.
 * @param bigInteger2 Reference to a bigInteger.
 * @return Reference to a bigInteger.
 */
BigInteger *bigInteger_add_new(BigInteger *bigInteger1, BigInteger *bigInteger2);

/**
 * @brief Computes bigInteger1 - bigInteger2 and store the result in the result parameter.
 *
 * @param bigInteger1 Reference to a bigInteger.
 * @param bigInteger2 Reference to a bigInteger.
 * @param result Reference to a bigInteger. It could be another bigInteger or one of the parameters.
 */
void bigInteger_subtract(BigInteger *bigInteger1, BigInteger *bigInteger2, BigInteger *result);

/**
 * @brief Computes bigInteger1 - bigInteger2 and returns a new bigInteger as result.
 *
 * @param bigInteger1 Reference to a bigInteger.
 * @param bigInteger2 Reference to a bigInteger.
 * @return Reference to a bigInteger.
 */
BigInteger *bigInteger_subtract_new(BigInteger *bigInteger1, BigInteger *bigInteger2);

/**
 * @brief Computes bigInteger1 * bigInteger2 and store the result in the result parameter.
 *
 * @param bigInteger1 Reference to a bigInteger.
 * @param bigInteger2 Reference to a bigInteger.
 * @param result Reference to a bigInteger. It could be another bigInteger or one of the parameters.
 */
void bigInteger_multiply(BigInteger *bigInteger1, BigInteger *bigInteger2, BigInteger *result);

/**
 * @brief Computes bigInteger1 * bigInteger2 and returns a new bigInteger as result.
 *
 * @param bigInteger1 Reference to a bigInteger.
 * @param bigInteger2 Reference to a bigInteger.
 * @return Reference to a bigInteger.
 */
BigInteger *bigInteger_multiply_new(BigInteger *bigInteger1, BigInteger *bigInteger2);

/**
 * @brief Computes bigInteger1 / bigInteger2 and store the result in the result parameter.
 *
 * @param bigInteger1 Reference to a bigInteger.
 * @param bigInteger2 Reference to a bigInteger.
 * @param result Reference to a bigInteger. It could be another bigInteger or one of the parameters.
 */
void bigInteger_divide(BigInteger *bigInteger1, BigInteger *bigInteger2, BigInteger *result);

/**
 * @brief Computes bigInteger1 / bigInteger2 and returns a new bigInteger as result.
 *
 * @param bigInteger1 Reference to a bigInteger.
 * @param bigInteger2 Reference to a bigInteger.
 * @return Reference to a bigInteger.
 */
BigInteger *bigInteger_divide_new(BigInteger *bigInteger1, BigInteger *bigInteger2);

/**
 * @brief Computes bigInteger1 % bigInteger2 and store the result in the result parameter.
 *
 * @param bigInteger1 Reference to a bigInteger.
 * @param bigInteger2 Reference to a bigInteger.
 * @param result Reference to a bigInteger. It could be another bigInteger or one of the parameters.
 */
void bigInteger_modulo(BigInteger *bigInteger1, BigInteger *bigInteger2, BigInteger *result);

/**
 * @brief Computes bigInteger1 % bigInteger2 and returns a new bigInteger as result.
 *
 * @param bigInteger1 Reference to a bigInteger.
 * @param bigInteger2 Reference to a bigInteger.
 * @return Reference to a bigInteger.
 */
BigInteger *bigInteger_modulo_new(BigInteger *bigInteger1, BigInteger *bigInteger2);



///My functions
/**
 * @brief Shifts the digits of the bigInteger to the left by the specified number of digits (multiplies by 10^shift).
 * @param bigInteger The bigInteger to be shifted.
 * @param shift The number of digits to shift.
 */
void bigInteger_shift_left(BigInteger *bigInteger, int shift);

/**
 * @brief Prints a bigInteger.
 * @param bigInteger Reference to a bigInteger.
*/
void bigInteger_print(BigInteger *bigInteger);

/**
 * @brief Compares absolut values of two bigIntegers.
 * @param bigInteger1 Reference to a bigInteger.
 * @param bigInteger2 Reference to a bigInteger.
 * @return -1 if |bigInteger1| < |bigInteger2|, 0 if they are equal or 1 if |bigInteger1| > |bigInteger2|
*/
int bigInteger_absolut_compare(BigInteger *bigInteger1, BigInteger *bigInteger2);

/**
 * @brief Eliminates leading zeros of a bigInteger.
 * @param bigInteger
 */
void bigInteger_leading_zeros(BigInteger *bigInteger);