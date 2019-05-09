#include "iostream"

//NameSpace for a Tasks
namespace itertools {
    
    template <typename T1, typename T2> 
    class product {
    
    private: // private variables and functions
        T1 iterable_A;
        T2 iterable_B;

    public:
        product(T1 start, T2 end) :  iterable_A(start), iterable_B(end) {}
        
    auto begin(){ 
        return  iterator<decltype(iterable_A.begin()),decltype(iterable_B.begin())>(iterable_A.begin(), iterable_B.begin()); }  // iteratable object

    auto end() {
        return iterator<decltype(iterable_A.end()),decltype(iterable_B.end())>(iterable_A.end(), iterable_B.end()); }  // iteratable object  
 
    template <typename C1, typename C2>
        class iterator {

        private:
            C1 iter_A; // iterator A
            C2 iter_B; // iterator B
            C2 save_position_B;

        public:
            iterator(C1 itA , C2 itB): iter_A(itA) , iter_B(itB) , save_position_B(iter_B) {}

           iterator<C1,C2>& operator++() {
               ++iter_B;
               return *this;
 
            }

            std::pair<decltype(*iter_A),decltype(*iter_B)> operator*() const {

             return  std::pair<decltype(*iter_A),decltype(*iter_B)> (*iter_A , *iter_B);
            }

            bool operator!=(iterator<C1,C2>  it){
                if((iter_A != it.iter_A) && !(iter_B != it.iter_B)){
                    iter_B = save_position_B;
                    ++iter_A;
                }
                return (iter_A != it.iter_A);
 
            }


         
        }; // END OF CLASS ITERATOR


    };

}