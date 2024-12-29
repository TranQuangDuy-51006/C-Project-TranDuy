#include <stdio.h>
#include <string.h>
#include "function.h"

void printMenu(){
	printf("\n");
	printf("\t   STUDENT MENU\n");
	printf("\t======================\n");
	printf("\t[1] Add a new student.\n");
	printf("\t[2] Show all student.\n");
	printf("\t[3] Search a student.\n");
	printf("\t[4] Edit a student.\n");
	printf("\t[5] Delete a student.\n");
	printf("\t[0] Exit the program.\n");
	printf("\t======================\n");
}
void printExit(){
	printf("\t====Thank You======\n");
	printf("\t====See You Soon===");
	printf("\n");
}
void printStudent(struct Student user[], int n){
	int i;
	printf("\t\t\t\t\t\t**All student**\n\n");
	printf("\t|=======|===========================|===========================|=================|============|\n");
    printf("\t| %-5s | %-25s | %-25s | %-15s | %-10s |\n", "ID", "Name", "Email", "Phone", "NO.Course");
    printf("\t|=======|===========================|===========================|=================|============|\n");
    for (i = 0; i < n; i++) {
        printf("\t| %-5d | %-25s | %-25s | %-15s | %-10d |\n",
		user[i].id,
		user[i].name,
		user[i].mail,
		user[i].phone,
		user[i].no_course);
        printf("\t|-------|---------------------------|---------------------------|-----------------|------------|\n");
    }

}
void addStudent(struct Student user[], int *n){
	int add = *n;
	int i;
	printf("\t\t**Add a new student**\n");
	addStudent:
	printf("\tEnter the ID: ");
	int check = 0;
	scanf("%d", &user[add].id);
	fflush(stdin);
	for(i = 0; i < *n; i++){
		if(user[add].id == user[i].id||user[add].id < 1){
			check = 1;
		}
	}
	if(check != 1){
		printf("\tEnter the Name: ");
		fgets(user[add].name, sizeof(user[add].name), stdin);
		user[add].name[strcspn(user[add].name,"\n")] = '\0';
		printf("\tEnter the Email: ");
		fgets(user[add].mail, sizeof(user[add].mail), stdin);
		user[add].mail[strcspn(user[add].mail,"\n")] = '\0';
		printf("\tEnter the Phone: ");
		fgets(user[add].phone, sizeof(user[add].phone), stdin);
		user[add].phone[strcspn(user[add].phone,"\n")] = '\0';
		(*n)++;
		printf("\tAdded successfully!!\n");	
	}else{
		printf("\tError: This ID is already exists.\n");
		goto addStudent;
	}
}
void editStudent(struct Student user[], int n){
	int i;
	printf("\t\t**Edit student**\n");
	int searchId;
	printf("\tEnter the ID student: ");
	scanf("%d", &searchId);
	fflush(stdin);
	printf("\tStudent Infomations\n");
	printf("\t----------------------\n");
	for(i = 0; i < n; i++){
		if(searchId == user[i].id){
			printf("\tID: %d\n", user[i].id);
			printf("\tName: %s\n", user[i].name);
			printf("\tEmail: %s\n", user[i].mail);
			printf("\tPhone: %s\n", user[i].phone);
		}
	}
}
