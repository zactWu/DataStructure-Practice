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
    p = head1;//�����һ������
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

    p = head2;//����ڶ�������
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
    if(flag1 && flag2) {//���Էǿ�
        for (int i = 0; i < len1; ++i) {//ȡ����
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
        if(head3->next == nullptr){//������Ϊ��
            cout<<"NULL"<<endl;//ֱ�����NULL
            return 0;
        }
    }
    else{//��Ϊ��
        cout<<"NULL"<<endl;//ֱ�����NULL
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