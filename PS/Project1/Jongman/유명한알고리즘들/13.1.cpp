// 이분법 예제

#include <algorithm>
#include <vector>
using namespace std;

double f(double x);
double bisection(double lo, double hi) {
	if (f(lo) > 0)
		swap(lo, hi);
	while (fabs(hi - lo) > 2e-7) { // 절대 오차를 이용
		double mid = (lo + hi) / 2;
		double fmid = f(mid);
		if (fmid <= 0) lo = mid;
		else hi = mid;
	}

	return (lo + hi) / 2;
}

// 숫자의 절대값이 커질 수록 부동소수점이 표현할 수 있는 수가 듬성 듬성해지게 된다.
// 정해진 횟수만큼만 반복문 실행하여 오차가 10^-7보다 작음을 보장한다.

// 단변수 다항 방정식의 해를 이분법으로 찾기 (한계가 많은 방법)
vector<double> differentiate(const vector<double>& poly); // 미분 결과 계수를 반환
vector<double> solveNaive(const vector<double>& poly); // 1차혹은 2차방정식을 푼다.
double evaluate(const vector<double>& poly, double x0); // f(x0) 반환
// 방정식의 해의 절대값은 L 이하여야 한다.
const double L = 25;
vector<double> solve(const vector<double>& poly) {
	int n = poly.size() - 1;
	if (n <= 2) return solveNaive(poly);

	vector<double> derivative = differentiate(poly);
	vector<double> sols = solve(derivative);

	// 극점 사이를 하나하나 검사하며 근이 있나 확인한다.
	sols.insert(sols.begin(), -L - 1);
	sols.insert(sols.end(), L + 1);
	vector<double>ret;

	for (int i = 0; i + 1 < sols.size(); ++i) {
		double x1 = sols[i], x2 = sols[i + 1];
		double y1 = evaluate(poly, x1), y2 = evaluate(poly, x2);
		if (y1 * y2 > 0) continue;
		if (y1 > y2) { swap(y1, y2); swap(x1, x2); }
		// 이분법 사용
		for (int iter = 0; iter < 100; ++iter) {
			double mx = (x1 + x2) / 2;
			double my = evaluate(poly, mx);
			if (y1 * my > 0)
			{
				y1 = my, x1 = mx;
			}
			else {
				y2 = my, x2 = mx;
			}
		}
		ret.push_back((x1 + x2) / 2);
	}
	sort(ret.begin(), ret.end());
	return ret;
}

// 대출 잔금 N원, 월 이자 P/12%, 월상환액 C를 잔금에서 제거
// M개월에 걸려 다 갚기 위해서는 얼마씩 갚아야하나요?

double balance(double amount, int duration, double rates, double monthlPayment) {
	double balance = amount;
	for (int i = 0; i < duration; ++i) {
		balance *= (1.0 + (rates / 12.0) / 100.0);
		balance -= monthlPayment;
	}
	return balance;
}

double payment(double amount, int duration, double rates) {
	double lo = 0, hi = amount * (1.0 + (rates / 12.0) / 100.0);
	for (int iter = 0; iter < 100; ++iter) {
		double mid = (lo + hi) / 2.0;
		if (balance(amount, duration, rates, mid) <= 0) {
			hi = mid;
		}
		else {
			lo = mid;
		}
	}
	return hi;
}

// 게임 회수 G, 승리 회수 W, 승률 R (정수부만 표시)
// 승리 확률이 1%를 올리기 위해서 최소 몇게임을 해야하는지?

// 간단한 방법 - 승률이 변할때까지 하나씩 이긴다고 가정하고 변하는 최초 시점찾기
// 맨처음 20억번 연승을 하면 승률이 올라가는지 확인 - 이분법

typedef long long ll;
ll L = 2000000000; // 2억
int ratio(ll b, ll a) {
	return (a * 100) / b; // b게임중 a게임을 이겼을 때 승률
}

int needGames(ll games, ll won) {
	// 불가능한 경우 미리 걸러낸다,
	if (ratio(games, won) == ratio(games + L, won + L)) return -1;
	ll lo = 0, hi = L;
	while (lo + 1 < hi) { // lo게임을 이기면 승률이 변하지 않지만 hi게임을 이기면 승률이 변화한다,
		ll mid = (lo + hi) / 2;
		if (ratio(games, won) == ratio(games + mid, won + mid)) lo = mid;
		else hi = mid;
	}
	return hi;
}