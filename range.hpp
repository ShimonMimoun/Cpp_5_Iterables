
#include "iostream"

//NameSpace for a Tasks
namespace itertools {
    
    template <typename T> 
    class range {
    
    public: // Public variables and functions
       
        T from;
        T to;

        range(T from, T to) {
            this->from = from;
            this->to = to;
        }

        class iterator {

        private:


            T* ptr;

        public:


            iterator(T* ptr = nullptr): ptr(ptr) {}

            T& operator*() const {
                return *ptr;
            }

            iterator& operator++() {
                (*ptr)++;
                return *this;
            }

            const iterator operator++(int) {
                iterator tmp = *this;
                ptr++;
                return tmp;
            }

            bool operator!=(iterator  it) const {
                return *ptr != *it.ptr;
            }

            bool operator==(iterator it) const {
                return *ptr == *it.ptr;
            }


         
        }; // END OF CLASS ITERATOR

        iterator begin() 
        {
            return iterator{&from};
        }

        iterator end() 
        {
            return iterator{&to};
        }

    };
}
