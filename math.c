#include <stdio.h>
#include <check.h>

#define EPS 4.94065645841247E-324

int abs(int number) {
    return number > 0 ? number : number * (-1);
}

double fabs(double number) {
    return number > 0 ? number : number * (-1);
}
/////////////////////////////////SQRT/////////////////////////////////
char isNumberNegative(double number) {
    return number < 0 ? 1 : 0;
}
char isNumberNan(double number) {
    return number != number ? 1 : 0;
}

double sqrt(double x) {
    double result = x;
    double precision = 0.000000000000001;
    if(!(isNumberNan(x) && isNumberNegative(x))) {
        while (fabs(result * result - x) > precision) {
            result = 0.5 * (result + x / result);
        }
    }
    else {
        if(isNumberNan(x)) fprintf(stderr, "[EDOM] The value of x is NaN.");
        if(isNumberNegative(x)) fprintf(stderr, "[EDOM] The value of x is negative.");
    }
    return result;
}
/////////////////////////////////SQRT/////////////////////////////////

// fprintf(stderr, "[EDOM]: If x is negative, y must be an integer value.");

double power(double base, double exponent) {
    double result = 1.0;
    char isExpNeg = 0;
    if(exponent < 0) {
        isExpNeg = 1;
        exponent *= -1;
    }
    while (fabs(exponent) > EPS) {
        if (exponent >= 1.0) {
            result *= base;
            exponent--;
        } else {
            base = sqrt(base);
            exponent *= 2.0;
        }
    }
    if(isExpNeg) result = 1 / result;
    return result;
}

// double sqrt(double number) {
//     double result;
//     result = num
//     return result;
// }

int main() {
    printf("%lf\n", power(2, 1.23456346457658756765));
    printf("%lf\n", pow(2, 1.23456346457658756765));
    return 0;
}

