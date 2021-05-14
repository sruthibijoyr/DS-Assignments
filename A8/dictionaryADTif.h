#include"dictionaryADTimpl.h"

int height(dictionaryADT *D);

int max(int a, int b);

dictionaryADT *singleRotateLeft(dictionaryADT *D1);

dictionaryADT *singleRotateRight(dictionaryADT *D1);

dictionaryADT *doubleRotateLeft(dictionaryADT *D);

dictionaryADT *doubleRotateRight(dictionaryADT *D);

dictionaryADT* insert(dictionaryADT *D, data x);
		
void displayHierarchy(dictionaryADT *D,int depth);