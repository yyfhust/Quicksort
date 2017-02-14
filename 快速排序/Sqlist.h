#pragma once
#ifndef SQLIST
#define SQLIST

typedef struct
{//顺序表结构定义
	int *elem;                     //存储空间基地址
	int length;                     //当前长度
	int listsize;                   //当前分配的存储容量（以sizeof（int）为单位）
}SqList;

extern void InitList_Sq(SqList &L);
extern void Creat_Sq(SqList &L);
extern void ListTraverse(SqList L);

#endif // !SQLIST

