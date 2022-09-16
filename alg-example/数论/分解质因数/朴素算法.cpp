//
// Created by 走线大师 on 2022/9/11.
//

/**
 * 返回值为一个vector，其中每一个元素是一个pair，first代表素因子，second为素因子个数
 * 算法时间复杂度 O(sqrt(N))
 * 如果预先筛出素数表，时间复杂度降低到 O(sqrt(N/lnN))
 */

vector<pair<int, int>> breakdown(int N) {
    vector<pair<int, int>> ans; ans.clear();
    for (int i = 2; i * i <= N; i++) {
        if (N % i == 0) {
            int p = 0;
            while (N % i == 0) N /= i, p++;
            ans.push_back({ i, p });
        }
    }
    if (N != 1) {
        ans.push_back({ N, 1 });
    }
    return ans;
}