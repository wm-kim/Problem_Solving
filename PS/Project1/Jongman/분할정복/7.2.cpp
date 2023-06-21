// 두수 곱하기

#include <vector>
using namespace std;

// num[] 자리수 올림 처리
void normalize(vector<int>& num) {
	num.push_back(0); // MSB앞에 0을 붙임 (out of range 방지)
	// 자리수 올림 처리
	for (int i = 0; i < num.size(); ++i) {
		// 음수일 때
		if (num[i] < 0) {
			int borrow = (abs(num[i]) + 9) / 10;
			num[i + 1] -= borrow;
			num[i] += borrow * 10;
		}
		else {
			num[i + 1] += num[i] / 10;
			num[i] %= 10;
		}
	} 
	while (num.size() > 1 && num.back() == 0) num.pop_back();
}

// a와 b는 맨 아래 자리부터 저장함. 1234 면 4321 순으로
vector<int> multiply(const vector<int>& a, const vector<int>& b) {
	vector<int> c(a.size() + b.size() + 1, 0);
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < b.size(); ++j) {
			c[i + j] += a[i] * b[j];
		}
	}
	normalize(c);
	return c;
}

