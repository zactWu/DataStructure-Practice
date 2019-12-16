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
    stack<char> s;//用栈存操作符
    string original_str(ori_str.length() - 1, ' ');
    string str(2 * original_str.length(), ' ');//中缀字符串
    int i = 0;
    int j = 0;

    for (int l = 0; l < original_str.length(); ++l) {//去除等号
        original_str[l] = ori_str[l];
    }
    int len = original_str.length();
    while (i < original_str.length()) {//处理单目运算符
        if(i == 0 && (original_str[0] == '-'|| original_str[0] == '+')){//首位单目运算符
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
                && original_str[i-1] == '('){//后续单目运算符
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

    for (int k = 0; k < str.length(); ++k) {//减去括号所占长度
        if(str[k] == '(' || str[k] == ')'){
            len--;
        }
    }
    string rpnstr(len ,' ');//后缀字符串
    int index =0;
    for (int j = 0; j < str.length(); ++j) {//将中缀表达式转换为后缀表达式
        if (str[j] >= '0' && str[j] <= '9') {//若为操作数则暂存字符串
            rpnstr[index++] = str[j];
        }
        else if (s.IsEmpty() || str[j] == '(') {//若栈为空或读入左括号则进栈
            s.push(str[j]);
        }
        else if (str[j] == ')') {//若读入右括号
            while (s.get_top() != '(') {
                rpnstr[index++] = s.pop();
            }
            s.pop();

        }
        else {//若栈不为空且读入操作符优先度小于栈顶操作符则出栈进字符串
            while (!s.IsEmpty() && (opr_prio(str[j]) <= opr_prio(s.get_top()))) {
                rpnstr[index++] = s.pop();
            }
                s.push(str[j]);//出栈完将当前读入操作数进栈
        }
    }
    while(!s.IsEmpty()){//出栈入串至栈空
        rpnstr[index++] = s.pop();
    }
    return rpnstr;//返回字符串
}

int cal(int a,int b, int op){//计算函数
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

int calrpn(string rpn){//计算后缀表达式
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
        cout<<"输入表达式："<<endl;
        cin>>str;
        for (int i = 0; i < str.length(); ++i) {//检测非法输入
            if(str[i] == '.'){
                cerr<<"请输入整数！"<<endl;
                str = "0=";
                break;
            }
            if(str[i] >= '0' && str[i] <= '9' && str[i+1] >= '0' && str[i+1] <= '9'){
                cerr<<"请勿重复输入数字！"<<endl;
                str = "0=";
                break;
            }
            if((str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'|| str[i] == '^' || str[i] == '%')
            &&(str[i+1] == '+' || str[i+1] == '-' || str[i+1] == '*' || str[i+1] == '/' || str[i+1] == '^' ||str[i+1] == '%')){
                cerr<<"请勿重复输入操作符！"<<endl;
                str = "0=";
                break;
            }
            if(str == "+" || str == "-" || str == "*" || str == "/" || str == "^" || str == "%" || str == "="){
                cerr<<"请至少输入1个操作数！"<<endl;
                str = "0=";
                break;
            }
            if(str[str.length()-1] != '='){
                cerr<<"请在表达式最后输入'='！"<<endl;
                str = "0=";
                break;
            }
        }
        int ans = calrpn(convert(str));
        cout<<ans<<endl;
        cout<<"是否继续 （y, n）?";
        cin>>con_flag;
    }
    return 0;
}