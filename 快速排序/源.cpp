#include "all_header.h"
int time;        //ȫ�ֱ������������
int main()
{
	SqList L;
	printf("\n\n                             << ==================�� �� �� ��=============== >>  \n\n\n");
	InitList_Sq(L);    //��ʼ���ձ�L
	Creat_Sq(L);             //����L
	QSort(L, 0, L.length-1);
	ListTraverse(L);
	putchar('\n');
	system("pause");
	return 0;
}