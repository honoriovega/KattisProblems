#include <unordered_set>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	unordered_set<string> mySet;
	string uni, name;
	int n;
	cin >> n;
	while(mySet.size() != 12) {
		cin >> uni >> name;
		if( mySet.count(uni) == 0 ) {
			mySet.insert(uni);
			cout << uni << ' ' << name << endl;
		}
	}
}