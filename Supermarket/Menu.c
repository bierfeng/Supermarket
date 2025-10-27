#include "headfiles.h"


//
//功能菜单-管理员
//
void screen_main(void)
{
	int select1 = 0;
	system("cls");
	printf("\r\n");

	printf("\t\t\t\t\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\r\n");
	printf("\t\t\t\t\t|-------------超市管理系统-------------|\r\n");
	printf("\t\t\t\t\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\r\n");

	printf("\r\n\r\n\r\n");

	printf("\t\t\t\t\t1.建立库存信息\n");
	printf("\t\t\t\t\t2.显示库存信息\n");
	printf("\t\t\t\t\t3.购物车\n");
	printf("\t\t\t\t\t0.保存并退出\n");

	printf("\r\n\r\n");

	printf("\t\t\t\t\t请选择操作：");

	scanf_s("%d",&select1, (int)sizeof(select1)); //有效防止缓冲区溢出

	printf("\r\n");

	switch (select1)
	{
		case 1:/*建立库存信息*/ screen_add(); break;
		case 2:/*显示库存信息*/screen_show(); break;
		case 3:/*购物车*/shop_cart(); break;
		case 0:/*退出*/ break;

		default: {
			printf("\t\t\t\t\t**操作错误，请重新选择**\n");

			system("cls");           //清空界面
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
	printf("商品增加\r\n");
	printf("请输入要增加的商品信息(1 ~ 99)\r\n");
	printf("商品编号：");
	scanf("%d", &i);
	if (i >= NUM && i <= 0)
	{
		printf("编号超出范围");
		exit(0);
	}
	else
	{
		temp[i].num = i;
		printf("商品名称：");
		scanf("%s", temp[i].name);
		printf("商品进价：");
		scanf("%f", &temp[i].in_price);
		printf("商品售价:");
		scanf("%f", &temp[i].out_price);
		printf("商品库存：");
		scanf("%d", &temp[i].amount);
		system("cls");
		printf("\r\n");
		printf("商品信息增加成功，请选择下一步操作\r\n");

	}
	screen_main();
}

void screen_show(void)
{
	int select = 0;
	system("cls");
	printf("\r\n");
	printf("商品显示\r\n");
	printf("\t\t\t\t\t1.显示所有商品\n");
	printf("\t\t\t\t\t2.搜索商品\n");
	printf("\t\t\t\t\t0.退出\n");
	scanf_s("%d", &select, (int)sizeof(select)); //有效防止缓冲区溢出
	printf("\r\n");
	switch (select)
	{
	case 1:/*显示所有商品*/ goods_show_all(); break;
	case 2:/*搜索商品*/goods_show(); break;
	case 0:/*退出*/
	{
		system("cls");
		screen_main();
		break;
	}
	default: {
		printf("\t\t\t\t\t**操作错误，请重新选择**\n");

		system("cls");           //清空界面
		printf("\r\n");
		screen_show();
			 }
	}
}