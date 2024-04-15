#include <stdio.h>
#include <stdlib.h>

typedef struct Term 
{
    int coefficient;
    int exponent;
    struct Term* next;
} Term;

Term* createTerm(int coefficient, int exponent) 
{
    Term* newTerm = (Term*)malloc(sizeof(Term));
    if (newTerm == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}

Term* insertTerm(Term* poly, int coefficient, int exponent) 
{
    Term* newTerm = createTerm(coefficient, exponent);
    if (poly == NULL) {
        return newTerm;
    }
    Term* current = poly;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newTerm;
    return poly;
}

Term* addPolynomials(Term* poly1, Term* poly2) 
{
    Term* result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent > poly2->exponent) {
            result = insertTerm(result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            result = insertTerm(result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            int sum = poly1->coefficient + poly2->coefficient;
            if (sum != 0) {
                result = insertTerm(result, sum, poly1->exponent);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL) {
        result = insertTerm(result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        result = insertTerm(result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }
    return result;
}

void printPolynomial(Term* poly) 
{
    if (poly == NULL) {
        printf("0\n");
        return;
    }
    while (poly != NULL) {
        printf("%d %d ", poly->coefficient, poly->exponent);
        poly = poly->next;
    }
    printf("\n");
}

void freePolynomial(Term* poly)
{
    Term* temp;
    while (poly != NULL) {
        temp = poly;
        poly = poly->next;
        free(temp);
    }
}

int main() 
{
    int n1, n2;
    scanf("%d", &n1);
    Term* poly1 = NULL;
    for (int i = 0; i < n1; i++) {
        int coefficient, exponent;
        scanf("%d %d", &coefficient, &exponent);
        poly1 = insertTerm(poly1, coefficient, exponent);
    }

    scanf("%d", &n2);
    Term* poly2 = NULL;
    for (int i = 0; i < n2; i++) {
        int coefficient, exponent;
        scanf("%d %d", &coefficient, &exponent);
        poly2 = insertTerm(poly2, coefficient, exponent);
    }

    Term* sum = addPolynomials(poly1, poly2);
    printPolynomial(sum);

    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(sum);

    return 0;
}
