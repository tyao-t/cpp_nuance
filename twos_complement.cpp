// #include <iostream> 
#include <cstdio>

int main() {    
    int a = 2, b = -2;
    bool *ac = reinterpret_cast<bool*>(&a);
    bool *bc = reinterpret_cast<bool*>(&b);

    // for (int i=0;i<sizeof(a)*8;++i)
    //     std::cout << (*(ac++));
    // std::cout << std::endl;
    // for (int i=0;i<sizeof(b)*8;++i)
    //     std::cout << (*(bc++));
    // std::cout << std::endl;
    int num_bits = sizeof(a)*8; 
    for (int i=num_bits-1;i>=0;--i) { 
        printf("%d", (a >> i) & 1);
    }
    printf("\n");
    for (int i=num_bits-1;i>=0;--i) { 
        printf("%d", (b >> i) & 1);
    }
    printf("\n");
    return 0;
}