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



int BubbleSort()
{
	int temp;
	int flag;//��ʾ����ð���Ƿ����˽����ı�־
	struct Arr arr;
	for (int i = 0; i < arr.length - 1; i++)
		//ÿ�α���һ�������ܻ��һ��Ԫ�ط�������ȷ��λ�ã�
	{
		flag = 1;
		for (int j = 0; j < arr.length - i - 1; j++)
		{
			if (arr.numData[j] > arr.numData[j + 1])
			{
				temp = arr.numData[j];
				arr.numData[j] = arr.numData[j + 1];
				arr.numData[j + 1] = temp;
				flag = 0;
			}
		}
		if (flag)
			continue;//���˱�����û�з���������˵���ñ��Ѿ����������ٴν��б���
	}
}

int BinarySearch(int numData[], int searchElem)
{
	int small = 0;
	int middle;
	int large=arr.length-1;
	if (searchElem > arr.numData[large] || searchElem < arr.numData[small])
	{
		return -1;
	}

	if (small < large)
	{
		middle = (small + large) / 2;
		if (searchElem == arr.numData[middle])
			return middle;
		else if (searchElem > arr.numData[middle])
			small = middle + 1;
		else
			large = middle - 1;

	}
	return -1;

}

void main()
{
	/*cout <<  << result.numData;
	Arr BubbleSort();
	Arr result = BubbleSort();
	cout << result.length << result.numData;*/
	int se;
	cout << "Please input the data that you want to inquire : ";
	cin >> se;
	int k;
	//k = SequentialSearch(arr.numData, se);
	k = BinarySearch(result.numData, se);
	if (k == -1)
		cout << "There is no data that you want to query in this array. " << endl;
	else
		cout << "The number of the data that you inquiring is : " << k << endl;

}