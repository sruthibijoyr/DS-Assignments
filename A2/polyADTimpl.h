typedef struct{
	int exp;
	int coeff;
}term;

typedef struct mypoly{
	term data;
	struct  mypoly *next;
}polyADT;

polyADT* createPoly(){
	polyADT *head;
	head = (polyADT *)malloc(sizeof(polyADT));
	head->next = NULL;
	return head;
}

void delete(polyADT *head, polyADT *p){
	polyADT *temp,*prev;
	temp = head->next;
	prev = head;
	while(temp != NULL){
		if((temp->data.coeff == p->data.coeff) && (temp->data.exp == p->data.exp)){
			prev->next = temp->next;
			free(temp);
			break;
		}
		prev = prev->next;
		temp = temp->next;
	}
}

void display(polyADT *head){
	polyADT *p;
	p=head->next;
	printf("\n");
	while(p != NULL)
	{
		printf("%dx^%d ",p->data.coeff,p->data.exp);
		if(p->next != NULL && p->data.coeff>=0){
			printf("+ ");
		}
		p=p->next;
	}
}


polyADT *polySimplify(polyADT  *head){
	polyADT *temp,*prev,*pi,*pj;
	term t;
	pi = head->next;
	while(pi != NULL){
		pj = head->next;
		while(pj->next != NULL){
			if(pj->data.exp < (pj->next)->data.exp){
				t = pj->data;
				pj->data = (pj->next)->data;
				(pj->next)->data = t;
			}
			pj = pj->next;
		}
		pi = pi->next;
	}

	prev = head->next;
	temp = prev->next;
	while(temp != NULL)
	{
		if(prev->data.exp == temp->data.exp){
			prev->data.coeff += temp->data.coeff;
			delete(head,temp);
			temp = prev->next;
			continue;
		}
		if(prev->next == NULL){
			break;
		}
		prev = prev->next;
		temp = prev->next;
	}
	return head;
}

void insertFront(polyADT *head, term t){
	polyADT *temp;
	temp = createPoly();
	temp->data = t;
	temp->next = head->next;
	head->next = temp;
}

void insertEnd(polyADT *head, term t){
	polyADT *temp,*end;
	temp = createPoly();
	end = createPoly();
	temp->data = t;
	end = head;
	while(end->next != NULL){
		end = end->next;
	}
	end->next = temp;
	temp->next = NULL;
}

polyADT* findTerm(polyADT *head,int exp){
	polyADT *temp;
	temp = head->next;
	while(temp != NULL){
		if(temp->data.exp == exp){
			return temp;
		}
		temp = temp->next;
	}
	printf("\nExponent not found in existing polynomial! ");
	return NULL;
}

void insertAfterTerm(polyADT *head, term t, int exp){
	polyADT *find,*temp;
	find = findTerm(head,exp);
	if(find == NULL){
		return;
	}
	temp = createPoly();
	temp->data = t;
	temp->next = find->next;
	find->next = temp;
}




int polyEvaluate(polyADT *head){
	int x, value = 0;
	printf("\nEnter value of x to evaluate the polynomial :");
	scanf("%d",&x);
	printf("\nPolynomial : ");
	head = polySimplify(head);
	display(head);
	polyADT *p;
	p = head->next;
	while( p != NULL){
		value += (p->data.coeff)*pow(x,p->data.exp);
		p = p->next;
	}
	return value;
}


polyADT* polyAdd(polyADT *head1,polyADT *head2){
	term res;
	polyADT *head3,*p1,*p2,*p3;
	head3=createPoly(head3);
	p1=head1->next;
	p2=head2->next;
	p3=head3->next;
	while(p1!=NULL && p2!=NULL)
	{
		if(p1->data.exp > p2->data.exp)
		{
			insertEnd(head3,p1->data);
			p1=p1->next;
		}
		else if(p2->data.exp > p1->data.exp)
		{
			insertEnd(head3,p2->data);
			p2=p2->next;
		}
		else
		{
			res.coeff=(p1->data.coeff)+(p2->data.coeff);
			res.exp = p1->data.exp;
			insertEnd(head3,res);
			p1=p1->next;
			p2=p2->next;
		}
	}
	
	if(p1==NULL)
	{
		while(p2!=NULL)
		{
			insertEnd(head3,p2->data);
			p2 = p2->next;
		}
	}
	
	else if(p2==NULL)
	{
		while(p1!=NULL)
		{
			insertEnd(head3,p1->data);
			p1=p1->next;
		}
	}
	
	return head3;
}

polyADT *polyMultiply(polyADT *head1,polyADT *head2){
	int res, degree;
	term t;
	polyADT *head3,*p1,*p2,*p3, *temp = createPoly();
	head3 = createPoly();
	p1=head1->next;
	p2=head2->next;

	temp = (polyADT*)malloc(sizeof(polyADT));

	degree = p1->data.exp + p2->data.exp;

	for(int i=degree; i>=0; i--){
		t.coeff = 0;
		t.exp = i;
		insertEnd(head3,t);
	}

	while(p1!=NULL)
	{
		p2 = head2->next;
		while(p2!=NULL){
			p3 = head3->next;

			temp->data.coeff = p1->data.coeff * p2->data.coeff;
			temp->data.exp = p1->data.exp + p2->data.exp;
			while(p3 != NULL){
				if(temp->data.exp == p3->data.exp){
					p3->data.coeff = p3->data.coeff + temp->data.coeff;
					break;
				}
				p3 = p3->next;
			}
			p2 = p2->next;
		}	
		p1 = p1->next;
	}

	head3 = polySimplify(head3);

	p1 = head3->next;

	while(p1 != NULL){
		p2 = p1->next;
		if(p1->data.coeff == 0){
			delete(head3,p1);
		}
		p1 = p2;

	}

	return head3;
}

void polyDegree(polyADT *head){
	int degree;
	degree = (head->next)->data.exp;
	printf("\n\nDegree of the polynomial: %d",degree);
}
