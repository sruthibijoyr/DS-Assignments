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

int connect(cityADT *c, char source[],char destination[]){
	int i,j,pos1,pos2,x,y;
	int visited[50];
	Queue q;
	for(i=0;i<c->num;++i){
		if(strcmp(source,c->cities[i])==0)
			pos1=i;
		else if(strcmp(destination,c->cities[i])==0)
			pos2=i;
	}
	init(&q);
	for(i=0;i<c->num;++i){
		visited[i]=0;
	}
	x=pos1;
	visited[x]=1;
	enqueue(&q,x);
	while(!isEmpty(q)){
		y=dequeue(&q);
		for(j=0;j<c->num;++j){
			if(c->adj[y][j]==1){
				if(visited[j]==0){
					visited[j]=1;
					enqueue(&q,j);
				}
			}
		}
	}
	if(visited[pos2]==1)
		return 1;
	else
		return 0;
}

int hasUnvisitedNeighbours(int visited[],cityADT *c,int pos){
	for(int i=0;i<c->num;++i){
		if(visited[i]==0 && c->adj[pos][i]==1)
			return 1;
	}
	return 0;
}

void BFS(cityADT *c){
	int pos1,pos2,x,y,i,j,k,visited[50];
	char source[25];
	Queue q;
	init(&q);
	printf("\nEnter source :");
	scanf("%s",source);
	for(i=0;i<c->num;++i){
		visited[i]=0;
		if(strcmp(c->cities[i],source)==0){
			k=i;
		}
	}
	printf("\n\nStarting from %s :",source);
	x=k;
	visited[x]=1;
	enqueue(&q,x);
	while(!isEmpty(q)){
		y=dequeue(&q);
		for(i=0;i<c->num;++i){
			if(c->adj[y][i]==1){
				if(visited[i]==0){
					visited[i]=1;
					printf("\n%s has been visited",c->cities[i]);
					enqueue(&q,i);
				}
			}
		}
	}
}