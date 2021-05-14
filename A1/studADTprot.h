#include"studADTimp.h"

void getInput(student *s);

void insertEnd(listADT *l,student s);

void insertRegno(listADT *l,student s,int regnum);

void insertFront(listADT *l,student s);

student* searchRegno(listADT l, int rno);

listADT searchName(listADT l, char name[]);

void delete(listADT *l, int rno);

void computeResult(listADT *l);

listADT listResult(listADT l);

int listClass(listADT l);

void display(listADT l);

