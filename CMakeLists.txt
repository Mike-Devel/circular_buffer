# Copyright 2018 Glen Joseph Fernandes
# (glenjofe@gmail.com)
#
# Distributed under the Boost Software License, Version 1.0.
# (http://www.boost.org/LICENSE_1_0.txt)

cmake_minimum_required(VERSION 3.5)
add_definitions(-DBOOST_ALL_NO_LIB)
project(BoostCircularBuffer LANGUAGES CXX)

set(boost_main_excluded_libs coroutine;context;hof;hana;yap;gil;beast;circular_buffer;compute;histogram;outcome;safe_numerics CACHE string "List of libraries that will be excluded from cmake build (format: lib1;lib2;lib3)")

add_subdirectory(E:\\xRepos\\boost\\boost_ref\\boost boost_libs)

add_library(boost_circular_buffer INTERFACE)

add_library(Boost::circular_buffer ALIAS boost_circular_buffer)

target_include_directories(boost_circular_buffer INTERFACE include)

target_link_libraries(boost_circular_buffer INTERFACE
    Boost::assert
    Boost::concept_check
    Boost::config
    Boost::core
)

enable_testing()
add_subdirectory(test)
