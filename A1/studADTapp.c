#include<stdio.h>
#include<string.h>
#include"studADTprot.h"


void main()
{
	int option;
	student s,*sptr;
	listADT l,record;
	int rno, count;
	char name[25],ch = 'y',cont;
	l.size=0;
	while(ch == 'y')
	{
		printf("\n\n*********MENU**********");
		printf("\n1.	Insert a record in the front of the list "
		"\n2.	Insert a record at the end of the list" 
		"\n3.	Insert a record after a given Regno in the list"
		"\n4.	List the records of students based on his register number"
		"\n5.	List the records of students based on his name"
		"\n6.	Delete a given student record given his register number and display all the details"
		"\n7.	Calculate the Total and update the Result field"
		"\n8.	List the students who have passed"
		"\n9.	List the students how many have secured FirstClass"
		"\n10.	Display records");
		printf("\nEnter menu choice:");
		scanf("%d",&option);
		switch(option)
		{
		
			case 1: cont = 'y';
					while(cont == 'y')
					{
						printf("\nEnter details of record:\n");
						getInput(&s);
						insertFront(&l,s);
						printf("Do you wish to enter more records?(y/n):");
						scanf(" %c",&cont);
					}
					break;

			case 2:	
					cont = 'y';
					while(cont == 'y')
					{
						printf("\nEnter details of record:\n");
						getInput(&s);
						insertEnd(&l,s);
						printf("Do you wish to enter more records?(y/n):");
						scanf(" %c",&cont);
					}
					break;

			case 3:	printf("Enter register number :");
					scanf("%d",&rno);
					printf("\nEnter details of record:\n");
					getInput(&s);
					insertRegno(&l,s,rno);
					break;

			case 4:	printf("\nEnter register number to be searched:");
					scanf("%d",&rno);
					sptr = searchRegno(l,rno);
					printf("\nSearch by register number result:");
					printf("\n%s %d %d %d %d",sptr->name,sptr->regno,sptr->mark1,sptr->mark2,sptr->mark3);
					break;

			case 5:	printf("\nEnter name to be searched:");
					scanf("%s",name);
					record = searchName(l,name);
					printf("\nSearch by name result:");
					display(record);
					break;

			case 6:	printf("\nEnter the register number to be deleted:");
					scanf("%d",&rno);
					delete(&l,rno);
					break;

			case 7:	computeResult(&l);
					break;

			case 8:	printf("\nStudents who passed: ");
					record = listResult(l);
					display(record);
					break;

			case 9:	count = listClass(l);
					printf("\nNumber of students with first class: %d",count);
					break;

			case 10: display(l);
					break;
			default:
					printf("Invalid option");
		}
		printf("\nDo you wish to continue? (y/n)");
		scanf(" %c",&ch);
	}
}


