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

void addTermSorted(struct Node* header, int coeff, int exp) {
    struct Node* temp = header->next;

    if (temp == header || exp > temp->exp) {
        insertTerm(header, coeff, exp);
        return;
    }

    while (temp != header && exp <= temp->exp) {
        if (exp == temp->exp) {
            temp->coeff += coeff;
            return;
        }
        temp = temp->next;
    }

    struct Node* newNode = createNode(coeff, exp);
    struct Node* prevNode = temp->prev;

    newNode->next = temp;
    newNode->prev = prevNode;
    prevNode->next = newNode;
    temp->prev = newNode;
}

struct Node* multiplyPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = createNode(0, 0); 
    result->next = result->prev = result;  

    struct Node* p1 = poly1->next;
    while (p1 != poly1) {
        struct Node* p2 = poly2->next;
        while (p2 != poly2) {
            int coeffProduct = p1->coeff * p2->coeff;
            int expSum = p1->exp + p2->exp;
            addTermSorted(result, coeffProduct, expSum);
            p2 = p2->next;
        }
        p1 = p1->next;
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

    printf("Enter Polynomial 1 [Enter 0 0 to stop]:\n");
    while (1) {
        int coeff, exp;
        scanf("%d%d", &coeff, &exp);
        if (coeff == 0 && exp == 0) break;
        insertTerm(poly1, coeff, exp);
    }

    printf("Enter Polynomial 2 [Enter 0 0 to stop]:\n");
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

    struct Node* result = multiplyPolynomials(poly1, poly2);

    printf("Result of multiplication: ");
    displayPoly(result);

    return 0;
}
