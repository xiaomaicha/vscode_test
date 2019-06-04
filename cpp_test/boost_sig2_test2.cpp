#include "boost/utility/result_of.hpp"  
#include "boost/typeof/typeof.hpp"  
#include "boost/assign.hpp"  
#include "boost/ref.hpp"  
#include "boost/bind.hpp"  
#include "boost/function.hpp"  
#include "boost/signals2.hpp"  
#include "numeric"  
#include "iostream"  
using namespace std;  
  
  
template<int N>  
struct Slot  
{  
    int operator()(int x)  
    {  
        cout << "Slot current N * x value is : " << N * x << endl;  
  
        return (N * x);  
    }  
};  
  
template<int N>  
bool operator== (const Slot<N>& a, const Slot<N>& b)  
{  
    return true;  
}  
  
template<typename T>  
class combiner  
{  
public:  
    typedef pair<T, T> result_type;  
    combiner(T t = T()) : v(t)  
    {  
  
    }  
  
    template<typename InputIterator>  
    result_type operator()(InputIterator begin, InputIterator end) const  
    {  
        if (begin == end)  
        {  
            return result_type();  
        }  
  
        vector<T> vec(begin, end);  
        T sum = accumulate(vec.begin(), vec.end(), v);  
        T max = *max_element(vec.begin(), vec.end());  
  
        return result_type(sum, max);  
    }  
  
private:  
    T v;  
};  
  
  
int main()  
{  
    boost::signals2::signal<int(int)> sig;  
    boost::signals2::connection c1 = sig.connect(0, Slot<10>());  
    boost::signals2::connection c2 = sig.connect(0, Slot<10>());  
    boost::signals2::connection c3 = sig.connect(0, Slot<10>());  
  
    // c1.disconnect();  
    // assert(sig.num_slots() == 2);  
    // assert(!c1.connected());  
    // assert(c2.connected());  
    cout<<"Return code is: "<<*sig(4)<<endl;// 只能返回最后被调用的插槽的返回值
    return 0;  
}  