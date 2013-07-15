algorithm.h
-----------
`FB_for_each(It beg, It end, Func fn)` implements a for loop that applies a function to each element of a container, passing as arguments each element and its neighboring elements. The previous element for the beginning element is the last element, and the next element for the last element is the first element.

``` cpp
std::vector<Point> polygon;
/* contains some points defining a polygon that has more than three points, *
 * no collinear edges, and no crossing edges                                */
bool isConvex = true; /* innocent before proven guilty */
bool isCCW = crossProduct(polygon[1] - polygon[0], polygon[2] - polygon[0]) > 0;
FB_for_each(convexPolygonVertices.begin(), convexPolygonVertices.end(),
  [&isConvex, isCCW](Point const& current, Point const& next, Point const& prev) {
    if(isConvex) { /* only needs to be concave once */
      bool isStillCCW = crossProduct(next - current, prev - current) > 0;
      if(isStillCCW != isCCW)
        isConvex = false;
    }
  });
/* if isConvex is still true, polygon defines a convex polygon, otherwise it's concave */
```

memory.h
--------
`make_unique<T>(Args...)` from http://herbsutter.com/gotw/\_102/, the `unique_pointer` analog to `make_shared()`

``` cpp
auto x = make_unique< std::vector<int> >( 0, 1, 1, 2, 3, 5, 8, 13 );
/* x has type unique_pointer< std::vector<int> > *
 * *x contains { 0, 1, 1, 2, 3, 5, 8, 13 }       */
```

numerical.h
-----------
`clamp(T x, T min, T max)` limits the value of `x` to at most `max` and at least `min`

``` cpp
float x = 2.0f;           /* x == 2.0f */
x = clamp(x, 0.0f, 1.0f); /* x == 1.0f */
```

range.h
-------
`make_range(std::pair<It, It>)` from http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2009/n2995.pdf, allows `equal_range` to be used with range-based for loops

``` cpp
for( auto const& x : make_range( mymap.equal_range(key) ) );
```
