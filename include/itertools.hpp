// like python itertools
#include <iterator>


namespace rainboy {

    struct rangeImpl {
        int _start;
        int _stop;
        int _step;

        constexpr rangeImpl(int stop) 
            :rangeImpl(0,stop,1)
        {}

        constexpr rangeImpl(int start,int stop,int step=1) 
            :_start(start),_stop(stop),_step(step)
        {}

        struct Iterator {
            int _data;
            int _step;
            bool _end{};

            Iterator(int data,int step,bool end)
                :_data(data),_step(step),_end(end)
            {}


            using iterator_category = std::forward_iterator_tag;
            using value_type = int;
            using difference_type = std::ptrdiff_t;
            using pointer = value_type*; using reference = value_type;

            Iterator& operator++(){
                _data+=_step;
                return *this;
            }

            Iterator operator++(int){
                auto ret = *this;
                ++*this;
                return ret;
            }

            //不能直接的用 _data 和 other._data 比较
            //因为 (1,10,2) -> 结束点
            bool operator!=(const Iterator & other) {
                if( _end && other._end)  //都是截止
                    return false;
                if( !_end && !other._end) //都不是截止
                    return _data != other._data;
                if( other._end)
                    return _data < other._data;
                // if( !_end)
                return other._data < _data;
            }
            bool operator==(const Iterator & other) {
                return !(*this!=other);
            }

            int operator*() {
                return _data;
            }
        };

        Iterator begin() const noexcept { 
            return {_start,_step,false};
        }

        Iterator end() const noexcept { 
            return {_stop,_step,true};
        }
    };

    constexpr rangeImpl range(int stop) {
        return {stop};
    }
    constexpr rangeImpl range(int start,int stop) {
        return {start,stop};
    }
    constexpr rangeImpl range(int start,int stop,int step){
        return {start,stop,step};
    }
    
} // _end namespace rainboy
