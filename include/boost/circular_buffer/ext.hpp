#pragma once

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

}