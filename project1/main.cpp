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
    cout<<"首先请建立考生信息系统！"<<endl;
    cout<<"请输入考生人数：";
    cin>>num;
    while(num <= 0){
        cout<<"请输入一个正整数！"<<endl;
        cin>>num;
    }
    cout<<"请依次输入考生的考号，姓名，性别，年龄及报考类别！"<<endl;
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
    cout<<"请输入您要插入的考生的位置：";
    int n;
    cin>>n;
    while(n <= 0 || n > num+1){
        cout<<"您输入的位置不合法，请重新输入！"<<endl;
        cin>>n;
    }
    cout<<"请依次输入要插入的考生的考号，姓名，性别，年龄及报考类型！"<<endl;
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
    cout<<"请输入要删除的考生的考号：";
    int n;
    cin>>n;
    p=head;
    while(p->next)
    {
        if(p->next->id==n)
        {
            q=p->next;
            cout<<"您删除的考生信息是："<<q->id<<"\t"<<q->name<<"\t"<<q->sex<<"\t"<<q->age<<"\t"<<q->exam<<endl;
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
    cout<<"查无此人！"<<endl;
}


void List::Lookup()
{
    cout<<"请输入要查找的考生的考号：";
    int n;
    cin>>n;
    p=head->next;
    while(p)
    {
        if(p->id==n)
        {
            cout<<endl<<"考号\t姓名\t性别\t年龄\t报考类别"<<endl;
            cout<<p->id<<"\t"<<p->name<<"\t"<<p->sex<<"\t"<<p->age<<"\t"<<p->exam<<endl;
            return;
        }
        else
        {
            p=p->next;
        }
    }
    cout<<"查无此人！"<<endl;
}


void List::Modify()
{
    cout<<"请输入要修改信息的考生的考号：";
    int n;
    cin>>n;
    p=head->next;
    while(p)
    {
        if(p->id==n)
        {
            cout<<"请以此输入该考生修改后的考号，姓名，性别，年龄及报考类别！"<<endl;
            cin>>p->id>>p->name>>p->sex>>p->age>>p->exam;
            return;
        }
        else
        {
            p=p->next;
        }
    }
    cout<<"查无此人！"<<endl;
}


void List::Output()
{
    p=head->next;
    cout<<endl<<"考号\t姓名\t性别\t年龄\t报考类别"<<endl;
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
        cout<<"请选择您要进行的操作（1为插入，2为删除，3为查找，4为修改，5为统计，0为取消操作）";
        int n;
        cin>>n;
        while(n<0 || n>5){
            cout<<"抱歉，您想要进行的操作不存在，请重新输入！"<<endl;
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
                cout<<"当前考生总人数为"<<num<<endl;
                break;
            case 0:
                exit(0);
        }
    }
    return 0;
}
