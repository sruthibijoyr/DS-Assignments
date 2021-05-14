#include"cityADTImpl.h"

void create(cityADT *c);

void disp(cityADT *c);

int connect(cityADT *c, char source[],char destination[]);

int hasUnvisitedNeighbours(int visited[],cityADT *c,int pos);

void BFS(cityADT *c);