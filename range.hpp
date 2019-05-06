
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
//
        class iterator {

        private:
            T* ptr_iter;

        public:


            iterator(T* ptr_iter = nullptr): ptr_iter(ptr_iter) {}

           iterator& operator++() {
                (*ptr_iter)++;
                return *this;
            }


            T& operator*() const {
                return *ptr_iter;
            }

          
            const iterator operator++(int) {
                iterator temp = *this;
                ptr_iter++;
                return temp;
            }

            bool operator!=(iterator  it) const {
                return *ptr_iter != *it.ptr_iter;
            }

            bool operator==(iterator it) const {
                return *ptr_iter == *it.ptr_iter;
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
