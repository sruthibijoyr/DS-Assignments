typedef struct{
     char  name[25],role[10];
     float avgRunRate;
}playerInfo;

typedef struct myplayer{
     playerInfo d;
     struct myplayer *left, *right;
}playerProfile;

playerProfile *init(playerProfile *p){
     p = malloc(sizeof(playerProfile));
     p->left = NULL;
     p->right = NULL;
     return p;
}

playerProfile *findMin(playerProfile *p){
     playerProfile *tmp;
     tmp=p;
     while(tmp->left!=NULL)
          tmp=tmp->left;
     return tmp;

}

playerProfile *insert(playerProfile *p,playerInfo d){
     if(p == NULL){
          p = init(p);
          p->d = d;
     }
     else if(strcmp(d.name, p->d.name) > 0){
          p->right = insert(p->right,d);
     }
     else if(strcmp(d.name, p->d.name) < 0){
          p->left = insert(p->left,d);
     }
     return p;
}

void displayHierarchy(playerProfile *p, int depth){
     if(p == NULL){
          return;
    
     }
     for(int i=0;i<depth;++i){
          printf("\t");
     }
     printf("[%s,%s,%.2f]\n",p->d.name,p->d.role,p->d.avgRunRate);
     displayHierarchy(p->left,depth+1);
     displayHierarchy(p->right,depth+1);
}

playerProfile *delete(playerProfile *p, char name[]){

     playerProfile *temp;
     if(p == NULL){
          return p;
     }
     else if(strcmp(p->d.name,name)>0){
          p->left = delete(p->left,name);
     }
     else if(strcmp(p->d.name,name)<0){
          p->right = delete(p->right,name);
     }
     else if(p->right && p->left){

          temp = init(temp);
          temp = findMin(p->right);
          p->d = temp->d;
          p->right = delete(p->right,p->d.name);
          free(temp);
     }
     else{
          
          temp = p;
          if(p->left == NULL){
               p = p->right;
          }
          else if(p->right == NULL){
               p = p->left;
          }    
          free(temp);
     }
     return p;

}

playerProfile *search(playerProfile *p,char name[]){
     if(p == NULL){
          return p;
     }
     else if(strcmp(p->d.name,name) == 0){
          return p;
     }
     else if(strcmp(p->d.name,name) > 0){
          return search(p->left,name);
     }
     else if(strcmp(p->d.name,name) < 0){
          return search(p->right,name);
     }
}

//displays player names in preorder
void preorder(playerProfile *p){
	if(p != NULL){
		printf("%s\n",p->d.name);
		preorder(p->left);
		preorder(p->right);
	}
}

//displays player names in inorder
void inorder(playerProfile *p){
	if(p != NULL){
		inorder(p->left);
		printf("%s\n",p->d.name);
		inorder(p->right);
	}
}

//displays player names in postorder
void postorder(playerProfile *p){
	if(p != NULL){
		postorder(p->left);
		postorder(p->right);
		printf("%s\n",p->d.name);
	}
}