#include<iostream>
#include"graph.h"
using namespace std;

int main() {
    graph PrimMap;
    char choise='0';
    cout << "------------------------------\n"
            "**  电网造价模拟系统     **\n"
            "------------------------------\n"
            "**  A——创建电网顶点    **\n"
            "**  B——添加电网的边    **\n"
            "**  C——构造最小生成树  **\n"
            "**  D——显示最小生成树  **\n"
            "**  E——退出程序       **\n"
            "------------------------------\n";

    while (true) {
        cout << "请选择操作";
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
