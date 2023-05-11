#include <iostream>
#include <vector>
using namespace std;
int n; int c = 0;
int chess[15][15] = { 0, };

// My Answer
#if 0
bool isValid(int x, int y)
{
	for (int i = 0; i < n; i++)
	{
		if (chess[y][i] == 1) return false;
		if (chess[i][x] == 1) return false;
	}
	for (int i = x, j = y; i >= 0 && j >= 0; i--, j--)
		if (chess[j][i] == 1) return false;
	for (int i = x, j = y; i < n && j < n; i++, j++)
		if (chess[j][i] == 1) return false;
	for (int i = x, j = y; i >= 0 && j < n; i--, j++)
		if (chess[j][i] == 1) return false;
	for (int i = x, j = y; i < n && j >= 0; i++, j--)
		if (chess[j][i] == 1) return false;
	return true;
}

void printChess()
{
	for (int i = 0; i < n; i++)
	{
		cout << "[";
		for (int j = 0; j < n; j++)
		{
			cout << chess[i][j] << " ";
		}
		cout << "]" << endl;
	}
	return;
}

void backtracking(int depth)
{
	if (depth == n) {
		// print chess board
		cout << "board " << ++c << endl;
		printChess();
	}

	// �� ���̿��� ��� ��� ���� ���� ���� ��ġ�Ϸ��� �õ�
	// 4 * 3 * 2 * 1 = 24, 24 * 2 = 48
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			if (!isValid(x, y)) continue;
			cout << "depth: " << depth << " x: " << x << " y: " << y << endl;
			printChess();
			chess[y][x] = 1;
			backtracking(depth + 1);
			chess[y][x] = 0;
		}
	}
}

int main() {
	cin >> n;
	backtracking(0);
	cout << c;
}
#endif

// GPT �� �࿡ ���� �ϳ��� �� ��ġ, ���̿� ���� ��ġ���� �� �࿡ ���� �ϳ����� ��ġ
# if 0
bool isValid(int x, int y)
{
	for (int i = 0; i < y; i++)
	{
		if (chess[i][x] == 1) return false;
	}

	for (int i = x, j = y; i >= 0 && j >= 0; i--, j--)
		if (chess[j][i] == 1) return false;

	for (int i = x, j = y; i < n && j >= 0; i++, j--)
		if (chess[j][i] == 1) return false;

	return true;
}

void backtracking(int depth)
{
	if (depth == n) { c++; return; }

	for (int x = 0; x < n; x++)
	{
		if (!isValid(x, depth)) continue;
		chess[depth][x] = 1;
		backtracking(depth + 1);
		chess[depth][x] = 0;
	}
}

int main() {
	cin >> n;
	backtracking(0);
	cout << c;
}
#endif

#if 0
#include <iostream>
#define MAX 15
using namespace std;

int col[MAX]; // N�� ������ �迭�� ���� ��, �� ���� ���° ���� ���� �ִ����� ����
int N, total = 0;

bool check(int level)
{
	for (int i = 0; i < level; i++)
		if (col[i] == col[level] || abs(col[level] - col[i]) == level - i)// �밢���̰ų� ���� ����
			return false;
	//col[i]�� �ǹ��ϴ� ���� X��ǥ, i�� �ǹ��ϴ°��� Y��ǥ�̹Ƿ� ���̰� �����ϴٸ� �밢���� �ִٰ� �� �� �ִ�.
	return true;
}

void nqueen(int x)
{
	if (x == N)
		total++;
	else
	{
		for (int i = 0; i < N; i++)
		{
			col[x] = i; // �ش� ��ġ�� ���� ��ġ
			if (check(x)) // ��ȿ�ϴٸ� �������� �� ��ġ, ��ȿ�����ʴٸ� �ٸ� ��ġ�� �� ��ġ ����
				nqueen(x + 1);
		}
	}
}
int main() {
	cin >> N;
	nqueen(0);
	cout << total;
}
#endif

#define MAX 15
using namespace std;

int ch[MAX];
int N, cnt = 0;

bool valid(int level)
{
	for (int i = 0; i < level; i++)
		if (ch[i] == ch[level] || abs(ch[level] - ch[i]) == level - i)
			return false;
	return true;
}

void bt(int x)
{
	if (x == N) cnt++;
	else
	{
		for (int i = 0; i < N; i++)
		{
			ch[x] = i;
			if (valid(x)) bt(x + 1);
		}
	}
}
int main() {
	cin >> N; bt(0); cout << cnt;
}