#include"cityADTImpl.h"

void create(cityADT *c);

void disp(cityADT *c);

void path(cityADT *c);

int hasUnvisitedNeighbours(int visited[],cityADT *c,int pos);

void DFS(cityADT *c);