#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	unordered_map<char, int> myMap;
	string s;
	cin >> s;
	
	for(auto c : s) 
		myMap[c] = (myMap[c] ? myMap[c] + 1 : 1);
	
	int total = 0;
	for(auto it : myMap) 
		total += it.second * it.second;
		
	if(myMap.size() == 3)
		total += 7 * min( min(myMap['C'],myMap['G']),myMap['T']);

	cout << total << endl;
		
}