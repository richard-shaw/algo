//
// Created by Shaw on 2022/10/6.
//

#include <bits/stdc++.h>

class BigInt {
private:
    enum CompareFlag { LESS, EQUAL, GREATER };
    typedef long long LL;
    static const int BASE = 1e8;
    static const int DLEN = 8;
    static const int MAX_SIZE = 10024;
    int s[MAX_SIZE], len;
    bool negative_flag;
    bool is_zero();
    bool is_negative();
    bool is_positive();
    CompareFlag abs_compare(BigInt & A, BigInt &B);
    BigInt abs_add(BigInt &A, BigInt &B);
    BigInt abs_sub(BigInt &A, BigInt &B);
    BigInt clone();
    void prs(int k);
    void pls(int k);
    LL toLL();
public:
    BigInt();
    explicit BigInt(LL b);
    explicit BigInt(int b);
    explicit BigInt(const char* buf);
    explicit BigInt(std::string & buf);
    bool operator == (BigInt & B);
    bool operator != (BigInt & B);
    bool operator < (BigInt & B);
    bool operator <= (BigInt & B);
    bool operator > (BigInt & B);
    bool operator >= (BigInt & B);
    BigInt operator - ();
    BigInt & operator += (BigInt &B);
    BigInt & operator += (LL b);
    BigInt & operator -= (BigInt &B);
    BigInt & operator -= (LL b);
    BigInt & operator *= (BigInt &B);
    BigInt & operator *= (LL b);
    BigInt & operator /= (BigInt &B);
    BigInt & operator /= (LL b);
    BigInt & operator %= (BigInt &B);
    BigInt & operator %= (LL b);
    BigInt& operator++ ();
    const BigInt operator++ (int);
    BigInt& operator-- ();
    const BigInt operator--(int);
    BigInt operator + (BigInt &B);
    BigInt operator + (LL b);
    BigInt operator - (BigInt &B);
    BigInt operator - (LL b);
    BigInt operator * (BigInt &B);
    BigInt operator * (LL b);
    BigInt operator / (BigInt &B);
    BigInt operator / (LL b);
    BigInt operator % (BigInt &B);
    BigInt operator % (LL b);

    BigInt right_shift(int k);
    BigInt left_shift(int k);
    friend std::ostream& operator << (std::ostream &os, BigInt B);
    friend std::istream& operator >> (std::istream &is, BigInt &B);

    static BigInt factorial(int n);
};

bool BigInt::is_zero() {
    return len == 1 && s[0] == 0;
}

bool BigInt::is_negative() {
    return !is_zero() && negative_flag;
}

bool BigInt::is_positive() {
    return !is_zero() && !is_negative();
}

BigInt::CompareFlag BigInt::abs_compare(BigInt &A, BigInt &B) {
    if (A.len < B.len) return LESS;
    if (A.len > B.len) return GREATER;
    for (int i = A.len - 1; ~i; --i) {
        if (A.s[i] > B.s[i]) return GREATER;
        if (A.s[i] < B.s[i]) return LESS;
    }
    return EQUAL;
}

BigInt BigInt::abs_add(BigInt &A, BigInt &B) {
    BigInt ans; ans.negative_flag = false, ans.len = std::max(A.len, B.len);
    int pr = 0;
    for (int i = 0; i < ans.len; i++) {
        ans.s[i] = pr;
        if (i < A.len) ans.s[i] += A.s[i];
        if (i < B.len) ans.s[i] += B.s[i];

        pr = 0;
        while (ans.s[i] >= BASE) pr ++, ans.s[i] -= BASE;
    }
    if (pr > 0) ans.s[ans.len++] = pr;
    return ans;
}

BigInt BigInt::abs_sub(BigInt &A, BigInt &B) {
    if (abs_compare(A, B) == LESS) {
        return -abs_sub(B, A);
    }
    BigInt ans; ans.len = A.len, ans.negative_flag = false;
    int pr = 0;
    for (int i = 0; i < A.len; i++) {
        int k = A.s[i] - pr;
        if (i < B.len) k -= B.s[i];
        pr = 0;
        while (k < 0) k += BASE, pr++;
        ans.s[i] = k;
    }
    while(ans.len > 1 && ans.s[ans.len-1] == 0) ans.len--;
    return ans;
}

BigInt BigInt::clone() {
    BigInt cloned;
    cloned.len = len;
    cloned.negative_flag = negative_flag;
    for (int i = 0; i < len; i++) cloned.s[i] = s[i];
    return cloned;
}

