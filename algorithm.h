#include <iterator>  //for std::prev, std::next

// expects function of type: fn(Iterator current, Iterator previous, Iterator next)
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
