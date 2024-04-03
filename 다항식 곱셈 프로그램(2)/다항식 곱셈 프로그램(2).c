#include <stdio.h>

typedef struct {
    int degree;
    double coef[10];
} polynomial;

void print_poly(polynomial p) {
    for (int i = p.degree; i > 0; i--) {
        printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
    }
    printf("%3.1f \n", p.coef[p.degree]);
}

polynomial poly_mult(polynomial a, polynomial b) {
    polynomial c;
    c.degree = a.degree + b.degree;
    for (int i = 0; i <= c.degree; i++) {
        c.coef[i] = 0;
    }
    for (int i = 0; i <= a.degree; i++) {
        for (int j = 0; j <= b.degree; j++) {
            c.coef[i + j] += a.coef[i] * b.coef[j];
        }
    }
    return c;
}

int main(void) {
    polynomial a = { 3, {4, 3, 2, 1} };
    polynomial b = { 2, {3, 2, 8} };
    polynomial c;

    a = (polynomial){ 6, {7, 0, 0, 5, 9, 0, 1} };
    b = (polynomial){ 3, {5, 2, 1, 10} };

    print_poly(a);
    print_poly(b);

    c = poly_mult(a, b);

    printf("\n-");
    print_poly(c);

    return 0;
}