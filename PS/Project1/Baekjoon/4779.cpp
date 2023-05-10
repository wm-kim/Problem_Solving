#include <iostream>
using namespace std;

string Cantor(string s)
{
	if (s.length() == 1) return s;
	for (int i = s.length() / 3; i < s.length() * 2 / 3; i++) s[i] = ' ';
	return Cantor(s.substr(0, s.length() / 3)) 
		+ s.substr(s.length() / 3, s.length() / 3) 
		+ Cantor(s.substr(s.length() * 2 / 3, s.length() / 3));
}

int main()
{
	int n; 
	while (cin >> n)
	{
		string s = "-";
		for (int i = 0; i < n; i++) { s = s + s + s; }
		cout << Cantor(s) << endl;
	}
}
/*
using namespace std;

void sol(int n){
    if(n==0){
        printf("-"); return ;
    }
    sol(n-1);
    for(int i=0; i<pow(3, n-1); i++)
        printf(" ");
    sol(n-1);

}

int main (void){
    int n;
    while (scanf("%d", &n) != EOF){
        sol(n);
        printf("\n");
    }
}
*/