template<size_t size>
bigint<size> bigint<size>::one(){
    bigint<size> number;
    move(number, 1);
    return number;
}

template<size_t size>
bigint<size> bigint<size>::zero(){
    bigint<size> number;
    move(number, 0);
    return number;
}
