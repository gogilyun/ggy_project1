#include<stdio.h>
#include<stdlib.h>
#include<string.h>//1

<<<<<<< HEAD
struct list{
=======
<<<<<<< HEAD
<<<<<<< HEAD
struct list//hotfix
=======
struct list//hotfix2
>>>>>>> hotfix
{
=======
struct list{//iss53 branch
>>>>>>> iss53
>>>>>>> 82f851f2f4d35b213c4691512c71fbaa3f4fd270
	char id[20];
	char name[20];
	char department[30];
	char PhoneNumber[20];
};

int c,i;
int Menu_Number;
int NewStudent;
int ForModify;
int ForRemove=0;
int List_all=0;
int AddListNum=0;
struct list data[1000];
char str[10];

FILE *list;

void ListView();
void StudentSearch();
void StudentAdd();
void StudentUpdate();
void StudentDelete();

int main()
{
<<<<<<< HEAD

	while(1){
		printf("\n1.List View\n");
		printf("2.Student Search\n");
		printf("3.Student Add\n");
		printf("4.Student Update\n");
		printf("5.Student Delete\n");
		printf("6.End\n\n");
		printf("Input Number : ");
		scanf("%d",&Menu_Number);

=======

<<<<<<< HEAD
	int newStudent;
	int ForModify;

	int List_all=0;//텍스트파일의 총 리스트 수 
	int AddListNum=0;//주소록을 추가하는 메뉴에서 추가될 때 마다 f값이 올라감
	struct list data[1000];
	char str[10];
	FILE *list;

	while(1)
	{
		printf("1.학생정보 보기\n");
		printf("2.학생정보 검색\n");
		printf("3.학생정보 추가\n");
		printf("4.학생정보 수정\n");
		printf("5.종료\n");

		scanf("%d",&menu_number);
		switch(menu_number)
		{
=======
	while(1){
		printf("\n1.List View\n");
		printf("2.Student Search\n");
		printf("3.Student Add\n");
		printf("4.Student Update\n");
		printf("5.Student Delete\n");
		printf("6.End\n\n");
		printf("Input Number : ");
		scanf("%d",&Menu_Number);
>>>>>>> iss53

>>>>>>> 82f851f2f4d35b213c4691512c71fbaa3f4fd270
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
<<<<<<< HEAD
			StudentDelete();
			break;
		case 6:
=======
<<<<<<< HEAD
=======
			StudentDelete();
			break;
		case 6:
>>>>>>> iss53
>>>>>>> 82f851f2f4d35b213c4691512c71fbaa3f4fd270
			exit(0);
		}
	}
	return 0;
}

void ListView(void){
	list=fopen("Infromation of a student.txt","r");

	for(List_all=0;;List_all++){
		fscanf(list,"%s %s %s %s",&data[List_all].id, &data[List_all].name, &data[List_all].department, &data[List_all].PhoneNumber);
		
		if(feof(list)){	
			break;
		}
	}
	printf("------------------------------------------------\n");
	printf("[ID/ NAME/DEPARTMENT/PHONENUMBER]\n");
	printf("------------------------------------------------\n");
	for(c=0;c<List_all;c++)		
		printf("%-10s %-10s %-10s %-10s\n",data[c].id, data[c].name, data[c].department, data[c].PhoneNumber);	
	fclose(list);
}

void StudentSearch(void){
	list = fopen("Infromation of a student.txt","r");		
	printf("Input ID : ");	
	scanf("%s",str);
	
	for(c=0;c<List_all;c++)	
		if(strncmp(data[c].id,str,6)==0){		
			printf("* ID:%s\n* Name:%s\n* Department:%s\n* PhoneNumber:%s\n",data[c].id,data[c].name,data[c].department,data[c].PhoneNumber);	
		}
}

void StudentAdd(void){
	NewStudent=List_all+AddListNum;
	list = fopen("Infromation of a student.txt","a+");

	printf("ID:");		
	scanf("%s",data[NewStudent].id);	
	printf("Name:");	
	scanf("%s",data[NewStudent].name);
	printf("Department:");
	scanf("%s",data[NewStudent].department);
	printf("PhoneNumber:");
	scanf("%s",data[NewStudent].PhoneNumber);
	gets(str);

	fprintf(list,"%-10s %-10s %-10s %-10s\n",data[NewStudent].id, data[NewStudent].name, data[NewStudent].department, data[NewStudent].PhoneNumber);
	printf("Successfully done!\n");
	
	fclose(list);
	AddListNum++;
}

void StudentUpdate(void){
	printf("Input ID : ");
	scanf("%s",str);

	for(i=0;i<List_all;i++){
		if(strncmp(data[i].id,str,7)==0){	
			ForModify=i;
<<<<<<< HEAD
			printf("Phone Number : ");	
			scanf("%s",&data[ForModify].PhoneNumber);
			printf("Successfully done!\n");	
			list=fopen("Infromation of a student.txt","w");

			for(c=0;c<List_all;c++){
				fprintf(list,"%-10s %-10s %-10s %-10s\n",data[c].id, data[c].name, data[c].department, data[c].PhoneNumber);
			}
		}	
	}
	fclose(list);

}

void StudentDelete(void){
	printf("Input ID : ");
	scanf("%s",&str);
			
	for(i=0;i<List_all;i++){		
		if(strncmp(data[i].id,str,7)==0){		
			for(ForRemove=i;ForRemove<=List_all;ForRemove++){	
				strcpy(data[ForRemove].id,data[ForRemove+1].id);
				strcpy(data[ForRemove].name,data[ForRemove+1].name);
				strcpy(data[ForRemove].department,data[ForRemove+1].department);
				strcpy(data[ForRemove].PhoneNumber,data[ForRemove+1].PhoneNumber);
			}
			List_all--;
		}
		list = fopen("Infromation of a student.txt","w");
=======
		}
	}

	printf("Phone Number : ");	
	scanf("%s",&data[ForModify].PhoneNumber);
	printf("Successfully done!\n");	

	list=fopen("Infromation of a student.txt","w");
	for(c=0;c<List_all;c++){
		fprintf(list,"%-10s %-10s %-10s %-10s\n",data[c].id, data[c].name, data[c].department, data[c].PhoneNumber);
	}	
	fclose(list);
}

void StudentDelete(void){
	printf("Input ID : ");
	scanf("%s",&str);
			
	for(i=0;i<List_all;i++){		
		if(strncmp(data[i].id,str,7)==0){		
			for(ForRemove=i;ForRemove<=List_all;ForRemove++){	
				strcpy(data[ForRemove].id,data[ForRemove+1].id);
				strcpy(data[ForRemove].name,data[ForRemove+1].name);
				strcpy(data[ForRemove].department,data[ForRemove+1].department);
				strcpy(data[ForRemove].PhoneNumber,data[ForRemove+1].PhoneNumber);
			}
			List_all--;
		}
		list = fopen("Infromation of a student.txt","w");

>>>>>>> 82f851f2f4d35b213c4691512c71fbaa3f4fd270
		for(c=0;c<List_all;c++){		
			fprintf(list,"%-10s %-10s %-10s %-10s\n",data[c].id, data[c].name, data[c].department, data[c].PhoneNumber);	
		}	
		fclose(list);
	}
}