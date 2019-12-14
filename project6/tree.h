//
// Created by ����ͥ on 2019/11/1.
//

#ifndef PROJECT6_TREE_H
#define PROJECT6_TREE_H

#include <iostream>
#include <string>
#include "vector.h"
using namespace std;

template <typename T>
class tree_node{
private:
    Vector<tree_node*> children;
    T name;
public:
    tree_node(){;}
    explicit tree_node(T cur_name):name(cur_name){;}
    void addChild(tree_node *child);
    void eliminate();
    void changeName(tree_node &target);
    bool noChildren();
    T getName(){return name;}
    void printChidren();
    tree_node * searchNode(tree_node & target);
    friend istream& operator >> (istream & is, tree_node<T> & _person);
};

template<typename T>
void tree_node<T>::addChild(tree_node *child) {
    children.push_back(child);
}

template<typename T>
void tree_node<T>::eliminate() {
    if(children.get_size() == 0){
        return;
    }
    else{
        for (int i = 0; i < children.get_size(); ++i) {
            children[i]->eliminate();
            delete children[i];
        }
        children.del();
    }
}

template<typename T>
void tree_node<T>::changeName(tree_node &target) {
    name = target.name;
}

template<typename T>
bool tree_node<T>::noChildren() {
    return children.get_size() == 0;
}

template<typename T>
void tree_node<T>::printChidren() {
    cout<< getName() << "�ĺ�����";
    for(int i = 0; i<children.get_size() && children.get_size() != 0;++i){
        cout<< children[i]->getName()<< " ";
    }
}

template<typename T>
tree_node<T>*tree_node<T>::searchNode(tree_node &target) {
    tree_node *p = this;
    if(p->name == target.getName()){
        return p;
    }
    else{
        if(p->children.get_size() == 0){
           return nullptr;
        }
        for (int i = 0; i < p->children.get_size(); ++i) {
            tree_node *temp = p->children[i]->searchNode(target);
            if(temp != nullptr){
                return temp;
            }
        }
        return nullptr;
    }
}

istream &operator>>(istream &is, tree_node<string> &_person) {
    string _Name;
    is >> _Name;
    if (is) {
        _person.name = _Name;
    }
    else {
        cout << "fail to cin>>";
    }
    return is;
}


template <class type>
class tree{
public:
    void buildTree(tree_node<type> * ancestor);//��������
    void buildFamily(tree_node<type> & target);//������ͥ
    void perfectFamily(tree_node<type> & target );//���Ƽ�ͥ
    void disbandFamily(tree_node<type> & target);//��ɢ��ͥ
    void replaceMember(tree_node<type> & target);//���ļ�ͥ��Ա����

private:
    tree_node<type>* root;
};

template<class type>
void tree<type>::buildTree(tree_node<type> *ancestor) {
    root = ancestor;
    cout<<"�˼��׵�������"<<root->getName()<<endl;
}

template<class type>
void tree<type>::buildFamily(tree_node<type> &target) {
    if(root == nullptr){
        cerr<<"���Ƚ������ף�"<<endl;
    }
    else{
        tree_node<type> *p = root->searchNode(target);
        if(p == nullptr){
            cerr<<"û���ҵ��ö���"<<endl;
        }
        else if(!p->noChildren()){
            cerr<<"�ö������м�ͥ��"<<endl;
        }
        else{
            cout<<"������"<<p->getName()<<"�Ķ�Ů����";
            int num = 0;
            cin>>num;
            cout<<"����������"<<p->getName()<<"�Ķ�Ů����";
            for (int i = 0; i < num ; ++i) {
                auto * temp = new tree_node<type>;
                cin>>*temp;
                p->addChild(temp);
            }
            p->printChidren();
        }
    }
}

template<class type>
void tree<type>::perfectFamily(tree_node<type> &target) {
    if(root == nullptr){
        cerr<<"���Ƚ������ף�"<<endl;
    }
    else{
        tree_node<type> *p = root->searchNode(target);
        if(p == nullptr){
            cerr<<"û���ҵ��ö���"<<endl;
        }
        else if(p->noChildren()){
            cerr<<"�ö���û��ͥ�����Ƚ�����ͥ";
        }
        else{
            cout<<"������"<<p->getName()<<"����ӵ���Ů����"<<endl;
            auto * temp = new tree_node<type>;
            cin>>*temp;
            p->addChild(temp);
            p->printChidren();
        }
    }
}

template<class type>
void tree<type>::disbandFamily(tree_node<type> &target) {
    if(root == nullptr){
        cerr<<"���Ƚ������ף�"<<endl;
    }
    else{
        tree_node<type> *p = root->searchNode(target);
        if(p == nullptr){
            cerr<<"û���ҵ��ö���"<<endl;
        }
        else if(p->noChildren()){
            cerr<<"�ö�������Ů��"<<endl;
        }
        else{
            cout<<"Ҫ��ɢ��ͥ������"<<p->getName()<<endl;
            p->eliminate();
        }
    }
}

template<class type>
void tree<type>::replaceMember(tree_node<type> &target) {
    if(root == nullptr){
        cerr<<"���Ƚ������ף�"<<endl;
    }
    else{
        tree_node<type> *p = root->searchNode(target);
        if(p == nullptr){
            cerr<<"û���ҵ��ö���"<<endl;
        }
        else{
            cout<<"��������ĺ������"<<endl;
            auto * temp = new tree_node<type>;
            cin>>*temp;
            type before_name = p->getName();
            p->changeName(*temp);
            cout<< before_name <<"�Ѿ�����Ϊ"<< p->getName() <<endl;
        }
    }
}

#endif //PROJECT6_TREE_H
