/*
 * utils.h
 *
 *  Created on: 10-Nov-2010
 *      Author: vivek
 */

#ifndef UTILS_H_
#define UTILS_H_

template<bool> struct STATIC_ASSERT_FAILURE;
template<> struct STATIC_ASSERT_FAILURE<true>{};
template<int X> struct static_assert_test{};

#define STATIC_ASSSERT(B, error) \
	typedef static_assert_test< sizeof(STATIC_ASSERT_FAILURE<(bool)B, error>) > \
	static_assert_typedef_;

struct SIZEOF_INT_NOT_EQUAL_TO_LONG{};

template <int X, template<int> class F>
struct Accumulate
{
	enum { value = Accumulate<X-1,F>::value + F<X>::value};
};

template <template<int> class F>
struct Accumulate<0, F>
{
	enum { value = F<0>::value };
};

template <int N>
class Factorial
{
public:
	enum { value = N*Factorial<N-1>::value };
};

template <>
class Factorial<0>
{
public:
	enum { value = 1 };
};

template<int X>
struct Square
{
	enum { value = X*X };
};

#endif /* UTILS_H_ */
