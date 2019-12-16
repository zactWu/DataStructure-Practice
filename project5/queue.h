//
// Created by Œ‰–≈Õ• on 2019/10/29.
//

#ifndef PROJECT5_QUEUE_H
#define PROJECT5_QUEUE_H

#include <iostream>
using namespace std;

template <class type>
class queue{
public:
    queue();
    ~queue();

    void enqueue(type t);
    type front();
    type dequeue();
    int size();
    int is_empty();

private:
    type *arr;
    int count{};

};

template<class type>
queue<type>::queue() {
    arr = new type[1000];
    count = 0;
    if(!arr){
        cerr<<"ƒ⁄¥Ê…Í«Î ß∞‹£°"<<endl;
    }
}

template<class type>
queue<type>::~queue() {
    if (arr) {
        delete[] arr;
        arr = NULL;
    }
}

template<class type>
void queue<type>::enqueue(type t) {
    arr[count++] = t;
}

template<class type>
type queue<type>::front() {
    return arr[0];
}

template<class type>
type queue<type>::dequeue() {
    if(count == 0){
        cerr<<"∂”¡–Œ™ø’£°"<<endl;
    }
    type ans = arr[0];
    count--;
    for (int i = 0; i < count; ++i) {
        arr[i] = arr[i+1];
    }
    return ans;
}

template<class type>
int queue<type>::size() {
    return count;
}

template<class type>
int queue<type>::is_empty() {
    if(count == 0){
        return 1;
    }
    return 0;
}

#endif //PROJECT5_QUEUE_H
