#include <iostream>
#include <algorithm>

using namespace std;



int main() {
	int n;
	cin >> n;

	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);

	int sum = 0; 
	for (int i = 0; i < n; i++)
		for(int j = 0 ; j <= i ; j++)
		sum += a[j];

	cout << sum;

}