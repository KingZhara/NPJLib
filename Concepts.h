// File: Concepts.h
///     _______    
///        |       
///        |       
///       /_\      
/// ,   ,'   ',   ,
///  ','       ',' 
///    ',     ,'
        
#ifndef INTREPID_PROJECTS_COMMON_CONCEPTS_H
#define INTREPID_PROJECTS_COMMON_CONCEPTS_H

#include <cstdint>

namespace npj
{
    template <typename T = bool> inline constexpr bool always_false_v = false;
    template <typename T = bool> inline constexpr bool always_true_v  = true;
    template <typename T> concept       Addable = requires(T a, T b) {{ a  + b } -> std::same_as<T>;};
    template <typename T> concept  Subtractable = requires(T a, T b) {{ a  - b } -> std::same_as<T>;};
    template <typename T> concept  Multipliable = requires(T a, T b) {{ a  * b } -> std::same_as<T>;};
    template <typename T> concept     Dividable = requires(T a, T b) {{ a  / b } -> std::same_as<T>;};
    template <typename T> concept       Modable = requires(T a, T b) {{ a  % b } -> std::same_as<T>;};
    template <typename T> concept AddAssignable = requires(T a, T b) {{ a += b } -> std::same_as<T&>;};
    template <typename T> concept SubAssignable = requires(T a, T b) {{ a -= b } -> std::same_as<T&>;};
    template <typename T> concept MulAssignable = requires(T a, T b) {{ a *= b } -> std::same_as<T&>;};
    template <typename T> concept DivAssignable = requires(T a, T b) {{ a /= b } -> std::same_as<T&>;};
    template <typename T> concept ModAssignable = requires(T a, T b) {{ a %= b } -> std::same_as<T&>;};
    template <typename T> concept    Assignable = requires(T a, T b) {{ a  = b } -> std::same_as<T&>;};
    template <size_t M, size_t S> concept MinSize = M <= S;
    template <size_t M, size_t S> concept MaxSize = M >= S;
    template <size_t M, size_t S> concept  IsSize = M == S;

    // template <typename R, typename T, std::function<R(T)> Func>

    // @todo add error message if not derived from
    template <typename Base, typename T> concept DerivedFrom = std::derived_from<Base, T>;

    struct FlagSet
    {
        using T = uint64_t;
        
        enum Flag : T
        {
            TRIVIAL = 0b0,
            CONSTEXPR = 0b1
        };
        
        T v = 0;

        constexpr bool is_trivial()      const {return v == TRIVIAL;}
        constexpr bool check_constexpr() const {return v & CONSTEXPR;}

        FlagSet() = default;
        constexpr FlagSet(const Flag& f) : v(f) {}
    };

    template <FlagSet F> concept Constexpr =  F.check_constexpr();

    
    template <FlagSet F> concept NotCxpr   = !F.check_constexpr();
    template <FlagSet F> concept Trivial   =  F.is_trivial();


    //template <>
}

#endif
