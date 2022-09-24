//
// Created by 走线大师 on 2022/9/11.
//

const int maxn = 1e6 + 10;
int _visit[maxn], prime[maxn], tot = 0;

void init() {
    memset(_visit, 0, sizeof(_visit));
    for (int i = 2; i < maxn; i++) {
        if (!_visit[i]) prime[++tot] = i;
        for (int j = 1; j <= tot && i * prime[j] < maxn; j++) {
            _visit[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}