#include <iostream>
#include <sstream>
#include <string>

using namespace std;

bool succ = false;
int oper_priority(char op) 
{
	if ((op == '-') || (op == '+')) return 1;
	else if ((op == '*') || (op == '/')) return 2;
	else {
		succ = true;
		cout << "Error";
		exit(0);
		return 0;
	}
}
int sum(int a, char op, int b) 
{
	int result = 0;
	if (op == '*') result = a*b;
	else if (op == '-')result = a - b;
	else if (op == '+') result = a + b;
	else if (op == '/') 
	{
		if (b == 0) cout << "Error";
		else result = a / b;
	}
	else {
		succ = true;
		cout << "Error";
		exit(0);
		return 0;
	}
	return result;
}

int main()
{
	string string;
	int x, y, z, res = 0;
	char op, op2;
	getline(cin, string);
	istringstream stream(string);
	stream >> x;
	stream >> op;
	if (!(stream >> y)) 
	{
	    cout << x << endl; exit(0); 
	}
	while (stream >> op2) 
	{
		bool lastprior = false;
		stream >> z;
		int oper_priority1 = oper_priority(op), oper_priority2 = oper_priority(op2);
		if ((oper_priority1 > oper_priority2) || (oper_priority1 == oper_priority2)) 
		{
			x = sum(x, op, y);
			res = x;
			y = z;
			op = op2;
		}
		else if (oper_priority2 > oper_priority1) 
		{
			y = sum(y, op2, z);
			res = y;
			lastprior = true;
		}
		else 
		{ 
		    succ = true; cout << "Error"; break; 
		}
		if (!lastprior) res = sum(x, op, y);
		else res = sum(x, op, y);
	}
	if (!(stream >> op2)) 
	{
	    cout << sum(x, op, y) << endl; succ = false; return 0; 
	}
	if (!succ) cout << res << endl;
}
