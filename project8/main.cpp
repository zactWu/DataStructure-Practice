#include<iostream>
#include"graph.h"
using namespace std;

int main() {
    graph PrimMap;
    char choise='0';
    cout << "------------------------------\n"
            "**  �������ģ��ϵͳ     **\n"
            "------------------------------\n"
            "**  A����������������    **\n"
            "**  B������ӵ����ı�    **\n"
            "**  C����������С������  **\n"
            "**  D������ʾ��С������  **\n"
            "**  E�����˳�����       **\n"
            "------------------------------\n";

    while (true) {
        cout << "��ѡ�����";
        cin >> choise;
            switch (choise) {
                case 'A':PrimMap.buildNodes(); break;
                case 'B':PrimMap.appendLines(); break;
                case 'C':PrimMap.setupPrim(); break;
                case 'D':PrimMap.displayPrim(); break;
                case 'E':return 0;
                default:break;
            }
    }
}
