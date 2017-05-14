#include <iostream>
#include <cstdlib>
#include <cstdint>

static uint32_t bigint_overflow;

template<size_t tsize>
class bigint{
    uint32_t* a;
public:
    bigint() {
        if (tsize <= 0) throw "logic error: bigint size should be > 0.";
        a = new uint32_t[tsize];
        if (tsize > 0x7fffffff) std::cout << "multiply operations may have undefined behavior" << std::endl;
    }

    static bigint<tsize> one();
    static bigint<tsize> zero();

    template<size_t end_size, size_t start_size>
    friend bigint<end_size> format(const bigint<start_size>& operand);

    template<size_t size>
    friend void move(bigint<size>& left, uint32_t value);
    template<size_t size>
    friend void copy(bigint<size>& left, const bigint<size>& right);
    template<size_t size>
    friend void exchange(bigint<size>& left, bigint<size>& right);
    inline const bigint<tsize>& operator=(uint32_t value) {move(*this, value); return *this;}
    inline const bigint<tsize>& operator=(const bigint<tsize>& another) {copy(*this, another); return *this;}

    template<size_t size>
    friend bigint<size> add(const bigint<size>& left_number, const bigint<size>& right_number);
    template<size_t size>
    friend bigint<size> adc(const bigint<size>& left_number, const bigint<size>& right_number);
    template<size_t size>
    friend bigint<size> sub(const bigint<size>& left_number, const bigint<size>& right_number);
    template<size_t size>
    friend bigint<size> sbb(const bigint<size>& left_number, const bigint<size>& right_number);

    template<size_t size>
    friend bigint<size> mul(const bigint<size>& left_number, const bigint<size>& right_number);
    template<size_t size>
    friend bigint<size> mul(const bigint<size>& left_number, uint32_t right_number);
    template<size_t size>
    friend bigint<size + 1> extended_mul(const bigint<size>& left_number, uint32_t right_number);
    template<size_t size>
    friend bigint<size * 2> extended_mul(const bigint<size>& left_number, const bigint<size>& right_number);
    template<size_t size>
    friend bigint<size> div(const bigint<size>& left_number, const bigint<size>& right_number);
    template<size_t size>
    friend bigint<size> mod(const bigint<size>& left_number, const bigint<size>& right_number);
    template<size_t size>
    friend std::pair<bigint<size>, bigint<size>> div_mod(const bigint<size>& left_number, const bigint<size>& right_number);

    ///Bitwise operators
    template<size_t size>
    friend bigint<size> operator&(const bigint<size>& left, const bigint<size>& right);
    template<size_t size>
    friend bigint<size> operator|(const bigint<size>& left, const bigint<size>& right);
    template<size_t size>
    friend bigint<size> operator^(const bigint<size>& left, const bigint<size>& right);

    ///Bit search functions

    ///compare operators
    template<size_t size>
    friend bool less(const bigint<size>& left, const bigint<size>& right);
    template<size_t size>
    friend bool equal(const bigint<size>& left, const bigint<size>& right);
    template<size_t size>
    inline friend bool operator==(const bigint<tsize>& left, const bigint<tsize>& right) {return equal(left, right);}
    template<size_t size>
    inline friend bool operator!=(const bigint<tsize>& left, const bigint<tsize>& right) {return !equal(left, right);}
    template<size_t size>
    inline friend bool operator< (const bigint<tsize>& left, const bigint<tsize>& right) {return less(left, right);}
    template<size_t size>
    inline friend bool operator> (const bigint<tsize>& left, const bigint<tsize>& right) {return less(right, left);}
    template<size_t size>
    inline friend bool operator>=(const bigint<tsize>& left, const bigint<tsize>& right) {return !less(left, right);}
    template<size_t size>
    inline friend bool operator<=(const bigint<tsize>& left, const bigint<tsize>& right) {return !less(right, left);}

    ///shifts
    void fast_shl(size_t modify);
    void fast_shr(size_t modify);

    ///iostream operators
    template<size_t size>
    friend std::istream& operator>>(std::istream& in, bigint<size>& right);
    template<size_t size>
    friend std::ostream& operator<<(std::ostream& out, bigint<size>& right);
};
