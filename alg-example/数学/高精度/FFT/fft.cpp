//
// Created by 走线大师 on 2022/10/12.
//

const double PI = acos(-1.0);
struct Complex {
    double x, y;
    Complex(double x = 0.0, double y = 0.0) : x(x), y(y) {}
    Complex operator-(const Complex &b) const { return Complex(x - b.x, y - b.y); }
    Complex operator+(const Complex &b) const { return Complex(x + b.x, y + b.y); }
    Complex operator*(const Complex &b) const { return Complex(x * b.x - y * b.y, x * b.y + y * b.x); }
};

void change(Complex y[], int len) {
    for (int i = 1, j = len / 2; i < len - 1; i++) {
        if (i < j) std::swap(y[i], y[j]);
        int k = len / 2;
        while (j >= k) j = j - k, k = k / 2;
        if (j < k) j += k;
    }
}

void fft(Complex y[], int len, bool dft) {
    change(y, len);
    for (int h = 2; h <= len; h <<= 1) {
        Complex wn(cos(2 * PI / h), (dft ? 1.0 : -1.0) * sin(2 * PI / h));
        for (int j = 0; j < len; j += h) {
            Complex w(1, 0);
            for (int k = j; k < j + h / 2; k++) {
                Complex u = y[k];
                Complex t = w * y[k + h / 2];
                y[k] = u + t;
                y[k + h / 2] = u - t;
                w = w * wn;
            }
        }
    }

    if (!dft) for (int i = 0; i < len; i++) y[i].x /= len;
}
