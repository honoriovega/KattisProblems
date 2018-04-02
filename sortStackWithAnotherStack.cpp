
//Sort a stack using an auxiliary stack. Return the sortedstack.

#include <stack>
#include <vector>
#include <iostream>

using namespace std;

stack<int> sortStack(stack<int> s) {

	if(s.empty() ) return s;

	
	stack<int> auxiliary;
	

	
	auxiliary.push(s.top());
	s.pop();
	while(!s.empty()) {
		int temp = s.top();
		s.pop();
		while(!auxiliary.empty() && temp < auxiliary.top()) {
			s.push(auxiliary.top());
			auxiliary.pop();
		}
		
		auxiliary.push(temp);
	}	
	

	return auxiliary;
	
}

vector<int> stackWrapper(vector<int> v) {
  stack<int> s;
  for (auto el : v) {
    s.push(el);
  }
  stack<int> r = sortStack(s);
  vector<int> updated = {};
  while(!r.empty()) {
    updated.insert(updated.begin(), r.top());
    r.pop();
  }
  return updated;
}

int main()
{
	stack<int> nums;
	nums.push(10); nums.push(7), nums.push(5), nums.push(1);
	stack<int> wtf = sortStack(nums);
	
	while(! wtf.empty() ) {
		cout << wtf.top() << endl;
		wtf.pop();
	}
}