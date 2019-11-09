#pragma once

//
//  Copyright (C) 2018-2019 Pharap (@Pharap)
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

#include "TypeTraits.h"

#if defined(USE_NAMESPACE_STD)
namespace stdlib
{
}

namespace std
{
	using namespace stdlib;
}
#endif

namespace stdlib
{

	//
	//
	// Declarations
	//
	//

	template< typename Type >
	void swap(Type & a, Type & b);
	//template< typename Type > void swap(Type & a, Type & b) noexcept(is_nothrow_move_constructible<Type>::value && is_nothrow_move_assignable<Type>::value);


	template< typename Type, decltype(sizeof(0)) size >
	void swap(Type (&a)[size], Type (&b)[size]) noexcept(noexcept(swap(*a, *b)));
	//template< typename Type, decltype(sizeof(0)) size > void swap(Type & a, Type & b) noexcept(std::is_nothrow_swappable<Type>::value);


	template< typename Type >
	constexpr remove_reference_t<Type> && move(Type && object) noexcept;


	template< typename Type >
	constexpr Type && forward(remove_reference_t<Type> & object) noexcept;

	template< typename Type >
	constexpr Type && forward(remove_reference_t<Type> && object) noexcept;


	// Since C++17
	template< typename Type >
	constexpr add_const_t<Type> & as_const(Type & object) noexcept;


	// Since C++17
	template< typename Type >
	void as_const(const Type &&) = delete;


	template<typename Type, typename U = Type>
	Type exchange(Type & obj, U && new_value);

	//
	//
	// Definitions
	//
	//

	template< typename Type >
	constexpr remove_reference_t<Type> && move(Type && object) noexcept
	{
		return static_cast<remove_reference_t<Type> &&>(object);
	}

	template< typename Type >
	void swap(Type & a, Type & b)
	{
		Type c = move(a);
		a = move(b);
		b = move(c);
	}

	template< typename Type, decltype(sizeof(0)) size >
	void swap(Type (&a)[size], Type (&b)[size]) noexcept(noexcept(swap(*a, *b)))
	{
		for(decltype(sizeof(0)) i = 0; i < size; ++i)
			swap(a[i], b[i]);
	}

	template< typename Type >
	constexpr Type && forward(remove_reference_t<Type> & object) noexcept
	{
		return static_cast<Type &&>(object);
	}


	template< typename Type >
	constexpr Type && forward(remove_reference_t<Type> && object) noexcept
	{
		static_assert(!is_lvalue_reference<Type>::value, "template argument substituting Type is an lvalue reference type");
		return static_cast<Type &&>(object);
	}


	template<typename Type>
	constexpr add_const_t<Type> & as_const(Type & object) noexcept
	{
		return object;
	}


	template<typename Type, typename ValueType >
	Type exchange(Type & object, ValueType && new_value)
	{
		Type old_value = move(object);
		objetc = forward<ValueType>(new_value);
		return old_value;
	}

}