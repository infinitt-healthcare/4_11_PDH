#include <iostream>
#include <vector>

using namespace std;

int only_int()
{
	int num;

	cin >> num;
	if (!cin) {
		cout << "���� ������ �ƴմϴ�. " << endl;
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
		cout << "�� ���� �Է��Ͻÿ�" << endl;

		a = only_int();
		b = only_int();

	};
	virtual void output() = 0;

};




class DivCalc : public Calc {

public:
	virtual void input() override {

		cout << "������ ���� ";
		Calc::input();

		if (b == 0) {
			cout << "0���� ���� �� �����ϴ�\n" << endl;
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