#include <iostream>
#include "tree.h"
#include <string>

int main() {
    tree<string> family;
    cout << "  **            ���׹���ϵͳ               **" << endl;
    cout << "=============================================" << endl;
    cout << "  **          ��ѡ��Ҫִ�еĲ���:           **" << endl;
    cout << " **             A -- ���Ƽ�ͥ               **" << endl;
    cout << "**              B -- ��Ӽ�ͥ��Ա             **" << endl;
    cout << " **             C -- ��ɢ�ֲ���ͥ           **" << endl;
    cout << "  **            D -- ���ļ�ͥ��Ա����      **" << endl;
    cout << "   **           E -- �˳�����           **" << endl;
    cout << "=============================================" << endl;
    cout << "���Ƚ���һ������" << endl << "�����������ȵ����� ";
    auto * ancestor = new tree_node<string>;
    cin >> *ancestor;
    family.buildTree(ancestor);
    char flag;
    while(true){
        cout<<"��������Ҫִ�еĲ���";
        cin>>flag;
        switch (flag){
            case 'A':{
                cout<<"������Ҫ������ͥ���˵�����";
                tree_node<string> target;
                cin>>target;
                family.buildFamily(target);
                break;
            }
            case 'B':{
                cout<<"����������Ҫ��Ӷ�Ů���˵�����";
                tree_node<string> target;
                cin>>target;
                family.perfectFamily(target);
                break;
            }
            case 'C':{
                cout<<"����������Ҫ��ɢ��ͥ���˵�����";
                tree_node<string> target;
                cin>>target;
                family.disbandFamily(target);
                break;
            }
            case 'D':{
                cout<<"����������Ҫ�ı���˵�����";
                tree_node<string> target;
                cin>>target;
                family.replaceMember(target);
                break;
            }
            case 'E':{
                cout<<"�˳���"<<endl;
                return 0;
            }
        }
    }
    return 0;
}