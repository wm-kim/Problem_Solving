#include <vector>

using namespace std;
const int INF = 987654321;
bool canEveryBodyEat(const vector<int>& menu);
int M;
int selectMenu(vector<int>& menu, int food) {
	if (food == M) {
		if (canEveryBodyEat(menu)) return menu.size();
		return INF;
	}
	// 이음식을 만들지 앟는 경우
	int ret = selectMenu(menu, food + 1);
	// 이음식을 만드는 경우
	menu.push_back(food);
	ret = min(ret, selectMenu(menu, food + 1));
	menu.pop_back();
	return ret;
}

