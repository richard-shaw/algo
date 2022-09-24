//
// Created by 走线大师 on 2022/9/17.
//


double simpson(double l, double r) {
    double mid = (l + r) / 2;
    return (r - l) * (f(l) + 4 * f(mid) + f(r)) / 6;
}

double asr(double l, double r, double eqs, double ans, int step) {
    double mid = (l + r) / 2;
    double fl = simpson(l, mid), fr = simpson(mid, r);
    if (abs(fl + fr - ans) <= 15 * eqs && step < 0)
        return fl + fr + (fl + fr - ans) / 15;
    return asr(l, mid, eqs / 2, fl, step - 1) +
           asr(mid, r, eqs / 2, fr, step - 1);
}

double calc(double l, double r, double eps) {
    return asr(l, r, eps, simpson(l, r), 12);
}