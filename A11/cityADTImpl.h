typedef struct{
     int num;
     char cities[100][25];
     int adj[100][100];
}cityADT;

void create(cityADT *c){
     int conn,pos1,pos2,flag1=0,flag2=0;
     c->num=0;
     char ch='y',source[25],destination[25];
     while(ch == 'y'){
          printf("\nEnter city %d:",c->num+1);
          scanf("%s",c->cities[c->num]);
          c->num++;
          printf("\nEnter more cities? (y/n):");
          scanf(" %c",&ch);
     }
     for(int i=0;i<c->num;++i){
     	for(int j=0;j<c->num;++j){
     		c->adj[i][j]=0;
     	}
     }
    printf("\nEnter number of direct connections:");
    scanf("%d",&conn);
    for(int i=0;i<conn;++i){
    	flag1=0;
    	flag2=0;
    	printf("\nEnter source and destination:");
    	scanf("%s %s",source,destination);
    	for(int j=0;j<c->num;++j){
    		if(strcmp(source,c->cities[j])==0){
    			pos1=j;
    			flag1=1;
    		}
    		if(strcmp(destination,c->cities[j])==0){
    			pos2=j;
    			flag2=1;
    		}
    		if(flag1&&flag2)	c->adj[pos1][pos2]=1;
    	}
    }
}

void disp(cityADT *c){
	printf("\n");
	for(int i=0;i<c->num;++i){
		for(int j=0;j<c->num;++j){
			if(c->adj[i][j]==1){
				printf("\nThere exists a direct connection between %s and %s",c->cities[i],c->cities[j]);
			}
		}
	}
}

int hasUnvisitedNeighbours(int visited[],cityADT *c,int pos){
	for(int i=0;i<c->num;++i){
		if(visited[i]==0 && c->adj[pos][i]==1)
			return i;
	}
	return -1;
}

void path(cityADT *c)
{
	char source[25],destination[25];
	int visited[50]={0},len=0;
	printf("\nEnter source :");
	scanf("%s",source);
	printf("\nEnter destination :");
	scanf("%s",destination);
	int i,s,d,x,y;

	for(i=0;i<c->num;++i)
	{
		if(strcmp(c->cities[i],source) == 0)
		{
			s = i;
			break;
		}
	}

	for(i=0;i<c->num;++i)
	{
		if(strcmp(c->cities[i],destination) == 0)
		{
			d = i;
			break;
		}
	}

	Stack *S;
	S = malloc(sizeof(Stack));
	S = initialize(S);
	int flag=0;
	push(S,s);
	visited[s] = 1;

	while(!isEmpty(S))
	{
		x = peak(S);
		y = hasUnvisitedNeighbours(visited,c,x);
		if(y!= -1)
		{
			visited[y]=1;
			push(S,y);
			if(y == d)
			{
				flag = 1;
				break;
			}
		}
		else
		{
			x = pop(S);

		}
	}
	
	if(flag == 1)
	{
		printf("\nPath exists from %s to %s :\n",source,destination );
		for(i=0;i<=S->top;++i)
		{
			printf("%s ",c->cities[S->elements[i]]);
			if(i != S->top)
			{
				printf("-> ");
			}
		}	
		printf("\n");
	}
	else
	{
		printf("\nPath doesnt exist from %s to %s !\n\n",source,destination );
	}
}

void DFS(cityADT *c){
	
	Stack *s;
	char source[25];
	int x,y,i,visited[50];
	s = malloc(sizeof(Stack));
	s = initialize(s);
	int k;
	printf("\nEnter source :");
	scanf("%s",source);
	for(i=0;i<c->num;++i){
		visited[i]=0;
		if(strcmp(c->cities[i],source)==0){
			k=i;
		}
	}
	printf("\n\nStarting from %s :\n",source);
	push(s,k);
	visited[k]=1;
	while(!isEmpty(s))
	{
		x = peak(s);

		if(hasUnvisitedNeighbours(visited,c,x) != -1)
		{
			y = hasUnvisitedNeighbours(visited,c,x);
			visited[y]=1;
			printf("%s can be visited.\n",c->cities[y]);
			push(s,y);
		}
		else
		{
			x=pop(s);
		}
	}
}