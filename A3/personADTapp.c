#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"personADTif.h"


void main(){
	personADT *head,*list;
	data d;
	head = (personADT *)malloc(sizeof(personADT));
	head->next = NULL;
	head->prev = NULL;
	ratio r;
	char ch,city[20];
	int option=0,PIN,choice;
	while(option != 7)
	{
		printf("\n\t\t\t\t***************PERSON INFORMATION SYSTEM***************\n\n");
		printf("\t\tMENU\n");
		printf("1.Insert a record in the List	\n2.List the senior persons based on their age\n3.List the persons based on the given location\n4.Sort the persons based on their age in ascending order\n5.Display the persons in the List\n6.Give the ratio of male versus female\n7.Exit");
		printf("\nEnter menu choice :");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
					ch = 'y';
					while(ch == 'y'){

						printf("How do you want to insert the record?\n1.Insertion in the front\n2.Insertion a the end\n3.Insert after a PIN\n4.Exit");
						printf("\nEnter choice:");
						scanf("%d",&choice);
						srand(time(0));
						printf("\nEnter details :");
						printf("\nEnter name:");
						scanf(" %[^\n]",d.name);
						printf("\nEnter age:");
						scanf("%d",&d.age);
						printf("\nEnter sex ( m for male / f for female):");
						scanf(" %c",&d.sex);
						printf("\nEnter street address:");
						scanf(" %[^\n]",d.street);	
						printf("\nEnter city address:");
						scanf(" %[^\n]",d.city);
						d.PIN = (rand()% (9999-1000+1)) + 1000;
						if(choice == 1){
							insertFront(head,d);
						}
						else if(choice == 2){
							insertEnd(head,d);
						}
						else if (choice == 3){
							printf("Enter PIN number after which you want to insert the record");
							scanf("%d",&PIN);
							insertPIN(head,d,PIN);
						}
						else if(choice == 4){
							break;
						}
						else{
							printf("\nInvalid choice! Re-enter \n");
						}
						printf("\nDo you wish to enter more records? (y/n) :");
						scanf(" %c",&ch);	
					}
					break;

			case 2:
					list = seniorPersons(head);
					list = list->next;
					printf("\nSenior persons:");
					while(list != NULL){
						printf("\nName: %s\nPIN: %d\nAge: %d\nSex: %c\nStreet Address: %s\nCity Address: %s\n",list->d.name,list->d.PIN,list->d.age,list->d.sex,list->d.street, list->d.city);
						list = list->next;
					}
					break; 
			case 3:
					printf("\nEnter city to be located:");
					scanf("%s",city);
					list = locatePerson(head,city);
					list = list->next;
					printf("\nLocated persons:");
					while(list != NULL){
						printf("\nName: %s\nPIN: %d\nAge: %d\nSex: %c\nStreet Address: %s\nCity Address: %s\n",list->d.name,list->d.PIN,list->d.age,list->d.sex,list->d.street, list->d.city);
						list = list->next;
					}
					break;
			case 4:
					listSort(head);
					break;
			case 5:
					listPersons(head);
					break;
			case 6:
					r = adultPerson(head);
					printf("\nMale to female ratio is %d:%d",r.male,r.female);
					break;
			case 7:
						break;
			default: printf("\nInvalid choice! Re-enter :");
		}
	}
	
}	



