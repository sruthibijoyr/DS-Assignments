#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"polyADTif.h"

void main(){
	polyADT *head1,*head2,*head3;
	char ch , inchoice;
	term t;
	int option,choice,exp;
	while(option !=6){
		inchoice = 'y';
		head1 = createPoly();
		head2 = createPoly();
		printf("\n\n\nMENU:  \n1)Add two polynomials \n2)Multiply two polynomials\n3)Find degree of a polynomial\n4)Evaluate polynomial\n5)Simplify a polynomial - combine terms\n6)Exit\nEnter choice:");
		scanf("%d",&option);
		if(option == 1 || option == 2 || option == 3 || option == 4 || option == 5)
		{
			while(inchoice == 'y')
			{
				printf("\nPolynomial 1: \n1.Input a polynomial through insertion at the front\n2.Input a polynomial through insertion at the end \n3.Input a polynomial after a term\nEnter choice:");
				scanf("%d",&choice);

				if(choice != 1 && choice != 2 && choice != 3){
					printf("\nInavlid insetion choice! Re-enter choice: ");
					continue;
				}
				printf("\nEnter coeffecient:");
				scanf("%d",&t.coeff);
				printf("\nEnter exponent:");
				scanf("%d",&t.exp);
				if(choice == 1){
					insertFront(head1,t);
				}
				else if(choice == 2){
					insertEnd(head1,t);
				}
				else if(choice == 3){
					printf("\nEnter the exponent after which you want to input the term: ");
					scanf("%d",&exp);
					insertAfterTerm(head1,t,exp);
				}
				printf("\nDo you wish to enter more terms to the polynomial? (y/n)");
				scanf(" %c",&inchoice);
			}
		}

		if(option == 1 || option == 2){
			inchoice = 'y';
			while(inchoice == 'y')
			{
				printf("\nPolynomial 2: \n1.Input a polynomial through insertion at the front\n2.Input a polynomial through insertion at the end \n3.Input a polynomial after a term\nEnter choice:");
				scanf("%d",&choice);
				if(choice != 1 && choice != 2 && choice != 3){
					printf("\nInavlid insetion choice! Re-enter choice: ");
					continue;
				}
				printf("\nEnter coeffecient:");
				scanf("%d",&t.coeff);
				printf("\nEnter exponent:");
				scanf("%d",&t.exp);
				if(choice == 1){
					insertFront(head2,t);
				}
				else if(choice == 2){
					insertEnd(head2,t);
				}
				else if(choice == 3){
					printf("\nEnter the exponent after which you want to input the term: ");
					scanf("%d",&exp);
					insertAfterTerm(head2,t,exp);
				}
				printf("\nDo you wish to enter more terms to the polynomial? (y/n)");
				scanf(" %c",&inchoice);
			}
		}

		if(option == 1){
			head1 = polySimplify(head1);
			head2 = polySimplify(head2);
			head3 = polyAdd(head1,head2);
			printf("\nPolynomial 1: ");
			display(head1);
			printf("\n\nPolynomial 2: ");
			display(head2);
			printf("\n\nAddition result :");
			display(head3);
		}
		else if(option == 2){
			head1 = polySimplify(head1);
			head2 = polySimplify(head2);
			head3 = polyMultiply(head1,head2);
			printf("\nPolynomial 1: ");
			display(head1);
			printf("\n\nPolynomial 2: ");
			display(head2);
			printf("\n\nMultiplication result :");
			display(head3);
		}
		else if(option == 3){
			printf("\nPolynomial : ");
			head1 = polySimplify(head1);
			display(head1);
			polyDegree(head1);
		}
		else if(option == 4){
			printf("\nPolynomial : ");
			head1 = polySimplify(head1);
			display(head1);
			printf("\nValue of polynomial : %d",polyEvaluate(head1));
		}
		else if(option == 5){
			printf("\nPolynomial : ");
			display(head1);
			head1 = polySimplify(head1);
			printf("\nSimplified polynomial :");
			display(head1);
		}
		else if(option == 6){
			break;
		}
		else{
			printf("\nInvalid option! Re-enter option! ");
		}
	}
}

