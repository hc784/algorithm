#include <stack>
#include <iostream>

using namespace std;


int main() {


	int tc;
	cin >> tc;
	while (tc--)
	{
		stack<char> sta;
		string str;
		cin >> str;
		bool ok = true;
		for (char a : str) {
			
			
			if (a == '(') {
				sta.push(a);
			}
			else if (a == ')') {
				if (sta.empty())
				{
					cout << "NO"<<endl;
					ok = false;
					break;
				}
				else {
					sta.pop();
				}

			}
		}
		if (ok && sta.empty())
			cout << "YES" << endl;
		else if(ok==true) cout << "NO"<<endl;
	}
		
	return 0;
}