#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

void insertTerm(struct Node* header, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    struct Node* temp = header->prev;

    newNode->next = header;
    newNode->prev = temp;
    temp->next = newNode;
    header->prev = newNode;
}

void displayPoly(struct Node* header) {
    struct Node* temp = header->next;
    if (temp == header) {
        printf("0\n");
        return;
    }

    while (temp != header) {
        printf("%d*x^%d", temp->coeff, temp->exp);
        temp = temp->next;
        if (temp != header)
            printf(" + ");
    }
    printf("\n");
}

struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = createNode(0, 0);
    result->next = result->prev = result;

    struct Node* p1 = poly1->next;
    struct Node* p2 = poly2->next;

    while (p1 != poly1 || p2 != poly2) {
        if (p1 == poly1) {
            insertTerm(result, p2->coeff, p2->exp);
            p2 = p2->next;
        } else if (p2 == poly2) {
            insertTerm(result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p1->exp == p2->exp) {
            int sumCoeff = p1->coeff + p2->coeff;
            if (sumCoeff != 0) {
                insertTerm(result, sumCoeff, p1->exp);
            }
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->exp > p2->exp) {
            insertTerm(result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else {
            insertTerm(result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
    }

    return result;
}

struct Node* initializeHeader() {
    struct Node* header = createNode(0, 0);
    header->next = header->prev = header; 
    return header;
}

int main() {
    struct Node* poly1 = initializeHeader();
    struct Node* poly2 = initializeHeader();

    printf("Enter Polynomial 1 (coeff exp) [Enter 0 0 to stop]:\n");
    while (1) {
        int coeff, exp;
        scanf("%d%d", &coeff, &exp);
        if (coeff == 0 && exp == 0) break;
        insertTerm(poly1, coeff, exp);
    }

    printf("Enter Polynomial 2 (coeff exp) [Enter 0 0 to stop]:\n");
    while (1) {
        int coeff, exp;
        scanf("%d%d", &coeff, &exp);
        if (coeff == 0 && exp == 0) break;
        insertTerm(poly2, coeff, exp);
    }

    printf("Polynomial 1: ");
    displayPoly(poly1);

    printf("Polynomial 2: ");
    displayPoly(poly2);

    struct Node* result = addPolynomials(poly1, poly2);

    printf("Result of addition: ");
    displayPoly(result);

    return 0;
}
