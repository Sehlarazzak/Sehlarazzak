#include <iostream>
#include <vector>
#include <string>

class BigInteger {
private:
    std::vector<int> digits; 
    bool isNegative;

    void removeLeadingZeros() {
        while (digits.size() > 1 && digits.back() == 0) {
            digits.pop_back();
        }
        if (digits.size() == 1 && digits[0] == 0) {
            isNegative = false;
        }
    }

    static bool absLessThan(const BigInteger& a, const BigInteger& b) {
        if (a.digits.size() != b.digits.size()) {
            return a.digits.size() < b.digits.size();
        }
        for (int i = a.digits.size() - 1; i >= 0; --i) {
            if (a.digits[i] != b.digits[i]) {
                return a.digits[i] < b.digits[i];
            }
        }
        return false;
    }

public:
    BigInteger() : isNegative(false) { digits.push_back(0); }
    BigInteger(const std::string& num) {
        isNegative = (num[0] == '-');
        for (int i = num.length() - 1; i >= (isNegative ? 1 : 0); --i) {
            digits.push_back(num[i] - '0');
        }
        removeLeadingZeros();
    }

    BigInteger operator-() const {
        BigInteger result = *this;
        if (result.digits.size() != 1 || result.digits[0] != 0) {
            result.isNegative = !isNegative;
        }
        return result;
    }

    BigInteger operator+(const BigInteger& other) const {
        if (isNegative == other.isNegative) {
            BigInteger result;
            result.isNegative = isNegative;
            result.digits.clear();
            int carry = 0, sum;
            size_t maxSize = std::max(digits.size(), other.digits.size());
            for (size_t i = 0; i < maxSize || carry; ++i) {
                sum = carry;
                if (i < digits.size()) sum += digits[i];
                if (i < other.digits.size()) sum += other.digits[i];
                result.digits.push_back(sum % 10);
                carry = sum / 10;
            }
            return result;
        }
        return *this - (-other);
    }

    BigInteger operator-(const BigInteger& other) const {
        if (isNegative != other.isNegative) {
            return *this + (-other);
        }
        if (absLessThan(*this, other)) {
            return -(other - *this);
        }
        BigInteger result;
        result.isNegative = isNegative;
        result.digits.clear();
        int borrow = 0, diff;
        for (size_t i = 0; i < digits.size(); ++i) {
            diff = digits[i] - borrow - (i < other.digits.size() ? other.digits[i] : 0);
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            result.digits.push_back(diff);
        }
        result.removeLeadingZeros();
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const BigInteger& num) {
        if (num.isNegative) os << "-";
        for (int i = num.digits.size() - 1; i >= 0; --i) {
            os << num.digits[i];
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, BigInteger& num) {
        std::string input;
        is >> input;
        num = BigInteger(input);
        return is;
    }
};

int main() {
    BigInteger num1, num2;
    std::cout << "Enter first big integer: ";
    std::cin >> num1;
    std::cout << "Enter second big integer: ";
    std::cin >> num2;
    
    std::cout << "Sum: " << (num1 + num2) << std::endl;
    std::cout << "Difference: " << (num1 - num2) << std::endl;
    
    return 0;
}

