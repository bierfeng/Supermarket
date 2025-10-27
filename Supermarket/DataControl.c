#include "headfiles.h"

void goods_read(void)
{
	FILE* fp;
	if ((fp = fopen("goods.txt", "r")) == NULL)
	{
		printf("读取文件失败\r\n");

		exit(0);
	}
	
	while (!feof(fp))
	{
		fscanf(fp, "%d %s %f %f %d\n", &temp[n].num, temp[n].name, &temp[n].in_price, &temp[n].out_price, &temp[n].amount);
		
		n++;
	}
	fclose(fp);

}

void goods_write(void)
{
	FILE* fp;
	if ((fp = fopen("goods.txt", "w")) == NULL)
	{
		printf("打开文件失败\r\n");

		exit(0);
	}
	for (int j = 0; j < NUM; j++)                               
		{
			fprintf(fp, "%d %s %f %f %d\n", temp[j].num, temp[j].name, temp[j].in_price, temp[j].out_price, temp[j].amount);
			
		}
	//待添加：检查写入是否成功

	fclose(fp);
}



