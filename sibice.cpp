#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n, l, w;
	cin >> n >> l >> w;
	int max =  (int) floor(sqrt(pow(l,2) + pow(w,2)));
	int temp;
	for(int i = 0; i < n; i++) {
		cin >> temp;
		cout << (temp <= max ? "DA" : "NE") << endl;
	}
}