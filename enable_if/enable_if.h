namespace ty {
    // template <bool B, class T = void> 
    // struct enable_if;
    // template <class T>
    // struct enable_if<false, T> {}; 
    template <bool B, class T = void>
    struct enable_if {};

    template <class T>
    struct enable_if<true, T> { 
        typedef T type;
        // using type = T;
    }; 

    template <bool B, class T>
    using enable_if_t = typename enable_if<B, T>::type;
}

