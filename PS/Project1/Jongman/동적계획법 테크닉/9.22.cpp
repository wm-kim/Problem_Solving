// 블록게임 L 모양 또는 2*1 블럭으로 5*5 게임판에 번갈아 놓다가
// 더이상 놓을 수 없을 때 마지막에 올려놓는 사람이 승리
// 이번 차례인 사람이 승리할 수 있는 방법이 있는지 판단하는 프로그램 
// - 항상 이기는 방법이 있다면 WINNING, 
// - 항상 질수 밖에 없다면 LOSING

// 비트마스크 사용 25 bool -> 32bit 


// precalc 모든 블록 조합을 생성
// play에서 현재 게임판과 비트 AND 연산을 통해 결과가 0인 수

#include <vector>
using namespace std;
vector<int> moves;
inline int cell(int y, int x) {	return 1 << (y * 5 + x); }
void precalc() {
	for (int y = 0; y < 4; ++y) {
		for (int x = 0; x < 4; ++x) {
			vector<int> cells;
			for (int dy = 0; dy < 2; ++dy) {
				for (int dx = 0; dx < 2; ++dx)
				{
					cells.push_back(cell(y + dy, x + dx));
				}
			}
			int square = cells[0] + cells[1] + cells[2] + cells[3];
			for (int i = 0; i < 4; ++i) moves.push_back(square - cells[i]);
		}
	}
	// 2칸짜리 블록 계산
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 4; ++j) {
			moves.push_back(cell(i, j) + cell(i, j + 1));
			moves.push_back(cell(j, i) + cell(j + 1, i));
		}
	}
}
// 게임판의 상태 : board 일때, 현재 차례인 사람이 승리할지 여부 반환
char cache[1 << 25];
char play(int board) {
	char& ret = cache[board];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < moves.size(); ++i) {
		if (!play(board | moves[i])) {
			ret = 1;
			break;
		}
	}
	return ret;
}