void BigInt::prs(int k) {
    for (int i = len - 1; ~i; --i) s[i + k] = s[i];
    for (int i = 0; i < k; i++) s[i] = 0;
    len += k;
}

void BigInt::pls(int k) {
    for (int i = k; i < len; i++) {
        s[i-k] = s[i];
    }
    len = std::max(0, len - k);
}

BigInt::LL BigInt::toLL() {
    LL ans = 0;
    for (int i = len - 1; ~i; --i) ans = ans * BASE + s[i];
    if (negative_flag) ans = -ans;
    return ans;
}

BigInt::BigInt() {
    s[0] = 0;
    len = 1;
    negative_flag = false;
}

BigInt::BigInt(BigInt::LL b) : BigInt() {
    if (b != 0) {
        if (b < 0) b = -b, negative_flag = true;
        len = 0;
        while (b > 0) {
            s[len++] = b % BASE;
            b /= BASE;
        }
    }
}

BigInt::BigInt(int b) : BigInt((LL) b) {}

BigInt::BigInt(const char *buf) {
    int l = strlen(buf), st = buf[0] == '-' ? 1 : 0;
    negative_flag = buf[0] == '-';
    len = 0;
    for (int j = l - 1; j >= st; j -= DLEN) {
        int k = 0;
        for (int i = std::max(st, j - DLEN + 1); i <= j; i++) {
            k = 10 * k + buf[i] - '0';
        }
        s[len++] = k;
    }
}

BigInt::BigInt(std::string &buf) : BigInt(buf.c_str()) {}

bool BigInt::operator==(BigInt &B) {
    if (is_zero()) return B.is_zero();
    if (negative_flag ^ B.negative_flag) return false;
    if (len != B.len) return false;
    for (int i = 0; i < len; i++) if (s[i] != B.s[i]) return false;
    return true;
}

bool BigInt::operator!=(BigInt &B) {
    return !((*this) == B);
}

bool BigInt::operator<(BigInt &B) {
    if (is_negative()) {
        if (B.is_zero() || B.is_positive()) return true;
        else return abs_compare(*this, B) == GREATER;
    } else if (is_zero()) {
        return B.is_positive();
    } else {
        if (B.is_zero() || B.is_negative()) return false;
        return abs_compare(*this, B) == LESS;
    }
}

bool BigInt::operator<=(BigInt &B) {
    return (*this) == B || (*this) < B;
}

bool BigInt::operator>(BigInt &B) {
    return !((*this) <= B);
}

bool BigInt::operator>=(BigInt &B) {
    return !((*this) < B);
}

BigInt BigInt::operator-() {
    BigInt ans(*this);
    ans.negative_flag = !ans.negative_flag;
    return ans;
}

BigInt &BigInt::operator+=(BigInt &B) {
    *this = *this + B;
    return *this;
}

BigInt &BigInt::operator+=(BigInt::LL b) {
    *this = *this + b;
    return *this;
}

BigInt &BigInt::operator-=(BigInt &B) {
    *this = *this - B;
    return *this;
}

BigInt &BigInt::operator-=(BigInt::LL b) {
    *this = *this - b;
    return *this;
}

BigInt &BigInt::operator*=(BigInt &B) {
    *this = (*this) * B;
    return *this;
}

BigInt &BigInt::operator*=(BigInt::LL b) {
    *this = (*this) * b;
    return *this;
}

BigInt &BigInt::operator/=(BigInt &B) {
    *this = (*this) / B;
    return *this;
}

BigInt &BigInt::operator/=(BigInt::LL b) {
    *this = (*this) / b;
    return *this;
}

BigInt &BigInt::operator%=(BigInt &B) {
    *this = (*this) % B;
    return *this;
}

BigInt &BigInt::operator%=(BigInt::LL b) {
    *this = (*this) % b;
    return *this;
}

BigInt &BigInt::operator++() {
    (*this) += 1;
    return *this;
}

const BigInt BigInt::operator++(int) {
    BigInt tmp = clone();
    (*this) += 1;
    return tmp;
}

BigInt &BigInt::operator--() {
    (*this) -= 1;
    return *this;
}

const BigInt BigInt::operator--(int) {
    BigInt tmp = clone();
    (*this) -= 1;
    return tmp;
}

BigInt BigInt::operator+(BigInt &B) {
    if (is_zero()) return B;
    if (B.is_zero()) return *this;

    if (is_positive() && B.is_positive()) return abs_add(*this, B);
    else if (is_negative() && B.is_negative()) return -abs_add(*this, B);
    else if (is_positive() && B.is_negative()) return abs_sub(*this, B);
    else return abs_sub(B, *this);
}

