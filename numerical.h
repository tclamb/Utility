#ifndef _Utility_numerical_h
#define _Utility_numerical_h

// clamp x to within [min, max]
template <typename T>
T clamp(T x, T min, T max) {
    if(x < min) return min;
    if(x > max) return max;
    return x;
}

#endif
