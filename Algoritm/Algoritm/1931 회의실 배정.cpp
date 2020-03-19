#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

bool compare2(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	
	return a.second < b.second;
}

int main() {
	vector<pair<int, int> > end;

	int n;
	cin >> n;

	int s, e;
	for (int i = 0; i < n; i++) {
		cin >> s >> e;
		end.push_back(pair<int, int>(s, e));
	}

	sort(end.begin(), end.end(), compare2);

	int count = 0;
	int index = 0;
	int time = end[index].second;

	index++;
	count++;

	while (index < n) {
		
		if (time <= end[index].first) {
			count++;
			time = end[index].second;
		}

		index++;
	}
	cout << count;

	return 0;
}