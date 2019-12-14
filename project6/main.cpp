#include <iostream>
#include "tree.h"
#include <string>

int main() {
    tree<string> family;
    cout << "  **            家谱管理系统               **" << endl;
    cout << "=============================================" << endl;
    cout << "  **          请选择要执行的操作:           **" << endl;
    cout << " **             A -- 完善家庭               **" << endl;
    cout << "**              B -- 添加家庭成员             **" << endl;
    cout << " **             C -- 解散局部家庭           **" << endl;
    cout << "  **            D -- 更改家庭成员姓名      **" << endl;
    cout << "   **           E -- 退出程序           **" << endl;
    cout << "=============================================" << endl;
    cout << "首先建立一个家谱" << endl << "请先输入祖先的姓名 ";
    auto * ancestor = new tree_node<string>;
    cin >> *ancestor;
    family.buildTree(ancestor);
    char flag;
    while(true){
        cout<<"请输入你要执行的操作";
        cin>>flag;
        switch (flag){
            case 'A':{
                cout<<"请输入要建立家庭的人的姓名";
                tree_node<string> target;
                cin>>target;
                family.buildFamily(target);
                break;
            }
            case 'B':{
                cout<<"请输入你想要添加儿女的人的姓名";
                tree_node<string> target;
                cin>>target;
                family.perfectFamily(target);
                break;
            }
            case 'C':{
                cout<<"请输入你想要解散家庭的人的姓名";
                tree_node<string> target;
                cin>>target;
                family.disbandFamily(target);
                break;
            }
            case 'D':{
                cout<<"请输入你想要改变的人的姓名";
                tree_node<string> target;
                cin>>target;
                family.replaceMember(target);
                break;
            }
            case 'E':{
                cout<<"退出！"<<endl;
                return 0;
            }
        }
    }
    return 0;
}