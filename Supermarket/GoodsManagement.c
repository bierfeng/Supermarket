#include "headfiles.h"



void goods_clean_all(void)
{

	for (int i = 0; i < 101; i++)
	{
		temp[i].num = 0;
		strcpy(temp[i].name, "temp");
		temp[i].in_price = 0;
		temp[i].out_price = 0;
		temp[i].amount = 0;
	}

}

void goods_clean(void)
{
	int i;
	scanf("%d", &i);
	if (i > NUM || i <= 0)
	{
		printf("�������������1��%d֮�������",NUM);
		return;
	}
	else
	{
		temp[i].num = 0;
		strcpy(temp[i].name, "temp");
		temp[i].in_price = 0;
		temp[i].out_price = 0;
		temp[i].amount = 0;

	}
}

void goods_show_all(void)
{
	int i;
	printf("---------------------------------------------\r\n");
	for (i = 0; i < 101; i++)
	{
		if (temp[i].num < NUM && temp[i].num > 0)
		{
			
			printf("���     Ʒ��    ����    �ۼ�    �������\r\n");
			printf("%2.d      %s    %.2f  %.2f       %d\r\n\r\n",
				temp[i].num,
				temp[i].name,
				temp[i].in_price,
				temp[i].out_price,
				temp[i].amount);
		}
	}
	printf("---------------------------------------------\r\n");
	printf("����:\r\n");
	scanf("%d", &i);
	system("cls");
	screen_show();
	
}

void goods_show(void)
{
	int i;
	printf("��Ʒ����\r\n");
	printf("������Ҫ��������Ʒ���(1 ~ 99)��������\r\n");
	printf("��Ʒ��ţ�");
	printf("��Ʒ���ƣ�");
	getchar();//���˻س�
	scanf("%d", &i);
	if (temp[i].num == 0 && temp[i].num >= NUM)
	{
		printf("�޴���Ʒ\r\n");
		system("cls");
		screen_show();
	}
	else
	{
		printf("---------------------------------------------\r\n");
		printf("���     Ʒ��    ����    �ۼ�    �������\r\n");
		printf("%2.d      %s    %.2f  %.2f       %d\r\n",
			temp[i].num,
			temp[i].name,
			temp[i].in_price,
			temp[i].out_price,
			temp[i].amount
			  );
		printf("---------------------------------------------\r\n");
		printf("����:\r\n");
		scanf("%d", &i);
		system("cls");
		screen_show();
		
	}
	

}