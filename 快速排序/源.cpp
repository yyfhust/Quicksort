#include "all_header.h"
int time;        //全局变量，保存次数
int main()
{
	SqList L;
	printf("\n\n                             << ==================快 速 排 序=============== >>  \n\n\n");
	InitList_Sq(L);    //初始化空表L
	Creat_Sq(L);             //创建L
	QSort(L, 0, L.length-1);
	ListTraverse(L);
	putchar('\n');
	system("pause");
	return 0;
}