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

#include <stdint.h>

#include "TypeTraits.h"

//
// Declarations
//

template< typename Type, uint8_t capactiy >
class Deque;

template< typename Type, uint8_t capactiyValue >
class Deque
{
public:

	//
	// Constraints
	//

	static_assert(capactiyValue > 0, "Attempt to create Deque with a capacity less than 1");
	static_assert(capactiyValue < 128, "Attempt to create Deque with a capacity greater than 127");

	//
	// Type Aliases
	//

	using ValueType = Type;
	using SizeType = uint8_t;
	using IndexType = uint8_t;
	using IndexOfType = int8_t;
	
	//
	// Constants
	//
	
	constexpr static const SizeType capactiy = capactiyValue;
	constexpr static const IndexOfType InvalidIndex = -1;
	constexpr static const IndexType FirstIndex = 0;
	constexpr static const IndexType LastIndex = capactiy - 1;

private:
	
	//
	// Member Variables
	//
	
	ValueType items[capactiy] = {};
	IndexType next = 0;
	
public:

	//
	// Common Member Functions
	//
	
	// O(1)
	bool isEmpty() const noexcept
	{
		return (this->next == FirstIndex);
	}
	
	// O(1)
	bool isFull() const noexcept
	{
		return (this->next > LastIndex);
	}
	
	// O(1)
	SizeType getCount() const noexcept
	{
		return this->next;
	}
	
	// O(1)
	constexpr SizeType getCapacity() const noexcept
	{
		return capactiy;
	}
	
	// O(1)
	ValueType * getData() noexcept
	{
		return &this->items[FirstIndex];
	}
	
	// O(1)
	const ValueType * getData() const noexcept
	{
		return &this->items[FirstIndex];
	}
	
	// O(1)
	ValueType & operator [](IndexType index)
	{
		return this->items[index];
	}
	
	// O(1)
	const ValueType & operator [](IndexType index) const
	{
		return this->items[index];
	}
	
	// O(N)
	void clear();
	
	// O(N)
	void fill(const ValueType & item);
	
	// O(N)
	bool contains(const ValueType & item) const;
	
	// O(N)
	IndexOfType indexOfFirst(const ValueType & item) const;
	
	// O(N)
	IndexOfType indexOfLast(const ValueType & item) const;
	
public:

	//
	// Specific Member Functions
	//

	// O(1)
	ValueType & getFirst()
	{
		return this->items[FirstIndex];
	}

	// O(1)
	const ValueType & getFirst() const
	{
		return this->items[FirstIndex];
	}

	// O(1)
	ValueType & getLast()
	{
		return this->items[this->next];
	}

	// O(1)
	const ValueType & getLast() const
	{
		return this->items[this->next];
	}

	// O(1)
	bool append(const ValueType & item);

	// O(1)
	bool prepend(const ValueType & item);

	// O(1)
	void unappend();

	// O(1)
	void unprepend();
	
	// O(N)
	bool removeFirst(const ValueType & item);
	
	// O(N)
	bool removeLast(const ValueType & item);
	
	// O(N)
	bool removeAt(IndexType index);

	// O(N)
	bool insert(IndexType index, const ValueType & item);
};

//
// Definition
//

// O(N)
template< typename Type, uint8_t capactiy >
void Deque<Type, capactiy>::clear()
{
	for (IndexType i = 0; i < this->getCount(); ++i)
		this->items[i].~ValueType();
	this->next = 0;
}

// O(N)
template< typename Type, uint8_t capactiy >
void Deque<Type, capactiy>::fill(const ValueType & item)
{
	for (IndexType i = 0; i < this->getCount(); ++i)
		this->items[i] = item;
}

// O(N)
template< typename Type, uint8_t capactiy >
bool Deque<Type, capactiy>::contains(const ValueType & item) const
{
	for (IndexType i = 0; i < this->getCount(); ++i)
		if (this->items[i] == item)
			return true;

	return false;
}

// O(N)
template< typename Type, uint8_t capactiy >
auto Deque<Type, capactiy>::indexOfFirst(const ValueType & item) const -> IndexOfType
{
	for (IndexType i = 0; i < this->getCount(); ++i)
		if (this->items[i] == item)
			return i;

	return InvalidIndex;
}

// O(N)
template< typename Type, uint8_t capactiy >
auto Deque<Type, capactiy>::indexOfLast(const ValueType & item) const -> IndexOfType
{
	for (IndexType i = this->getCount() - 1; i > 0; --i)
		if (this->items[i] == item)
			return i;

	return InvalidIndex;
}

// O(1)
template< typename Type, uint8_t capactiy >
bool Deque<Type, capactiy>::append(const ValueType & item)
{
	if (this->isFull())
		return false;

	this->items[this->next] = item;
	++this->next;
	return true;
}

// O(1)
template< typename Type, uint8_t capactiy >
bool Deque<Type, capactiy>::prepend(const ValueType & item)
{
	if (this->isFull())
		return false;

	++this->next;
	for (IndexType i = this->next; i > 0; --i)
			this->items[i] = stdlib::move(this->items[i - 1]);

	this->items[0] = item;
	return true;
}

