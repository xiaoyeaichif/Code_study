#include<iostream>
using namespace std;

/*
��Ŀ���壬��1-N֮���˶�����1λ��ֻ�������ƶ�����Nλ��ֻ�������ƶ�
������2-N-1֮����������Ҷ����ƶ�����������˳�ʼλ����start��
Ŀ��λ��Ϊaim���涨������ֻ���ƶ�K�������ػ����˴�start-aim�ķ����ܺ�
*/
//Ҫ�����������߰�way1����д��process1��������
int process1(int cur, int rest, int aim, int N);
int way1(int N, int start, int aim, int K)
{
	return process1(start, K, aim, N);
}
//�����˵�ǰ������λ��Ϊcur
//������ʣ��Ĳ���rest
//����Ŀ��Ϊaim
//����Щλ��1-N
int process1(int cur, int rest, int aim, int N)
{
	//���û��ʣ�ಽ�������ô���Ŀ��λ��ʱ
	if (rest == 0)
	{
		return cur == aim ? 1 : 0;
	}
	//rest>0,���в���Ҫ��,��1λ��ֻ�����ߵ�2��������Ŀ��ֵ
	if (cur == 1)
	{
		return process1(2, rest - 1, aim, N);
	}
	//����Nλ�ã�ֻ�����ߵ�N-1��λ��ȡ��������aimλ��
	if (cur == N)
	{
		return process1(N-1, rest - 1, aim, N);
	}
	//�������������м��λ����
	return process1(cur - 1, rest - 1, aim, N) +
		process1(cur + 1, rest - 1, aim, N);
}
int main02()
{
	int ans = way1(4, 2, 4, 4);
	cout << ans;
	return 0;
}