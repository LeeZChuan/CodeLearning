//���㷨Ϊ���������㷨

//����ð������ĸĽ��㷨
//1���ȴ�������ȡ��һ������Ϊ��׼����
//2���������̣���������������ȫ�ŵ������ұߣ�С�ڻ����������ȫ�ŵ�������ߡ�
//3���ٶ����������ظ��ڶ�����ֱ��������ֻ��һ������
//



#include<iostream>
using namespace std;

int circle = 0;//������������
void QuickSort(int* pdata, int low, int high)
{
	if (low < high)
	{
		int first = low, last = high;
		int key = pdata[first];
		while (first < last)
		{
			while (first < last && pdata[last] >= key)  //���������ҵ�һ��С�ڱ�׼ֵ��λ��
				last--;
			if (first < last)
				pdata[first] = pdata[last];    //С�����ŵ�ǰ��
			while (first < last && pdata[first] <= key) //���������ұ�keyС��ֵ��λ��,λ����ȷ�Ͳ�����е���
				first++;
			if (first < last)
				pdata[last] = pdata[first];    //������ŵ�����
			cout << "the " << ++circle << "round:";
		}
		pdata[first] = key;
		for (int i = 0; i < 10; i++)
			cout << pdata[i];
		cout << endl;
		QuickSort(pdata, low, first - 1);  //��firstΪ���ķֳ������֣�
		QuickSort(pdata, first + 1, high);
	}
}
//������
//�ο� http://developer.51cto.com/art/201403/430986.htm#commment
//�ܺ���⣨Ѳ�ӵ�����Ԫ�أ����ǱȻ�׼��ģ����ǱȻ�׼С�ģ�
void quickSort(int* pdata, int left, int right)
{
	if (left >= right)//����Ԫ��Ϊ0
	{
		return;
	}
	if (left < right)//�����Ҫ�����Ԫ�ش���1��
	{
		int temp = 0;//�ݴ����
		int key = pdata[left];
		int i = left, j = right;
		while (i != j)
			//����������Ŀǰ����������ͬ���ֵ����
		{
			while (pdata[j] >= key && i < j) //�ұߵ��ڱ���ʼ����Ѳ��
				j--;
			while (pdata[i] <= key && i < j) //��ߵ��ڱ���ʼѵ��
				i++;
			if (i < j)  //��������ڱ�û�������������ݽ��н���
			{
				temp = pdata[j];
				pdata[j] = pdata[i];
				pdata[i] = temp;
			}
			cout << "the " << ++circle << "round:";
		}
		pdata[left] = pdata[i];//iͣ��λ�ü�<key��λ��,i��ֵ�ŵ������
		pdata[i] = key;//��׼λ��λ
		for (int m = 0; m < 10; m++)
			cout << pdata[m];
		cout << endl;
		quickSort(pdata, left, i - 1);//��i��λ��Ϊ��׼,�ֳ������֣��󲿷�
		quickSort(pdata, i + 1, right);//�Ұ벿��
	}
}
int main()
{
	/*int data[] = { 6,1,2,7,9,3,4,5,10,8 };
	int data2[] = { 1,2,3,4,5,6 };
	int data3[] = { 9,8,7,6,5,4,3,2,1 };
	int data4[,],, = { 1,2,3,4,5,6,7,8,9 };*/
	int data[] = { 10,15,19,5,4,1,8,29,48,2,56 };
	cout << "----------------------------------" << endl;
	quickSort(data, 0, 10);
	for (int i = 0; i < 10; i++)
		cout << data[i] << ' ';
	cout << endl;
	return 0;
}