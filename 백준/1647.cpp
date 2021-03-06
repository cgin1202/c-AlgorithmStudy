#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent[100001];

struct node {
	int left;
	int right;
	int value;
};

bool compare(node a, node b){
	if (a.value < b.value)
		return true;
	else
		return false;
}

vector<node> v;

int getParent(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = getParent(parent[x]);
}

void unionParent(int x, int y) {
	int a = getParent(x);
	int b = getParent(y);
	if (a < b) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}

int findParent(int x, int y) {
	int a = getParent(x);
	int b = getParent(y);
	if (a == b)
		return 1;
	else
		return 0;
}

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int left, right, value;
		cin >> left >> right >> value;

		v.push_back({ left, right, value });
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 1; i <= n; i++)
		parent[i] = i;

	int sum = 0;
	int max = 0;
	for (int i = 0; i < v.size(); i++) {
		if (findParent(v[i].left, v[i].right) == 1)
			continue;
		sum += v[i].value;
		if (v[i].value > max)
			max = v[i].value;
		unionParent(v[i].left, v[i].right);
	}
	sum = sum - max;
	cout << sum << "\n";
	return 0;
}