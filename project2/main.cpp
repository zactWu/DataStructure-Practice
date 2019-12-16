#include <iostream>
using namespace std;

class list{
public:
    list* next;
    int num;
};

int main() {
    list *p,*q,*r,*head1,*head2,*head3,*tem;
    int input,flag1,flag2,len1,len2,len3;
    flag1 = flag2 = len1 = len2 = len3 = 0;
    head1 = new list;head2 = new list;head3 = new list;
    head1->next = nullptr;head2->next = nullptr;head3->next = nullptr;
    p = head1;//读入第一个序列
    while(true){
        cin>>input;
        if(input == -1){
            break;
        }
        else{
            flag1 = 1;
            len1++;
            tem = new list;
            tem->num = input;
            tem->next = nullptr;
            p->next = tem;
            p = tem;
        }
    }

    p = head2;//读入第二个序列
    while(true){
        cin>>input;
        if(input == -1){
            break;
        }
        else{
            flag2 =1;
            len2++;
            tem = new list;
            tem->num = input;
            tem->next = nullptr;
            p->next = tem;
            p = tem;
        }
    }

    p = head1;
    r = head3;
    if(flag1 && flag2) {//若皆非空
        for (int i = 0; i < len1; ++i) {//取交集
            p = p->next;
            q = head2->next;
            for (int j = 0; j < len2; ++j) {
                if (p->num == q->num) {
                    len3++;
                    tem = new list;
                    tem->num = p->num;
                    tem->next = nullptr;
                    r->next = tem;
                    r = tem;
                    break;
                }
                else {
                    q = q->next;
                }
            }
        }
        if(head3->next == nullptr){//若交集为空
            cout<<"NULL"<<endl;//直接输出NULL
            return 0;
        }
    }
    else{//若为空
        cout<<"NULL"<<endl;//直接输出NULL
        return 0;
    }

    r = head3->next;
    for (int k = 0; k < len3; ++k) {
        cout<<r->num<<" ";
        r = r->next;
    }
    system("pause");
    return 0;
}