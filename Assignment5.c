#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int pow;
    struct Node* next;
};

void insert(struct Node* head, int c, int p) {
    if (c == 0) {
        return;
    } 

    struct Node* temp = head;
    while (temp->next != head && temp->next->pow > p) {
        temp = temp->next;
    }

    if (temp->next != head && temp->next->pow == p) {
        temp->next->coeff += c;
        if (temp->next->coeff == 0) {
            struct Node* deleteMe = temp->next;
            temp->next = deleteMe->next;
            free(deleteMe);
        }
    } else {
        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        if (newnode == NULL) {
            printf("Memory allocation failed!\n");
            return;
        }
        newnode->coeff = c;
        newnode->pow = p;
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void createPoly(struct Node* head) {
    int n, c, p;
    freePoly(head);
    
    printf("Enter number of terms: ");
    if (scanf("%d", &n) != 1) return;
    
    for (int i = 0; i < n; i++) {
        printf("Enter coeff and power: ");
        if (scanf("%d %d", &c, &p) == 2) {
            insert(head, c, p);
        }
    }
}

void display(struct Node* head) {
    if (head->next == head) {
        printf("0\n");
        return;
    }
    
    struct Node* temp = head->next;
    int isFirst = 1;
    
    while (temp != head) {
        if (!isFirst && temp->coeff > 0) {
            printf(" + ");
        } else if (temp->coeff < 0) {
            printf(" - ");
        }
        
        int printCoeff = (temp->coeff < 0) ? -temp->coeff : temp->coeff;
        if (isFirst && temp->coeff < 0) {
            printf("-%d", printCoeff);
        } else {
            printf("%d", printCoeff);
        }
        
        printf("x^%d", temp->pow);
        
        isFirst = 0;
        temp = temp->next;
    }
    printf("\n");
}

void addPoly(struct Node* p1, struct Node* p2, struct Node* res) {
    freePoly(res);
    
    struct Node* temp1 = p1->next;
    while (temp1 != p1) {
        insert(res, temp1->coeff, temp1->pow);
        temp1 = temp1->next;
    }
    
    struct Node* temp2 = p2->next;
    while (temp2 != p2) {
        insert(res, temp2->coeff, temp2->pow);
        temp2 = temp2->next;
    }
}

void freePoly(struct Node* head) {
    if (head == NULL) return;
    
    struct Node* current = head->next;
    while (current != head) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    head->next = head;
}

int main() {
    struct Node* poly1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* poly2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* result = (struct Node*)malloc(sizeof(struct Node));
    
    if (!poly1 || !poly2 || !result) {
        printf("Initial memory allocation failed!\n");
        return 1;
    }
    
    poly1->next = poly1;
    poly2->next = poly2;
    result->next = result;

    int ch;
    while(1) {
        printf("\n1. Create Poly 1\n2. Create Poly 2\n3. Display Poly 1\n4. Display Poly 2\n5. Add\n6. Display Result\n7. Exit\n");
        printf("Choice: ");
        if (scanf("%d", &ch) != 1) {
            break;
        }
        
        switch(ch) {
            case 1:  createPoly(poly1);
                     break;
            case 2:  createPoly(poly2);
                     break;
            case 3: printf("Poly 1: ");
                    display(poly1);
                    break;
            case 4: printf("Poly 2: ");
                    display(poly2);
                    break;
            case 5: addPoly(poly1, poly2, result);
                    printf("Polynomials added successfully.\n");
                    break;
            case 6: printf("Result: ");
                    display(result);
                    break;
            case 7: printf("Exiting\n");
                    freePoly(poly1); 
                    free(poly1);
                    freePoly(poly2); 
                    free(poly2);
                    freePoly(result); 
                    free(result);
                    return 0;
            default: 
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}
