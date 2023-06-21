// 짐싸기 (부피, 중요도) - 부피 w이하, 중요도 최대화 - 물건 리스트 출력

// 완전 탐색 : 2^n 가지 조합,
// pack(items) : items (지금까지 고른 목록)에서 남은 용량을 채웠을 떄 최대 중요도
// items을 넣고 남은 용량의 최대 중요도의 합만을 반환하면 지금까지 고른 목록은 상관없음
// pack(capacity, item) : capacity는 남은 용량, item 이후 물건을 싸서 얻을 수 있는 최대 중요도
#include <string>
#include <vector>
using namespace std;
int n, capcity;
int volume[100], need[100];
int cache[1001][100];
string name[100];
int pack(int capacity, int item) {
	if (item == n) return 0;
	int& ret = cache[capcity][item];
	if (ret != -1) return ret;
	// 이물건을 담지 않을 경우
	ret = pack(capcity, item + 1);
	// 담을 경우
	if (capcity >= volume[item])
	{
		ret = max(ret, pack(capacity - volume[item], item + 1) + need[item]);
	}
	return ret;
}

// 역 추적
void reconstruct(int capcity, int item, vector<string> picked) {
	if (item == n) return;
	if (pack(capcity, item) == pack(capcity, item + 1)) {
		reconstruct(capcity, item + 1, picked);
	}
	else {
		picked.push_back(name[item]);
		reconstruct(capcity - volume[item], item + 1, picked);
	}
}


