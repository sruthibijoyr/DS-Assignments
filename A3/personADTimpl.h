typedef struct{
	char name[50],street[150],city[150];
	int age;
	int PIN;
	char sex;
}data;

typedef struct{
	int male;
	int female;
}ratio;

typedef struct myperson{
	data d;
	struct myperson *next;
	struct myperson *prev;
}personADT;

void insertFront(personADT *head, data d){
	personADT *temp;
	temp = (personADT*)malloc(sizeof(personADT));
	temp->d = d;
	if(head->next != NULL){
		head->next->prev = temp;
	}
	temp->next = head->next;
	head->next = temp;
	temp->prev = head;
}

void insertEnd(personADT *head, data d){
	personADT *temp,*end;
	temp = (personADT*)malloc(sizeof(personADT));
	temp->d = d;
	end = head->next;
     while(end->next != NULL){
          end = end->next;
     }
     end->next = temp;
     temp->prev = end;
     temp->next = NULL;
}

void insertPIN(personADT *head, data d, int PIN){
	personADT *find;
	personADT *temp;
	temp = (personADT*)malloc(sizeof(personADT));
	temp->d = d;
	find = head->next;
	while(find != NULL){
		if(find->d.PIN == PIN){
			temp->next = find->next;
			find->next->prev = temp;
			find->next = temp;
			temp->prev = find;
			return;
		}
		find = find->next;
	}
	printf("\nPIN not found in records!");
}


void listPersons(personADT *head){
	personADT *list,*temp;
	list = (personADT *) malloc(sizeof(personADT));
	list->next = NULL;
	list->prev = NULL;
	temp = head->next;
	printf("\nDisplay from head:");
	while(temp->next != NULL){
		printf("\nName: %s\nPIN: %d\nAge: %d\nSex: %c\nStreet Address: %s\nCity Address: %s\n",temp->d.name,temp->d.PIN,temp->d.age,temp->d.sex,temp->d.street, temp->d.city);
		temp = temp->next;
	}
	printf("\nName: %s\nPIN: %d\nAge: %d\nSex: %c\nStreet Address: %s\nCity Address: %s\n",temp->d.name,temp->d.PIN,temp->d.age,temp->d.sex,temp->d.street, temp->d.city);;
	printf("\nDisplay from tail:");
	while(temp != head){
		printf("\nName: %s\nPIN: %d\nAge: %d\nSex: %c\nStreet Address: %s\nCity Address: %s\n",temp->d.name,temp->d.PIN,temp->d.age,temp->d.sex,temp->d.street, temp->d.city);
		temp = temp->prev;
	}
	
}


void listSort(personADT *head){
	personADT *temp1,*temp2;
	data d;
	temp1 = head->next;
	while(temp1 != NULL){
		temp2 = head->next;
		while(temp2->next != NULL){
			if(temp2->d.age > temp2->next->d.age){
				d = temp2->d;
				temp2->d = temp2->next->d;
				temp2->next->d = d;
			}
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	
}

ratio adultPerson(personADT *head){
	int mcount=0, fcount = 0;
	ratio r;
	personADT *temp;
	temp = head->next;
	while(temp != NULL){
		if(temp->d.sex == 'm'){
			mcount++;
		}
		else if(temp->d.sex == 'f'){
			fcount++;
		}
		temp = temp->next;
	}
	for(int i=2;i<=mcount && i<= fcount;++i){
		if(mcount%i == 0 && fcount%i == 0){
			mcount = mcount/i;
			fcount = fcount/i;
		}
	}
	r.male = mcount;
	r.female= fcount;
	return r;
}


personADT *seniorPersons(personADT *head){
	personADT *list,*temp;
	list = (personADT*)malloc(sizeof(personADT));
	list->next = NULL;
	list->prev = NULL;
	temp = head->next; 
	while(temp != NULL)
	{
		if(temp->d.age >= 65){
			insertFront(list,temp->d);
		}
		temp = temp->next;
	}
	return list;
}


personADT *locatePerson(personADT *head, char *s){
	personADT *temp,*list;
	list = (personADT *) malloc(sizeof(personADT));
	temp = head->next;
	list->next = NULL;
	list->prev = NULL;
	while(temp != NULL){
		if(strcmp(temp->d.city,s) == 0){
			insertFront(list,temp->d);
		}
		temp = temp->next;
	}
	return list;
}








