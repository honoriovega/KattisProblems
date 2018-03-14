#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	int hands;
	char card, suit,dominant;
	unordered_map<char, int> myMap;
	myMap['A'] = 11;
	myMap['K'] = 4;
	myMap['Q'] = 3;
	myMap['T'] = 10;

	cin >> hands >> dominant;
	int points = 0;
	for(int i = 0; i < 4 * hands; i++) {
		cin >> card >> suit;
		if(card != 'J' && card != '9')
			points += myMap[card];
		else {
			if(card == 'J')
				points += (dominant == suit ? 20 : 2);
			else 
				points += (dominant == suit ? 14 : 0);

		}
	}
	cout << points << endl;
}