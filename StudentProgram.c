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
	int menu_number;//�޴� �Է¹���
	int newStudent;

	int List_all=0;//�ؽ�Ʈ������ �� ����Ʈ �� 
	int AddListNum=0;//�ּҷ��� �߰��ϴ� �޴����� �߰��� �� ���� f���� �ö�
	struct list data[1000];
	char str[10];
	FILE *list;

	while(1)
	{
		printf("1.�л����� �߰�\n");
		printf("2.����\n");

		scanf("%d",&menu_number);
		switch(menu_number)
		{

		case 1:
			newStudent=List_all+AddListNum;
			list = fopen("�׽�Ʈ�׽�Ʈ����.txt","a+");
			printf("�й�:");
			scanf("%s",data[newStudent].id);
			printf("�̸�:");
			scanf("%s",data[newStudent].name);
			printf("�а�:");
			scanf("%s",data[newStudent].department);
			printf("��ȭ��ȣ:");
			scanf("%s",data[newStudent].PhoneNumber);
			gets(str);

			fprintf(list,"%-10s %-10s %-10s %-10s\n",data[newStudent].id, data[newStudent].name, data[newStudent].department, data[newStudent].PhoneNumber);
			printf("�Է¼���\n");
			fclose(list);
			AddListNum++;
			break;

		case 2:
			exit(0);
			}
			}

	return 0;
}