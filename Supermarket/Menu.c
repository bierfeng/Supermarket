#include "headfiles.h"


//
//���ܲ˵�-����Ա
//
void screen_main(void)
{
	int select1 = 0;
	system("cls");
	printf("\r\n");

	printf("\t\t\t\t\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\r\n");
	printf("\t\t\t\t\t|-------------���й���ϵͳ-------------|\r\n");
	printf("\t\t\t\t\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\r\n");

	printf("\r\n\r\n\r\n");

	printf("\t\t\t\t\t1.���������Ϣ\n");
	printf("\t\t\t\t\t2.��ʾ�����Ϣ\n");
	printf("\t\t\t\t\t3.���ﳵ\n");
	printf("\t\t\t\t\t0.���沢�˳�\n");

	printf("\r\n\r\n");

	printf("\t\t\t\t\t��ѡ�������");

	scanf_s("%d",&select1, (int)sizeof(select1)); //��Ч��ֹ���������

	printf("\r\n");

	switch (select1)
	{
		case 1:/*���������Ϣ*/ screen_add(); break;
		case 2:/*��ʾ�����Ϣ*/screen_show(); break;
		case 3:/*���ﳵ*/shop_cart(); break;
		case 0:/*�˳�*/ break;

		default: {
			printf("\t\t\t\t\t**��������������ѡ��**\n");

			system("cls");           //��ս���
			printf("\r\n");
			screen_main();
		}break;
	}

	
	
}

void screen_add(void)
{
	int i = 0;
	system("cls");
	printf("\r\n");
	printf("��Ʒ����\r\n");
	printf("������Ҫ���ӵ���Ʒ��Ϣ(1 ~ 99)\r\n");
	printf("��Ʒ��ţ�");
	scanf("%d", &i);
	if (i >= NUM && i <= 0)
	{
		printf("��ų�����Χ");
		exit(0);
	}
	else
	{
		temp[i].num = i;
		printf("��Ʒ���ƣ�");
		scanf("%s", temp[i].name);
		printf("��Ʒ���ۣ�");
		scanf("%f", &temp[i].in_price);
		printf("��Ʒ�ۼ�:");
		scanf("%f", &temp[i].out_price);
		printf("��Ʒ��棺");
		scanf("%d", &temp[i].amount);
		system("cls");
		printf("\r\n");
		printf("��Ʒ��Ϣ���ӳɹ�����ѡ����һ������\r\n");

	}
	screen_main();
}

void screen_show(void)
{
	int select = 0;
	system("cls");
	printf("\r\n");
	printf("��Ʒ��ʾ\r\n");
	printf("\t\t\t\t\t1.��ʾ������Ʒ\n");
	printf("\t\t\t\t\t2.������Ʒ\n");
	printf("\t\t\t\t\t0.�˳�\n");
	scanf_s("%d", &select, (int)sizeof(select)); //��Ч��ֹ���������
	printf("\r\n");
	switch (select)
	{
	case 1:/*��ʾ������Ʒ*/ goods_show_all(); break;
	case 2:/*������Ʒ*/goods_show(); break;
	case 0:/*�˳�*/
	{
		system("cls");
		screen_main();
		break;
	}
	default: {
		printf("\t\t\t\t\t**��������������ѡ��**\n");

		system("cls");           //��ս���
		printf("\r\n");
		screen_show();
			 }
	}
}