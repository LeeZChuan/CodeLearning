//ֱ�Ӳ�������

//�㷨����
//1.���ҵ�L(i)���������е�λ��k��
//2.����λ���Ժ������Ԫ�غ���
//��L(i)���Ƶ�L(k)��.
//ֱ��������һ���ȶ������򷽷���
//�����ԣ�ֱ�Ӳ�������������˳��洢����ʽ�洢�����Ա�Ϊ��ʽ�洢�ң����Դ�ǰ�������ָ��Ԫ��λ��
//ע�⣺�󲿷��㷨������������˳��洢�����Ա�

#include<iostream>
using namespace std;

void InserSort(int Arr[], int length)
{
	int temp;
	int i, j;
	for (i = 1; i < length; i++)//�������������е�Ԫ��
	{
		if (Arr[i] < Arr[i - 1])//�ҵ������������Ҫ��,��ȡ����
		{
			temp = Arr[i];
			for (j = i - 1; temp<Arr[j]&&j>=0; j--)
			{
				Arr[j + 1] = Arr[j];
			}
			//��������ǰ��˳����ֵ��С��һ�£���Ҫ�ƶ�Ȼ�󽫲�һ�µ����ݲ����ȥ
			    Arr[j + 1] = temp;
		}
	}
}


void OutputArr(int Arr[], int length) {
	for (int i = 0; i < length; i++)
	{
		cout << Arr[i] << ",";

	}
	cout << endl;
}
void main()
{
	int Arr[] = { 45,85,78,59,25,48,15 };
	InserSort(Arr, 7);
	OutputArr(Arr, 7);
}

