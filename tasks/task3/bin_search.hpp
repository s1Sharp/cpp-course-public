// bin_search.hpp

#ifndef BIN_SEARCH_HPP
#define BIN_SEARCH_HPP

#include <cstddef> // для std::nullptr_t

// Перегрузка для nullptr
template <typename T>
T* LowerBound(std::nullptr_t, std::nullptr_t, const T&) {
    return nullptr;
}

// Шаблон для указателей
template <typename T>
T* LowerBound(T* first, T* last, const T& value) {
    if (first == last) {
        return last;
    }

    if (first == nullptr || last == nullptr) {
        return last;
    }

    while (first < last) {
        T* mid = first + (last - first) / 2;
        if (*mid < value) {
            first = mid + 1;
        }
        else {
            last = mid;
        }
    }

    return first;
}

#endif // BIN_SEARCH_HPP