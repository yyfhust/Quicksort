#include "Sqlist.h"
extern int time;

int Partition(SqList &L, int low, int high)
{//����L���ӱ�L.elem[low..high]�ļ�¼��ʹ�����¼��λ��������������λ�ã���ʱ����ǰ���󣩵ļ�¼����С�ڣ����ڣ���
	int pivotkey = L.elem[low];             //�����¼�ؼ���,��ʼֵȡ�ӱ���Ԫ��
	while (low < high)
	{//�ӱ����˽������м�ɨ��
		while (low < high && L.elem[high] >= pivotkey)
		{
			--high;
			++time;
		}
		L.elem[low] = L.elem[high];        //��������С���Ƶ��Ͷ�
		while (low < high && L.elem[low] <= pivotkey)
		{
			++low;
			++time;
		}
		L.elem[high] = L.elem[low];       //�����������Ƶ��߶�
	}
	L.elem[low] = pivotkey;            //�����¼��λ
	return low;                //��������λ��
}//Partition

void QSort(SqList &L, int low, int high)
{//�����Ա�L��������L.elem[low..high]����������

	int pivoteloc;
	if (low < high)   //�ǿձ�
	{
		pivoteloc = Partition(L, low, high);        //��L.elem[low..high]һ��Ϊ��
		QSort(L, low, pivoteloc - 1);               //������ӱ�ݹ�����
		QSort(L, pivoteloc + 1, high);               //���Ҳ��ӱ�ݹ�����
	}
}//Qsort
