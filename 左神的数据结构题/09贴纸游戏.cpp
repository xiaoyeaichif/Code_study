#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<climits> 
#include <unordered_map>
using namespace std;

//��������
int process1(vector<string>& stickers, string target);
string Strminus(string target, string s1);
//�����ݹ�Ľ��
//��������ʹ��
//��ȡ��С����ֽ��Ŀ
//������Ҫ���ٶ�������ֽ��������������
int minSticker(vector<string>& stickers, string target)
{
	int ans = process1(stickers, target);
	return ans == INT_MAX ? -1 : ans;
}

//������ֽstickers��ÿһ����ֽ����������
//��������target����������
int process1(vector<string>& stickers, string target) 
{
	if (target.length() == 0) return 0;
	int Min = INT_MAX;
	for (string first : stickers)
	{
		string rest = Strminus(target, first);
		if (rest.length() != target.length())
		{
			Min = min(Min, process1(stickers, rest));
		}
	}
	return Min + (Min == INT_MAX ? 0 : 1);
}

string Strminus(string target, string s1) {
	vector<int>count(26, 0);
	for(char cha : target)
	{
		count[cha - 'a']++;
	}
	for(char cha : s1)
	{
		count[cha - 'a']--;
	}
	string result = "";
	for (int i = 0; i < 26; i++)
	{
		if (count[i] > 0) {
			for (int j = 0; j < count[i]; j++)
			{
				//ϵͳת������Ľṹ
				result += (i + 'a');
				//result += static_cast<char>(i + 'a');
			}
		}
	}
	return result;
}
//��֦����

int process2(vector<vector<int>>&stickers, string target)
{
	if (target.size() == 0) return 0;
	vector<int>targetCount(26, 0);
	//
	for (char cha : target)
	{
		targetCount[cha - 'a']++;
	}

	int minStickers = INT_MAX;

	for (vector<int>& sticker : stickers) {
		if (sticker[target[0] - 'a'] > 0) {
			string rest = "";
			for (int j = 0; j < 26; j++) {
				int num = targetCount[j] - sticker[j];
				for (int k = 0; k < num; k++) {
					rest += (j + 'a');
				}
			}

			int remainingStickers = process2(stickers, rest);

			if (remainingStickers != INT_MAX) {
				minStickers = min(minStickers, remainingStickers + 1);
			}
		}
	}
	return minStickers;
}
//
int minSticker2(vector<string>& stickers, string target)
{
	int N = stickers.size();
	vector<vector<int>> counts(N, vector<int>(26, 0));
	// �����ַ�Ƶ�ʱ� counts
	for (int i = 0; i < N; i++) {
		for (char cha : stickers[i]) {
			counts[i][cha - 'a']++;
		}
	}
	int ans = process2(counts, target);
	return ans == INT_MAX ? -1 : ans;
}
//���仯����
// �޸� process3 ������������仯������ʹ�� memo ��Ϊ����
int process3(vector<vector<int>>& stickers, string target, unordered_map<string, int>& memo) {
	if (target.size() == 0) return 0;
	if (memo.find(target) != memo.end()) {
		return memo[target];
	}

	vector<int> targetCount(26, 0);
	for (char cha : target) {
		targetCount[cha - 'a']++;
	}

	int minStickers = INT_MAX;

	for (vector<int>& sticker : stickers) {
		if (sticker[target[0] - 'a'] > 0) {
			string rest = "";
			for (int j = 0; j < 26; j++) {
				int num = targetCount[j] - sticker[j];
				for (int k = 0; k < num; k++) {
					rest += (j + 'a');
				}
			}

			int remainingStickers = process3(stickers, rest, memo);

			if (remainingStickers != -1) { // �޸Ĵ˴�
				minStickers = min(minStickers, remainingStickers + 1);
			}
		}
	}

	memo[target] = (minStickers == INT_MAX) ? -1 : minStickers;
	return memo[target];
}

// ������ minSticker3�����ٽ��� memo ����
int minSticker3(vector<string>& stickers, string target) {
	int N = stickers.size();
	vector<vector<int>> counts(N, vector<int>(26, 0));
	// �����ַ�Ƶ�ʱ� counts
	for (int i = 0; i < N; i++) {
		for (char cha : stickers[i]) {
			counts[i][cha - 'a']++;
		}
	}

	unordered_map<string, int> memo; // ���仯�����Ļ���
	int ans = process3(counts, target, memo);
	return ans == INT_MAX ? -1 : ans;
}
//������
int main09()
{
	vector<string>stickers = { "ba","c","abcd" };
	string target = "babacaacacacacac";
	cout <<"�����ݹ�Ľ��: "<< minSticker(stickers, target)<<endl;
	cout << "�����ݹ�Ľ��: " << minSticker2(stickers, target) << endl;
	cout << "�����ݹ�Ľ��: " << minSticker3(stickers, target) << endl;
	return 0;
}