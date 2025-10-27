#include "headfiles.h"

struct item_node* cart;
//购物车除了添加东西还可以做一个删除已经添加的物品的功能（目前还没做）
//      字符串  字符串  float float  int
//商品  名字  商品编号  进阶  售价   数量
//购物车
struct item_node
{
	struct Goods wanted;//想买的商品
	int amount;//购买数量
	struct item_node* next;
};

//购物车实现函数
void shop_cart(void)
{
	system("cls");//清屏，美化界面
	while (1)
	{
		switch (screen_cart())
		{
		case 1://显示当前商品列表
			display_cart();
			break;  
		case 2://添加商品到购物车
			shoppingcar_add();
			break;
		case 3:cart_balance(); break;//结算
		case 0:return;
		}
	}
}
//购物车菜单函数
int screen_cart(void)
{
	int select;//操作变量
	system("cls");
	printf("请选择您要执行的操作:\n");
	printf("--------------------------\n");
	printf("1.显示当前购物车列表\n");
	printf("2.添加商品到购物车\n");
	printf("3.结算\n");
	printf("0.退出当前界面\n");
	printf("--------------------------\n");

	while (1) {
		scanf("%d", &select);//输入操作变量
		if (select < 0 || select > 3)
		{
			printf("没有此项操作，请重新输入：\n");
		}
		else break;
	}
	return select;
}
//添加商品
void shoppingcar_add(void)
{
	char str[20];//物品名字的字符串
	int m;
	int i;
	char choice,choice2;
	struct item_node* p1,*p;
	do{
		printf("请选择输入所需商品的名称:\r\n");
		fflush(stdin);
		scanf("%s", str);
		
		for (i = 1; i <= NUM; i++)
		{
			if (strcmp(temp[i].name, str) == 0 && temp[i].amount != 0)
			{
				printf("已经找到所需物品: \n");
				printf("------------------------------\n");
				printf("编号\t品名\t单价\t库存数量\n");
				printf("%d%9s%9.2f%9d\n", temp[i].num, temp[i].name, temp[i].out_price, temp[i].amount);
				printf("请输入所需要的数量: \n");
				scanf("%d", &m);
				if (m > temp[i].amount)//对库存短缺情况的判断
				{
					printf("库存不足\n");
					break;
				}
				printf("是否购买？(Y/N)\n");
				//fflush(stdin);
				getchar();//过滤回车
				scanf("%c", &choice);
				if (choice == 'Y' || choice == 'y')
				{
					p1 = (struct item_node*)malloc(sizeof(struct item_node));//申请购物车内存
					if(p1 == NULL)
					{
						printf("内存申请失败！\n");
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
			printf("未找到所需物品\n");
		}
		printf("是否继续购物?(Y/N):\n");
		//fflush(stdin);
		getchar();//过滤回车
		scanf("%c", &choice2);
	} while (choice2=='Y'||choice2=='y');
}
//购物列表显示函数
void display_cart(void)
{
	struct item_node* p = cart;
	if (p == NULL)
	{
		printf("购物车为空\n");
		return;
	}
	while (p != NULL)
	{
		printf("------------------------------\n");
		printf("编号\t品名\t单价\t数量\n");
		printf("%d%9s%9.2f%9d\n", p->wanted.num, p->wanted.name, p->wanted.out_price, p->amount);
		p = p->next;//跳转到下一节点直到把购物车里的清单全部显示
	}
}
//结算
void cart_balance(void)
{
	float total_price = 0, clinic_pay, finally_pay;//添加打折功能
	struct item_node* p = cart;
	printf("以下是购物清单:\r\n");
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
	printf("总计:%7.2f\r\n", total_price);
	printf("输入支付金额:");
	scanf("%f", &clinic_pay);
	printf("实际支付:%7.2f\t\t找零:%7.2f", clinic_pay, clinic_pay - total_price);
	int i;
	printf("按任意键返回:");
	scanf("%d", i);
	return;
}