/*

output:


*********MENU**********
1.      Insert a record in the front of the list
2.      Insert a record at the end of the list
3.      Insert a record after a given Regno in the list
4.      List the records of students based on his register number
5.      List the records of students based on his name
6.      Delete a given student record given his register number and display all the details
7.      Calculate the Total and update the Result field
8.      List the students who have passed
9.      List the students how many have secured FirstClass
10.     Display records
Enter menu choice:1

Enter details of record:

Enter name, reg number, mark 1, mark 2, mark 3 :a 1 90 95 94
Do you wish to enter more records?(y/n):y

Enter details of record:

Enter name, reg number, mark 1, mark 2, mark 3 :b 2 60 70 65
Do you wish to enter more records?(y/n):y

Enter details of record:

Enter name, reg number, mark 1, mark 2, mark 3 :c 3 85 80 88
Do you wish to enter more records?(y/n):n

Do you wish to continue? (y/n)y


*********MENU**********
1.      Insert a record in the front of the list
2.      Insert a record at the end of the list
3.      Insert a record after a given Regno in the list
4.      List the records of students based on his register number
5.      List the records of students based on his name
6.      Delete a given student record given his register number and display all the details
7.      Calculate the Total and update the Result field
8.      List the students who have passed
9.      List the students how many have secured FirstClass
10.     Display records
Enter menu choice:2

Enter details of record:

Enter name, reg number, mark 1, mark 2, mark 3 :d 4 99 98 100
Do you wish to enter more records?(y/n):y

Enter details of record:

Enter name, reg number, mark 1, mark 2, mark 3 :e 5 50 40 35
Do you wish to enter more records?(y/n):n

Do you wish to continue? (y/n)y


*********MENU**********
1.      Insert a record in the front of the list
2.      Insert a record at the end of the list
3.      Insert a record after a given Regno in the list
4.      List the records of students based on his register number
5.      List the records of students based on his name
6.      Delete a given student record given his register number and display all the details
7.      Calculate the Total and update the Result field
8.      List the students who have passed
9.      List the students how many have secured FirstClass
10.     Display records
Enter menu choice:2

Enter details of record:

Enter name, reg number, mark 1, mark 2, mark 3 :a 6 95 90 94
Do you wish to enter more records?(y/n):n

Do you wish to continue? (y/n)y


*********MENU**********
1.      Insert a record in the front of the list
2.      Insert a record at the end of the list
3.      Insert a record after a given Regno in the list
4.      List the records of students based on his register number
5.      List the records of students based on his name
6.      Delete a given student record given his register number and display all the details
7.      Calculate the Total and update the Result field
8.      List the students who have passed
9.      List the students how many have secured FirstClass
10.     Display records
Enter menu choice:3
Enter register number :5

Enter details of record:

Enter name, reg number, mark 1, mark 2, mark 3 :f 7 23 30 22

Do you wish to continue? (y/n)y


*********MENU**********
1.      Insert a record in the front of the list
2.      Insert a record at the end of the list
3.      Insert a record after a given Regno in the list
4.      List the records of students based on his register number
5.      List the records of students based on his name
6.      Delete a given student record given his register number and display all the details
7.      Calculate the Total and update the Result field
8.      List the students who have passed
9.      List the students how many have secured FirstClass
10.     Display records
Enter menu choice:4

Enter register number to be searched:6

Search by register number result:
a 6 95 90 94
Do you wish to continue? (y/n)y


*********MENU**********
1.      Insert a record in the front of the list
2.      Insert a record at the end of the list
3.      Insert a record after a given Regno in the list
4.      List the records of students based on his register number
5.      List the records of students based on his name
6.      Delete a given student record given his register number and display all the details
7.      Calculate the Total and update the Result field
8.      List the students who have passed
9.      List the students how many have secured FirstClass
10.     Display records
Enter menu choice:5

Enter name to be searched:a

Search by name result:
list:
Name regnum mark1 mark2 mark3 Total Result
a 1 90 95 94 0 -
a 6 95 90 94 0 -
Do you wish to continue? (y/n)y


*********MENU**********
1.      Insert a record in the front of the list
2.      Insert a record at the end of the list
3.      Insert a record after a given Regno in the list
4.      List the records of students based on his register number
5.      List the records of students based on his name
6.      Delete a given student record given his register number and display all the details
7.      Calculate the Total and update the Result field
8.      List the students who have passed
9.      List the students how many have secured FirstClass
10.     Display records
Enter menu choice:6

Enter the register number to be deleted:2

Do you wish to continue? (y/n)y


*********MENU**********
1.      Insert a record in the front of the list
2.      Insert a record at the end of the list
3.      Insert a record after a given Regno in the list
4.      List the records of students based on his register number
5.      List the records of students based on his name
6.      Delete a given student record given his register number and display all the details
7.      Calculate the Total and update the Result field
8.      List the students who have passed
9.      List the students how many have secured FirstClass
10.     Display records
Enter menu choice:7

Do you wish to continue? (y/n)y


*********MENU**********
1.      Insert a record in the front of the list
2.      Insert a record at the end of the list
3.      Insert a record after a given Regno in the list
4.      List the records of students based on his register number
5.      List the records of students based on his name
6.      Delete a given student record given his register number and display all the details
7.      Calculate the Total and update the Result field
8.      List the students who have passed
9.      List the students how many have secured FirstClass
10.     Display records
Enter menu choice:8

Students who passed:
list:
Name regnum mark1 mark2 mark3 Total Result
c 3 85 80 88 253 P
a 1 90 95 94 279 P
d 4 99 98 100 297 P
a 6 95 90 94 279 P
Do you wish to continue? (y/n)y


*********MENU**********
1.      Insert a record in the front of the list
2.      Insert a record at the end of the list
3.      Insert a record after a given Regno in the list
4.      List the records of students based on his register number
5.      List the records of students based on his name
6.      Delete a given student record given his register number and display all the details
7.      Calculate the Total and update the Result field
8.      List the students who have passed
9.      List the students how many have secured FirstClass
10.     Display records
Enter menu choice:9

Number of students with first class: 3
Do you wish to continue? (y/n)y


*********MENU**********
1.      Insert a record in the front of the list
2.      Insert a record at the end of the list
3.      Insert a record after a given Regno in the list
4.      List the records of students based on his register number
5.      List the records of students based on his name
6.      Delete a given student record given his register number and display all the details
7.      Calculate the Total and update the Result field
8.      List the students who have passed
9.      List the students how many have secured FirstClass
10.     Display records
Enter menu choice:10

list:
Name regnum mark1 mark2 mark3 Total Result
c 3 85 80 88 253 P
a 1 90 95 94 279 P
d 4 99 98 100 297 P
e 5 50 40 35 125 F
f 7 23 30 22 75 F
a 6 95 90 94 279 P
Do you wish to continue? (y/n)n

*/



