//����ջʵ��
// Created by ����ͥ on 2019/10/22.
//

#ifndef PROJECT3_STACK_H
#define PROJECT3_STACK_H

#include <iostream>
using namespace std;

template <class type>
class stack{
public:
    stack(int len = 12);//defaultֵ
    ~stack();
    void push(type &n);//��ջ
    type pop();//��ջ
    type get_top();//ȡջ��Ԫ��
    void MakeEmpty(){top = -1;}//�ÿ�
    int IsEmpty(){return top == -1;}
    int IsFull(){return top ==maxsize-1;}
private:
    int top;//ջ��
    type *elements;//����
    int maxsize;//ջ�������
};

template<class type>
stack<type>::stack(int len) {
    maxsize = len;
    top = -1;
    elements = new type[maxsize];
    if (!elements){
        cerr<<"ջ�ڴ�����ʧ�ܣ�"<<endl;
    }
}

template<class type>
stack<type>::~stack() {
    delete []elements;
}

template<class type>
void stack<type>::push(type &n) {
    if(IsFull()){
        cerr<<"ջ����"<<endl;
    }
    elements[++top] = n;
}

template<class type>
type stack<type>::pop() {
    if(IsEmpty()){
        cerr<<"ջ�գ�"<<endl;
    }
    return elements[top--];
}

template<class type>
type stack<type>::get_top() {
    if(IsEmpty()){
        cerr<<"ջ�գ�"<<endl;
    }
    return elements[top];
}




#endif //PROJECT3_STACK_H
