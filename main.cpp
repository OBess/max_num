// C++
#include <iostream>
#include <cassert>

using ull = unsigned long long;

template <int Base, int Exp>
class power
{
public:
   constexpr static ull value = power<Base, Exp - 1>::value * Base;
};

template <int Base>
class power<Base, 0>
{
public:
   constexpr static ull value = 1;
};

template <int N>
constexpr ull max_int()
{
   static_assert(N > 0 && N <= 19);
   return power<10, N>::value - 1;
}

int main()
{
   // Simple tests
   static_assert(max_int<1>() == 9);
   static_assert(max_int<2>() == 99);
   static_assert(max_int<3>() == 999);
   static_assert(max_int<4>() == 9999);
   static_assert(max_int<5>() == 99999);
   static_assert(max_int<6>() == 999999);
   static_assert(max_int<7>() == 9999999);
   static_assert(max_int<8>() == 99999999);
   static_assert(max_int<9>() == 999999999);
   static_assert(max_int<10>() == 9999999999);
   static_assert(max_int<11>() == 99999999999);
   static_assert(max_int<12>() == 999999999999);
   static_assert(max_int<13>() == 9999999999999);
   static_assert(max_int<14>() == 99999999999999);
   static_assert(max_int<15>() == 999999999999999);
   static_assert(max_int<16>() == 9999999999999999);
   static_assert(max_int<17>() == 99999999999999999);
   static_assert(max_int<18>() == 999999999999999999);
   static_assert(max_int<19>() == 9999999999999999999);
   
   // Tests for asserts
   static_assert(max_int<-1>() == 0);
   static_assert(max_int<0>() == 0);
   static_assert(max_int<20>() == 0);
   return EXIT_SUCCESS;
}