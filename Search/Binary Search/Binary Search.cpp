//�۰����

//�����ҵ�����Ӧ���������
//���ȣ��������Ԫ���ǰ��������У������м�λ�ü�¼�Ĺؼ�������ҹؼ��ֱȽϣ����������ȣ�����ҳɹ���
//
//���������м�λ�ü�¼����ֳ�ǰ���������ӱ�����м�λ�ü�¼�Ĺؼ��ִ��ڲ��ҹؼ��֣����һ������ǰһ�ӱ������һ�����Һ�һ�ӱ�
//
//�ظ����Ϲ��̣�ֱ���ҵ����������ļ�¼��ʹ���ҳɹ�����ֱ���ӱ�����Ϊֹ����ʱ���Ҳ��ɹ���

//Notes��1.�������˳��洢�ṹ��2.���밴�ؼ��ִ�С�������С�

//����һ��������У�Ȼ��ʹ��ð������������У���ʹ���۰�����㷨���в���

//ʹ��C++�Ľṹ�������жԷ���������ٴ��ڷ����е���

#include<iostream>
#include<malloc.h>
using namespace std;


           //�ڽṹ�����������
int numData[9] = { 31,15,85,95,74,16,88,95,10 };
int length = sizeof(numData) / sizeof(int);


int BinarySearch(int numData[], int searchElem)
{
	int small = 0;
	int middle;
	int large=length-1;
	if (searchElem > numData[large] || searchElem < numData[small])
	{
		return -1;
	}

	if (small < large)
	{
		middle = (small + large) / 2;
		if (searchElem == numData[middle])
			return middle;
		else if (searchElem > numData[middle])
			small = middle + 1;
		else
			large = middle - 1;

	}
	return -1;

}

void main()
{

	int se;
	cout << "Please input the data that you want to inquire : ";
	cin >> se;
	int k;

	k = BinarySearch(numData, se);
	if (k == -1)
		cout << "There is no data that you want to query in this array. " << endl;
	else
		cout << "The number of the data that you inquiring is : " << k << endl;

}