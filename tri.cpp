#include <iostream>
#include <string>
using namespace std;


int check(const int a, const int  b, const int c);

int main() {

	
	string signs[] = {"+","-","/","*"};

	int a, b, c;
	cin >> a >> b >> c;
	
	int solution = check(a,b,c);
	if(solution!= -1) {
		cout << a << "=" << b << signs[solution] << c << endl;

	} else {
		solution = check(c,a,b);
		cout << a << signs[solution] << b << "=" << c << endl;

	}
	
	
	
}

int check(const int a, const int  b, const int c) {
	int result[4];
	
	result[0] = b + c;
	result[1] = b - c;
	result[2] = b / c;
	result[3] = b * c;
	
	for(int i = 0; i < 4; i++) {
		if(a == result[i]) {
			return i;
		}
	}
	
	return -1;

}