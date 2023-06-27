// n명의 친구, m가지 음식
// 알러지가 있어 친구마다 못먹는 음식의 정보가 주어짐
// 각 친구가 먹을 수 있는 음식이 최소 한개가 있도록 하기 위한 만들어야하는 최소 음식 수

// set cover NP complete 문제
// 탐욕적 접근 방법 ? - 남은 친구들중 가장 많은 사람이 먹을 수 있는 음식 만들기 (모든 입력에 대해 최적해를 찾을 수 없음)

// 완전 탐색, 문제를 m개의 조각으로 쪼갬


#include <vector>
using namespace std;
int n, m;
vector<int> eaters[50]; // eaters[food] = food을 먹을 수 있는 친구들의 번호
int best;

// food 이번에 골르는 음식 번호
// edible : 지금까지 고른 음식 중 i번 친구가 먹을 수 있는 음식 수
// chosen 지금까지 고른 음식 수
void slowSearch(int food, vector<int>& edible, int chosen) {
	// 간단한 가지치기
	if (chosen >= best) return;
	// 기저사례
	if (food == m) {
		// 모든 친구들이 음식을 먹을 수 있는가
		if (find(edible.begin(), edible.end(), 0) == edible.end())
		{
			best = chosen;
			return;
		}
	}

	// food를 만들지 않는 경우
	slowSearch(food + 1, edible, chosen);
	// food를 만드는 경우
	for (int j = 0; j < eaters[food].size(); ++j) {
		edible[eaters[food][j]]++;
	}
	slowSearch(food + 1, edible, chosen + 1);

	for (int j = 0; j < eaters[food].size(); ++j) {
		edible[eaters[food][j]]--;
	}
}
// 먹을 음식이 있는지 bool 배열이 아닌 int 배열로 표현하는 패턴, 
// bool로 표현하면 edible을 바꿨다가 복구하기 어렵다

// 여기서 사용한 최적 기법 - 탐색의 형태 바꾸기. 
// 음식을 만들것인지 여부를 선택하기보다, 아직 먹을 음식이 없는 친구를 선택하여 어떤 음식을 만들지 결정하기

vector<int> canEat[50]; // i번 친구가 먹을 수 있는 음식 집합
void search(vector<int>& edible, int chosen) {
	if (chosen >= best) return;
	
	// 아직 먹을 음식이 없는 첫번째 친구를 찾는다
	int first = 0;
	while (first < n && edible[first] > 0) ++first;
	// 모든 친구들이 먹을 음식이 있는 경우 종료
	if (first == n) {
		best = chosen; return;
	}
	// 먹을 수 있는 음식 하나 만든다
	for (int i = 0; i < canEat[first].size(); ++i) {
		int food = canEat[first][i];

		for (int j = 0; j < eaters[food].size(); ++j) {
			edible[eaters[food][j]]++;
		}
		slowSearch(food + 1, edible, chosen + 1);

		for (int j = 0; j < eaters[food].size(); ++j) {
			edible[eaters[food][j]]--;
		}
	}
}

// 더 최적화 할 수 있는가?
// 먹을수 있는 음식의 종류가 적은 친구 먼저 찾아주기
// 음식을 선택할 떄는 가장 많은 사람이 먹을 수 있는 음식부터 시도한다.