/*

output:

MENU:
1)Add two polynomials
2)Multiply two polynomials
3)Find degree of a polynomial
4)Evaluate polynomial
5)Simplify a polynomial - combine terms
6)Exit
Enter choice:1

Polynomial 1:
1.Input a polynomial through insertion at the front
2.Input a polynomial through insertion at the end
3.Input a polynomial after a term
Enter choice:1

Enter coeffecient:8

Enter exponent:4

Do you wish to enter more terms to the polynomial? (y/n)y

Polynomial 1:
1.Input a polynomial through insertion at the front
2.Input a polynomial through insertion at the end
3.Input a polynomial after a term
Enter choice:1

Enter coeffecient:3

Enter exponent:5

Do you wish to enter more terms to the polynomial? (y/n)y

Polynomial 1:
1.Input a polynomial through insertion at the front
2.Input a polynomial through insertion at the end
3.Input a polynomial after a term
Enter choice:2

Enter coeffecient:5

Enter exponent:1

Do you wish to enter more terms to the polynomial? (y/n)y

Polynomial 1:
1.Input a polynomial through insertion at the front
2.Input a polynomial through insertion at the end
3.Input a polynomial after a term
Enter choice:3

Enter coeffecient:9

Enter exponent:0

Enter the exponent after which you want to input the term: 1

Do you wish to enter more terms to the polynomial? (y/n)n

Polynomial 2:
1.Input a polynomial through insertion at the front
2.Input a polynomial through insertion at the end
3.Input a polynomial after a term
Enter choice:2

Enter coeffecient:3

Enter exponent:17

Do you wish to enter more terms to the polynomial? (y/n)y

Polynomial 2:
1.Input a polynomial through insertion at the front
2.Input a polynomial through insertion at the end
3.Input a polynomial after a term
Enter choice:2

Enter coeffecient:5

Enter exponent:2

Do you wish to enter more terms to the polynomial? (y/n)y

Polynomial 2:
1.Input a polynomial through insertion at the front
2.Input a polynomial through insertion at the end
3.Input a polynomial after a term
Enter choice:3

Enter coeffecient:1

Enter exponent:1

Enter the exponent after which you want to input the term: 2

Do you wish to enter more terms to the polynomial? (y/n)y

Polynomial 2:
1.Input a polynomial through insertion at the front
2.Input a polynomial through insertion at the end
3.Input a polynomial after a term
Enter choice:1

Enter coeffecient:4

Enter exponent:5

Do you wish to enter more terms to the polynomial? (y/n)n

Polynomial 1:
3x^5 + 8x^4 + 5x^1 + 9x^0

Polynomial 2:
3x^17 + 4x^5 + 5x^2 + 1x^1

Addition result :
3x^17 + 7x^5 + 8x^4 + 5x^2 + 6x^1 + 9x^0


MENU:
1)Add two polynomials
2)Multiply two polynomials
3)Find degree of a polynomial
4)Evaluate polynomial
5)Simplify a polynomial - combine terms
6)Exit
Enter choice:2

Polynomial 1:
1.Input a polynomial through insertion at the front
2.Input a polynomial through insertion at the end
3.Input a polynomial after a term
Enter choice:1

Enter coeffecient:3

Enter exponent:3

Do you wish to enter more terms to the polynomial? (y/n)y

Polynomial 1:
1.Input a polynomial through insertion at the front
2.Input a polynomial through insertion at the end
3.Input a polynomial after a term
Enter choice:2

Enter coeffecient:2

Enter exponent:15

Do you wish to enter more terms to the polynomial? (y/n)y

Polynomial 1:
1.Input a polynomial through insertion at the front
2.Input a polynomial through insertion at the end
3.Input a polynomial after a term
Enter choice:2

Enter coeffecient:4

Enter exponent:5

Do you wish to enter more terms to the polynomial? (y/n)y

Polynomial 1:
1.Input a polynomial through insertion at the front
2.Input a polynomial through insertion at the end
3.Input a polynomial after a term
Enter choice:3

Enter coeffecient:3

Enter exponent:0

Enter the exponent after which you want to input the term: 5

Do you wish to enter more terms to the polynomial? (y/n)n

Polynomial 2:
1.Input a polynomial through insertion at the front
2.Input a polynomial through insertion at the end
3.Input a polynomial after a term
Enter choice:1

Enter coeffecient:2

Enter exponent:2

Do you wish to enter more terms to the polynomial? (y/n)y

Polynomial 2:
1.Input a polynomial through insertion at the front
2.Input a polynomial through insertion at the end
3.Input a polynomial after a term
Enter choice:2

Enter coeffecient:5

Enter exponent:4

Do you wish to enter more terms to the polynomial? (y/n)y

Polynomial 2:
1.Input a polynomial through insertion at the front
2.Input a polynomial through insertion at the end
3.Input a polynomial after a term
Enter choice:1

Enter coeffecient:3

Enter exponent:3

Do you wish to enter more terms to the polynomial? (y/n)y

Polynomial 2:
1.Input a polynomial through insertion at the front
2.Input a polynomial through insertion at the end
3.Input a polynomial after a term
Enter choice:4

Inavlid insetion choice! Re-enter choice:
Polynomial 2:
1.Input a polynomial through insertion at the front
2.Input a polynomial through insertion at the end
3.Input a polynomial after a term
Enter choice:1

Enter coeffecient:4

Enter exponent:1

Do you wish to enter more terms to the polynomial? (y/n)n

Polynomial 1:
2x^15 + 4x^5 + 3x^3 + 3x^0

Polynomial 2:
5x^4 + 3x^3 + 2x^2 + 4x^1

Multiplication result :
10x^19 + 6x^18 + 4x^17 + 8x^16 + 20x^9 + 12x^8 + 23x^7 + 25x^6 + 6x^5 + 27x^4 + 9x^3 + 6x^2 + 12x^1


MENU:
1)Add two polynomials
2)Multiply two polynomials
3)Find degree of a polynomial
4)Evaluate polynomial
5)Simplify a polynomial - combine terms
6)Exit
Enter choice:3

Polynomial 1:
1.Input a polynomial through insertion at the front
2.Input a polynomial through insertion at the end
3.Input a polynomial after a term
Enter choice:1

Enter coeffecient:5

Enter exponent:6

Do you wish to enter more terms to the polynomial? (y/n)y

Polynomial 1:
1.Input a polynomial through insertion at the front
2.Input a polynomial through insertion at the end
3.Input a polynomial after a term
Enter choice:2

Enter coeffecient:7

Enter exponent:4

Do you wish to enter more terms to the polynomial? (y/n)y

Polynomial 1:
1.Input a polynomial through insertion at the front
2.Input a polynomial through insertion at the end
3.Input a polynomial after a term
Enter choice:1

Enter coeffecient:3

Enter exponent:2

Do you wish to enter more terms to the polynomial? (y/n)y

Polynomial 1:
1.Input a polynomial through insertion at the front
2.Input a polynomial through insertion at the end
3.Input a polynomial after a term
Enter choice:1

Enter coeffecient:8

Enter exponent:0

Do you wish to enter more terms to the polynomial? (y/n)n

Polynomial :
5x^6 + 7x^4 + 3x^2 + 8x^0

Degree of the polynomial: 6


MENU:
1)Add two polynomials
2)Multiply two polynomials
3)Find degree of a polynomial
4)Evaluate polynomial
5)Simplify a polynomial - combine terms
6)Exit
Enter choice:4

Polynomial 1:
1.Input a polynomial through insertion at the front
2.Input a polynomial through insertion at the end
3.Input a polynomial after a term
Enter choice:1

Enter coeffecient:3

Enter exponent:3

Do you wish to enter more terms to the polynomial? (y/n)y

Polynomial 1:
1.Input a polynomial through insertion at the front
2.Input a polynomial through insertion at the end
3.Input a polynomial after a term
Enter choice:2

Enter coeffecient:2

Enter exponent:1

Do you wish to enter more terms to the polynomial? (y/n)y

Polynomial 1:
1.Input a polynomial through insertion at the front
2.Input a polynomial through insertion at the end
3.Input a polynomial after a term
Enter choice:3

Enter coeffecient:6

Enter exponent:4

Enter the exponent after which you want to input the term: 2

Exponent not found in existing polynomial!
Do you wish to enter more terms to the polynomial? (y/n)y

Polynomial 1:
1.Input a polynomial through insertion at the front
2.Input a polynomial through insertion at the end
3.Input a polynomial after a term
Enter choice:3

Enter coeffecient:6

Enter exponent:4

Enter the exponent after which you want to input the term: 1

Do you wish to enter more terms to the polynomial? (y/n)n

Polynomial :
6x^4 + 3x^3 + 2x^1
Enter value of x to evaluate the polynomial :-3

Polynomial :
6x^4 + 3x^3 + 2x^1
Value of polynomial : 399


MENU:
1)Add two polynomials
2)Multiply two polynomials
3)Find degree of a polynomial
4)Evaluate polynomial
5)Simplify a polynomial - combine terms
6)Exit
Enter choice:5

Polynomial 1:
1.Input a polynomial through insertion at the front
2.Input a polynomial through insertion at the end
3.Input a polynomial after a term
Enter choice:1

Enter coeffecient:6

Enter exponent:4

Do you wish to enter more terms to the polynomial? (y/n)y

Polynomial 1:
1.Input a polynomial through insertion at the front
2.Input a polynomial through insertion at the end
3.Input a polynomial after a term
Enter choice:1

Enter coeffecient:4

Enter exponent:2

Do you wish to enter more terms to the polynomial? (y/n)y

Polynomial 1:
1.Input a polynomial through insertion at the front
2.Input a polynomial through insertion at the end
3.Input a polynomial after a term
Enter choice:1

Enter coeffecient:2

Enter exponent:4

Do you wish to enter more terms to the polynomial? (y/n)y

Polynomial 1:
1.Input a polynomial through insertion at the front
2.Input a polynomial through insertion at the end
3.Input a polynomial after a term
Enter choice:2

Enter coeffecient:0

Enter exponent:9

Do you wish to enter more terms to the polynomial? (y/n)y

Polynomial 1:
1.Input a polynomial through insertion at the front
2.Input a polynomial through insertion at the end
3.Input a polynomial after a term
Enter choice:3

Enter coeffecient:3

Enter exponent:3

Enter the exponent after which you want to input the term: 9

Do you wish to enter more terms to the polynomial? (y/n)n

Polynomial :
2x^4 + 4x^2 + 6x^4 + 0x^9 + 3x^3
Simplified polynomial :
0x^9 + 8x^4 + 3x^3 + 4x^2

MENU:
1)Add two polynomials
2)Multiply two polynomials
3)Find degree of a polynomial
4)Evaluate polynomial
5)Simplify a polynomial - combine terms
6)Exit
Enter choice:6

*/