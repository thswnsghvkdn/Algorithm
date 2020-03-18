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
			cout << "범위 오류" << endl;
			return;
		}
	}
	int getSingle() { return single; }
	int getPackage() { return package; }
	// 인수로 끊어진 기타 줄을 가져와 낱개 가격을 리턴
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
			cout << "범위 오류" << endl;
			return;
		}
	}

	int getString() { return string; }
	Brand* getBrand() { return brand; }

	~Guitar() { delete[] brand; }
};


int main() {


	// 기타줄과 브랜드의 갯수를 받아와 Guitar 클래스 생성
	int string, brand;
	cout << "끊어진 기타줄과 브랜드의 갯수를 입력하세요 >> ";
	cin >> string >> brand;
	Guitar g(string, brand);

	// Guitar의 멤버인 브랜드에 낱개가격과 패키지가격을 설정
	int s_price, p_price;
	cout << "브랜드의 패키지 상품가격과 낱개 가격을 입력해주세요 " << endl;
	for (int i = 0; i < brand; i++) {
		cout << i + 1 << ':';
		cin >> p_price >> s_price;
		g.getBrand()[i].setPrice(s_price, p_price);
	}

	
	// 최소합을 판별해나간다. 
	int sum = 0, total = 0;
	while (string > 0) {
		// 6보다 큰 경우에 6을 기준으로 제일 작은 값을 선별한다.
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
		// 6보다 작은 경우에는 나머지 줄을 기준으로 최소값을 선별한다.
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

		// 선별해 나갈 때마다 최종 가격에 합해 간다.
		total += sum;
	}


	
	cout << total;
}