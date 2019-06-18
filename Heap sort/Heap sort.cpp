//������/ϣ������
//ԭ�ĵ�ַ��https://blog.csdn.net/qq_29542611/article/details/79356378



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/timeb.h>
#define MAXSIZE 1000000
//����ֵ
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
//��ӡ����Ԫ��
void PrintArr(int* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return;
}
long GetSysTime()
{
	struct timeb tb;
	ftime(&tb);
	return tb.time * 1000 + tb.millitm;
}

//�ѵ��� ��Ѷ��������ֵ���ڸ����
void BigHeadAdjust(int* arr, int index, int length)
{
	int lchild = 2 * index + 1;
	int rchild = 2 * index + 2;
	int max = index;
	if (lchild<length && arr[lchild]>arr[max])
	{
		max = lchild;
	}
	if (rchild<length && arr[rchild]>arr[max])
	{
		max = rchild;
	}
	if (max != index)
	{
		Swap(&arr[max], &arr[index]);
		BigHeadAdjust(arr, max, length);
	}
	return;
}

//�����򣬲��ô󶥶� ����
void HeapSort_Up(int* arr, int length)
{
	//��ʼ���ѣ���ÿ����Ҷ�ӽ�㵹����д󶥶ѵ�����
	//ѭ����� ��ʼ�󶥶ѣ�ÿ������㶼�������ӽ��ֵ���γ�
	for (int i = length / 2 - 1; i >= 0; i--)
	{
		BigHeadAdjust(arr, i, length);
	}
	//printf("��Ѷ���ʼ��˳��");
	//PrintArr(arr, length);
	//���Ѷ�ֵ�ŵ�����β����Ȼ���ֽ��д�Ѷ�������һ�ζѵ�����ֵ�͵��Ѷ��ˡ� 
	for (int i = length - 1; i >= 0; i--)
	{
		Swap(&arr[0], &arr[i]);
		BigHeadAdjust(arr, 0, i);
	}
	return;
}

//�ѵ��� С�Ѷ�������Сֵ���ڸ����
void SmallHeadAdjust(int* arr, int index, int length)
{
	int lchild = 2 * index + 1;
	int rchild = 2 * index + 2;
	int min = index;
	if (lchild < length && arr[lchild] < arr[min])
	{
		min = lchild;
	}
	if (rchild < length && arr[rchild] < arr[min])
	{
		min = rchild;
	}
	if (min != index)
	{
		Swap(&arr[min], &arr[index]);
		SmallHeadAdjust(arr, min, length);
	}
	return;
}

//�����򣬲���С���� ����
void HeapSort_Down(int* arr, int length)
{
	for (int i = length / 2 - 1; i >= 0; i--)
	{
		SmallHeadAdjust(arr, i, length);
	}
	for (int i = length - 1; i >= 0; i--)
	{
		Swap(&arr[0], &arr[i]);
		SmallHeadAdjust(arr, 0, i);
	}
	return;
}
//ϣ������ ����
//���ݲ��������ԭ����ԭ����һ�����飬���ü������ʽ�ֳɺܶ�С�飬�ֱ���в�������
//ÿһ�ֽ����� �����ֳɸ�С������� ��������ֱ���ֳɵ�С�鳤��Ϊ1��˵�������������
void ShellSort_Up(int* arr, int length)
{
	int increase = length;
	int i, j, k, temp;
	do
	{
		increase = increase / 3 + 1;//ÿ��С��ĳ���
									//ÿ��С��ĵ�0��Ԫ��
		for (i = 0; i < increase; i++)
		{
			//��ÿ��С����в���������Ϊ�Ǽ������ʽ���飬ÿ��С����һ��Ԫ��Ϊ j+=increse
			for (j = i + increase; j < length; j += increase)
			{
				temp = arr[j];//������Ԫ��

				for (k = j - increase; k >= 0 && temp < arr[k]; k -= increase)
				{
					arr[k + increase] = arr[k];
				}
				arr[k + increase] = temp;
			}
		}
	} while (increase > 1);
}

int main(int argc, char* argv[])
{
	srand((size_t)time(NULL));//�����������
	int arr[10] = { 6,8,2,3,9,7,4,1,5,10 };
	int* arr2 = (int*)malloc(sizeof(int) * MAXSIZE);
	int* arr3 = (int*)malloc(sizeof(int) * MAXSIZE);
	//��ÿ��Ԫ������һ�����ֵ
	for (int i = 0; i < MAXSIZE; i++)
	{
		int num = rand() % MAXSIZE;
		arr2[i] = num;
		arr3[i] = num;
	}
	printf("����ǰ:\n");
	PrintArr(arr, 10);
	printf("����������:\n");
	HeapSort_Up(arr, 10);
	PrintArr(arr, 10);
	printf("��������:\n");
	HeapSort_Down(arr, 10);
	PrintArr(arr, 10);

	long start1 = GetSysTime();
	ShellSort_Up(arr2, MAXSIZE);
	long end1 = GetSysTime();
	printf("%d��Ԫ�� ϣ������ķ�%d����\n", MAXSIZE, end1 - start1);

	long start2 = GetSysTime();
	HeapSort_Up(arr3, MAXSIZE);
	long end2 = GetSysTime();
	printf("%d��Ԫ�� ������ķ�%d����\n", MAXSIZE, end2 - start2);
	return 0;
}