#pragma once

#define NUM 101    //最多储存商品信息数
static int n = 0;


struct Goods
{
	int num;     //编号
	char name[100];		  //商品名
	float in_price;		  //进价
	float out_price;	  //售价
	int amount;			  //数量
}temp[NUM] , cancles[NUM];

void goods_read(void);
void goods_write(void);


