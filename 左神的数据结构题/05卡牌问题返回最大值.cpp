#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int f1(vector<int>& arr, int L, int R);
int g1(vector<int>& arr, int L, int R);
//��ȡ������Ϸֵ�����ֵ
int GetMaxValue1(vector<int>& arr)
{	
	if (arr.size() == 0) return 0;
	int first = f1(arr, 0, arr.size() - 1);
	int second = g1(arr, 0, arr.size() - 1);
	return max(first, second);
}
//arr[L,R]���ֻ����õķ�������
int f1(vector<int>& arr, int L, int R)
{
	if (L == R)
	{
		return arr[L];
	}
	//L<R
	//��һ��ȡ�������
	int p1 = arr[L] + g1(arr, L + 1, R);
	//ȡ�����Ҳ�
	int p2 = arr[R] + g1(arr, L, R - 1);
	return max(p1, p2);
}
//���ֺ��������ֻ�����ֵ����
int g1(vector<int>& arr, int L, int R)
{
	//��һ�����Ѿ���ȡ���ˣ����ֺ���û�ƿ�ȡ
	if (L == R)
	{
		return 0;
	}
	//������ֺ���ȡ����arr[L],���ֺ���ֻ����L+1 --  R��ѡȡ
	int p1 = f1(arr, L + 1, R);
	//������ֺ���ȡ����arr[R],���ֺ���ֻ����L -- R-1��ѡȡ
	int p2 = f1(arr, L , R-1);
	return min(p1, p2);
}
//��̬�滮���� 
int GetMaxValue2(vector<int>& arr)
{
	int N = arr.size();
	vector<vector<int>>fmap(N, vector<int>(N));
	vector<vector<int>>gmap(N, vector<int>(N));
	//��ʼ������,���½ǲ��ֲ��ùܣ����������Ƕ�Ϊ0Ҳ��
	for (int i = 0; i < N; i++)
	{
		fmap[i][i] = arr[i];
		gmap[i][i] = 0;
	}
	for (int i = 0;  i < N; i++)
	{
		for (int j = 0; j < i; j++) {
			fmap[i][j] = 0;
			gmap[i][j] = 0;
		}
	}
	//���岿��
	//���п�ʼ����
	for (int startCol = 1; startCol < N; startCol++)
	{
		int R = startCol;
		int L = 0;
		while (R < N)
		{
			fmap[L][R] = max(arr[L] + gmap[L+1][R],arr[R] + gmap[L][R-1]);
			gmap[L][R] = min(fmap[L+1][R], fmap[L][R-1]);
			L++;
			R++;
		}
	}
	return max(fmap[0][N - 1], gmap[0][N - 1]);
	/*for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << fmap[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << gmap[i][j] << " ";
		}
		cout << endl;
	}*/
}


int main05()
{
	vector<int>arr = { 1,5,2};
	cout << "�����ݹ�汾: " ;
	cout<<GetMaxValue1(arr);
	cout << endl;
	cout << "��̬�滮�汾��";
	cout << GetMaxValue2(arr);
	GetMaxValue2(arr);
	return 0;
}