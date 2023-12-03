/*
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 실습11 1번 문제 코드
#include <iostream>
#include <string>

template <typename T>
T Average(T a, T b) {
	return (a + b) / 2.;
}

std::string Average(std::string s1, std::string s2) {
	std::string ss1 = s1 + " " + s2, ss2;
	int len = ss1.length();
	for (int i = 0; i < len / 2; ++i)
		ss2 += ss1[i];
	return ss2;
}

int main() {
	std::cout << Average(2.5, 3.3) << std::endl; // 2.9 출력
	std::cout << Average(2, 3) << std::endl; // 2 출력
	std::cout << Average(std::string("C++"), std::string("Programming")) << std::endl; // C++ Pro출력 ("C++" + " " + "Programming"의 앞의 1/2 문자열(소수점 이하 버림) 
} */

/*
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 실습11 2번 문제 코드
#include <iostream>
#include <vector>

template <typename T>
class Vector {
	std::vector<T> v;
public:
	Vector(T t1, T t2) {
		v.push_back(t1);
		v.push_back(t2);
	}

	std::vector<T> re_v() const {
		return v;
	}
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T> Vec) {
	int i = 0;
	for (i = 0; i < Vec.re_v().size() - 1; ++i) {
		os << Vec.re_v()[i] << ", ";
	}
	os << Vec.re_v()[i];
	return os;
}

template <>
std::ostream& operator<<(std::ostream& os, const Vector<char> Vec) {
	int i = 0;
	for (i = 0; i < Vec.re_v().size() - 1; ++i) {
		os << static_cast<int>(Vec.re_v()[i]) << ", ";
	}
	os << static_cast<int>(Vec.re_v()[i]);
	return os;
}

int main() {
	Vector<int> v1(1234, 32644);
	Vector<char> v2(121, 22);
	Vector<double> v3(1.32, 2.234);
	std::cout << v1 << std::endl; // 1234, 32644 출력
	std::cout << v2 << std::endl; // 121, 22 출력
	std::cout << v3 << std::endl; // 1.32, 2.234 출력
} */

/*
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 실습11 3번 문제 코드
#include <iostream>
#include <vector>
#include <algorithm>

struct Data {
	int x;
	Data(int x = 0) : x(x) {}
	~Data() {
		std::cout << "Destr.: " << x << std::endl;
	}
};

std::ostream& operator << (std::ostream& os, const Data& d) {
	os << d.x;
	return os;
}

template <class T>
class A {
	std::shared_ptr<T> p;
public:
	A(int x = 0) : p(new T(x)) {}
	T& get() const {
		return *p;
	}
	A copy() {
		A a(p->x);
		return a;
	}
};

int main() {
	A<Data> a1, a2(10), a3(20), a4(30);

	std::cout << a1.get() << std::endl;
	std::cout << a2.get() << std::endl;
	std::cout << a3.get() << std::endl;
	std::cout << a4.get() << std::endl;

	a1 = a2.copy();
	a3 = a4;

	std::cout << a1.get() << std::endl;
	std::cout << a2.get() << std::endl;
	std::cout << a3.get() << std::endl;
	std::cout << a4.get() << std::endl;
} */