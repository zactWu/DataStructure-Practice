#include <iostream>
#include <string>

using namespace std;


class List
{
public:
    List *next;
    void Init();
    void Input();
    void Insert();
    void Delete();
    void Lookup();
    void Modify();
    void Output();
private:
    int id,age;
    string name,sex,exam;
};


int num;
List *head,*p,*q;


void List::Init()
{
    head=new List;
    head->next=NULL;
    q=head;
}


void List::Input()
{
    cout<<"�����뽨��������Ϣϵͳ��"<<endl;
    cout<<"�����뿼��������";
    cin>>num;
    while(num <= 0){
        cout<<"������һ����������"<<endl;
        cin>>num;
    }
    cout<<"���������뿼���Ŀ��ţ��������Ա����估�������"<<endl;
    head->next= nullptr;
    q=head;
    for(int i=0; i<num; i++)
    {
        p=new List;
        cin>>p->id>>p->name>>p->sex>>p->age>>p->exam;
        p->next=nullptr;
        q->next=p;
        q=p;
    }
}


void List::Insert()
{
    cout<<"��������Ҫ����Ŀ�����λ�ã�";
    int n;
    cin>>n;
    while(n <= 0 || n > num+1){
        cout<<"�������λ�ò��Ϸ������������룡"<<endl;
        cin>>n;
    }
    cout<<"����������Ҫ����Ŀ����Ŀ��ţ��������Ա����估�������ͣ�"<<endl;
    q=head;
    while(--n)
    {
        q=q->next;
    }
    p=new List;
    cin>>p->id>>p->name>>p->sex>>p->age>>p->exam;
    p->next=q->next;
    q->next=p;
    num++;
}


void List::Delete()
{
    cout<<"������Ҫɾ���Ŀ����Ŀ��ţ�";
    int n;
    cin>>n;
    p=head;
    while(p->next)
    {
        if(p->next->id==n)
        {
            q=p->next;
            cout<<"��ɾ���Ŀ�����Ϣ�ǣ�"<<q->id<<"\t"<<q->name<<"\t"<<q->sex<<"\t"<<q->age<<"\t"<<q->exam<<endl;
            p->next=q->next;
            delete []q;
            num--;
            return;
        }
        else
        {
            p=p->next;
        }
    }
    cout<<"���޴��ˣ�"<<endl;
}


void List::Lookup()
{
    cout<<"������Ҫ���ҵĿ����Ŀ��ţ�";
    int n;
    cin>>n;
    p=head->next;
    while(p)
    {
        if(p->id==n)
        {
            cout<<endl<<"����\t����\t�Ա�\t����\t�������"<<endl;
            cout<<p->id<<"\t"<<p->name<<"\t"<<p->sex<<"\t"<<p->age<<"\t"<<p->exam<<endl;
            return;
        }
        else
        {
            p=p->next;
        }
    }
    cout<<"���޴��ˣ�"<<endl;
}


void List::Modify()
{
    cout<<"������Ҫ�޸���Ϣ�Ŀ����Ŀ��ţ�";
    int n;
    cin>>n;
    p=head->next;
    while(p)
    {
        if(p->id==n)
        {
            cout<<"���Դ�����ÿ����޸ĺ�Ŀ��ţ��������Ա����估�������"<<endl;
            cin>>p->id>>p->name>>p->sex>>p->age>>p->exam;
            return;
        }
        else
        {
            p=p->next;
        }
    }
    cout<<"���޴��ˣ�"<<endl;
}


void List::Output()
{
    p=head->next;
    cout<<endl<<"����\t����\t�Ա�\t����\t�������"<<endl;
    while(p)
    {
        cout<<p->id<<"\t"<<p->name<<"\t"<<p->sex<<"\t"<<p->age<<"\t"<<p->exam<<endl;
        p=p->next;
    }
}


int main()
{
    List s;
    s.Init();
    s.Input();
    s.Output();
    while(true)
    {
        cout<<"��ѡ����Ҫ���еĲ�����1Ϊ���룬2Ϊɾ����3Ϊ���ң�4Ϊ�޸ģ�5Ϊͳ�ƣ�0Ϊȡ��������";
        int n;
        cin>>n;
        while(n<0 || n>5){
            cout<<"��Ǹ������Ҫ���еĲ��������ڣ����������룡"<<endl;
            cin>>n;
        }
        switch(n)
        {
            case 1:
                s.Insert();
                s.Output();
                break;
            case 2:
                s.Delete();
                s.Output();
                break;
            case 3:
                s.Lookup();
                break;
            case 4:
                s.Modify();
                s.Output();
                break;
            case 5:
                s.Output();
                cout<<"��ǰ����������Ϊ"<<num<<endl;
                break;
            case 0:
                exit(0);
        }
    }
    return 0;
}
