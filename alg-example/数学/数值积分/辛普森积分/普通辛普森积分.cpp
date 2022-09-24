//
// Created by 走线大师 on 2022/9/17.
//

const int N = 1000 * 1000;
double simpson_integration(double a, double b) {
    double d = (b - a) / N;
    double s = f(a) + f(b);
    for (int i = 1; i < N; i++) {
        double x = a + d * i;
        s += f(x) * ((i & 1) ? 4 : 2);
    }
    s *= d / 3;
    return s;
}