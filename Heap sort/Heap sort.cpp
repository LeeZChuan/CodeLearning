//�������㷨
//1.�����ʼ�ѡ��������������й����һ���󶥶ѣ�һ��������ô󶥶ѣ��������С����)��
//2.���Ѷ�Ԫ����ĩβԪ�ؽ��н�����ʹĩβԪ�����Ȼ����������ѣ��ٽ��Ѷ�Ԫ����ĩβԪ�ؽ�����
//�õ��ڶ���Ԫ�ء���˷������н������ؽ���������
//
//
//a.���������й�����һ���ѣ���������������ѡ��󶥶ѻ�С����;
//b.���Ѷ�Ԫ����ĩβԪ�ؽ����������Ԫ��"��"������ĩ��;
//c.���µ����ṹ��ʹ������Ѷ��壬Ȼ����������Ѷ�Ԫ���뵱ǰĩβԪ�أ�����ִ�е��� + �������裬
//ֱ��������������


#include<iostream>
using namespace std;

void Heapsort(int Arr, int length)
{
	function fun;

	//��������Ϊ�������У��򴴽������
	//1.�����󶥶�
	for (int i = int(length / 2) - 1; i >= 0; i--) {
		//�ӵ�һ����Ҷ�ӽ��������ϣ�������������ṹ
		
	}
	//2.�����ѽṹ+�����Ѷ�Ԫ����ĩβԪ��
	for (int j = length - 1; j > 0; j--) {
		fun.swap(Arr, 0, j);//���Ѷ�Ԫ����ĩβԪ�ؽ��н���
		fun.adjustHeap(Arr, 0, j);//���¶Զѽ��е���
	}

}


class function {

void adjustHeap(int Arr[], int i, int length)
{
	//�����ݷ�����״�ṹ
	//�ӵ�һ����Ҷ�ӽ��������ϣ�������������ṹ

	int temp = Arr[i];
	for (int k = i * 2 + 1; k < length; k = k * 2 + 1) {//��i�������ӽ�㿪ʼ��Ҳ����2i+1����ʼ
		if (k + 1 < length && Arr[k] < Arr[k + 1]) {//������ӽ��С�����ӽ�㣬kָ�����ӽ��
			k++;
		}
		if (Arr[k] > temp) {//����ӽڵ���ڸ��ڵ㣬���ӽڵ�ֵ�������ڵ㣨���ý��н�����
			Arr[i] = Arr[k];
			i = k;
		}
		else {
			break;
		}
	}
	Arr[i] = temp;//��tempֵ�ŵ����յ�λ��

}

void swap(int Arr[], int a, int b) {
	//����Ԫ��
	int temp = Arr[a];
	Arr[a] = Arr[b];
	Arr[b] = temp;
}

void OutputArr(int Arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << Arr[i] << ", ";

	}
	cout << endl;
}
};

void main()
{
	int Arr[] = { 9,8,7,6,5,4,3,2,1 };
	int length = 9;
	Heapsort(Arr, length);
	OutputArr(Arr, length);
}