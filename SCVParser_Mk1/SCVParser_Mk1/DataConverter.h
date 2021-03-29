#pragma once
#include <type_traits>
#include <string>
#include <vector>

//enable_if: type	either T or no such member, depending on the value of B

template< typename T, typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
T Convert(std::string const& data)
{
	return std::atoll(data.c_str());
}

template< typename T, typename std::enable_if<std::is_floating_point<T>::value>::type* = nullptr>
T Convert(std::string const& data)
{
	return std::atof(data.c_str());
}

template< typename T, typename std::enable_if<std::is_convertible<T, std::string>::value>::type* = nullptr>
T Convert(std::string const& data)
{
	return std::string(data);
}

/* WRONG 

struct T {
    enum { int_t, float_t } type;
    template <typename Integer,typename = std::enable_if_t<std::is_integral<Integer>::value> > T(Integer) : type(int_t) {}

    template <typename Floating, typename = std::enable_if_t<std::is_floating_point<Floating>::value> >
    T(Floating) : type(float_t) {} // error: treated as redefinition
};

/* RIGHT

struct T {
    enum { int_t, float_t } type;
    template <typename Integer, std::enable_if_t<std::is_integral<Integer>::value, bool> = true > T(Integer) : type(int_t) {}

    template <typename Floating, std::enable_if_t<std::is_floating_point<Floating>::value, bool> = true >T(Floating) : type(float_t) {} // OK
}; 
*/