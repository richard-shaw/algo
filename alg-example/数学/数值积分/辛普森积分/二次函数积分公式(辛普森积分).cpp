//
// Created by 走线大师 on 2022/9/17.
//


/**
 * 只用于二次函数的积分
 * @param a 积分下限
 * @param b 积分上限
 * @return
 */
double simpson(double a, double b) {
    return (b-a) / 6 * (f(a) + f(b) + 4 * f((a + b) / 2))
}