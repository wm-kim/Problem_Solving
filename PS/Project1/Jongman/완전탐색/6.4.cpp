// 2명 씩 짝을 지으나 친구만 가능한 경우의 수 세기

// 질못된 재귀호출 : 중복으로 여러번 세고 있음
// (0, 1)과 (1,0)을 따로 셈
// 다른 순서로 짝지어주는 것도 다른 경우로 세고 있음
int n;
bool areFriends[10][10];
int countPairings(bool taken[10]) {
	bool finished = true;
	for (int i = 0; i < n; ++i) if (!taken[i]) finished = false;
	if (finished) return 1;

	int ret = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!taken[i] && !taken[j] && areFriends[i][j]) {
				taken[i] = taken[j] = true;
				ret += countPairings(taken);
				taken[i] = taken[j] = false;
			}
		}
	}
	return ret;
}

// 항상 특정 형태의 답만 세기
// 사전 순으로 가장 먼저 오는 답만 세는 것
// 남아있는 학생 중 가장 번호가 빠른 학생의 짝 찾아주기

int n;
bool areFriends[10][10];
int countParings(bool taken[10]) {
	int firstFree = -1;
	for (int i = 0; i < n; ++i) {
		if (!taken[i]) {
			firstFree = i; break;
		}
	}
	// 모든 학생이 짝을 찾음
	if (firstFree == -1) return 1;
	int ret = 0;
	for (int pairWith = firstFree + 1; pairWith < n; ++pairWith) {
		if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairings(taken);
			taken[firstFree] = taken[pairWith] = false;
		}
	}
	return ret;
}