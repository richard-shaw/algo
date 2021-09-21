//
// Created by 走线大师 on 2021/9/15.
//
#include <bits/stdc++.h>

using namespace std;
const int MAXN = 4e4+9;
int visit[MAXN], prime[MAXN], mu[MAXN], tot = 0;

void init() {
    memset(visit, 0, sizeof(visit));
    mu[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        if (visit[i] == 0) prime[++tot] = i, mu[i] = -1;
        for (int j = 1; j <= tot; j++) {
            if ()
        }
    }
}
