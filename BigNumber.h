#pragma once
#include <vector>
#include <ostream>
using std::vector;
using std::ostream;

class BigNumber {
private:
	const int scale = 1000000000;
	vector<long long> num;

	void reArrange(); 
public:
	BigNumber();
	BigNumber(long long);
	BigNumber(const BigNumber&);
	BigNumber operator+(const BigNumber&);
	BigNumber operator*(const BigNumber&);
	void operator=(const BigNumber&);
	void operator+=(const BigNumber&);
	void operator*=(const BigNumber&);

	friend ostream& operator<<(ostream&, const BigNumber&);
};