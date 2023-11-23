#include <iostream>
#include <vector>
#include <string>
class BigUnsigned {
    std::vector<int> v;
public:
    BigUnsigned() : v({ 0 }) {}
    BigUnsigned(unsigned int n) {
        if (n == 0) v.push_back(0);
        std::vector<int> iv;
        while (n > 0) {
            iv.push_back(n % 10);
            n /= 10;
        }// 각 자리수 벡터에 저장 ... 하지만 거꾸로 저장됨
        for (int i = iv.size() - 1; i >= 0; --i) {
            v.push_back(iv[i]);
        } // 각 자리수 순서대로 돌려줌(큰 자리수 먼저)
    }
    BigUnsigned(std::string s) {
        for (int j = 0; j < s.size(); ++j) {
            v.push_back(static_cast<int> (s[j]) - '0');
        }
    }
    std::vector<int> GetV() {
        return v;
    }
    void Re_V(std::vector<int> Up_v) {
        v = Up_v;
    }
};
BigUnsigned operator+(BigUnsigned b1, BigUnsigned b2) {
    BigUnsigned B;
    int size_1 = b1.GetV().size(), size_2 = b2.GetV().size();
    std::vector<int> v1(size_1), v2(size_2);
    for (int i = 0; i < size_1; ++i) {
        v1[i] = b1.GetV()[size_1 - i - 1];
    }
    for (int j = 0; j < size_2; ++j) {
        v2[j] = b2.GetV()[size_2 - j - 1];
    }
    int v_size = (size_1 > size_2 ? size_1 : size_2);
    std::vector<int> Vec(v_size);
    int th = 0;
    for (int c = 0; c < v_size; ++c) {
        int sum = th;
        if (c < v1.size()) {
            sum += v1[c];
        }
        if (c < v2.size()) {
            sum += v2[c];
        }
        Vec[c] = sum % 10;
        th = sum / 10;
    }
    if (th > 0) {
        Vec.push_back(th);
    }
    std::vector<int> plus_vector(Vec.size());
    for (int k = 0; k < Vec.size(); ++k) {
        plus_vector[k] = Vec[Vec.size() - k - 1];
    }
    B.Re_V(plus_vector);
    return B;
}
std::ostream& operator<<(std::ostream& os, BigUnsigned B) {
    int h = B.GetV().size();
    for (int i = 0; i < B.GetV().size(); ++i)
        os << B.GetV()[i];
    return os;
}
int main() {
    BigUnsigned a("12345"), b(678);
    BigUnsigned c = a + b;
    std::cout << c << std::endl;
    BigUnsigned m, n("3456"), k(123);
    BigUnsigned t = m + n + k;
    std::cout << t << std::endl;
}