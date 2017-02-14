#include "Sqlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LIST_INIT_SIZE 100          //线性表存储空间的初始分配量
#define LISTINCREMENT 10           //线性表存储空间分配增量
extern int time;
void InitList_Sq(SqList &L)
{//构造一个空的线性表L
	L.elem = (int *)malloc(LIST_INIT_SIZE*sizeof(int));      //分配初始存储空间
	if (!L.elem)
	{//判断是否分配成功
		printf("存储空间分配失败！ \n");
		exit(0);
	}
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
}//InitList_Sq

void Creat_Sq(SqList &L)
{//创建线性表
	int i = 0;
	FILE *fp;
	char ch;
	error1:printf("		请输入文件名 :   ");
	char FileName[100];
	gets_s(FileName);
	if ((fp = fopen(FileName, "rt")) == NULL)
	{
		printf("无法打开指定文件，请重新输入：");
		goto error1;
	}
	char str[10];
	int bad_flg = 0;    //输入错误
	do {
		fgets(str, 10, fp);
		int len = strlen(str);
		for (int i = 0; i < len; i++)
		{
			if (!isdigit(str[i])&&str[i]!=' '&&str[i]!='\n'&&str[i]!='	') {
				bad_flg = 1;
				printf("给定文件不是全都是整数，请重新选择文件！\n");
				goto error1;
			}
			bad_flg = 0;
		}
	} while (bad_flg);
	i = 0;
	rewind(fp);
	do {
		fscanf(fp,"%d", &L.elem[i]);
		i++;
	} while (feof(fp) ==0);
	L.length = i;
	fclose(fp);
}//Creat_Sq

void ListTraverse(SqList L)
{//打印L全部元素
	FILE *fp;
	int i;
	error2:printf("		请输入输出文件 :   ");
	char FileName[100];
	gets_s(FileName);
	if ((fp = fopen(FileName, "wt+")) == NULL)
	{
		printf("无法打开指定文件，请重新输入： \n");
		goto error2;
	}
	fprintf(fp,"\n 排序结果为 : ");
	for (i = 0; i < L.length; i++)
	{
		fprintf(fp," %d ", L.elem[i]);
	}
	fprintf(fp,"\n 比较次数为 :  %d", time);
	printf("\n		结果已输入指定文件!\n");
	fclose(fp);
}