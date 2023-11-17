// 입력 받은 문자열이 펠린드롬인지 확인하기

#include <iostream>
#include <vector>
using namespace std;

int main() {
	string a;
	cin >> a;
	int n = a.size();
	char* b1 = new char[n];
	char* b2 = new char[n];

	for (int i = 0; i < n; ++i) {
		b1[i] = a[i];
	}

	for (int j = 0; j < n; ++j) {
		b2[n - 1 - j] = a[j];
	}


	bool fel = true;
	for (int k = 0; k < n; ++k) {
		if (b1[k] != b2[k]) {
			fel = false;
			break;
		}
		
	}

	cout << fel;

	delete[] b1;
	delete[] b2;
}