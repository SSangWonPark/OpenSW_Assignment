#include "advanced_ops.h"
long long mypow(int a, int b) {
    long long base = a, res = 1;
    if (b < 0) return 0;          // 단순 처리
    while (b) {
        if (b & 1) res *= base;
        base *= base;
        b >>= 1;
    }
    return res;
}
