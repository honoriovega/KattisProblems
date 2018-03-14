#include <iostream>
#include <cmath>
using namespace std;

int getMaxChocolateSize(int n);
int main()
{
	int needToSample;
	cin >> needToSample;
	int chocSize = pow(2, getMaxChocolateSize(needToSample));
	int needToBuy = chocSize;
	int breaks = 0;
	
	while(needToSample != 0)
	{
		if(needToSample - chocSize < 0)
		{
			chocSize /= 2;
			breaks++;
		}
		else
			needToSample -= chocSize;
	}

	// it's a power of 2
	if(breaks == 1 and needToSample != 2)
	{
		needToBuy /= 2;
		breaks = 0;
	}
	cout << needToBuy << ' ' << breaks << endl;

		
	
}
int getMaxChocolateSize(int n)
{
	int count = 0;
	while(true)
	{
		n /= 2;
		count += 1;
		
		if(n == 0) break;
	}
	
	return count;
}




