#ifndef _Utility_algorithm_h_
#define _Utility_algorithm_h_

#include <iterator>  //for std::prev, std::next

// expects function of type: fn(Iterator_type current, Iterator_type previous, Iterator_type next)
// iterators must have std::next() and std::prev() specializations
template<class InputIterator, class Function>
Function FB_for_each(InputIterator first, InputIterator last, Function fn) {
    using std::prev;
    using std::next;

    if(first == last) return fn; // empty range

    auto c = first,
         p = prev(last),
         n = next(first);
    if(n == last) n = first; // range of length 1

    while(c != last) {
        fn(*c, *p, *n);

        p = c;
        ++c;
        n = next(c);
        if(n == last) n = first;
    }
    
    return fn;
}

#endif
