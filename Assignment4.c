#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

struct Data {
  int regNo;
  char name[50];
  struct Data* next;
};

void add(struct Data* head) {
    struct Data* curr = head;
    
    while (curr->next != NULL) {
        curr = curr->next;
    }
    
    struct Data* newNode = (struct Data*)malloc(sizeof(struct Data));
    printf("Enter regNo: ");
    scanf("%d", &newNode->regNo);
    printf("Enter name: ");
    scanf("%s", newNode->name);
    newNode->next = NULL;
    curr->next = newNode;
    printf("Added successfully.\n");
}

void deleteNode(struct Data* head, int val) {
    if (head->next == NULL) {
      printf("List is empty.\n");
      return;
    }
    struct Data* curr = head;
    
    while (curr->next != NULL && curr->next->regNo != val) {
       curr = curr->next;
    }
    
    if (curr->next == NULL) {
        printf("Value not found.\n");
        return;
    }
    
    struct Data* temp = curr->next;
    curr->next = temp->next;
    free(temp);
    printf("Removed successfully.\n");
}

void display(struct Data* head){
    if (head->next == NULL) {
      printf("List is empty.\n");
      return;
    }
    struct Data* curr = head->next;
    while (curr != NULL) { 
       printf("RegNo: %d, Name: %s\n", curr->regNo, curr->name);
       curr = curr->next;
    }
}

void count(struct Data* head) {
    if (head->next == NULL) {
      printf("Total : 0\n");
      return;
    }
    struct Data* curr = head->next;
    int count = 0;
    while (curr != NULL) { 
       count++;
       curr = curr->next;
    }
    printf("Total : %d\n", count);
}

void sort(struct Data* head){
    if (head->next == NULL || head->next->next == NULL) {
        printf("No sorting needed.\n");
        return;
    }
    struct Data* curr1 = head->next;
    while (curr1->next != NULL) {
       struct Data* curr2 = curr1->next;
       while (curr2 != NULL) {
           if (curr1->regNo > curr2->regNo) {
                int tempReg = curr1->regNo;
                curr1->regNo = curr2->regNo;
                curr2->regNo = tempReg;
                char tempName[50];
                strcpy(tempName, curr1->name);
                strcpy(curr1->name, curr2->name);
                strcpy(curr2->name, tempName);
           }
           curr2 = curr2->next; 
       }
       curr1 = curr1->next;
    }
    printf("Sorted successfully.\n");
}

void reverseList(struct Data* head) { 
    if (head->next == NULL || head->next->next == NULL) {
        printf("No reversal needed.\n");
        return;
    }

    struct Data* prev = NULL;
    struct Data* current = head->next;
    struct Data* nextNode = NULL;

    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;    
        prev = current;          
        current = nextNode;      
    }

    head->next = prev;
    printf("List reversed.\n");
}

void freell(struct Data* head) {
    struct Data* temp = head;
    while (temp != NULL) {
        struct Data* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    printf("Memory freed.\n");
}

int main(){
  struct Data* head = (struct Data*)malloc(sizeof(struct Data));
  head->next = NULL;
  int val;
  
  while(1) {
    int choice;
    printf("\n1.Add 2.Remove 3.Display 4.Count 5.Sort 6.Reverse 7.Exit\n");
    printf("Enter your choice: ");

    switch(choice) {
       case 1 : add(head);
                break;
       case 2 : printf("Value to delete: ");
                scanf("%d", &val);
                deleteNode(head, val);
                break;
       case 3 : display(head);
                break;
       case 4 : count(head);
                break;
       case 5 : sort(head);
                break;
       case 6 : reverseList(head); 
                break;
       case 7 : printf("Exit\n"); 
                freell(head); 
                return 0;
       default : printf("Invalid choice.\n");
    }
  }
  return 0;
}
