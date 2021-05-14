#include"cityADTImpl.h"

void create(cityADT *c);

void disp(cityADT *c);

int hasUnvisitedNeighbours(int visited[],cityADT *c,int pos,int s);

void dijkstras(cityADT *c,char source[]);

void displayTable(cityADT *c,int k[],int d[],int v[]);

int hasUnknown(int n,int k[],int d[]);

