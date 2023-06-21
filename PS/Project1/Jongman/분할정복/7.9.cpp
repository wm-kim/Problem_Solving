// 팬미팅 - 일렬로 서서 멤버와 펜이 서로 포옹하는데 남자끼리는 포옹안함. 
// 멤버 모두가 동시에 포옹하게되는 개수  
// 곱셈으로의 변형
#include <vector>
#include <string>

using namespace std;
int hugs(const string& members, const string& fans) {
	int N = members.size(), M = fans.size();
	vector<int> A(N), B(M);
	for (int i = 0; i < N; ++i) A[i] = (members[i] == 'M');
	// 앞뒤를 뒤집은 다음 곱셈
	for (int i = 0; i < M; ++i) B[M - i - 1] = (fans[i] == 'M');
	vector<int> C = karatsuba(A, B);
	int allHugs = 0;
	for (int i = N - 1; i < M; ++i) {
		if (C[i] == 0) ++allHugs;
	}
	return allHugs;
}