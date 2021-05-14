typedef struct{
     int num;
     char cities[100][25];
     int adj[100][100];
}cityADT;

void create(cityADT *c){
     int conn,pos1,pos2,flag1=0,flag2=0,cost;
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
    		if(flag1&&flag2){
    			printf("\nEnter cost :");
    			scanf("%d",&cost);
    			c->adj[pos1][pos2]=cost;
    			break;
    		}
    	}
    }
}

void disp(cityADT *c){
	printf("\n");
	for(int i=0;i<c->num;++i){
		for(int j=0;j<c->num;++j){
				printf("%d ",c->adj[i][j]);
		}
		printf("\n");
	}
	for(int i=0;i<c->num;++i){
		for(int j=0;j<c->num;++j){
			if(c->adj[i][j]>0){
				printf("\nThere exists a direct connection between %s and %s",c->cities[i],c->cities[j]);
			}
		}
	}
}

int hasUnvisitedNeighbours(int visited[],cityADT *c,int pos,int s){
	for(int i=0;i<c->num;++i){
		if(visited[i]==0 && c->adj[pos][i]>0 &&i!=s)
			return i;
	}
	return -1;
}

int hasUnknown(int n,int k[],int d[])
{
	int dist=10000;
	int pos=-1;
	for(int i=0;i<n;++i)
	{
		if(k[i]==0)
		{
			if(d[i]<=dist)
			{
				dist = d[i];
				pos = i;
			}
		}
	}
	return pos;
}

void displayTable(cityADT *c,int k[],int d[],int v[])
{
	printf("vertex\tk\td\tv");
	for(int i=0;i<c->num;++i)
	{
		printf("\n%s\t%d\t%d\t%s",c->cities[i],k[i],d[i],c->cities[v[i]]);
	}

}


void dijkstras(cityADT *c,char source[])
{
	int k[50],d[50],v[50];
	int i,pos,neighbour;
	int visited[50];
	for(i = 0;i<c->num;++i)
	{
		if(strcmp(source,c->cities[i])==0)
		{
			pos = i;
		}
		k[i]=0;
		d[i]=10000;
		v[i]=0;
	}
	d[pos]=0;
	int s = pos;
	printf("\n\t\t*******INITITIAL STATE********\n");
	displayTable(c,k,d,v);
	while(pos!=-1)
	{
		k[pos]=1;
		for(i=0;i<c->num;++i)
		{
			visited[i]=0;
		}
		neighbour = hasUnvisitedNeighbours(visited,c,pos,s);
		while(neighbour != -1)
		{
			visited[neighbour]=1;
			if(d[pos]+c->adj[pos][neighbour] < d[neighbour])
			{
				d[neighbour] = d[pos]+c->adj[pos][neighbour];
			}
			v[neighbour]=pos;
			neighbour = hasUnvisitedNeighbours(visited,c,pos,s);
		}
		printf("\n\t\t*******WHEN %s IS KNOWN********\n",c->cities[pos]);
		displayTable(c,k,d,v);
		pos = hasUnknown(c->num,k,d);
	}
}

void displayPath(cityADT *c, char source[], char destination[])
{
	int k[50],d[50],v[50],dest;
	int i,pos,neighbour;
	int visited[50];
	for(i = 0;i<c->num;++i)
	{
		if(strcmp(source,c->cities[i])==0)
		{
			pos = i;
		}
		if(strcmp(destination,c->cities[i])==0)
		{
			dest = i;
		}
		k[i]=0;
		d[i]=10000;
		v[i]=0;
	}
	d[pos]=0;
	int s = pos;
	while(pos!=-1)
	{
		k[pos]=1;
		for(i=0;i<c->num;++i)
		{
			visited[i]=0;
		}
		neighbour = hasUnvisitedNeighbours(visited,c,pos,s);
		while(neighbour != -1)
		{
			visited[neighbour]=1;
			if(d[pos]+c->adj[pos][neighbour] < d[neighbour])
			{
				d[neighbour] = d[pos]+c->adj[pos][neighbour];
			}
			v[neighbour]=pos;
			neighbour = hasUnvisitedNeighbours(visited,c,pos,s);
		}
		pos = hasUnknown(c->num,k,d);
	}
	int route[50];
	int len = 0;
	route[len]=dest;
	len++;
	if(d[dest] != 10000)
	{
		printf("\nPath exists from %s to %s with total cost %d .\n",source,destination,d[dest]);
		while(dest!=s)
		{
			route[len] = v[dest];
			len++;
			dest = v[dest];
		}

		for(i=len-1;i>0;--i)
		{
			printf("%s -> ",c->cities[route[i]]);
		}
		printf("%s",c->cities[route[i]]);
	}
	else
	{
		printf("\nPath doesnt exist. ");
	}
}