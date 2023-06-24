// n명씩 프로 코더로 팀 구성
// 각선수 실력 rating (1:1 승부)  
// 상대방 팀 선수의 순서와 rating를 알고있을 때 어느 순서로 선수들을 내보내야 승수를 최대화 할 수 있을까?

// 동적 구상
// order(taken) : 각 한국팀 선수를 이미순서에 추가했느지 여부가 taken에 주어질 때, 남은 선수들을 적절히 배치해서 얻을 수 있는 최대 승수
// 
// 탐욕 구상
// 상대 선수가 우리 팀 선수 모두보다 실력이 높은경우 - 우리팀의 가장 실력이 낮은 선수와 매칭
// 그 외에 경우에는 최소 레이팅으로 이길수 있는 선수와 매칭

// 정당성 증명
// 질 수 밖에 없는 경우와 이길 수 있는 경우로 나눠서 생각해보자
#include <vector>
using namespace std;

int order(const vector<int>& russian, const vector<int>& korean) {
	int n = russian.size(), wins = 0;
}