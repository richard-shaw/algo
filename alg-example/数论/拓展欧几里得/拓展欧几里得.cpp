//
// Created by 走线大师 on 2022/9/11.
//

int extend_gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int g = extend_gcd(b, a % b, y, x);
    y -= (a / b) * x;
    return g;
}
