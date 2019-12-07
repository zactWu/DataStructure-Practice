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
    int space;//总容量
    type* element;
public:
    Vector(int s=0):size(s),space(s+16){ element = new type[space];}
    Vector(const Vector& other) :size(0),space(0),element(NULL){*this=other;}
    Vector(initializer_list<type>list) :size{list.size()},element{ new type[size] }{copy(list.begin(), list.end(), element);}
    ~Vector(){delete []element;}
    type & operator[](int i);
    void reserve(int newalloc);
    void push_back(type &val);
    int get_size() const{ return size; }
    void del();
    bool pop_back();
    bool Delete(int ind);
    Vector& operator=(Vector& other){
        //    判断是否为自身赋值
        if (this == &other)
            return *this;
        else {
            delete[]element;
            size = other.size;
            space = other.space;
            this->element = new type[space];

            for (int i = 0; i < size; ++i) {
                element[i] = other.element[i];
            }
            return *this;
        }
    }

};

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
    if(newalloc <= space){
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
        reserve(2* space+1);
    }
    element[size++] = val;
}

template<class type>
void Vector<type>::del() {
    delete[] element;
    size = space = 0;
}
template<class type>
bool Vector<type>::pop_back(){
    if (!size) {
        std::cerr << "Fail to pop back, the vector is empty!\n";
        return false;
    }
    size--;
    return true;
}

template<class type>
bool Vector<type>::Delete(int ind) {
    if(ind<0 || ind >= size){
        cerr << "删除失败！"<<endl;
        return false;
    }
    for (int i = ind; i < size - 1; ++i) {
        element[i] = element[i+1];
    }
    return pop_back();
}


#endif //PROJECT6_VECTOR_H
