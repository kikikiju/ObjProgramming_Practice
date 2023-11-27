/*
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 실습10 1번 문제 코드
#include <iostream>

class Shape {
public:
	static double PI;
	virtual void area() const = 0; // 면적 계산&출력하는 순수가상함수
};
double Shape::PI = 3.14159;

class TwoDimensional : public Shape {
	virtual void round() const = 0; // 둘레 계산&출력하는 순수가상함수
};

class ThreeDimensional : public Shape {
	virtual void volume() const = 0; // 부피 계산&출력하는 순수가상함수
};

class Triangle : public TwoDimensional {
	double t1; // 삼각형 첫 번째 변 (왼쪽 변)
	double t2; // 삼각형 두 번째 변 (밑변)
	double t3; // 삼각형 세 번째 변 (오른쪽 변)
	double nop; // 삼각형 높이
public:
	Triangle(double n1, double n2, double n3, double n4) : t1(n1), t2(n2), t3(n3), nop(n4) {}

	void area() const override {
		std::cout << "삼각형 넓이(면적) : " << t2 * nop / 2 << std::endl; // 삼각형 넓이(면적) 계산&출력
	}

	void round() const override {
		std::cout << "삼각형 둘레 : " << t1 + t2 + t3 << std::endl; // 삼각형 둘레 계산&출력
	}
};

class Rectangle : public TwoDimensional {
	double garo; // 사각형 가로
	double sero; // 사각형 세로
public:
	Rectangle(double n1, double n2) : garo(n1), sero(n2) {}

	void area() const override {
		std::cout << "사각형 넓이(면적) : " << garo * sero << std::endl; // 사각형 넓이(면적) 계산&출력
	}

	void round() const override {
		std::cout << "사각형 둘레 : " << 2 * (garo + sero) << std::endl; // 사각형 둘레 계산&출력
	}
};

class Circle : public TwoDimensional {
	double r; // 원 반지름
public:
	Circle(double n1) : r(n1) {}

	void area() const override {
		std::cout << "원 넓이(면적) : " << r * r * PI << std::endl; // 원 넓이(면적) 계산&출력
	}

	void round() const override {
		std::cout << "원 둘레 : " << 2 * PI * r << std::endl; // 원 둘레 계산&출력
	}
};

class Cube : public ThreeDimensional {
	double c_garo; // 육면체 가로
	double c_sero; // 육면체 세로
	double c_nop; // 육면체 높이
public:
	Cube(double n1, double n2, double n3) : c_garo(n1), c_sero(n2), c_nop(n3) {}

	void area() const override {
		std::cout << "육면체 겉넓이(면적) : " << 2 * (c_garo * c_sero) + 2 * (c_garo * c_nop) + 2 * (c_sero * c_nop) << std::endl;
		// 육면체 겉넓이(면적) 계산&출력
	}

	void volume() const override {
		std::cout << "육면체 부피 : " << c_garo * c_sero * c_nop << std::endl; // 육면체 부피 계산&출력
	}
};

class Sphere : public ThreeDimensional {
	double s_r; // 구 반지름
public:
	Sphere(double n1) : s_r(n1) {}

	void area() const override {
		std::cout << "구 겉넓이(면적) : " << 4 * PI * s_r * s_r << std::endl; // 구 겉넓이(면적) 계산&출력
	}

	void volume() const override {
		std::cout << "구 부피 : " << (4. / 3 * PI * s_r * s_r * s_r)  << std::endl; // 구 부피 계산&출력
	}
};

int main() {
	Triangle tri(1, 2, 3, 4);
	tri.area();
	tri.round();
	std::cout << std::endl;

	Rectangle rec(3, 4);
	rec.area();
	rec.round();
	std::cout << std::endl;

	Circle c(4);
	c.area();
	c.round();
	std::cout << std::endl;

	Cube cu(2, 3, 4);
	cu.area();
	cu.volume();
	std::cout << std::endl;

	Sphere s(6);
	s.area();
	s.volume();
	std::cout << std::endl;
} */


/*
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 실습10 2번 문제 코드
#include <iostream>

class Base {
	int x; // 멤버변수 x
public:
	Base(int n) : x(n) {}

	virtual void print() const { // x 출력
		std::cout << x << std::endl;
	}

	int getx() const { // x 반환
		return x;
	}

	Base& operator= (const Base& B) { // 할당 연산자
		x = B.x;
		return *this;
	}

	void mod_x(int n) {
		x = n;
	}
};

class Derived : public Base {
	int y;
public:
	Derived(int n, int m) : Base(n), y(m) {}

	void print() const override {
		std::cout << getx() << ", " << y << std::endl;
	}

	bool operator< (Derived D) const { // 할당 연산자
		if (getx() + y < D.getx() + D.y)
			return true;
		else
			return false;
	}

	Derived& operator= (const Derived& D) { // 할당 연산자
		mod_x(D.getx()); // 현재 인스턴스의 x를 수정
		y = D.y;
		return *this;
	}
};

int main() {
	// All data members of Base and Derived classes must be declared
	// as private access types
	Base* p1 = new Derived(10, 20); // (x, y)
	Base* p2 = new Base(5); // (x)
	p1->print(); // prints 10, 20
	p1->Base::print(); // prints 10
	p2->print(); // prints 5
	Derived* p3 = dynamic_cast<Derived*>(p1);
	if (p3 != nullptr) p3->print(); // prints 10, 20
	const Base b1 = *p2;
	b1.print(); // prints 5
	Derived d1(1, 3), d2(2, 4);
	Derived d3 = (d1 < d2) ? d1 : d2; // operator <: (d1.x+d1.y) < (d2.x+d2.y)
	d3.print(); // prints 1, 3
} */

/*
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 실습10 3번 문제 코드
#include <iostream>
#include <vector>

class Base {
	int x;
	std::vector<int> v;
public:
	Base(int n) : x(n), v(n) {}

	virtual void print() const {
		std::cout << x << std::endl;
	}

	void setN(int k, int t) {
		if(k < v.size()) v[k] = t;
	}

	void printData() {
		for (int i = 0; i < v.size(); ++i) {
			std::cout << v[i] << " ";
		}
		std::cout << std::endl;
	}

	std::vector<int>& return_v() {
		return v;
	}
};

class Derived : public Base {
public:
	Derived(int n) : Base(n) {}

	void insert(int m) {
		return_v().push_back(m);
	}
};

int main() {
	Base b1(2), b2(10);
	b1.print(); // 2
	b2.print(); // 10
	for (int i = 0; i < 5; i++) {
		b1.setN(i, (i + 1) * 20);
		b2.setN(i, (i + 1) * 10);
	}
	b1.printData();  // 20 40
	b2.printData();  // 10 20 30 40 50 0 0 0 0 0
	Derived d(5); // Derived는 Base의 파생 클래스
	d.print(); // 5
	d.printData(); // 0 0 0 0 0
	for (int i = 0; i < 10; i++) {
		d.setN(i, (i + 1) * 3);
	}
	d.printData(); // 3 6 9 12 15
	d.insert(99); // Base는 insert 함수를 가지지 않음
	d.printData(); // 3 6 9 12 15 99
} */