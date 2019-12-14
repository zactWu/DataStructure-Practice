//
// Created by ����ͥ on 2019/11/26.
//

#ifndef PROJECT8_GRAPH_H
#define PROJECT8_GRAPH_H

#include <iostream>
using namespace std;

const int maxint = 100;
int adjMat[maxint][maxint] = {maxint};
char node[maxint];
int lowcost[maxint],mst[maxint];
struct node_display{
    char first_node;
    char second_node;
    int node_cost;
}display_node[maxint];

class graph{
private:
    int node_nums = 0;
public:
    void buildNodes();
    void appendLines();
    void setupPrim();
    void displayPrim();
};

void graph::buildNodes() {
    cout << "�����붥��ĸ���?" << endl;
    cin >> node_nums;
    cout << "�������������������ƣ�"<< endl;
    for (int i = 0; i < node_nums; i++) {
        cin >> node[i];
    }
}

void graph::appendLines() {
    char node1='1', node2='1'; int len=1;
    while (true) {
        cout << "��������������ͱ�";
        cin >> node1 >> node2 >> len;
        if (node1 == '?') {
            break;
        }
        for (int i = 0; i < node_nums; ++i) {//map�����
            for (int j = 0; j < node_nums; ++j) {
                if(node1 == node[i] && node2 == node[j]){
                    adjMat[i][j] = len;
                }
            }
        }
    }
    for(int i = 0; i < node_nums; i++){
        for(int j = 0; j < node_nums; j++){
            if(i == j) adjMat[i][j] = 0;
            else if(!adjMat[i][j]) adjMat[i][j] = maxint;
            }
        }
}

void graph::setupPrim() {
    cout << "��������ʼ����";
    char start_node;
    int start_num = 0;
    cin >> start_node;
    for (int i = 0; i < node_nums; ++i) {
        if (node[i] == start_node) {
            start_num = i;
            break;
        }
    }
    for (int i = 0; i < node_nums; ++i) {
        lowcost[i] = adjMat[start_num][i];
        mst[i] = start_num;
    }
    mst[start_num] = -1;
    for (int i = 0; i < node_nums - 1; ++i) {
        int min_cost = maxint;
        int min_node_num = -1;
        for (int j = 0; j < node_nums; ++j) {
            if(mst[j] != -1 && lowcost[j] < min_cost){
                min_cost = lowcost[j];
                min_node_num = j;
            }
        }
        if(min_node_num != -1){
            display_node[i].first_node = node[mst[min_node_num]];
            display_node[i].second_node = node[min_node_num];
            display_node[i].node_cost = lowcost[min_node_num];
            mst[min_node_num] = -1;
            for (int j = 0; j < node_nums; ++j) {
                if(mst[j] != -1 && lowcost[j] >adjMat[min_node_num][j]){
                    lowcost[j] = adjMat[min_node_num][j];
                    mst[j] = min_node_num;
                }
            }
        }
    }
    cout << "����prim��С��������"<<endl;
}

void graph::displayPrim() {
    cout << "��С�������Ķ��㼰��Ϊ��"<<endl;
    for (int i = 0; i < node_nums-1; ++i) {
        cout << display_node[i].first_node << "-(" << display_node[i].node_cost
             << ")-" << display_node[i].second_node << endl;
    }
}


#endif //PROJECT8_GRAPH_H
