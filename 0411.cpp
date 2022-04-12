#include <iostream>
#include <vector>

using namespace std;

int only_int()
{
	int num;

	cin >> num;
	if (!cin) {
		cout << "정수 형식이 아닙니다. " << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		return only_int();
	}
	return num;
}


class Calc
{
protected:
	int a;
	int b;

public:
	virtual void input() {
		cout << "두 수를 입력하시오" << endl;

		a = only_int();
		b = only_int();

	};
	virtual void output() = 0;

};




class DivCalc : public Calc {

public:
	virtual void input() override {

		cout << "나누고 싶은 ";
		Calc::input();

		if (b == 0) {
			cout << "0으로 나눌 수 없습니다\n" << endl;
			input();
		}
	}

	virtual void output() override {
		cout << a << " / " << b << " = ";
		cout << (double)a / (double)b;
	}
};


void MYCalc(Calc& obj)
{
	obj.input();
	obj.output();
}



int main()
{

	DivCalc divCalc;

	MYCalc(divCalc);


	return 0;
}