class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;
    if (dividend == INT_MIN && divisor == 1)
        return INT_MIN;

    // Determine sign of result
    bool negative = (dividend < 0) ^ (divisor < 0);

    // Work with positive long long values
    long long dvd = labs(dividend);
    long long dvs = labs(divisor);
    long long quotient = 0;

    // Subtract divisor from dividend using bit manipulation
    while (dvd >= dvs) {
        long long temp = dvs, multiple = 1;
        while (dvd >= (temp << 1)) {
            temp <<= 1;         // Double the divisor
            multiple <<= 1;     // Double the multiple
        }
        dvd -= temp;            // Subtract from dividend
        quotient += multiple;   // Add to result
    }

    // Apply sign
    if (negative)
        quotient = -quotient;

    // Clamp result to 32-bit range
    if (quotient > INT_MAX) return INT_MAX;
    if (quotient < INT_MIN) return INT_MIN;

    return (int)quotient;
    }
};