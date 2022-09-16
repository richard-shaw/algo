//
// Created by 走线大师 on 2022/9/11.
//


/**
 * 时间复杂度 O(sqrt(N))
 */
bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}