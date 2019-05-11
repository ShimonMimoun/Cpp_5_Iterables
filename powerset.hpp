#include "iostream"
#include <set> // for set operations
#include <cmath>
#include <iostream>

namespace itertools {
        
    template <class T> 
    class powerset {
    
    private: 
        T iterable; // start point

    public:
    powerset(T start) : iterable(start) {} 

    auto begin() { 
    return iterator<decltype(iterable.begin())> (iterable.begin(), iterable.end()); 
    } 
    auto end()  { 
    return iterator<decltype(iterable.begin())>(iterable.end(), iterable.end());
    }    
 
    template <class C>
        class iterator {

        private:
            C iter_begin; // iterator A
            C iter_end; // iterator A
            unsigned   index;
            unsigned   count_elements;


        public:
            iterator(C itA , C itB): iter_begin(itA), iter_end(itB) , index(0),count_elements(0)  {

            C _element_iterator = iter_begin;
            while (_element_iterator != iter_end)
            {
                ++count_elements;
                ++_element_iterator;
            }

            count_elements = std::pow(2, count_elements);
            }

           iterator<C>& operator++() {
               ++index;
               return *this;
            }

            set<decltype(*iter_begin)> operator*() const         {
            C _element_iterator = iter_begin;
            std::set<decltype(*iter_begin)> S;
            unsigned int i = index;
            while (i != 0 && _element_iterator != iter_end)
            { 
                unsigned int r = i % 2;
                i = i >> 1; 

                if (r == 1)
                    S.insert(*_element_iterator);

                ++_element_iterator;
            }

            return S;
        }

        bool operator!=(iterator<C> const &it) const {
            return ((count_elements - index) != (it.count_elements - it.index - 1));

            }
 
         
        }; // END OF CLASS ITERATOR


    };
    
template <typename D>
std::ostream &operator<<(std::ostream &os, const std::set<D> &S)
{
    os << "{";

    auto it = S.begin();
    if(it != S.end())
    { // first element is without comma seperator.
        os << *it; 
        ++it;
    }

    while (it != S.end())
    {
        os << ',' << *it;
        ++it;
    }

    os << "}";

    return os;
}
}