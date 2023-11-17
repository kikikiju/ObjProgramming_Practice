// 입력 받은 문자열이 펠린드롬인지 확인하기

#include <iostream>
#include <vector>
using namespace std;

int main() {
	std::vector<char>v1, v2;
	string a;
	cin >> a;

	for (int i = 0; i < a.size(); ++i) {
		v1.push_back(a[i]);
	}
	for (int k = a.size() - 1; k >= 0; --k) {
		v2.push_back(a[k]);
	}

	if (v1 == v2) cout << 1;
	else cout << 0;
}