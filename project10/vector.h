//
// Created by 武信庭 on 2019/11/1.
//

#ifndef PROJECT6_VECTOR_H
#define PROJECT6_VECTOR_H

#include <iostream>
using namespace std;

template <class type>
class Vector{
private:
    int size;//已用长度
    int space{};//总容量
    type* element;
public:
    Vector():size(0),space(0),element(NULL){};
    explicit Vector(int len);
    Vector(const Vector& other) :size(0),space(0),element(NULL){*this=other;}
    Vector(initializer_list<type>list) :size{list.size()},element{ new type[size] }{copy(list.begin(), list.end(), element);}
    ~Vector(){delete []element;}
    type & operator[](int i);
    void reserve(int newalloc);
    void push_back(type &val);
    int get_size() const{ return size; }
    void del();


};

template<class type>
Vector<type>::Vector(int len) {
   size = len;
   element = new type[len];
    for (int i = 0; i < len ; ++i) {
        element[i] = 0;
    }
}

template <class type>
type &Vector<type>::operator[](int i) {
    if (i > size)
    {
        cerr << "越界访问!" << endl;
    }
    return element[i];
}

template<class type>
void Vector<type>::reserve(int newalloc) {
    if(newalloc < space){
        return;
    }
    type *temp = element;
    element = new type[newalloc];
    for (int i = 0; i < size; ++i)
        element[i] = temp[i];
    delete[] temp;
    space = newalloc;
}

template<class type>
void Vector<type>::push_back(type &val) {
    if(space == size){
        reserve(2* space);
    }
    if(space == 0){
        reserve(sizeof(val));
    }
    element[size] = val;
    size++;
}

template<class type>
void Vector<type>::del() {
    delete[] element;
    size = space = 0;
}


#endif //PROJECT6_VECTOR_H
