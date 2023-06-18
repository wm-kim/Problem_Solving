#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// dictionary를 vector를 이용해서 구현

struct Dictionary {
	vector<string> keys, values;

	//  해당 키를 갖는 항목이 있는지 반환
	bool has(const string& key) {
		return find(keys.begin(), keys.end(), key) != keys.end();
	}
	// 해당 키와 값을 갖는 항목 추가
	void instert(const string& key, const string& value) {
		if (has(key)) erase(key);
		keys.push_back(key);
		values.push_back(value);
	}
	string get(const string& key);
	void erase(const string& key);
};

