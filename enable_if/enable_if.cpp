#include <cassert> 
#include "enable_if.h"
#include <type_traits>

using ty::enable_if_t; 

template <class T> 
enable_if_t<std::is_integral<T>::value, char> foo(T t) {
    return 'Y';
}

template <class T> 
enable_if_t<!std::is_integral_v<T>, char> foo(T t) {
    return 'N';
}

struct S {
    enum Type {int_t, float_t} type; 
    // enum class Type

    // https://stackoverflow.com/questions/60528172/whats-the-meaning-of-stdenable-if-t-0
    template <typename Integer, std::enable_if_t<std::is_integral_v<Integer>, bool> = true>
    S(Integer) : type(int_t) {} 

    template <typename Floating, std::enable_if_t<std::is_floating_point_v<Floating>, bool> = true> 
    S(Floating) : type(float_t) {}
};

// The below is wrong!
/* WRONG */
 
// struct T
// {
//     enum { int_t, float_t } type;
 
//     template<typename Integer,
//              typename = std::enable_if_t<std::is_integral<Integer>::value>>
//     T(Integer) : type(int_t) {}
 
//     template<typename Floating,
//              typename = std::enable_if_t<std::is_floating_point<Floating>::value>>
//     T(Floating) : type(float_t) {} // error: treated as redefinition
// };

int main() {
    assert(foo<int>(1) == 'Y');
    assert(foo<double>(1) == 'N');

    assert(S(1).type == S::int_t);
    assert(S(1.5).type == S::float_t);
    S s(0.0); // Good
    // No good, doesn't compile!
    // S s('c'); 

    // Constructors will need special treatment.
    // See CS246E textbook
    return 0;
}

