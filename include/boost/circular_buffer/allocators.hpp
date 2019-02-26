// Copyright 2018 Glen Joseph Fernandes
// (glenjofe@gmail.com)
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CIRCULAR_BUFFER_ALLOCATORS_HPP
#define BOOST_CIRCULAR_BUFFER_ALLOCATORS_HPP

#include <limits>
#include <memory>
#include <new>
#include <utility>

namespace boost {
namespace cb_details {


template<class A>
struct allocator_traits
    : std::allocator_traits<A> {
    using typename std::allocator_traits<A>::value_type;
    using typename std::allocator_traits<A>::size_type;

    static size_type max_size(const A&) BOOST_NOEXCEPT {
        return (std::numeric_limits<size_type>::max)() / sizeof(value_type);
    }
};


} // cb_details
} // boost

#endif
