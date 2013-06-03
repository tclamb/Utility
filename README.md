range.h
-------
implements make\_range() from http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2009/n2995.pdf

e.g.
  for( auto const& x : make\_range( mymap.equal\_range(key) ) );
