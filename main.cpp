#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node{
  struct Node *next;
  int value;
  struct Node *prev;
};

void insert(int val);
void print();
void deleteNode(int val);
void search(int val);
struct Node *start = NULL;
int main(int argc, char const *argv[])
{
  insert(5);
  insert(10);
  insert(15);
  insert(20);
  insert(25);
  print();
  search(5);
  search(10);
  search(15);
  search(20);
  search(25);
  search(30);
  deleteNode(15);
  deleteNode(20);
  cout << "After deletetion list is " << endl;
  print();
  system("pause");
  return 0;
}

void insert(int val){
  struct Node *ptr;
  ptr = (struct Node*) malloc (sizeof(struct Node));
  ptr->next = NULL;
  ptr->prev = NULL;
  ptr->value = val;

  if(start == NULL){
    start = ptr;
    start->prev = NULL;
    ptr->prev = NULL;
  }else{
    struct Node *curr = start;
    while(curr->next != NULL){
      curr = curr->next;
    }
    curr->next = ptr;
    ptr->prev = curr;
  }
}

void deleteNode(int val){
  struct Node *curr = start;
  if(curr->value == val){
    start = curr->next;
    start->prev = NULL;
    free(curr);
  }else{
    curr = curr->next; 
    struct Node *prev = start;
    while(curr->value != val){
      curr = curr->next;
      prev = prev->next;
    }
    // prev->next = curr->next;
    (curr->prev)->next = curr->next;
    (curr->next)->prev = curr->prev;
    free(curr);
  }
}

void search(int val){
  struct Node *curr = start;
  int count = 0;
  while(curr != NULL){
    if(curr->value == val){
        cout << "Found" << endl;
        count++;
        break;
    }
    curr = curr->next;
  }
  if(count == 0){
    cout << "Not Found" << endl;
  }
}
void print(){
  struct Node *curr = start;
  while(curr->next != NULL){
    cout << curr->value << endl;
    curr = curr->next;
  }
  cout << curr->value << endl;
}