#include <iostream> 
#include <queue>
using namespace std;
struct Member { int age = 0; string name; };
int main() { 
	cin.tie(NULL); cin.sync_with_stdio(false);
	queue<Member> q[10];
	int n; cin >> n; Member* members = new Member[n];
	for (int i = 0; i < n; i++)
		cin >> members[i].age >> members[i].name;

	for (int i = 1; i <= 100; i = i * 10) // Radix sort
	{
		for (int j = 0; j < n; j++)
			q[(members[j].age / i) % 10].push(members[j]);

		int index = 0;
		for (int j = 0; j < 10; j++)
		{
			while (!q[j].empty())
			{
				members[index] = q[j].front();
				q[j].pop();
				index++;
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << members[i].age << " " << members[i].name << "\n";
}
/*

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct person
{
	int age;
	string name; //int로 바꿔주면 오류 안남
};

bool compare(const person& now, const person& last)
{
	if(now.age != last.age) return now.age < last.age;
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	person people[100001]; //구조체 배열

	for (int i = 0; i < N; i++) //배열에 값 넣어줌
		cin >> people[i].age >> people[i].name;

	//정렬
	stable_sort(people, people + N, compare);

	//답 출력
	for (int i = 0; i < N; i++)
		cout << people[i].age << " " << people[i].name << "\n";
}
*/

/*
* 
* #include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct person
{
    int age, idx;
    string name; //int로 바꿔주면 오류 안남
};

bool compare(const person& now, const person& last)
{
    if(now.age != last.age) return now.age < last.age;
    return now.idx < last.idx;
}

int main()
{	
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int N;
    cin >> N;
    person people[100001]; //구조체 배열

    for (int i = 0; i < N; i++) //배열에 값 넣어줌
    {    
        cin >> people[i].age >> people[i].name;
        people[i].idx = i;
    }

    sort(people, people + N, compare);

    //답 출력
    for (int i = 0; i < N; i++)
        cout << people[i].age << " " << people[i].name << "\n";
}
*/