//
// Created by 走线大师 on 2022/10/19.
//

typedef pair<long long, long long> StringHash;
StringHash _hash(string &str) {
    int l = str.length();
    const long long mod1 = 1e9 + 7, mod2 = 1e9 + 9;
    long long h1 = 0, h2 = 0;
    for (int i = 0; i < l; i++) {
        h1 = (h1 * 131 + str[i]) % mod1;
        h2 = (h2 * 131 + str[i]) % mod2;
    }
    return {h1, h2};
}