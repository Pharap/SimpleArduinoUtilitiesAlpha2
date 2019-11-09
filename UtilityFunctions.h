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

//
// absT
//

template< typename Type >
constexpr Type absT(Type value)
{
	return (value < 0) ? -value : value;
}

//
// minT
//

template< typename Type >
constexpr Type minT(Type left, Type right)
{
	return (left < right) ? left : right;
}

template< typename Type >
constexpr Type & minT(Type & left, Type & right)
{
	return (left < right) ? left : right;
}

template< typename Type >
constexpr const Type & minT(const Type & left, const Type & right)
{
	return (left < right) ? left : right;
}

//
// maxT
//

template< typename Type >
constexpr Type maxT(Type left, Type right)
{
	return (left > right) ? left : right;
}

template< typename Type >
constexpr Type & maxT(Type & left, Type & right)
{
	return (left > right) ? left : right;
}

template< typename Type >
constexpr const Type & maxT(const Type & left, const Type & right)
{
	return (left > right) ? left : right;
}

//
// clampT
//

template< typename Type >
constexpr Type clampT(Type value, Type left, Type right)
{
	return (value < left) ? left : (value > right) ? right : value;
}

template< typename Type >
constexpr Type & clampT(Type & value, Type & left, Type & right)
{
	return (value < left) ? left : (value > right) ? right : value;
}

template< typename Type >
constexpr const Type & clampT(const Type & value, const Type & left, const Type & right)
{
	return (value < left) ? left : (value > right) ? right : value;
}