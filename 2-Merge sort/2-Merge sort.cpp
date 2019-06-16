//2-·�鲢����

//���õݹ飬��ԭʼ���в��������ֿ飬֪��ÿ��ʣ��һ��Ԫ�أ����Ԫ�ؿ϶�������ġ�
//Ȼ�����õݹ��ԭ��ϲ����ɣ�
//��·�鲢�������ã������ƽ��ʱ�临�Ӷ�ΪO(nlgn);��һ���ȶ�������

#include<iostream>
using namespace std;

void Merge(int data[], int low, int mid, int high)
{
	int i = low, j = mid + 1, k = 0;
	int* temp = new int[high - low + 1];      //temp�����ݴ�ϲ�����������

	if (!temp)                                 //�ڴ����ʧ�� 
	{
		cout << "ERROR!";
		return;
	}

	while (i <= mid && j <= high)             //˳��ѡȡ�����������Ľ�СԪ�أ��洢��t������
	{
		if (data[i] <= data[j])                 //��С���ȴ���temp��
			temp[k++] = data[i++];
		else
			temp[k++] = data[j++];
	}

	while (i <= mid)                          //���Ƚ���֮�󣬵�һ������������ʣ�࣬��ֱ�Ӹ��Ƶ�t������
		temp[k++] = data[i++];
	while (j <= high)                         //ͬ��
		temp[k++] = data[j++];
	for (i = low, k = 0; i <= high; i++, k++)     //���ź���Ĵ��data��low��high������ 
		data[i] = temp[k];
	delete[]temp;                          //ɾ��ָ�룬����ָ��������飬������delete [] 
}


void MergeSort(int data[], int low, int high)
{                                            //�õݹ�Ӧ�ö�·�鲢����ʵ�����򡪡����η�
	if (low < high)                             //����if������while�����Ҳ����Ⱥţ�������ѭ������
	{
		int mid = (low + high) / 2;
		MergeSort(data, low, mid);
		MergeSort(data, mid + 1, high);
		Merge(data, low, mid, high);
	}
}

int main()
{
	int x[] = { 0, 5, 33, 1, 8, 7, 23, 3 };
	MergeSort(x, 0, 7);
	for (int i = 0; i < 8; i++)
		cout << x[i] << " ";
	return 0;
}