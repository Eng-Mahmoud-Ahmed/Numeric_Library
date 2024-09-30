#ifndef _MATH_HPP_
#define _MATH_HPP_

#include <type_traits>
#include <iostream>


class Custom {
    public:
        Custom(std::string b) : m_b{b} {}
        
        Custom operator-(const Custom& s2) const 
        {
            return Custom( m_b + "-" +  s2.m_b);
        }
        string get_mb() const
        {
            return m_b;
        }
    private:
        std::string m_b;
};

// Overload the << operator for printing
std::ostream& operator<<(std::ostream& output_stream, const Custom& c) {
    
    output_stream << c.get_mb();
    return output_stream;
}



namespace nlib
{
    // a helper variable that checks whether all types in a parameter pack are arithmetic types
    template <typename... Ts>
    constexpr bool all_arithmetic = (std::is_arithmetic_v<Ts> && ...);


/********************************************************************************************* */
/*************************************** max() *********************************************** */
    /* max function and its side corners
    1. no argument passed
    2. one argument passed
    3. two or more arguments passed 
    */
    auto max()
    {
        return 0;
    }

    template <typename T>
    auto max( const T& n1)
    {
        return n1;
    }

    template <typename T, typename U , typename ... Ts >
    auto max( const T& n1, const U& n2, const Ts& ... values  )
    {
        static_assert( std::is_arithmetic_v<T> && std::is_arithmetic_v<U> && nlib::all_arithmetic<Ts...>, "All arguments must be arithmetic" );
        auto max_of_two = (n1 > n2)? n1 : n2;
        
        if constexpr(sizeof...(Ts) > 0  )
        {
            return max(max_of_two, values...);
        }
        else
        {
            return max_of_two;
        }
    }

/********************************************************************************************* */
/*************************************** min() *********************************************** */
    auto min()
    {
        return 0;
    }

    template <typename T>
    auto min( const T& n1)
    {
        return n1;
    }

    template <typename T, typename U , typename ... Ts >
    auto min( const T& n1, const U& n2, const Ts& ... values  )
    {
        static_assert( std::is_arithmetic_v<T> && std::is_arithmetic_v<U> && nlib::all_arithmetic<Ts...>, "All arguments must be arithmetic" );
        auto min_of_two = (n1 < n2)? n1 : n2;
        
        if constexpr(sizeof...(Ts) > 0  )
        {
            return min(min_of_two, values...);
        }
        else
        {
            return min_of_two;
        }
    }

/********************************************************************************************* */
/*************************************** sub() *********************************************** */
    // Template overloading.
    template < typename T>
    T sub(const T& n)
    {
        return n;
    }

    template < typename T , typename U, typename ... Ts > 
    auto sub (const T& n1, const U & n2, const Ts & ... values)
    {

        static_assert( std::is_arithmetic_v<T> && std::is_arithmetic_v<U> && nlib::all_arithmetic<Ts...> || (std::is_same_v<T, Custom> && std::is_same_v<U, Custom>) , "All arguments must be arithmetic" );
        auto sub_of_two = n1 - n2;
        if constexpr ( sizeof...(Ts) > 0 )
        {
           return sub( sub_of_two , values ... );
        }
        else 
        {
            return sub_of_two;
        }
    }







/********************************************************************************************* */
/*************************************** sum() *********************************************** */
    int sum ()
    {
        return 0;
    }
    template < typename T>
    T sum(const T& n)
    {
        return n;
    }
    template < typename T , typename U, typename ... Ts > // parameter packing.
    auto sum (const T& n1, const U & n2, const Ts & ... values)
    {
        static_assert( std::is_arithmetic_v<T> && std::is_arithmetic_v<U> && nlib::all_arithmetic<Ts...>, "All arguments must be arithmetic" );
        auto sum_of_two = n1 + n2;
        return  sum_of_two + sum(values ...);
    }



}






#endif
