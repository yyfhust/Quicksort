#include "Sqlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LIST_INIT_SIZE 100          //���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT 10           //���Ա�洢�ռ��������
extern int time;
void InitList_Sq(SqList &L)
{//����һ���յ����Ա�L
	L.elem = (int *)malloc(LIST_INIT_SIZE*sizeof(int));      //�����ʼ�洢�ռ�
	if (!L.elem)
	{//�ж��Ƿ����ɹ�
		printf("�洢�ռ����ʧ�ܣ� \n");
		exit(0);
	}
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
}//InitList_Sq

void Creat_Sq(SqList &L)
{//�������Ա�
	int i = 0;
	FILE *fp;
	char ch;
	error1:printf("		�������ļ��� :   ");
	char FileName[100];
	gets_s(FileName);
	if ((fp = fopen(FileName, "rt")) == NULL)
	{
		printf("�޷���ָ���ļ������������룺");
		goto error1;
	}
	char str[10];
	int bad_flg = 0;    //�������
	do {
		fgets(str, 10, fp);
		int len = strlen(str);
		for (int i = 0; i < len; i++)
		{
			if (!isdigit(str[i])&&str[i]!=' '&&str[i]!='\n'&&str[i]!='	') {
				bad_flg = 1;
				printf("�����ļ�����ȫ����������������ѡ���ļ���\n");
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
{//��ӡLȫ��Ԫ��
	FILE *fp;
	int i;
	error2:printf("		����������ļ� :   ");
	char FileName[100];
	gets_s(FileName);
	if ((fp = fopen(FileName, "wt+")) == NULL)
	{
		printf("�޷���ָ���ļ������������룺 \n");
		goto error2;
	}
	fprintf(fp,"\n ������Ϊ : ");
	for (i = 0; i < L.length; i++)
	{
		fprintf(fp," %d ", L.elem[i]);
	}
	fprintf(fp,"\n �Ƚϴ���Ϊ :  %d", time);
	printf("\n		���������ָ���ļ�!\n");
	fclose(fp);
}