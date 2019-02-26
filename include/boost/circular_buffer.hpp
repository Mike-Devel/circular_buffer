// Circular buffer library header file.

// Copyright (c) 2003-2008 Jan Gaspar

// Use, modification, and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

//  See www.boost.org/libs/circular_buffer for documentation.

#if !defined(BOOST_CIRCULAR_BUFFER_HPP)
#define BOOST_CIRCULAR_BUFFER_HPP

#include <boost/circular_buffer_fwd.hpp>

// BOOST_CB_ENABLE_DEBUG: Debug support control.
#if !defined(BOOST_CB_ENABLE_DEBUG)
    #define BOOST_CB_ENABLE_DEBUG 0
#endif

// BOOST_CB_ASSERT: Runtime assertion.
#if BOOST_CB_ENABLE_DEBUG
    #include <cassert>
    #define BOOST_CB_ASSERT(Expr) assert(Expr)
#else
    #define BOOST_CB_ASSERT(Expr) ((void)0)
#endif

// BOOST_CB_IS_CONVERTIBLE: Check if Iterator::value_type is convertible to Type.
#include <iterator>
#include <type_traits>
#define BOOST_CB_IS_CONVERTIBLE(Iterator, Type) \
    static_assert(std::is_convertible<typename std::iterator_traits<Iterator>::value_type, Type>::value,"")


#define BOOST_CB_ASSERT_TEMPLATED_ITERATOR_CONSTRUCTORS ((void)0);


#include <boost/circular_buffer/debug.hpp>
#include <boost/circular_buffer/details.hpp>
#include <boost/circular_buffer/base.hpp>
#include <boost/circular_buffer/space_optimized.hpp>

#undef BOOST_CB_ASSERT_TEMPLATED_ITERATOR_CONSTRUCTORS
#undef BOOST_CB_IS_CONVERTIBLE
#undef BOOST_CB_ASSERT

#endif // #if !defined(BOOST_CIRCULAR_BUFFER_HPP)
