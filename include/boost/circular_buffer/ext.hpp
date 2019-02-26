#pragma once

/*
Copyright 2017-2018 Glen Joseph Fernandes
(glenjofe@gmail.com)
Distributed under the Boost Software License, Version 1.0.
(http://www.boost.org/LICENSE_1_0.txt)
*/
// This header mostly contains helper functions and types that where copied from Boost.Core
// or are rewritten replacements for such

#include <type_traits>
#include <iterator>

namespace utils {
	template<class T>
	using is_stateless = std::conditional_t<
		::std::is_trivially_default_constructible<T>::value
		&& ::std::is_trivially_copyable<T>::value
		&& ::std::is_trivially_destructible<T>::value
		&& ::std::is_class<T>::value
		&& ::std::is_empty<T>::value, std::true_type, std::false_type>;


	template< class T >
	constexpr T* to_address(T* p) noexcept { return p; }


	template< class Ptr>
	auto to_address_impl(const Ptr& p) noexcept {
		return utils::to_address(p.operator->());
	}

	template< class Ptr >
	auto to_address(const Ptr& p) noexcept {
		return to_address_impl(p);
	}

	template<class T>
	struct use_empty_value_base {
		enum {
			value = std::is_empty<T>::value && !std::is_final<T>::value
		};
	};

	struct empty_init_t { };

	namespace empty_ {

		template<class T, unsigned N = 0,
			bool E = utils::use_empty_value_base<T>::value>
			class empty_value {
			public:
				typedef T type;

				empty_value() = default;


				empty_value(utils::empty_init_t)
					: value_() { }


				template<class... Args>
				explicit empty_value(utils::empty_init_t, Args&&... args)
					: value_(std::forward<Args>(args)...) { }


				const T& get() const noexcept {
					return value_;
				}

				T& get() noexcept {
					return value_;
				}

			private:
				T value_;
		};

		template<class T, unsigned N>
		class empty_value<T, N, true>
			: T {
		public:
			typedef T type;

			empty_value() = default;


			empty_value(utils::empty_init_t)
				: T() { }


			template<class... Args>
			explicit empty_value(utils::empty_init_t, Args&&... args)
				: T(std::forward<Args>(args)...) { }

			const T& get() const noexcept {
				return *this;
			}

			T& get() noexcept {
				return *this;
			}
		};

	} /* empty_ */

	using empty_::empty_value;

	template<class Iterator, class Type>
	constexpr void assert_is_convertible() {
		static_assert(std::is_convertible<typename std::iterator_traits<Iterator>::value_type, Type>::value, "");
	}

}