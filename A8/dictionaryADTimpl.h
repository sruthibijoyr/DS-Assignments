typedef struct mydata
{
	char word[25];
	char meaning[100];
}data;

typedef struct mydictionaryADT{
	data wordMeaning;
	struct mydictionaryADT *right, *left;
	int height;
}dictionaryADT;

dictionaryADT *init(dictionaryADT *D){
	D = malloc(sizeof(dictionaryADT));
	D->height = 0;
	D->left = NULL;
	D->right = NULL;
	return D;
}

int height(dictionaryADT *D){
	if(D == NULL)
	{
		return -1;
	}
	else
		return D->height;
}

int max(int a, int b){
	if(a>b)
		return a;
	else
		return b;
}

dictionaryADT *singleRotateLeft(dictionaryADT *D1){
	dictionaryADT *D2;
	D2 = D1->left;
	D1->left = D2->right;
	D2->right = D1;

	D1->height = max(height(D1->left),height(D1->right));
	D2->height = max(height(D2->left),height(D2->right));

	return D2;
}

dictionaryADT *singleRotateRight(dictionaryADT *D1){
	dictionaryADT *D2;
	D2 = D1->right;
	D1->right = D2->left;
	D2->left = D1;

	D1->height = max(height(D1->left),height(D1->right));
	D2->height = max(height(D2->left),height(D2->right));

	return D2;
}

dictionaryADT *doubleRotateLeft(dictionaryADT *D){

	D->left = singleRotateRight(D->left);

	return singleRotateLeft(D);
}

dictionaryADT *doubleRotateRight(dictionaryADT *D){

	D->right = singleRotateLeft(D->right);

	return singleRotateRight(D);

}

dictionaryADT* insert(dictionaryADT *D, data x){

	if (D== NULL)
	{
		D = init(D);
		D->wordMeaning = x;
	}
	else if (strcmp(D->wordMeaning.word,x.word)>0)
	{
		D->left = insert(D->left,x);
		int hdiff = abs(height(D->left) - height(D->right));
		if(hdiff == 2){
			if(strcmp(D->left->wordMeaning.word,x.word)>0)
				D = singleRotateLeft(D);
			else
				D = doubleRotateLeft(D);
		}
	}
	else if(strcmp(D->wordMeaning.word,x.word)<0){
		D->right = insert(D->right,x);
		int hdiff = abs(height(D->left) - height(D->right));
		if(hdiff == 2){
			if(strcmp(D->left->wordMeaning.word,x.word)<0)
				D = singleRotateRight(D);
			else
				D = doubleRotateRight(D);
		}
	}
	D->height = max(height(D->left),height(D->right))+1;
	return D;
}

void displayHierarchy(dictionaryADT *D,int depth){
	
	if(D==NULL)
		return;
	for(int i=0;i<depth;++i){
		printf("\t");
	}
	printf("%s: %s\n",D->wordMeaning.word,D->wordMeaning.meaning);
	displayHierarchy(D->left,depth+1);
	displayHierarchy(D->right,depth+1);

}

dictionaryADT *search(dictionaryADT *D,char word[]){
     if(D == NULL){
          return D;
     }
     else if(strcmp(D->wordMeaning.word,word) == 0){
          return D;
     }
     else if(strcmp(D->wordMeaning.word,word) > 0){
          return search(D->left,word);
     }
     else if(strcmp(D->wordMeaning.word,word) < 0){
          return search(D->right,word);
     }
}

