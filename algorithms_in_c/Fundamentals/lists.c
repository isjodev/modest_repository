#include <stdlib.h> 
#include <stdio.h> 

struct node {
  int key;
  struct node *next;
};

struct node *head, *z, *t;

void list_initialize() {
  head = (struct node *)malloc(sizeof *head);
  z = (struct node *)malloc(sizeof *z);
  head->next = z;
  z->next = z; 
}

void delete_next(struct node *t) {
  t->next = t->next->next; 
}

struct node *insert_after(int v, struct node *t) {
  struct node *x;
  x = (struct node *)malloc(sizeof *x);
  x->key = v;
  x->next = t->next;
  t->next = x;
  return x; 
}

int main() {
  int i, N, M;
  struct node *t, *x;
  scanf("%d %d", &N, &M);

  t = (struct node *)malloc(sizeof *t); 
  t->key = 1;
  x = t;

  for (i = 2; i < N; i++) {
    t->next = (struct node *)malloc(sizeof *t);
    t = t->next;
    t->key = i; 
  }

  t->next = x;

  while (t != t->next) {
    for (i = 1; i < M; i++) {
      t = t->next; 
    }
    printf("%d ", t->next->key);
    x = t->next;
    t->next = t->next->next;
    free(x); 
  }
  printf("%d\n", t->key); 
  return 0; 
}
