#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	struct Student user[100] = {1,"hello","kow43@gmail.com","0913121212"};
	int n = 1;
	int choice;
	do{
		printMenu();
		printf("\tEnter the choice: ");
		scanf("%d", &choice);
		printf("\n");
		fflush(stdin);
		switch(choice){
			case 1:
				addStudent(user,&n);
				break;
			case 2:
				printStudent(user,n);
				break;
			case 4:
				editStudent(user,n);
				break;
			case 0:
				printExit();
				break;
			default:
				printf("\t\tsai cu phap!\n");
		}
	}while(choice != 0);
	return 0;
}
