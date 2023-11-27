/*
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! �ǽ�10 1�� ���� �ڵ�
#include <iostream>

class Shape {
public:
	static double PI;
	virtual void area() const = 0; // ���� ���&����ϴ� ���������Լ�
};
double Shape::PI = 3.14159;

class TwoDimensional : public Shape {
	virtual void round() const = 0; // �ѷ� ���&����ϴ� ���������Լ�
};

class ThreeDimensional : public Shape {
	virtual void volume() const = 0; // ���� ���&����ϴ� ���������Լ�
};

class Triangle : public TwoDimensional {
	double t1; // �ﰢ�� ù ��° �� (���� ��)
	double t2; // �ﰢ�� �� ��° �� (�غ�)
	double t3; // �ﰢ�� �� ��° �� (������ ��)
	double nop; // �ﰢ�� ����
public:
	Triangle(double n1, double n2, double n3, double n4) : t1(n1), t2(n2), t3(n3), nop(n4) {}

	void area() const override {
		std::cout << "�ﰢ�� ����(����) : " << t2 * nop / 2 << std::endl; // �ﰢ�� ����(����) ���&���
	}

	void round() const override {
		std::cout << "�ﰢ�� �ѷ� : " << t1 + t2 + t3 << std::endl; // �ﰢ�� �ѷ� ���&���
	}
};

class Rectangle : public TwoDimensional {
	double garo; // �簢�� ����
	double sero; // �簢�� ����
public:
	Rectangle(double n1, double n2) : garo(n1), sero(n2) {}

	void area() const override {
		std::cout << "�簢�� ����(����) : " << garo * sero << std::endl; // �簢�� ����(����) ���&���
	}

	void round() const override {
		std::cout << "�簢�� �ѷ� : " << 2 * (garo + sero) << std::endl; // �簢�� �ѷ� ���&���
	}
};

class Circle : public TwoDimensional {
	double r; // �� ������
public:
	Circle(double n1) : r(n1) {}

	void area() const override {
		std::cout << "�� ����(����) : " << r * r * PI << std::endl; // �� ����(����) ���&���
	}

	void round() const override {
		std::cout << "�� �ѷ� : " << 2 * PI * r << std::endl; // �� �ѷ� ���&���
	}
};

class Cube : public ThreeDimensional {
	double c_garo; // ����ü ����
	double c_sero; // ����ü ����
	double c_nop; // ����ü ����
public:
	Cube(double n1, double n2, double n3) : c_garo(n1), c_sero(n2), c_nop(n3) {}

	void area() const override {
		std::cout << "����ü �ѳ���(����) : " << 2 * (c_garo * c_sero) + 2 * (c_garo * c_nop) + 2 * (c_sero * c_nop) << std::endl;
		// ����ü �ѳ���(����) ���&���
	}

	void volume() const override {
		std::cout << "����ü ���� : " << c_garo * c_sero * c_nop << std::endl; // ����ü ���� ���&���
	}
};

class Sphere : public ThreeDimensional {
	double s_r; // �� ������
public:
	Sphere(double n1) : s_r(n1) {}

	void area() const override {
		std::cout << "�� �ѳ���(����) : " << 4 * PI * s_r * s_r << std::endl; // �� �ѳ���(����) ���&���
	}

	void volume() const override {
		std::cout << "�� ���� : " << (4. / 3 * PI * s_r * s_r * s_r)  << std::endl; // �� ���� ���&���
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
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! �ǽ�10 2�� ���� �ڵ�
#include <iostream>

class Base {
	int x; // ������� x
public:
	Base(int n) : x(n) {}

	virtual void print() const { // x ���
		std::cout << x << std::endl;
	}

	int getx() const { // x ��ȯ
		return x;
	}

	Base& operator= (const Base& B) { // �Ҵ� ������
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

	bool operator< (Derived D) const { // �Ҵ� ������
		if (getx() + y < D.getx() + D.y)
			return true;
		else
			return false;
	}

	Derived& operator= (const Derived& D) { // �Ҵ� ������
		mod_x(D.getx()); // ���� �ν��Ͻ��� x�� ����
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
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! �ǽ�10 3�� ���� �ڵ�
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
	Derived d(5); // Derived�� Base�� �Ļ� Ŭ����
	d.print(); // 5
	d.printData(); // 0 0 0 0 0
	for (int i = 0; i < 10; i++) {
		d.setN(i, (i + 1) * 3);
	}
	d.printData(); // 3 6 9 12 15
	d.insert(99); // Base�� insert �Լ��� ������ ����
	d.printData(); // 3 6 9 12 15 99
} */