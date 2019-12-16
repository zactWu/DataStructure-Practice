//数组栈实现
// Created by 武信庭 on 2019/10/22.
//

#ifndef PROJECT3_STACK_H
#define PROJECT3_STACK_H

#include <iostream>
using namespace std;

template <class type>
class stack{
public:
    stack(int len = 12);//default值
    ~stack();
    void push(type &n);//入栈
    type pop();//出栈
    type get_top();//取栈顶元素
    void MakeEmpty(){top = -1;}//置空
    int IsEmpty(){return top == -1;}
    int IsFull(){return top ==maxsize-1;}
private:
    int top;//栈顶
    type *elements;//数组
    int maxsize;//栈最大容量
};

template<class type>
stack<type>::stack(int len) {
    maxsize = len;
    top = -1;
    elements = new type[maxsize];
    if (!elements){
        cerr<<"栈内存申请失败！"<<endl;
    }
}

template<class type>
stack<type>::~stack() {
    delete []elements;
}

template<class type>
void stack<type>::push(type &n) {
    if(IsFull()){
        cerr<<"栈满！"<<endl;
    }
    elements[++top] = n;
}

template<class type>
type stack<type>::pop() {
    if(IsEmpty()){
        cerr<<"栈空！"<<endl;
    }
    return elements[top--];
}

template<class type>
type stack<type>::get_top() {
    if(IsEmpty()){
        cerr<<"栈空！"<<endl;
    }
    return elements[top];
}




#endif //PROJECT3_STACK_H
