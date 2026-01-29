#pragma once

#include <cassert>
#include <stdexcept>

// Func&& is a forwarding reference in this context because the three following facts are true.
// 1) This a template
// 2) The parameter is exactly Func&&
// 3) Func is deduced from the call
//
// If we call assert_throw([] { /*...*/ }) with an rvalue argument, func is an rvalue reference.
//
// If we call:
// auto f = [] { /*...*/ }; 
// assert_throw(f);
// the argument is an lvalue, so func is an lvalue reference.
//
// Subtle point: Even when func is bound as an rvalue reference,
// the expression 'func' itself is still an lvalue because it has a name.
// Therefor, the function body sees a named lvalue.
//
// To sum it up, deduction decides whether func collapses to & (lvalue reference)
// or && (rvalue reference).
//
// In contrast:
// void assert_throw(Func func) -> copies
// void assert_throw(Func& func) -> rejects temporaries
//
// Mental note: An expression is any piece of code that produces a value 
// (e.g. single variable, literal, function call etc.).
// That means all variables are expressions, but not all expressions are variables.

template<typename Exception, typename Func>
void assert_throw(Func&& func) {
    bool exception_thrown = false;
    try {
        func();
    } catch (const Exception&) {
        exception_thrown = true;
    }
    assert(exception_thrown && "Expected exception was not thrown");
}