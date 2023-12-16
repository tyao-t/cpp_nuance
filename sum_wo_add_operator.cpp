#include <cassert> 
#include <cmath>

int getSum(int a, int b) {
    while (b != 0) {
        int carry = (a & b) << 1;
        a = a ^ b;
        b = carry;
    }
    return a;
}

/* int getSum(int a, int b) {
    return (b == 0) ? a : getSum(a^b, ((a&b) << 1));
} */

int main() {
    assert(getSum(1, 2) == 3);
    assert(getSum(2, -2) == 0);
    assert(getSum(100, -102) == -2);
    assert(getSum(1000, 8008) == 9008);
    // Undefined behavior: 
    // assert(1073741824, 1073741824 == 2147483648); 
    return 0;
}