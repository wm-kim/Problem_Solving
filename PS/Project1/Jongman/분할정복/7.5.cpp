// 쿼드 트리 뒤집기
// 검은 색과 흰색밖에 없는 흑백 그림을 압축 표현
// 그림을 상하로 뒤집은 그림을 압축해서 출력

// 가장 무식한 방법 : 압축을 풀어서 이미지를 얻고 다시 압축하기
// 1. 큰 입력에도 동작하게끔 새로운 알고리즘 설계
// 2. 작은 입력에만 동작하는 단순한 알고리즘 최적화


// ***s를 통째로 전달하는 것이 아니라 s 한글자를 가르키는 포인터를 전달 
#include <string>
using namespace std;

const int MAX_SIZE = 100;
char decompressed[MAX_SIZE][MAX_SIZE];
// x와 y는 배열에 어느 부분에 저장되어야하는지 offset
void decompress(string::iterator& it, int y, int x, int size) {
	char head = *(it++);
	// 기저 사례 : 배열 전체를 모두 칠함
	if (head == 'b' || head == 'w') {
		for (int dy = 0; dy < size; ++dy) {
			for (int dx = 0; dx < size; ++dx) {
				decompressed[y + dy][x + dx] = head;
			}
		}
	}
	else {
		int half = size / 2;
		decompress(it, y, x, half);
		decompress(it, y, x + half, half);
		decompress(it, y + half, x, half);
		decompress(it, y + half, x + half, half);
	}
}

// 압축 다 풀지 않고 뒤집기 - 모두 풀기에는 그림이 너무 큼
string reverse(string::iterator& it) {
	char head = *it;
	++it;
	if (head == 'b' || head == 'w') {
		return string(1, head);
	}
	string upperLeft = reverse(it); string upperRight = reverse(it);
	string lowerLeft = reverse(it); string lowerRight = reverse(it);
	return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}