//���㷨Ϊð������

//�㷨����
//1.�Ƚ����ڵ�Ԫ�ء������һ���ȵڶ����󣬾ͽ�������������
//2.��ÿһ������Ԫ����ͬ���Ĺ������ӿ�ʼ��һ�Ե���β�����һ�ԡ�����һ�㣬����Ԫ��Ӧ�û�����������
//3.������е�Ԫ���ظ����ϵĲ��裬�������һ����
//4.����ÿ�ζ�Խ��Խ�ٵ�Ԫ���ظ�����Ĳ��裬ֱ��û���κ�һ��������Ҫ�Ƚϡ�

#include<iostream>
using namespace std;

void BubbleSort(int Arr[], int length) {
	int temp;
	int flag;
	for (int i = 0; i < length - 1; i++)
	{
		flag = 1;
		for (int j = 0; j < length - i - 1; j++)
		{
			if (Arr[j] > Arr[j + 1])
			{
				temp = Arr[j];
				Arr[j] = Arr[j + 1];
				Arr[j + 1] = temp;
				flag = 0;
			}
		}
		if (flag)
			return;
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
	BubbleSort(Arr, 9);
	OutputArr(Arr, 9);
}