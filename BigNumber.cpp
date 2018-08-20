#include "BigNumber.h"

void BigNumber::reArrange() {
	for (int i = 0; i < num.size(); i++) {
		long long value = num[i] / scale;
		long long remain = num[i] % scale;
		if (value) {
			if (i + 1 == num.size())
				num.push_back(0);
			num[i + 1] += value;
			num[i] = remain;
		}
	}
}

BigNumber::BigNumber() { }

BigNumber::BigNumber(long long init) {
	num.push_back(init);
}

BigNumber::BigNumber(const BigNumber& init) {
	num = init.num;
}

BigNumber BigNumber::operator+(const BigNumber& other) {
	if (num.size() >= other.num.size()) {
		for (int i = 0; i < other.num.size(); i++) 
			num[i] += other.num[i];
	}
	else {
		for (int i = 0; i < num.size(); i++)
			num[i] += other.num[i];
		for (int i = num.size(); i < other.num.size(); i++)
			num.push_back(other.num[i]);
	}
	reArrange();
	return *this;
}

BigNumber BigNumber::operator*(const BigNumber& other) {
	vector<long long> temp = num;
	num.clear();
	for (int i = 0; i < temp.size(); i++)
		for (int j = 0; j < other.num.size(); j++) {
			if (num.size() <= i + j)
				num.push_back(0);
			num[i + j] += temp[i] * other.num[j];
		}
	reArrange();

	return *this;
}

void BigNumber::operator=(const BigNumber& other) {
	num = other.num;
}

void BigNumber::operator+=(const BigNumber& other) {
	*this = *this + other;
}

void BigNumber::operator*=(const BigNumber& other) {
	*this = *this * other;
}

ostream& operator<<(ostream& os, const BigNumber& bignum) {
	for (int i = bignum.num.size() - 1; i >= 0; i--) {
		if (i != bignum.num.size() - 1) {
			int cnt = 9;
			int temp = bignum.num[i];
			while (temp) {
				temp /= 10;
				cnt--;
			}
			while (cnt--)
				os << 0;
		}
		os << bignum.num[i];
	}
	return os;
}
