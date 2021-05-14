//avl tree

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"dictionaryADTif.h"

void main(){
	dictionaryADT *D,*temp;
	D = NULL;
	data x;
	int ch=0;

	while(ch != 4){

		printf("\n************MENU************\n\n1)Insert a new word and meaning\n2)Display Dictionary\n3)Search meaning\n4)Exit\nChoose an option:");
		scanf("%d",&ch);

		switch(ch){

			case 1:

			printf("Enter word:\n");
			scanf("%s",x.word);
			printf("Enter meaning:\n");
			scanf(" %[^\n]",x.meaning);
			D = insert(D,x);
			break;

			case 2:

			displayHierarchy(D,0);
			break;

			case 3:

			printf("Enter word to search for:\n");
			scanf("%s",x.word);
			temp = search(D,x.word);
			if(temp != NULL){
				printf("%s: %s\n",temp->wordMeaning.word,temp->wordMeaning.meaning);
			}
			else{
				printf("Word not found in dictionary!\n");
			}
			break;

			case 4:

			break;

		}
	}

}


/*
output:

************MENU************

1)Insert a new word and meaning
2)Display Dictionary
3)Search meaning
4)Exit
Choose an option:1
Enter word:
f
Enter meaning:
ffff

************MENU************

1)Insert a new word and meaning
2)Display Dictionary
3)Search meaning
4)Exit
Choose an option:1
Enter word:
w
Enter meaning:
wwww

************MENU************

1)Insert a new word and meaning
2)Display Dictionary
3)Search meaning
4)Exit
Choose an option:1
Enter word:
a
Enter meaning:
aaaaa

************MENU************

1)Insert a new word and meaning
2)Display Dictionary
3)Search meaning
4)Exit
Choose an option:1
Enter word:
c
Enter meaning:
cccc

************MENU************

1)Insert a new word and meaning
2)Display Dictionary
3)Search meaning
4)Exit
Choose an option:1
Enter word:
h
Enter meaning:
hhhhh

************MENU************

1)Insert a new word and meaning
2)Display Dictionary
3)Search meaning
4)Exit
Choose an option:
1
Enter word:
n
Enter meaning:
nnnnn

************MENU************

1)Insert a new word and meaning
2)Display Dictionary
3)Search meaning
4)Exit
Choose an option:1
Enter word:
z
Enter meaning:
zzzzz

************MENU************

1)Insert a new word and meaning
2)Display Dictionary
3)Search meaning
4)Exit
Choose an option:1
Enter word:
o
Enter meaning:

ooooooooo

************MENU************

1)Insert a new word and meaning
2)Display Dictionary
3)Search meaning
4)Exit
Choose an option:2
f: ffff
        a: aaaaa
                c: cccc
        w: wwww
                n: nnnnn
                        h: hhhhh
                        o: ooooooooo
                z: zzzzz

************MENU************

1)Insert a new word and meaning
2)Display Dictionary
3)Search meaning
4)Exit
Choose an option:3
Enter word to search for:
w
w: wwww

************MENU************

1)Insert a new word and meaning
2)Display Dictionary
3)Search meaning
4)Exit
Choose an option:3
Enter word to search for:
i
Word not found in dictionary!

************MENU************

1)Insert a new word and meaning
2)Display Dictionary
3)Search meaning
4)Exit
Choose an option:4

*/