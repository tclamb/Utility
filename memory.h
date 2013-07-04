#ifndef _Utility_algorithm_h_
#define _Utility_algorithm_h_

#include <memory> //for std::unique_ptr, std::forward

/*         By Herb Sutter           *
 * http://herbsutter.com/gotw/_102/ */
template<typename T, typename ...Args>
std::unique_ptr<T> make_unique( Args&& ...args )
{
    return std::unique_ptr<T>( new T( std::forward<Args>(args)... ) );
}

#endif
