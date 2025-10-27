#include "headfiles.h"


extern struct Goods temp[NUM];

int main()
{
	goods_read();
	screen_main();
	goods_write();
	return 0;
}

