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
	int c;//c�� ����Ʈ�� cmdâ�� ����Ʈ�� ������ŭ ����ϱ� ���� for���� ���� i����
	int i;//for loop�ȿ��� ���̴� i
	int newStudent;

	int List_all=0;//�ؽ�Ʈ������ �� ����Ʈ �� 
	int AddListNum=0;//�ּҷ��� �߰��ϴ� �޴����� �߰��� �� ���� f���� �ö�
	struct list data[1000];
	char str[10];
	FILE *list;

	while(1)
	{
		printf("1.�л����� ����\n");
		printf("2.�л����� �˻�\n");
		printf("3.�л����� �߰�\n");
		printf("4.����\n");

		scanf("%d",&menu_number);
		switch(menu_number)
		{

		case 1:
			list=fopen("�׽�Ʈ�׽�Ʈ����.txt","r");
			for(List_all=0;;List_all++)
			{
				fscanf(list,"%s %s %s %s",&data[List_all].id, &data[List_all].name, &data[List_all].department, &data[List_all].PhoneNumber);
				
				if(feof(list))
				{
					break;
				}
			}

			for(c=0;c<List_all;c++)
				printf("%-10s %-10s %-10s %-10s\n",data[c].id, data[c].name, data[c].department, data[c].PhoneNumber);

			fclose(list);
			break;

		case 2:
			list = fopen("�׽�Ʈ�׽�Ʈ����.txt","r");
			printf("�й��� �Է��ϼ���");
			scanf("%s",str);
			for(c=0;c<List_all;c++)
				if(strncmp(data[c].id,str,6)==0)
				{
					printf("�̸�:%s\n�й�:%s\n��ȣ:%s\n�ּ�:%s\n",data[c].id,data[c].name,data[c].department,data[c].PhoneNumber);	
				}
			
			break;

		case 3:
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

		case 4:
			exit(0);
			}
			}

	return 0;
}
