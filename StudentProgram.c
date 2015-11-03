#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Student_dataTable.h"
//eunjung02
int c,i;
int Menu_Number;
int NewStudent;
int ForModify;
int ForRemove=0;
int List_all=0;
int AddListNum=0;
struct student StudentInfo[1000];
char IdFromUser[20];

FILE *list;

void ListView();
void StudentSearch();
int StudentAdd();
void StudentUpdate();
void StudentDelete();

int main()
{
	list=fopen("Infromation of a student.txt","r");

	for(List_all=0;;List_all++){
		fscanf(list,"%s %s %s %s",&StudentInfo[List_all].id, &StudentInfo[List_all].name, &StudentInfo[List_all].department, &StudentInfo[List_all].PhoneNumber);
		
		if(feof(list)){	
			break;
		}
	}

	while(1){
		printf("\n1.List View\n");
		printf("2.Student Search\n");
		printf("3.Student Add\n");
		printf("4.Student Update\n");
		printf("5.Student Delete\n");
		printf("6.End\n\n");
		printf("Input Number : ");
		scanf("%d",&Menu_Number);

		switch(Menu_Number)
		{
		case 1:
			ListView();
			break;
		case 2:
			StudentSearch();
			break;
		case 3:
			StudentAdd();
			break;
		case 4:
			StudentUpdate();
			break;
		case 5:
			StudentDelete();
			break;
		case 6:
			exit(0);
		}
	}
	return 0;
}

void ListView(void){
	
	printf("------------------------------------------------\n");
	printf("[ID/ NAME/ DEPARTMENT/ PHONENUMBER]\n");
	printf("------------------------------------------------\n");
	for(c=0;c<List_all;c++)		
		printf("%-10s %-10s %-10s %-10s\n",StudentInfo[c].id, StudentInfo[c].name, StudentInfo[c].department, StudentInfo[c].PhoneNumber);	
	fclose(list);
}

void StudentSearch(void){
	list = fopen("Infromation of a student.txt","r");		
	printf("Input ID : ");	
	scanf("%s",IdFromUser);
	
	for(c=0;c<List_all;c++)	
		if(strncmp(StudentInfo[c].id,IdFromUser,7)==0){		
			printf("* ID:%s\n* Name:%s\n* Department:%s\n* PhoneNumber:%s\n",StudentInfo[c].id,StudentInfo[c].name,StudentInfo[c].department,StudentInfo[c].PhoneNumber);	
		}
}

int StudentAdd(void){
	NewStudent=List_all+AddListNum;
	list = fopen("Infromation of a student.txt","a+");
	
	printf("ID:");
	scanf("%s",IdFromUser);
	for(List_all=0;;List_all++){
		fscanf(list,"%s %s %s %s",&StudentInfo[List_all].id, &StudentInfo[List_all].name, &StudentInfo[List_all].department, &StudentInfo[List_all].PhoneNumber);
		
		if(strncmp(StudentInfo[List_all].id,IdFromUser,7)==0){	
			printf("It's duplicate student ID, please write other ID\n");
			return 0;
		}
		if(feof(list))	
			break;
	}
	strcpy(StudentInfo[NewStudent].id,IdFromUser);

	printf("Name:");	
	scanf("%s",StudentInfo[NewStudent].name);
	printf("Department:");
	scanf("%s",StudentInfo[NewStudent].department);
	printf("PhoneNumber:");
	scanf("%s",StudentInfo[NewStudent].PhoneNumber);
	gets(IdFromUser);

	fprintf(list,"%-10s %-10s %-10s %-10s\n",StudentInfo[NewStudent].id, StudentInfo[NewStudent].name, StudentInfo[NewStudent].department, StudentInfo[NewStudent].PhoneNumber);
	printf("Successfully done!\n");
	
	
	fclose(list);
	AddListNum++;
	return 0;
}

void StudentUpdate(void){
	printf("Input ID : ");
	scanf("%s",IdFromUser);

	for(i=0;i<List_all;i++){
		if(strncmp(StudentInfo[i].id,IdFromUser,7)==0){	
			ForModify=i;
			printf("Phone Number : ");	
			scanf("%s",&StudentInfo[ForModify].PhoneNumber);
			printf("Successfully done!\n");	
			list=fopen("Infromation of a student.txt","w");

			for(c=0;c<List_all;c++){
				fprintf(list,"%-10s %-10s %-10s %-10s\n",StudentInfo[c].id, StudentInfo[c].name, StudentInfo[c].department, StudentInfo[c].PhoneNumber);
			}
		}	
	}
	fclose(list);

}

void StudentDelete(void){
	printf("Input ID : ");
	scanf("%s",&IdFromUser);
			
	for(i=0;i<List_all;i++){		
		if(strncmp(StudentInfo[i].id,IdFromUser,7)==0){		
			for(ForRemove=i;ForRemove<=List_all;ForRemove++){	
				strcpy(StudentInfo[ForRemove].id,StudentInfo[ForRemove+1].id);
				strcpy(StudentInfo[ForRemove].name,StudentInfo[ForRemove+1].name);
				strcpy(StudentInfo[ForRemove].department,StudentInfo[ForRemove+1].department);
				strcpy(StudentInfo[ForRemove].PhoneNumber,StudentInfo[ForRemove+1].PhoneNumber);
			} //지우고자 하는 학생의 리스트의 다음학생부터 한칸씩 앞으로 
			List_all--;
		}
		list = fopen("Infromation of a student.txt","w");
		for(c=0;c<List_all;c++){		
			fprintf(list,"%-10s %-10s %-10s %-10s\n",StudentInfo[c].id, StudentInfo[c].name, StudentInfo[c].department, StudentInfo[c].PhoneNumber);	
		}	
		fclose(list);
	}
}