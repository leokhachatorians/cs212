#include "Set.h"
#include "LinkedBag.h"
#include <vector>

#ifndef SET_CPP
#define SET_CPP

template<class Type>
Set<Type>::Set() {}

template<class Type>
int Set<Type>::get_current_size() const {
    return m_bag.getCurrentSize();
}

template<class Type>
void Set<Type>::is_empty() const {
    return m_bag.isEmpty();
}

template<class Type>
bool Set<Type>::add(const Type &element) {
    return m_bag.add(element);
}

template<class Type>
bool Set<Type>::remove(const Type &element) {
    return m_bag.remove(element);
}

template<class Type>
std::vector<Type> Set<Type>::to_vector() const {
    return m_bag.toVector();
}
template<class Type>
bool Set<Type>::exists(Type element) const {
    std::vector<Type> set_vec = to_vector();
    bool found = false;
    for (int i = 0; i < get_current_size(); i++) {
        if (element == set_vec[i]) {
            found = true;
            break;
        }
    }
    return found;
}

#endif
