// list.c - conflict
#include <stdio.h>
#include <stdlib.h>
#include <sys/signal.h>

typedef struct node * Node;

Node head;

struct node {
    int val;
    Node next;
};

int insert(int val)
{
    Node p, q;
    p = head;
    if (p != NULL) {
        while (p->next != NULL) {
            p = p->next;
        }
    }
    q = (Node)malloc(sizeof(struct node));
    if (q == NULL) {
        return -1;
    }
    q->next = NULL;
    q->val = val;
    if (p == NULL) {
        head = q;
        return 1;
    }
    p->next = q;
    return 1;
}

void sigusr1_handler(int signo)
{
    if (insert(5) == -1) {
        perror("fail to insert");
        exit(1);
    }
}

int main()
{
    int i = 0;
    while (i < 5) {
        if (insert(i) == -1) {
            perror("fail to insert");
            exit(1);
        }
        ++i;
    }

    return 0;
}
