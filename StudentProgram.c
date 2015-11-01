#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct list
{
	char id[20];
	char name[20];
	char department[30];
	char PhoneNumber[20];
};

int main()
{
	int menu_number;//메뉴 입력받음
	int newStudent;

	int List_all=0;//텍스트파일의 총 리스트 수 
	int AddListNum=0;//주소록을 추가하는 메뉴에서 추가될 때 마다 f값이 올라감
	struct list data[1000];
	char str[10];
	FILE *list;

	while(1)
	{
		printf("1.학생정보 추가\n");
		printf("2.종료\n");

		scanf("%d",&menu_number);
		switch(menu_number)
		{

		case 1:
			newStudent=List_all+AddListNum;
			list = fopen("테스트테스트파일.txt","a+");
			printf("학번:");
			scanf("%s",data[newStudent].id);
			printf("이름:");
			scanf("%s",data[newStudent].name);
			printf("학과:");
			scanf("%s",data[newStudent].department);
			printf("전화번호:");
			scanf("%s",data[newStudent].PhoneNumber);
			gets(str);

			fprintf(list,"%-10s %-10s %-10s %-10s\n",data[newStudent].id, data[newStudent].name, data[newStudent].department, data[newStudent].PhoneNumber);
			printf("입력성공\n");
			fclose(list);
			AddListNum++;
			break;

		case 2:
			exit(0);
			}
			}

	return 0;
}