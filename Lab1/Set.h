#include <iostream>
#include <vector>
#include "LinkedBag.h"

#ifndef SET_H
#define SET_H

template<class Type>
class Set {
    private:
        LinkedBag<Type> m_bag;
    public:
        Set();
        int get_current_size() const;
        void is_empty() const;
        bool add(const Type &element);
        bool remove(const Type &element);
        bool exists(Type element) const;
        std::vector<Type> to_vector() const;

        Set<Type> &operator+(const Set<Type> &B) {
            // Iterate over set A and add element into temp set if not already exists
            // Then, do the same for set B.
            //
            // Return temp set as a pointer due to some errors via LinkedBag
            std::vector<Type> set_A = to_vector();
            std::vector<Type> set_B = B.to_vector();
            Set<Type> *temp = new Set<Type>;

            for (int i = 0; i < get_current_size(); i++) {
                if (!(temp->exists(set_A[i]))) {
                    temp->add(set_A[i]);
                }
            }

            for (int i = 0; i < B.get_current_size(); i++) {
                if (!(temp->exists(set_B[i]))) {
                    temp->add(set_B[i]);
                }
            }
            return *temp;
        }
        friend std::ostream &operator<<(std::ostream &out, Set<Type> &s) {
            // Simply loop over calling sets vector and output each element
            std::vector<Type> vec = s.to_vector();
            for (int i = 0; i < s.get_current_size(); i++) {
                out << vec[i] << " ";
            }
            out << std::endl;
            return out;
        }

        Set<Type> &operator-(const Set<Type> &B) {
            // Loops over set A and checks if that entry exists in set B.
            // If it does, simply add it into out temp set and return when
            // finished.
            std::vector<Type> set_A = to_vector();
            Set<Type> *temp = new Set<Type>;

            for (int i = 0; i < get_current_size(); i++) {
                if (B.exists(set_A[i])) {
                    temp->add(set_A[i]);
                }
            }
            return *temp;
        }
};

#include "Set.cpp"
#endif