BigInt BigInt::operator+(BigInt::LL b) {
    BigInt B = BigInt(b);
    return *this + B;
}

BigInt BigInt::operator-(BigInt &B) {
    if (is_zero()) return -B;
    if (B.is_zero()) return *this;

    if (is_positive() && B.is_negative()) return abs_add(*this, B);
    else if (is_negative() && B.is_positive()) return -abs_add(*this, B);
    else if (is_positive() && B.is_positive()) return abs_sub(*this, B);
    else return abs_sub(B, *this);
}

BigInt BigInt::operator-(BigInt::LL b) {
    BigInt B = BigInt(b);
    return *this - B;
}

BigInt BigInt::operator*(BigInt &B) {
    if (B.is_zero()) return BigInt(0);
    else if (B.is_negative()) {
        BigInt nB = -B;
        return -((*this) * nB);
    }
    BigInt ans(0);

    for (int i = 0; i < B.len; i++) {
        BigInt sub = (*this) * B.s[i];
        sub.prs(i);
        ans += sub;
    }
    return ans;
}

BigInt BigInt::operator*(BigInt::LL b) {
    if (b == 0) return BigInt(0);
    else if (b < 0) return -((*this) * (-b));
    BigInt ans;
    ans.len = len, ans.negative_flag = negative_flag;
    LL pr = 0;
    for (int i = 0; i < len; i++) {
        LL k = b * s[i] + pr;
        pr = k / BASE;
        ans.s[i] = k % BASE;
    }
    while (pr > 0) ans.s[ans.len++] = pr % BASE, pr /= BASE;
    return ans;
}

BigInt BigInt::operator/(BigInt &B) {
    assert(!B.is_zero());
    if (B.len <= 2) return *this / B.toLL();
    if (abs_compare(*this, B) == LESS) return BigInt(0);
    if (B.is_negative()) {
        BigInt nB = -B;
        return -((*this) / nB);
    }

    BigInt ans; ans.len = len - B.len;
    BigInt pr = left_shift(len - B.len + 1);
    for (int i = ans.len - 1; ~i; --i) {
        pr = pr * BASE + s[i];

        LL _l = 0, _r = BASE - 1;
        while (_l + 1 < _r) {
            LL m = (_l + _r) >> 1;
            BigInt ml = B * m;
            CompareFlag flag = abs_compare(ml, pr);
            if (flag == EQUAL) { _l = _r = m; break; }
            if (flag == LESS) _l = m;
            else _r = m;
        }
        if (_l < _r) {
            BigInt ml = B * _r;
            if (abs_compare(ml, pr) != GREATER) _l = _r;
        }

        ans.s[i] = _r;
        BigInt tmp = B * _r;
        pr -= tmp;
    }
    while (ans.len > 1 && ans.s[ans.len-1] == 0) ans.len--;
    return ans;
}

BigInt BigInt::operator/(BigInt::LL b) {
    assert(b != 0);
    if (b < 0) {
        return -((*this) / (-b));
    }

    BigInt ans;
    ans.len = len;

    LL pr = 0;
    for (int i = len - 1; ~i; --i) {
        LL cur = pr * BASE + s[i];
        LL k = cur / b;
        ans.s[i] = k;
        pr = cur - k * b;
    }

    while (ans.len > 1 && ans.s[ans.len-1] == 0) ans.len--;
    return ans;
}

BigInt BigInt::operator%(BigInt &B) {
    BigInt k = (*this) / B;
    k *= B;
    return (*this) - k;
}

BigInt BigInt::operator%(BigInt::LL b) {
    BigInt k = (*this) / b;
    k *= b;
    return (*this) - k;
}

BigInt BigInt::right_shift(int k) {
    BigInt ans = clone();
    ans.prs(k);
    return ans;
}

BigInt BigInt::left_shift(int k) {
    BigInt ans = clone();
    ans.pls(k);
    return ans;
}

std::ostream &operator<<(std::ostream &os, BigInt B) {
    if (B.negative_flag) os << '-';
    for (int i = B.len - 1; ~i; --i) {
        int l = std::to_string(B.s[i]).length();
        if (i != B.len - 1) while (l < B.DLEN) l++, os << '0';
        os << B.s[i];
    }
    return os;
}

std::istream &operator>>(std::istream &is, BigInt &B) {
    std::string buf; is >> buf;
    B = BigInt(buf);
    return is;
}

BigInt BigInt::factorial(int n)  {
    BigInt ans(1);
    for (int i = 1; i <= n; i++) ans *= i;
    return ans;
}