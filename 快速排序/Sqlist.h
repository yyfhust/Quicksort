#pragma once
#ifndef SQLIST
#define SQLIST

typedef struct
{//˳���ṹ����
	int *elem;                     //�洢�ռ����ַ
	int length;                     //��ǰ����
	int listsize;                   //��ǰ����Ĵ洢��������sizeof��int��Ϊ��λ��
}SqList;

extern void InitList_Sq(SqList &L);
extern void Creat_Sq(SqList &L);
extern void ListTraverse(SqList L);

#endif // !SQLIST

