#include <bigint.h>

template<size_t size>
bool equal(const bigint<size>& left, const bigint<size>& right){
    for(size_t i = 0; i < size; ++i)
        if (left.a[i] != right.a[i]) return false;
    return true;
}

template<size_t size>
bool less(const bigint<size>& left, const bigint<size>& right){
    for(size_t i = 0; i < size; ++i)
        if (left.a[i] != right.a[i]) return left.a[i] < right.a[i];
    return false;
}
