//�۰��������
//1.���ҵ�L(i)���������е�λ�ã�
//2.����λ���Ժ������Ԫ�غ���
//3.��L(i)���Ƶ���λ��
//���㷨ͬʱʹ����˳��������

#include<iostream>
using namespace std;

void InsertSort(int Arr[], int length) {
	int i, j, low, high, mid, temp;
	for (i = 1; i < length; i++)
	{
		temp = Arr[i];
		low = 0;//�۰���ҵķ�Χ
		high = i - 1;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (Arr[mid] > temp)
				high = mid - 1;
			else
				low = mid + 1;
		}
		for (j = i - 1; j >= low; j--)//����λ�ã�������
			Arr[j + 1] = Arr[j];
		Arr[high + 1] = temp;

	}
}

void OutputArr(int Arr[], int length) {
	for (int i = 0; i < length; i++)
	{
		cout << Arr[i] << ", ";

	}
	cout << endl;
}

void main() {
	int Arr[] = { 45,57,12,31,1,60,92,71,87 };
	InsertSort(Arr, 9);
	OutputArr(Arr, 9);
}