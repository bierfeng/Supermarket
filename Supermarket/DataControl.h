#pragma once

#define NUM 101    //��ഢ����Ʒ��Ϣ��
static int n = 0;


struct Goods
{
	int num;     //���
	char name[100];		  //��Ʒ��
	float in_price;		  //����
	float out_price;	  //�ۼ�
	int amount;			  //����
}temp[NUM] , cancles[NUM];

void goods_read(void);
void goods_write(void);


