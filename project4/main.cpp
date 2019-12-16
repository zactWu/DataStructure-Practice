#include <iostream>
#include <string>
#include "stack.h"
using namespace std;

int opr_prio(char opr){
    if(opr == '(' ) return 0;

    if(opr == '+' || opr == '-') return 1;

    if(opr == '*' || opr == '/' || opr == '%') return 2;

    if (opr == '^') return 3;

    else{
        return -1;
    }
}

string convert(string ori_str){
    stack<char> s;//��ջ�������
    string original_str(ori_str.length() - 1, ' ');
    string str(2 * original_str.length(), ' ');//��׺�ַ���
    int i = 0;
    int j = 0;

    for (int l = 0; l < original_str.length(); ++l) {//ȥ���Ⱥ�
        original_str[l] = ori_str[l];
    }
    int len = original_str.length();
    while (i < original_str.length()) {//����Ŀ�����
        if(i == 0 && (original_str[0] == '-'|| original_str[0] == '+')){//��λ��Ŀ�����
            str[0] = '(';
            str[1] = '0';
            str[2] = original_str[0];
            str[3] = original_str[1];
            str[4] = ')';
            j += 4;
            i += 1;
            len += 3;
        }
        else if(i>0 && (original_str[i] == '-'|| original_str[i] == '+')
                && original_str[i-1] == '('){//������Ŀ�����
            str[j] = '(';
            str[j+1] = '0';
            str[j+2] = original_str[i];
            str[j+3] = original_str[i+1];
            str[j+4] = ')';
            j += 4;
            i += 1;
            len += 3;
        }
        else{
            str[j] = original_str[i];
        }
        i++;
        j++;
    }

    for (int k = 0; k < str.length(); ++k) {//��ȥ������ռ����
        if(str[k] == '(' || str[k] == ')'){
            len--;
        }
    }
    string rpnstr(len ,' ');//��׺�ַ���
    int index =0;
    for (int j = 0; j < str.length(); ++j) {//����׺���ʽת��Ϊ��׺���ʽ
        if (str[j] >= '0' && str[j] <= '9') {//��Ϊ���������ݴ��ַ���
            rpnstr[index++] = str[j];
        }
        else if (s.IsEmpty() || str[j] == '(') {//��ջΪ�ջ�������������ջ
            s.push(str[j]);
        }
        else if (str[j] == ')') {//������������
            while (s.get_top() != '(') {
                rpnstr[index++] = s.pop();
            }
            s.pop();

        }
        else {//��ջ��Ϊ���Ҷ�����������ȶ�С��ջ�����������ջ���ַ���
            while (!s.IsEmpty() && (opr_prio(str[j]) <= opr_prio(s.get_top()))) {
                rpnstr[index++] = s.pop();
            }
                s.push(str[j]);//��ջ�꽫��ǰ�����������ջ
        }
    }
    while(!s.IsEmpty()){//��ջ�봮��ջ��
        rpnstr[index++] = s.pop();
    }
    return rpnstr;//�����ַ���
}

int cal(int a,int b, int op){//���㺯��
    if(op == '+') return b + a;
    else if(op == '-') return b - a;
    else if(op == '*') return b * a;
    else if(op == '/') return b / a;
    else if(op == '%') return b % a;
    else if(op == '^') {
        int ans = 1;
        for (int i = 0; i < a; ++i) {
            ans *= b;
        }
        return ans;
    }
    else return 0;
}

int calrpn(string rpn){//�����׺���ʽ
    stack<int> ss;
    int tmp;
    for (int i = 0; i < rpn.length(); ++i) {
        if(rpn[i] >= '0' && rpn[i] <= '9'){
            tmp = rpn[i];
            ss.push(tmp - '0');
        }
        else{
            int a = ss.pop();
            int b = ss.pop();
            ss.push(cal(a,b,rpn[i]));
        }
    }
    return ss.IsEmpty() ? 0 : ss.get_top();
}



int main() {
    string str;
    char con_flag = 'y';
    while(con_flag == 'y'){
        cout<<"������ʽ��"<<endl;
        cin>>str;
        for (int i = 0; i < str.length(); ++i) {//���Ƿ�����
            if(str[i] == '.'){
                cerr<<"������������"<<endl;
                str = "0=";
                break;
            }
            if(str[i] >= '0' && str[i] <= '9' && str[i+1] >= '0' && str[i+1] <= '9'){
                cerr<<"�����ظ��������֣�"<<endl;
                str = "0=";
                break;
            }
            if((str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'|| str[i] == '^' || str[i] == '%')
            &&(str[i+1] == '+' || str[i+1] == '-' || str[i+1] == '*' || str[i+1] == '/' || str[i+1] == '^' ||str[i+1] == '%')){
                cerr<<"�����ظ������������"<<endl;
                str = "0=";
                break;
            }
            if(str == "+" || str == "-" || str == "*" || str == "/" || str == "^" || str == "%" || str == "="){
                cerr<<"����������1����������"<<endl;
                str = "0=";
                break;
            }
            if(str[str.length()-1] != '='){
                cerr<<"���ڱ��ʽ�������'='��"<<endl;
                str = "0=";
                break;
            }
        }
        int ans = calrpn(convert(str));
        cout<<ans<<endl;
        cout<<"�Ƿ���� ��y, n��?";
        cin>>con_flag;
    }
    return 0;
}