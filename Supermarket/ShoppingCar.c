#include "headfiles.h"

struct item_node* cart;
//���ﳵ������Ӷ�����������һ��ɾ���Ѿ���ӵ���Ʒ�Ĺ��ܣ�Ŀǰ��û����
//      �ַ���  �ַ���  float float  int
//��Ʒ  ����  ��Ʒ���  ����  �ۼ�   ����
//���ﳵ
struct item_node
{
	struct Goods wanted;//�������Ʒ
	int amount;//��������
	struct item_node* next;
};

//���ﳵʵ�ֺ���
void shop_cart(void)
{
	system("cls");//��������������
	while (1)
	{
		switch (screen_cart())
		{
		case 1://��ʾ��ǰ��Ʒ�б�
			display_cart();
			break;  
		case 2://�����Ʒ�����ﳵ
			shoppingcar_add();
			break;
		case 3:cart_balance(); break;//����
		case 0:return;
		}
	}
}
//���ﳵ�˵�����
int screen_cart(void)
{
	int select;//��������
	system("cls");
	printf("��ѡ����Ҫִ�еĲ���:\n");
	printf("--------------------------\n");
	printf("1.��ʾ��ǰ���ﳵ�б�\n");
	printf("2.�����Ʒ�����ﳵ\n");
	printf("3.����\n");
	printf("0.�˳���ǰ����\n");
	printf("--------------------------\n");

	while (1) {
		scanf("%d", &select);//�����������
		if (select < 0 || select > 3)
		{
			printf("û�д�����������������룺\n");
		}
		else break;
	}
	return select;
}
//�����Ʒ
void shoppingcar_add(void)
{
	char str[20];//��Ʒ���ֵ��ַ���
	int m;
	int i;
	char choice,choice2;
	struct item_node* p1,*p;
	do{
		printf("��ѡ������������Ʒ������:\r\n");
		fflush(stdin);
		scanf("%s", str);
		
		for (i = 1; i <= NUM; i++)
		{
			if (strcmp(temp[i].name, str) == 0 && temp[i].amount != 0)
			{
				printf("�Ѿ��ҵ�������Ʒ: \n");
				printf("------------------------------\n");
				printf("���\tƷ��\t����\t�������\n");
				printf("%d%9s%9.2f%9d\n", temp[i].num, temp[i].name, temp[i].out_price, temp[i].amount);
				printf("����������Ҫ������: \n");
				scanf("%d", &m);
				if (m > temp[i].amount)//�Կ���ȱ������ж�
				{
					printf("��治��\n");
					break;
				}
				printf("�Ƿ���(Y/N)\n");
				//fflush(stdin);
				getchar();//���˻س�
				scanf("%c", &choice);
				if (choice == 'Y' || choice == 'y')
				{
					p1 = (struct item_node*)malloc(sizeof(struct item_node));//���빺�ﳵ�ڴ�
					if(p1 == NULL)
					{
						printf("�ڴ�����ʧ�ܣ�\n");
						exit(1);
					}
					p1->amount = m;
					p1->wanted = temp[i];
					p1->next = NULL;
					p = cart;
					if (cart == NULL) cart = p1;
					else
					{
						while (p->next != NULL) p = p->next;
						p->next = p1;
					} 
				}
				break;
			}

		}
		
		if(i == NUM)
		{
			printf("δ�ҵ�������Ʒ\n");
		}
		printf("�Ƿ��������?(Y/N):\n");
		//fflush(stdin);
		getchar();//���˻س�
		scanf("%c", &choice2);
	} while (choice2=='Y'||choice2=='y');
}
//�����б���ʾ����
void display_cart(void)
{
	struct item_node* p = cart;
	if (p == NULL)
	{
		printf("���ﳵΪ��\n");
		return;
	}
	while (p != NULL)
	{
		printf("------------------------------\n");
		printf("���\tƷ��\t����\t����\n");
		printf("%d%9s%9.2f%9d\n", p->wanted.num, p->wanted.name, p->wanted.out_price, p->amount);
		p = p->next;//��ת����һ�ڵ�ֱ���ѹ��ﳵ����嵥ȫ����ʾ
	}
}
//����
void cart_balance(void)
{
	float total_price = 0, clinic_pay, finally_pay;//��Ӵ��۹���
	struct item_node* p = cart;
	printf("�����ǹ����嵥:\r\n");
	display_cart();
	

	while (p != NULL)
	{
		total_price += p->wanted.out_price * p->amount;
		for (int i = 1;i < NUM; i++)
		{
			if (strcmp(temp[i].name, p->wanted.name) == 0)
			{
				temp[i].amount -= p->amount;
			}
			
		}
		p = p->next;
	}
	printf("�ܼ�:%7.2f\r\n", total_price);
	printf("����֧�����:");
	scanf("%f", &clinic_pay);
	printf("ʵ��֧��:%7.2f\t\t����:%7.2f", clinic_pay, clinic_pay - total_price);
	int i;
	printf("�����������:");
	scanf("%d", i);
	return;
}