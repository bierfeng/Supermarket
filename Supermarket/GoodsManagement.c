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
		printf("输入错误，请输入1到%d之间的数！",NUM);
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
			
			printf("编号     品名    进价    售价    库存数量\r\n");
			printf("%2.d      %s    %.2f  %.2f       %d\r\n\r\n",
				temp[i].num,
				temp[i].name,
				temp[i].in_price,
				temp[i].out_price,
				temp[i].amount);
		}
	}
	printf("---------------------------------------------\r\n");
	printf("继续:\r\n");
	scanf("%d", &i);
	system("cls");
	screen_show();
	
}

void goods_show(void)
{
	int i;
	printf("商品搜索\r\n");
	printf("请输入要搜索的商品编号(1 ~ 99)或者名称\r\n");
	printf("商品编号：");
	printf("商品名称：");
	getchar();//过滤回车
	scanf("%d", &i);
	if (temp[i].num == 0 && temp[i].num >= NUM)
	{
		printf("无此商品\r\n");
		system("cls");
		screen_show();
	}
	else
	{
		printf("---------------------------------------------\r\n");
		printf("编号     品名    进价    售价    库存数量\r\n");
		printf("%2.d      %s    %.2f  %.2f       %d\r\n",
			temp[i].num,
			temp[i].name,
			temp[i].in_price,
			temp[i].out_price,
			temp[i].amount
			  );
		printf("---------------------------------------------\r\n");
		printf("继续:\r\n");
		scanf("%d", &i);
		system("cls");
		screen_show();
		
	}
	

}