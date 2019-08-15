#include <cstdio>
#include <iostream>

using namespace std;

class Error {
public:
	void errormessage() {
		cout << "First or secound argument is 0"<<endl;
	}
};

template<typename T>
T divide(T a, T b) {
	if (a == 0 || b == 0) throw Error();
	return a / b;
}

int main()
{
	double score;
	try {
		score = divide(0.0, 5.0);
		cout << "Score = " << score << endl;
	}
	catch (Error msg) {
		msg.errormessage();
	}

}

