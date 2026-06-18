// File: Macros.h
///     _______    
///        |       
///        |       
///       /_\      
/// ,   ,'   ',   ,
///  ','       ',' 
///    ',     ,'
        
#ifndef INTREPID_PROJECTS_COMMON_MACROS_H
#define INTREPID_PROJECTS_COMMON_MACROS_H

/**
 * F : TypeFlags            |
 * T : Templates            |
 * D : Function declaration |
 * P : Function params      | Separated to allow for comma separation w/ parenthesis wrapping
 * Q : Qualifiers           |
 * B : Function body        |
 */
#define NPJ_ENSURE_CXPR_CAPABLE(NAME)           \
    requires requires() {                   \
        { NAME() } -> std::same_as<void>;        \
    }


#define NPJ_TMPL_MACRO(PARAMS)          \
    template <PARAMS> 

/*
#define NPJ_CXP_TRIVIAL(TMPL, TYPE, NAME, PARAMS, BODY) \
    TMPL           TYPE NAME PARAMS BODY \
    TMPL constexpr TYPE NAME PARAMS NPJ_ENSURE_CXPR_CAPABLE(NAME) B
*/

#define NPJ_CXP_TRIVIAL(F, T, D, P, Q, B)          \
    T           D P Q requires npj::NotCxpr  <F> B    \
    T constexpr D P Q requires npj::Constexpr<F> B

#define NPJ_CONST_VARIANT(T, D, P, B) \
    T       D P       B               \
    T const D P const B

#define NPJ_CXPR_VARIANT(T, D, P, B) \
    T D P B          \
    T constexpr D P const B               

#define NPJ_CXPR_VARIANT_CSCT(D, P, B) \
    D P B               \
    constexpr D P B


#define NPJ_CXPR_VARIANT_GUARDED(T, D, P, B, F)   \
    T D P  requires npj::NotCxpr  <F> B          \
    T constexpr D P const  requires npj::Constexpr <F> B               

#define NPJ_CXPR_VARIANT_CSCT_GUARDED(D, P, B, F)     \
    D P  requires npj::NotCxpr  <F> B               \
    constexpr D P  requires npj::Constexpr <F> B


#define NPJ_BUILD_COND(condition, truev)       \
    std::conditional_t< condition , truev, Next >

#define NPJ_BUILD_COND_END(condition, truev, basev)           \
    std::conditional_t< condition , truev, basev >

//#define NPJ_BUILD_COND_BEGIN(tmpla, tmplb, name, build)       \
//    template < tmpla , tmplb > \
//    using name = build;

#define NPJ_DECR_TBL_1 0
#define NPJ_DECR_TBL_2 1
#define NPJ_DECR_TBL_3 2
#define NPJ_DECR_TBL_4 3
#define NPJ_DECR_TBL_5 4
#define NPJ_DECR_TBL_6 5
#define NPJ_DECR_TBL_7 6
#define NPJ_DECR_TBL_8 7
#define NPJ_DECR_TBL_9 8
#define NPJ_DECR_TBL_10 9


#define DECREMENT(x) NPJ_DECR_TBL_##x

#define STRINGIFY(x) #x
#define TO_STRING(x) STRINGIFY(x)
#define STR(...) #__VA_ARGS__
#define FPARAM(...) (__VA_ARGS__)
#define TPARAM(...) <__VA_ARGS__>
#define RPARAM(...) __VA_ARGS__
#define BODY(...) __VA_ARGS__

#endif
