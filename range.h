#ifndef _Utility_range_h_
#define _Utility_range_h_

template<typename It> struct range {
    It begin_, end_;
    It begin() const { return begin_; }
    It end()   const { return end_; }
};

template<typename It> range<It> make_range(std::pair<It, It> const& p) {
       return {p.first, p.second};
}

template<typename It> range<It> make_range(It const& begin, It const& end) {
       return {begin, end};
}

#endif
