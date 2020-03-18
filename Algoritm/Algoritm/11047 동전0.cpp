#include <iostream>
using namespace std;


int main() {
	int n; int k;
	cin >> n >> k;

	int* m = new int[n];
	for (int i = 0; i < n; i++)
	 cin >> m[i];
	n--;

	int count = 0;
	while (k > 0) {
		int share = k / m[n];
		if (share) {
			k -= (m[n] * share);
			count += share;
		}
		n--;
	}

	cout << count;
	delete[] m;
}