//˳�����

//1.��ѯĳ�ض�Ԫ���Ƿ��ڲ��ұ��У�
//
//2.�������ض�Ԫ�صĸ������ԣ�
//
//3.�ڲ��ұ��в���һ������Ԫ�أ�
//
//4.�Ӳ��ұ���ɾ��ĳ������Ԫ�ء�

//numData[] = { 12,31,25,67,80,51,77,32 };

#include<iostream>
#include<malloc.h>

using namespace std;

int numData[] = { 12,31,25,67,80,51,77,32 };
int length = sizeof(numData) / sizeof(int);
//sizeof���ж�����ĳ���

//�㷨�ṹ
int SequentialSearch(int numData[], int searchElem) {
	for (int i = 0; i < length; i++)
	{
		if (numData[i] == searchElem)
			return i;
	}
	return -1;
}



void main(){
	int se;
	cout << "Please input the data that you want to inquire : ";
	cin >> se;
	int k = SequentialSearch(numData, se);
	if (k == -1)
		cout << "There is no data that you want to query in this array. " << endl;
	else
		cout << "The number of the data that you inquiring is : " << k << endl;

}
