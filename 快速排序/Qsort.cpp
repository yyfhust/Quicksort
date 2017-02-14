#include "Sqlist.h"
extern int time;

int Partition(SqList &L, int low, int high)
{//交换L中子表L.elem[low..high]的记录，使枢轴记录到位，并返回其所在位置，此时在它前（后）的记录均不小于（大于）它
	int pivotkey = L.elem[low];             //枢轴记录关键字,初始值取子表首元素
	while (low < high)
	{//从表两端交替向中间扫描
		while (low < high && L.elem[high] >= pivotkey)
		{
			--high;
			++time;
		}
		L.elem[low] = L.elem[high];        //将比枢轴小的移到低端
		while (low < high && L.elem[low] <= pivotkey)
		{
			++low;
			++time;
		}
		L.elem[high] = L.elem[low];       //将比枢轴大的移到高端
	}
	L.elem[low] = pivotkey;            //枢轴记录到位
	return low;                //返回枢轴位置
}//Partition

void QSort(SqList &L, int low, int high)
{//对线性表L的子序列L.elem[low..high]作快速排序

	int pivoteloc;
	if (low < high)   //非空表
	{
		pivoteloc = Partition(L, low, high);        //把L.elem[low..high]一分为二
		QSort(L, low, pivoteloc - 1);               //对左侧子表递归排序
		QSort(L, pivoteloc + 1, high);               //对右侧子表递归排序
	}
}//Qsort