// O(1)
template< typename Type, uint8_t capactiy >
void Deque<Type, capactiy>::unappend()
{
	if (this->isEmpty())
		return;

	--this->next;
	this->items[this->next].~ValueType();
	return true;
}

// O(1)
template< typename Type, uint8_t capactiy >
void Deque<Type, capactiy>::unprepend()
{
	if (this->isEmpty())
		return;

	--this->next;
	for (IndexType i = 0; i < this->next; ++i)
			this->items[i] = stdlib::move(this->items[i + 1]);

	this->items[this->next].~ValueType();
	return true;
}

// O(N)
template< typename Type, uint8_t capactiy >
bool Deque<Type, capactiy>::removeFirst(const ValueType & item)
{
	for(IndexType i = 0; i < this->next; ++i)
		if (this->items[i] == item)
		{
			--this->next;
			for (IndexType j = i; j < this->next; ++j)
				this->items[j] = stdlib::move(this->items[j + 1]);

			this->items[this->next].~ValueType();
			return true;
		}
	return false;
}

// O(N)
template< typename Type, uint8_t capactiy >
bool Deque<Type, capactiy>::removeLast(const ValueType & item)
{
	for(IndexType i = this->next - 1; i > 0; --i)
		if (this->items[i] == item)
		{
			--this->next;
			for (IndexType j = i; j < this->next; ++j)
				this->items[j] = stdlib::move(this->items[j + 1]);

			this->items[this->next].~ValueType();
			return true;
		}
	return false;
}

// O(N)
template< typename Type, uint8_t capactiy >
bool Deque<Type, capactiy>::removeAt(IndexType index)
{
	if(index >= this->next)
		return false;

	--this->next;
	for (IndexType i = index; i < this->next; ++i)
			this->items[i] = stdlib::move(this->items[i + 1]);

	this->items[this->next].~ValueType();
	return true;
}

// O(N)
template< typename Type, uint8_t capactiy >
bool Deque<Type, capactiy>::insert(IndexType index, const ValueType & item)
{
	if(index >= this->next)
		return false;

	if (this->isFull())
		return false;

	++this->next;
	for (IndexType i = index + 1; i < this->next; ++i)
		this->items[i] = stdlib::move(this->items[i + 1]);

	this->items[index] = item;
	return true;
}

//
// Empty Deque
//

template< typename Type >
class Deque<Type, 0>
{
public:

	//
	// Type Aliases
	//

	using ValueType = Type;
	using SizeType = uint8_t;
	using IndexType = uint8_t;
	using IndexOfType = int8_t;
	
	//
	// Constants
	//
	
	constexpr static const SizeType capactiy = 0;
	constexpr static const IndexOfType InvalidIndex = -1;
	constexpr static const IndexType FirstIndex = InvalidIndex;
	constexpr static const IndexType LastIndex = InvalidIndex;
	
public:

	//
	// Common Member Functions
	//
	
	// O(1)
	constexpr bool isEmpty() const
	{
		return true;
	}
	
	// O(1)
	constexpr bool isFull() const noexcept
	{
		return true;
	}
	
	// O(1)
	constexpr SizeType getCount() const noexcept
	{
		return 0;
	}
	
	// O(1)
	constexpr SizeType getCapacity() const noexcept
	{
		return 0;
	}
	
	// O(1)
	/*constexpr*/ ValueType * getData() noexcept
	{
		return nullptr;
	}
	
	// O(1)
	constexpr const ValueType * getData() const noexcept
	{
		return nullptr;
	}
	
	// O(1)
	/*constexpr*/ ValueType & operator [](IndexType index) = delete;
	
	// O(1)
	constexpr const ValueType & operator [](IndexType index) const = delete;
	
	// O(1)
	constexpr void clear() noexcept
	{
	}
	
	// O(1)
	constexpr bool contains(const ValueType & item) const noexcept
	{
		return false;
	}
	
	// O(1)
	constexpr IndexOfType indexOf(const ValueType & item) const noexcept
	{
		return InvalidIndex;
	}
	
public:

	//
	// Specific Member Functions
	//

	// O(1)
	/*constexpr*/ ValueType & getFirst() = delete;

	// O(1)
	constexpr const ValueType & getFirst() const = delete;

	// O(1)
	/*constexpr*/ ValueType & getLast() = delete;
	
	// O(1)
	constexpr const ValueType & getLast() const = delete;

	// O(1)
	constexpr bool append(const ValueType & item)
	{
		return false;
	}

	// O(1)
	constexpr bool prepend(const ValueType & item)
	{
		return false;
	}

	// O(1)
	constexpr void unappend()
	{
	}

	// O(1)
	constexpr void unprepend()
	{
	}
	
	// O(N)
	constexpr bool removeFirst(const ValueType & item)
	{
		return false;
	}
	
	// O(N)
	constexpr bool removeLast(const ValueType & item)
	{
		return false;
	}
	
	// O(N)
	constexpr bool removeAt(IndexType index)
	{
		return false;
	}

	// O(N)
	constexpr bool insert(IndexType index, const ValueType & item)
	{
		return false;
	}
};