/*

output:



				***************PERSON INFORMATION SYSTEM***************

		MENU
1.Insert a record in the List	
2.List the senior persons based on their age
3.List the persons based on the given location
4.Sort the persons based on their age in ascending order
5.Display the persons in the List
6.Give the ratio of male versus female
7.Exit
Enter menu choice :1
How do you want to insert the record?
1.Insertion in the front
2.Insertion a the end
3.Insert after a PIN
4.Exit
Enter choice:1

Enter details :
Enter name:a

Enter age:67

Enter sex ( m for male / f for female):m

Enter street address: 
a

Enter city address:a

Do you wish to enter more records? (y/n) :y
How do you want to insert the record?
1.Insertion in the front
2.Insertion a the end
3.Insert after a PIN
4.Exit
Enter choice:2

Enter details :
Enter name:b

Enter age:45

Enter sex ( m for male / f for female):m

Enter street address:b

Enter city address:b

Do you wish to enter more records? (y/n) :y
How do you want to insert the record?
1.Insertion in the front
2.Insertion a the end
3.Insert after a PIN
4.Exit
Enter choice:1

Enter details :
Enter name:c

Enter age:23

Enter sex ( m for male / f for female):f

Enter street address:c

Enter city address:c

Do you wish to enter more records? (y/n) :y
How do you want to insert the record?
1.Insertion in the front
2.Insertion a the end
3.Insert after a PIN
4.Exit
Enter choice:1

Enter details :
Enter name:d

Enter age:70

Enter sex ( m for male / f for female):f

Enter street address:d

Enter city address:d

Do you wish to enter more records? (y/n) :y
How do you want to insert the record?
1.Insertion in the front
2.Insertion a the end
3.Insert after a PIN
4.Exit
Enter choice:2

Enter details :
Enter name:e

Enter age:34

Enter sex ( m for male / f for female):f

Enter street address:d

Enter city address:d

Do you wish to enter more records? (y/n) :y
How do you want to insert the record?
1.Insertion in the front
2.Insertion a the end
3.Insert after a PIN
4.Exit
Enter choice:1

Enter details :
Enter name:e

Enter age:56

Enter sex ( m for male / f for female):f

Enter street address:e

Enter city address:e

Do you wish to enter more records? (y/n) :y
How do you want to insert the record?
1.Insertion in the front
2.Insertion a the end
3.Insert after a PIN
4.Exit
Enter choice:2

Enter details :
Enter name:f

Enter age:78

Enter sex ( m for male / f for female):f

Enter street address:f

Enter city address:f

Do you wish to enter more records? (y/n) :n

				***************PERSON INFORMATION SYSTEM***************

		MENU
1.Insert a record in the List	
2.List the senior persons based on their age
3.List the persons based on the given location
4.Sort the persons based on their age in ascending order
5.Display the persons in the List
6.Give the ratio of male versus female
7.Exit
Enter menu choice :5

Display from head:
Name: e
PIN: 6649
Age: 56
Sex: f
Street Address: e
City Address: e

Name: d
PIN: 8516
Age: 70
Sex: f
Street Address: d
City Address: d

Name: c
PIN: 9801
Age: 23
Sex: f
Street Address: c
City Address: c

Name: a
PIN: 5390
Age: 67
Sex: m
Street Address: a
City Address: a

Name: b
PIN: 3653
Age: 45
Sex: m
Street Address: b
City Address: b

Name: e
PIN: 5424
Age: 34
Sex: f
Street Address: d
City Address: d

Name: f
PIN: 6686
Age: 78
Sex: f
Street Address: f
City Address: f

Display from tail:
Name: f
PIN: 6686
Age: 78
Sex: f
Street Address: f
City Address: f

Name: e
PIN: 5424
Age: 34
Sex: f
Street Address: d
City Address: d

Name: b
PIN: 3653
Age: 45
Sex: m
Street Address: b
City Address: b

Name: a
PIN: 5390
Age: 67
Sex: m
Street Address: a
City Address: a

Name: c
PIN: 9801
Age: 23
Sex: f
Street Address: c
City Address: c

Name: d
PIN: 8516
Age: 70
Sex: f
Street Address: d
City Address: d

Name: e
PIN: 6649
Age: 56
Sex: f
Street Address: e
City Address: e

				***************PERSON INFORMATION SYSTEM***************

		MENU
1.Insert a record in the List	
2.List the senior persons based on their age
3.List the persons based on the given location
4.Sort the persons based on their age in ascending order
5.Display the persons in the List
6.Give the ratio of male versus female
7.Exit
Enter menu choice :1
How do you want to insert the record?
1.Insertion in the front
2.Insertion a the end
3.Insert after a PIN
4.Exit
Enter choice:3

Enter details :
Enter name:g

Enter age:44

Enter sex ( m for male / f for female):m

Enter street address:g

Enter city address:d
Enter PIN number after which you want to insert the record9801

Do you wish to enter more records? (y/n) :n

				***************PERSON INFORMATION SYSTEM***************

		MENU
1.Insert a record in the List	
2.List the senior persons based on their age
3.List the persons based on the given location
4.Sort the persons based on their age in ascending order
5.Display the persons in the List
6.Give the ratio of male versus female
7.Exit
Enter menu choice :5

Display from head:
Name: e
PIN: 6649
Age: 56
Sex: f
Street Address: e
City Address: e

Name: d
PIN: 8516
Age: 70
Sex: f
Street Address: d
City Address: d

Name: c
PIN: 9801
Age: 23
Sex: f
Street Address: c
City Address: c

Name: g
PIN: 3326
Age: 44
Sex: m
Street Address: g
City Address: d

Name: a
PIN: 5390
Age: 67
Sex: m
Street Address: a
City Address: a

Name: b
PIN: 3653
Age: 45
Sex: m
Street Address: b
City Address: b

Name: e
PIN: 5424
Age: 34
Sex: f
Street Address: d
City Address: d

Name: f
PIN: 6686
Age: 78
Sex: f
Street Address: f
City Address: f

Display from tail:
Name: f
PIN: 6686
Age: 78
Sex: f
Street Address: f
City Address: f

Name: e
PIN: 5424
Age: 34
Sex: f
Street Address: d
City Address: d

Name: b
PIN: 3653
Age: 45
Sex: m
Street Address: b
City Address: b

Name: a
PIN: 5390
Age: 67
Sex: m
Street Address: a
City Address: a

Name: g
PIN: 3326
Age: 44
Sex: m
Street Address: g
City Address: d

Name: c
PIN: 9801
Age: 23
Sex: f
Street Address: c
City Address: c

Name: d
PIN: 8516
Age: 70
Sex: f
Street Address: d
City Address: d

Name: e
PIN: 6649
Age: 56
Sex: f
Street Address: e
City Address: e

				***************PERSON INFORMATION SYSTEM***************

		MENU
1.Insert a record in the List	
2.List the senior persons based on their age
3.List the persons based on the given location
4.Sort the persons based on their age in ascending order
5.Display the persons in the List
6.Give the ratio of male versus female
7.Exit
Enter menu choice :2

Senior persons:
Name: f
PIN: 6686
Age: 78
Sex: f
Street Address: f
City Address: f

Name: a
PIN: 5390
Age: 67
Sex: m
Street Address: a
City Address: a

Name: d
PIN: 8516
Age: 70
Sex: f
Street Address: d
City Address: d

				***************PERSON INFORMATION SYSTEM***************

		MENU
1.Insert a record in the List	
2.List the senior persons based on their age
3.List the persons based on the given location
4.Sort the persons based on their age in ascending order
5.Display the persons in the List
6.Give the ratio of male versus female
7.Exit
Enter menu choice :3

Enter city to be located:d

Located persons:
Name: e
PIN: 5424
Age: 34
Sex: f
Street Address: d
City Address: d

Name: g
PIN: 3326
Age: 44
Sex: m
Street Address: g
City Address: d

Name: d
PIN: 8516
Age: 70
Sex: f
Street Address: d
City Address: d

				***************PERSON INFORMATION SYSTEM***************

		MENU
1.Insert a record in the List	
2.List the senior persons based on their age
3.List the persons based on the given location
4.Sort the persons based on their age in ascending order
5.Display the persons in the List
6.Give the ratio of male versus female
7.Exit
Enter menu choice :4

				***************PERSON INFORMATION SYSTEM***************

		MENU
1.Insert a record in the List	
2.List the senior persons based on their age
3.List the persons based on the given location
4.Sort the persons based on their age in ascending order
5.Display the persons in the List
6.Give the ratio of male versus female
7.Exit
Enter menu choice :5

Display from head:
Name: c
PIN: 9801
Age: 23
Sex: f
Street Address: c
City Address: c

Name: e
PIN: 5424
Age: 34
Sex: f
Street Address: d
City Address: d

Name: g
PIN: 3326
Age: 44
Sex: m
Street Address: g
City Address: d

Name: b
PIN: 3653
Age: 45
Sex: m
Street Address: b
City Address: b

Name: e
PIN: 6649
Age: 56
Sex: f
Street Address: e
City Address: e

Name: a
PIN: 5390
Age: 67
Sex: m
Street Address: a
City Address: a

Name: d
PIN: 8516
Age: 70
Sex: f
Street Address: d
City Address: d

Name: f
PIN: 6686
Age: 78
Sex: f
Street Address: f
City Address: f

Display from tail:
Name: f
PIN: 6686
Age: 78
Sex: f
Street Address: f
City Address: f

Name: d
PIN: 8516
Age: 70
Sex: f
Street Address: d
City Address: d

Name: a
PIN: 5390
Age: 67
Sex: m
Street Address: a
City Address: a

Name: e
PIN: 6649
Age: 56
Sex: f
Street Address: e
City Address: e

Name: b
PIN: 3653
Age: 45
Sex: m
Street Address: b
City Address: b

Name: g
PIN: 3326
Age: 44
Sex: m
Street Address: g
City Address: d

Name: e
PIN: 5424
Age: 34
Sex: f
Street Address: d
City Address: d

Name: c
PIN: 9801
Age: 23
Sex: f
Street Address: c
City Address: c

				***************PERSON INFORMATION SYSTEM***************

		MENU
1.Insert a record in the List	
2.List the senior persons based on their age
3.List the persons based on the given location
4.Sort the persons based on their age in ascending order
5.Display the persons in the List
6.Give the ratio of male versus female
7.Exit
Enter menu choice :6

Male to female ratio is 3:5
				***************PERSON INFORMATION SYSTEM***************

		MENU
1.Insert a record in the List	
2.List the senior persons based on their age
3.List the persons based on the given location
4.Sort the persons based on their age in ascending order
5.Display the persons in the List
6.Give the ratio of male versus female
7.Exit
Enter menu choice :7

				***************PERSON INFORMATION SYSTEM***************

		MENU
1.Insert a record in the List	
2.List the senior persons based on their age
3.List the persons based on the given location
4.Sort the persons based on their age in ascending order
5.Display the persons in the List
6.Give the ratio of male versus female
7.Exit
Enter menu choice :1
How do you want to insert the record?
1.Insertion in the front
2.Insertion a the end
3.Insert after a PIN
4.Exit
Enter choice:1

Enter details :
Enter name:a

Enter age:67

Enter sex ( m for male / f for female):m

Enter street address: 
a

Enter city address:a

Do you wish to enter more records? (y/n) :y
How do you want to insert the record?
1.Insertion in the front
2.Insertion a the end
3.Insert after a PIN
4.Exit
Enter choice:2

Enter details :
Enter name:b

Enter age:45

Enter sex ( m for male / f for female):m

Enter street address:b

Enter city address:b

Do you wish to enter more records? (y/n) :y
How do you want to insert the record?
1.Insertion in the front
2.Insertion a the end
3.Insert after a PIN
4.Exit
Enter choice:1

Enter details :
Enter name:c

Enter age:23

Enter sex ( m for male / f for female):f

Enter street address:c

Enter city address:c

Do you wish to enter more records? (y/n) :y
How do you want to insert the record?
1.Insertion in the front
2.Insertion a the end
3.Insert after a PIN
4.Exit
Enter choice:1

Enter details :
Enter name:d

Enter age:70

Enter sex ( m for male / f for female):f

Enter street address:d

Enter city address:d

Do you wish to enter more records? (y/n) :y
How do you want to insert the record?
1.Insertion in the front
2.Insertion a the end
3.Insert after a PIN
4.Exit
Enter choice:2

Enter details :
Enter name:e

Enter age:34

Enter sex ( m for male / f for female):f

Enter street address:d

Enter city address:d

Do you wish to enter more records? (y/n) :y
How do you want to insert the record?
1.Insertion in the front
2.Insertion a the end
3.Insert after a PIN
4.Exit
Enter choice:1

Enter details :
Enter name:e

Enter age:56

Enter sex ( m for male / f for female):f

Enter street address:e

Enter city address:e

Do you wish to enter more records? (y/n) :y
How do you want to insert the record?
1.Insertion in the front
2.Insertion a the end
3.Insert after a PIN
4.Exit
Enter choice:2

Enter details :
Enter name:f

Enter age:78

Enter sex ( m for male / f for female):f

Enter street address:f

Enter city address:f

Do you wish to enter more records? (y/n) :n

				***************PERSON INFORMATION SYSTEM***************

		MENU
1.Insert a record in the List	
2.List the senior persons based on their age
3.List the persons based on the given location
4.Sort the persons based on their age in ascending order
5.Display the persons in the List
6.Give the ratio of male versus female
7.Exit
Enter menu choice :5

Display from head:
Name: e
PIN: 6649
Age: 56
Sex: f
Street Address: e
City Address: e

Name: d
PIN: 8516
Age: 70
Sex: f
Street Address: d
City Address: d

Name: c
PIN: 9801
Age: 23
Sex: f
Street Address: c
City Address: c

Name: a
PIN: 5390
Age: 67
Sex: m
Street Address: a
City Address: a

Name: b
PIN: 3653
Age: 45
Sex: m
Street Address: b
City Address: b

Name: e
PIN: 5424
Age: 34
Sex: f
Street Address: d
City Address: d

Name: f
PIN: 6686
Age: 78
Sex: f
Street Address: f
City Address: f

Display from tail:
Name: f
PIN: 6686
Age: 78
Sex: f
Street Address: f
City Address: f

Name: e
PIN: 5424
Age: 34
Sex: f
Street Address: d
City Address: d

Name: b
PIN: 3653
Age: 45
Sex: m
Street Address: b
City Address: b

Name: a
PIN: 5390
Age: 67
Sex: m
Street Address: a
City Address: a

Name: c
PIN: 9801
Age: 23
Sex: f
Street Address: c
City Address: c

Name: d
PIN: 8516
Age: 70
Sex: f
Street Address: d
City Address: d

Name: e
PIN: 6649
Age: 56
Sex: f
Street Address: e
City Address: e

				***************PERSON INFORMATION SYSTEM***************

		MENU
1.Insert a record in the List	
2.List the senior persons based on their age
3.List the persons based on the given location
4.Sort the persons based on their age in ascending order
5.Display the persons in the List
6.Give the ratio of male versus female
7.Exit
Enter menu choice :1
How do you want to insert the record?
1.Insertion in the front
2.Insertion a the end
3.Insert after a PIN
4.Exit
Enter choice:3

Enter details :
Enter name:g

Enter age:44

Enter sex ( m for male / f for female):m

Enter street address:g

Enter city address:d
Enter PIN number after which you want to insert the record9801

Do you wish to enter more records? (y/n) :n

				***************PERSON INFORMATION SYSTEM***************

		MENU
1.Insert a record in the List	
2.List the senior persons based on their age
3.List the persons based on the given location
4.Sort the persons based on their age in ascending order
5.Display the persons in the List
6.Give the ratio of male versus female
7.Exit
Enter menu choice :5

Display from head:
Name: e
PIN: 6649
Age: 56
Sex: f
Street Address: e
City Address: e

Name: d
PIN: 8516
Age: 70
Sex: f
Street Address: d
City Address: d

Name: c
PIN: 9801
Age: 23
Sex: f
Street Address: c
City Address: c

Name: g
PIN: 3326
Age: 44
Sex: m
Street Address: g
City Address: d

Name: a
PIN: 5390
Age: 67
Sex: m
Street Address: a
City Address: a

Name: b
PIN: 3653
Age: 45
Sex: m
Street Address: b
City Address: b

Name: e
PIN: 5424
Age: 34
Sex: f
Street Address: d
City Address: d

Name: f
PIN: 6686
Age: 78
Sex: f
Street Address: f
City Address: f

Display from tail:
Name: f
PIN: 6686
Age: 78
Sex: f
Street Address: f
City Address: f

Name: e
PIN: 5424
Age: 34
Sex: f
Street Address: d
City Address: d

Name: b
PIN: 3653
Age: 45
Sex: m
Street Address: b
City Address: b

Name: a
PIN: 5390
Age: 67
Sex: m
Street Address: a
City Address: a

Name: g
PIN: 3326
Age: 44
Sex: m
Street Address: g
City Address: d

Name: c
PIN: 9801
Age: 23
Sex: f
Street Address: c
City Address: c

Name: d
PIN: 8516
Age: 70
Sex: f
Street Address: d
City Address: d

Name: e
PIN: 6649
Age: 56
Sex: f
Street Address: e
City Address: e

				***************PERSON INFORMATION SYSTEM***************

		MENU
1.Insert a record in the List	
2.List the senior persons based on their age
3.List the persons based on the given location
4.Sort the persons based on their age in ascending order
5.Display the persons in the List
6.Give the ratio of male versus female
7.Exit
Enter menu choice :2

Senior persons:
Name: f
PIN: 6686
Age: 78
Sex: f
Street Address: f
City Address: f

Name: a
PIN: 5390
Age: 67
Sex: m
Street Address: a
City Address: a

Name: d
PIN: 8516
Age: 70
Sex: f
Street Address: d
City Address: d

				***************PERSON INFORMATION SYSTEM***************

		MENU
1.Insert a record in the List	
2.List the senior persons based on their age
3.List the persons based on the given location
4.Sort the persons based on their age in ascending order
5.Display the persons in the List
6.Give the ratio of male versus female
7.Exit
Enter menu choice :3

Enter city to be located:d

Located persons:
Name: e
PIN: 5424
Age: 34
Sex: f
Street Address: d
City Address: d

Name: g
PIN: 3326
Age: 44
Sex: m
Street Address: g
City Address: d

Name: d
PIN: 8516
Age: 70
Sex: f
Street Address: d
City Address: d

				***************PERSON INFORMATION SYSTEM***************

		MENU
1.Insert a record in the List	
2.List the senior persons based on their age
3.List the persons based on the given location
4.Sort the persons based on their age in ascending order
5.Display the persons in the List
6.Give the ratio of male versus female
7.Exit
Enter menu choice :4

				***************PERSON INFORMATION SYSTEM***************

		MENU
1.Insert a record in the List	
2.List the senior persons based on their age
3.List the persons based on the given location
4.Sort the persons based on their age in ascending order
5.Display the persons in the List
6.Give the ratio of male versus female
7.Exit
Enter menu choice :5

Display from head:
Name: c
PIN: 9801
Age: 23
Sex: f
Street Address: c
City Address: c

Name: e
PIN: 5424
Age: 34
Sex: f
Street Address: d
City Address: d

Name: g
PIN: 3326
Age: 44
Sex: m
Street Address: g
City Address: d

Name: b
PIN: 3653
Age: 45
Sex: m
Street Address: b
City Address: b

Name: e
PIN: 6649
Age: 56
Sex: f
Street Address: e
City Address: e

Name: a
PIN: 5390
Age: 67
Sex: m
Street Address: a
City Address: a

Name: d
PIN: 8516
Age: 70
Sex: f
Street Address: d
City Address: d

Name: f
PIN: 6686
Age: 78
Sex: f
Street Address: f
City Address: f

Display from tail:
Name: f
PIN: 6686
Age: 78
Sex: f
Street Address: f
City Address: f

Name: d
PIN: 8516
Age: 70
Sex: f
Street Address: d
City Address: d

Name: a
PIN: 5390
Age: 67
Sex: m
Street Address: a
City Address: a

Name: e
PIN: 6649
Age: 56
Sex: f
Street Address: e
City Address: e

Name: b
PIN: 3653
Age: 45
Sex: m
Street Address: b
City Address: b

Name: g
PIN: 3326
Age: 44
Sex: m
Street Address: g
City Address: d

Name: e
PIN: 5424
Age: 34
Sex: f
Street Address: d
City Address: d

Name: c
PIN: 9801
Age: 23
Sex: f
Street Address: c
City Address: c

				***************PERSON INFORMATION SYSTEM***************

		MENU
1.Insert a record in the List	
2.List the senior persons based on their age
3.List the persons based on the given location
4.Sort the persons based on their age in ascending order
5.Display the persons in the List
6.Give the ratio of male versus female
7.Exit
Enter menu choice :6

Male to female ratio is 3:5
				***************PERSON INFORMATION SYSTEM***************

		MENU
1.Insert a record in the List	
2.List the senior persons based on their age
3.List the persons based on the given location
4.Sort the persons based on their age in ascending order
5.Display the persons in the List
6.Give the ratio of male versus female
7.Exit
Enter menu choice :7

*/


