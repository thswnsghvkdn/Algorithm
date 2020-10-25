#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point  // �簢���� ���� ����
{
	int r, c;
};

int sticker(int r , int c, int r_input, int c_input) // ��ƼĿ�� ���� �� �ִ��� �˻� 
{
	if (r >= r_input && c >= c_input) return 1; // ��ƼĿ�� ������ �ʰ� �ٿ����� 1
	if (r >= c_input && c >= r_input) return 2; // ��ƼĿ�� ������ �ٿ��� �ϸ� 2
	else return 0;
}
int main()
{
	int row, col;
	cin >> row >> col;
	int num;
	cin >> num;
	vector<Point> v(num);
	int nr, nc;
	for (int i = 0; i < num; i++)
	{
		cin >> v[i].r >> v[i].c;
	}
	
	int ans = 0; // ����
	for (int i = 0; i < num - 1; i++) // �Է¹��� ������ ũ�� - 1 ��ŭ �ݺ�
	{
		if (sticker(row, col, v[i].r, v[i].c) == 1)
		{
			int n_r = row - v[i].r;
			int n_c = col - v[i].c;
			for (int j = i + 1; j < num; j++) // �ι�° ������ i+1 ���� num���� �ݺ�
			{
				if (sticker(n_r, col, v[j].r, v[j].c)) ans = max(ans, (v[i].r * v[i].c) + (v[j].r) * (v[j].c));
				if (sticker(row, n_c, v[j].r, v[j].c)) ans = max(ans, (v[i].r * v[i].c) + (v[j].r) * (v[j].c));
			}
		}
		if (sticker(row, col, v[i].r, v[i].c) == 2)
		{
			int n_r = row - v[i].c;
			int n_c = col - v[i].r;
			for (int j = i + 1; j < num; j++) // �ι�° ������ i+1 ���� num���� �ݺ�
			{
				if (sticker(n_r, col, v[j].r, v[j].c)) ans = max(ans, (v[i].r * v[i].c) + (v[j].r) * (v[j].c));
				if (sticker(row, n_c, v[j].r, v[j].c)) ans = max(ans, (v[i].r * v[i].c) + (v[j].r) * (v[j].c));
			}
		}
		else continue;
	}
	cout << ans;
}