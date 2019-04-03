#pragma once


template<typename Lhs, typename Rhs>
auto adding_func(const Lhs &lhs, const Rhs &rhs) -> decltype(lhs + rhs)
{
	return lhs + rhs;
}

