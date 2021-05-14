
#define maxLimit 100

typedef struct
{
	char name[25];
	int regno;
	int mark1,mark2,mark3,Total;
	char result;
}student;

typedef struct
{
	student list[100];
	int size;
}listADT;

void getInput(student *s)
{
	printf("\nEnter name, reg number, mark 1, mark 2, mark 3 :");
	scanf("%s %d %d %d %d",s->name,&s->regno,&s->mark1, &s->mark2, &s->mark3);
	s->Total = 0;
	s->result = '-';
}
	
void insertEnd(listADT *l,student s)
{
	int i;
	if(l->size==0)
	{
		l->list[l->size]=s;
		l->size++;
	}
	else if(l->size==maxLimit)
		printf("List is full!");
	else
	{
		l->list[l->size]=s;
		l->size++;
	}
}


void insertRegno(listADT *l,student s,int regnum)
{
	int i,pos=-1;
	for(i=0;i<l->size;++i)
	{
		if(l->list[i].regno == regnum)
		{
			pos=i;
			break;
		}
	}
	if(pos==-1)
	{
		printf("\nNot found");
	}
	else
	{
		for(i=l->size;i>pos+1;--i)
		{
			l->list[i]=l->list[i-1];
		}
		l->list[i]=s;
		l->size++;
	}
}

void insertFront(listADT *l,student s)
{
	int i;
	if(l->size==0)
	{
		l->list[l->size]=s;
		l->size++;
	}
	else if(l->size==maxLimit)
		printf("List is full!");
	else
	{
		for(i=l->size;i>0;--i)
		{
			l->list[i]=l->list[i-1];
		}
		l->list[0]=s;
		l->size++;
	}
}


student* searchRegno(listADT l, int rno)
{
	int i;
	student *ptr;
	for(i=0;i<l.size;++i)
	{
		if(l.list[i].regno == rno)
		{
			ptr = &l.list[i];
			return ptr;
		}
	}
	printf("Not found!");
}	


listADT searchName(listADT l, char name[])
{
	int i,flag=0,j=0;
	listADT found_rec;
	for(i=0;i<l.size;++i)
	{
		if(strcmp(l.list[i].name,name)==0)
		{
			flag=1;
			found_rec.list[j]=l.list[i];
			j++;
		}
	}
	if(flag==0)
	{
		printf("Not found!");
	}
	found_rec.size = j;
	found_rec.list[j].regno = 0;
	return found_rec;
}

void delete(listADT *l, int rno)
{
	int i,pos=-1;
	for(i=0;i<l->size;++i)
	{
		if(l->list[i].regno == rno)
		{
			pos=i;
			break;
		}
	}
	if(pos==-1)
	{
		printf("\nNot found");
	}
	else
	{
		for(i=pos;i<l->size-1;++i)
		{
			l->list[i]=l->list[i+1];
		}
		l->size--;
	}
}

void computeResult(listADT *l)
{
	for(int i=0;i<l->size;++i)
	{
		l->list[i].Total = l->list[i].mark1+l->list[i].mark2+l->list[i].mark3;
			
		float avg=(l->list[i].Total)/3;
		
		if(avg>=50){
			l->list[i].result = 'P';
		}
		else {
			l->list[i].result= 'F';
		}
	}
}

listADT listResult(listADT l)
{
	listADT res;
	int i=0,j=0;
	while(i<l.size)
	{
		if(l.list[i].result == 'P')
		{
			res.list[j]=l.list[i];
			j++;
		}
		i++;
	}
	res.size = j;
	res.list[j].regno= 0;
	return res;
}

int listClass(listADT l)
{
	int i,count=0;
	for(i=0;i<l.size;++i)
	{
		if(l.list[i].mark1 > 85 && l.list[i].mark2 > 85 && l.list[i].mark3 > 85 )
		{
			count++;
		}
	}
	return count;
}

void display(listADT l)
{
	int i;
	printf("\nlist:");
	printf("\nName regnum mark1 mark2 mark3 Total Result");
	for(i=0;i<l.size;++i)
	{
		printf("\n%s %d %d %d %d %d %c",l.list[i].name,l.list[i].regno,l.list[i].mark1,l.list[i].mark2,l.list[i].mark3,l.list[i].Total,l.list[i].result);
	}
}		

