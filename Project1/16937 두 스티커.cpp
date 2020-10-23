#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int cnt;

struct Point
{
	int r, c;
};
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
	int ans_1 = 0, ans_2 = 0;
	for (int i = 0; i < num; i++)
	{
		if (row >= v[i].r)
		{
			if (col >= v[i].c) {
				ans_1 = max(ans_1, (v[i].r * v[i].c));
				for (int j = i + 1; j < num; j++)
				{
					if (row - v[i].r >= v[j].r)
					{
						if (col >= v[j].c) {
							ans_2 = max(ans_2, ans_1 + (v[j].r * v[j].c));
						}
					}
					if (col >= v[j].r)
					{
						if (row - v[i].r >= v[j].c) {
							ans_2 = max(ans_2, ans_1 + (v[j].r * v[j].c));
						}
					}
					if (row - v[i].r >= v[j].r)
					{
						if (col >= v[j].c) {
							ans_2 = max(ans_2, ans_1 + (v[j].r * v[j].c));
						}
					}
					if (col >= v[j].r)
					{
						if (row - v[i].r >= v[j].c) {
							ans_2 = max(ans_2, ans_1 + (v[j].r * v[j].c));
						}
					}
				}
			}
			else continue;
		}
		if (col >= v[i].r)
		{
			if (row >= v[i].c) {
				ans_1 = max(ans_1, (v[i].r * v[i].c));
				for (int j = i + 1; j < num; j++)
				{
					if (row - v[i].c >= v[j].r)
					{
						if (col >= v[j].c) {
							ans_2 = max(ans_2, ans_1 + (v[j].r * v[j].c));
						}
					}
					if (col >= v[j].r)
					{
						if (row - v[i].c >= v[j].c) {
							ans_2 = max(ans_2, ans_1 + (v[j].r * v[j].c));
						}
					}
					if (row - v[i].c >= v[j].r)
					{
						if (col >= v[j].c) {
							ans_2 = max(ans_2, ans_1 + (v[j].r * v[j].c));
						}
					}
					if (col >= v[j].r)
					{
						if (row - v[i].c >= v[j].c) {
							ans_2 = max(ans_2, ans_1 + (v[j].r * v[j].c));
						}
					}
				}
			}
		}
	}

	cout << ans_2;
}