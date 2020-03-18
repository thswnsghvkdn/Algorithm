#include <iostream>
#include <cmath>

using namespace std;



class Brand {
	int single;
	int package;
public:
	void setPrice(int s_price, int p_price) {
		try {
			if (s_price > 1000 || p_price > 1000) throw 1;
			if (s_price < 0 || p_price < 0) throw 1;
			single = s_price;
			package = p_price;
		}
		catch (int n) {
			cout << "���� ����" << endl;
			return;
		}
	}
	int getSingle() { return single; }
	int getPackage() { return package; }
	// �μ��� ������ ��Ÿ ���� ������ ���� ������ ����
	int getSprice(int number) { return number * single; }
	int getPprice(int number) { return ceil ((double)number / 6.0) * package; }

};


class Guitar {
	int string;
	Brand* brand;
public : 
	Guitar(int s, int size) {
		try {
			if (s > 100 || size > 50) throw 1;
			if (s < 0 || size < 0) throw 1;
			string = s, brand = new Brand[size];
		}
		catch (int n) {
			cout << "���� ����" << endl;
			return;
		}
	}

	int getString() { return string; }
	Brand* getBrand() { return brand; }

	~Guitar() { delete[] brand; }
};


int main() {


	// ��Ÿ�ٰ� �귣���� ������ �޾ƿ� Guitar Ŭ���� ����
	int string, brand;
	cout << "������ ��Ÿ�ٰ� �귣���� ������ �Է��ϼ��� >> ";
	cin >> string >> brand;
	Guitar g(string, brand);

	// Guitar�� ����� �귣�忡 �������ݰ� ��Ű�������� ����
	int s_price, p_price;
	cout << "�귣���� ��Ű�� ��ǰ���ݰ� ���� ������ �Է����ּ��� " << endl;
	for (int i = 0; i < brand; i++) {
		cout << i + 1 << ':';
		cin >> p_price >> s_price;
		g.getBrand()[i].setPrice(s_price, p_price);
	}

	
	// �ּ����� �Ǻ��س�����. 
	int sum = 0, total = 0;
	while (string > 0) {
		// 6���� ū ��쿡 6�� �������� ���� ���� ���� �����Ѵ�.
		if (string > 6) {
			string -= 6;
			sum = g.getBrand()[0].getPprice(6);
			for (int i = 0; i < brand; i++) {
				if (sum > g.getBrand()[i].getPprice(6))
					sum = g.getBrand()[i].getPprice(6);
				if (sum > g.getBrand()[i].getSprice(6))
					sum > g.getBrand()[i].getSprice(6);
			}
		}
		// 6���� ���� ��쿡�� ������ ���� �������� �ּҰ��� �����Ѵ�.
		else {
			sum = g.getBrand()[0].getSprice(string);
			for (int i = 0; i < brand; i++) {
				if (sum > g.getBrand()[i].getPprice(string))
					sum = g.getBrand()[i].getPprice(string);
				if (sum > g.getBrand()[i].getSprice(string))
					sum = g.getBrand()[i].getSprice(string);
			}
			string = 0;
		}

		// ������ ���� ������ ���� ���ݿ� ���� ����.
		total += sum;
	}


	
	cout << total;
}