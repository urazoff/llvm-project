//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef _LIBCPP___ALGORITHM_IS_HEAP_UNTIL_H
#define _LIBCPP___ALGORITHM_IS_HEAP_UNTIL_H

#include <__config>
#include <__iterator/iterator_traits.h>

#if !defined(_LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER)
#pragma GCC system_header
#endif

_LIBCPP_PUSH_MACROS
#include <__undef_macros>

_LIBCPP_BEGIN_NAMESPACE_STD

template <class _RandomAccessIterator, class _Compare>
_LIBCPP_NODISCARD_EXT _LIBCPP_CONSTEXPR_AFTER_CXX17 _RandomAccessIterator
is_heap_until(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp)
{
    typedef typename iterator_traits<_RandomAccessIterator>::difference_type difference_type;
    difference_type __len = __last - __first;
    difference_type __p = 0;
    difference_type __c = 1;
    _RandomAccessIterator __pp = __first;
    while (__c < __len)
    {
        _RandomAccessIterator __cp = __first + __c;
        if (__comp(*__pp, *__cp))
            return __cp;
        ++__c;
        ++__cp;
        if (__c == __len)
            return __last;
        if (__comp(*__pp, *__cp))
            return __cp;
        ++__p;
        ++__pp;
        __c = 2 * __p + 1;
    }
    return __last;
}

template<class _RandomAccessIterator>
_LIBCPP_NODISCARD_EXT inline
_LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX17
_RandomAccessIterator
is_heap_until(_RandomAccessIterator __first, _RandomAccessIterator __last)
{
    return _VSTD::is_heap_until(__first, __last, __less<typename iterator_traits<_RandomAccessIterator>::value_type>());
}

_LIBCPP_END_NAMESPACE_STD

_LIBCPP_POP_MACROS

#endif // _LIBCPP___ALGORITHM_IS_HEAP_UNTIL_H
