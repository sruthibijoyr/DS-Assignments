#include"polyADTimpl.h"


polyADT* createPoly();

void insertFront(polyADT *head, term t);

void display(polyADT *head);

void insertEnd(polyADT *head, term t);

void insertAfterTerm(polyADT *head, term t, int exp);

polyADT *polySimplify(polyADT  *head);

polyADT* findTerm(polyADT *head,int exp);

polyADT* polyAdd(polyADT *head1,polyADT *head2);

polyADT* polyMultiply(polyADT *head1,polyADT *head2);

void delete(polyADT *head, polyADT *p);

void polyDegree(polyADT *head);

int polyEvaluate(polyADT *head);