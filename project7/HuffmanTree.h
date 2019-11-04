//
// Created by 武信庭 on 2019/11/4.
//

#ifndef PROJECT7_HUFFMANTREE_H
#define PROJECT7_HUFFMANTREE_H

#include<iostream>
using namespace std;


struct HuffmanTree_node{//节点类
    int weight;
    int lchild,rchild,parent;
};

class HuffmanTree{//哈夫曼树
public:
    void BuildTree(HuffmanTree_node huffman_tree[],const int ori_arr[],int num);//建立哈夫曼树
    static void SelectChild(HuffmanTree_node huffman_tree[], int target_pos, int &min1, int &min2);//搜索最小权值节点
    int PrintWPL(HuffmanTree_node huffman_tree[],int num);//打印最小带权路径长度和

};

void HuffmanTree::BuildTree(HuffmanTree_node huffman_tree[],const int ori_arr[],int num) {
    for (int i = 0; i < 2 * num - 1; ++i) {//初始化
        huffman_tree[i].lchild = huffman_tree[i].rchild = huffman_tree[i].parent =-1;
    }
    for (int i = 0; i < num; ++i) {//赋权值
        huffman_tree[i].weight = ori_arr[i];
    }
    for (int i = num; i < 2 * num - 1; ++i) {//建立父节点
        int target1,targer2;
        SelectChild(huffman_tree,i,target1,targer2);
        huffman_tree[target1].parent = huffman_tree[targer2].parent = i;
        huffman_tree[i].lchild = target1;
        huffman_tree[i].rchild = targer2;
        huffman_tree[i].weight = huffman_tree[target1].weight + huffman_tree[targer2].weight;
    }
}

void HuffmanTree::SelectChild(HuffmanTree_node huffman_tree[], int target_pos, int &min1, int &min2){
    for (int i = 0; i < target_pos; ++i) {//初始化min1、min2
        if(huffman_tree[i].parent == -1){
            min1 = i;
            for (int j = i+1; j < target_pos; ++j) {
                if(huffman_tree[j].parent == -1){
                    min2 = j;
                    break;
                }
            }
            break;
        }
    }

    for (int i = 0; i < target_pos; ++i) {//搜最小权值min1
        if(huffman_tree[i].parent == -1 && huffman_tree[i].weight < huffman_tree[min1].weight && i != min2){
            min1 = i;
        }
    }
    for (int j = 0; j < target_pos; ++j) {//搜最小权值min2
        if(huffman_tree[j].parent == -1 && huffman_tree[j].weight < huffman_tree[min2].weight && j != min1){
            min2 = j;
        }
    }
}

int HuffmanTree::PrintWPL(HuffmanTree_node *huffman_tree, int num) {
    int ans = 0;
    for (int i = 0; i < 2 * num - 1; ++i) {
        if(huffman_tree[i].lchild != -1 && huffman_tree[i].rchild != -1){
            ans += huffman_tree[i].weight;//将所有父节点权值相加得最小带权路径长度和（未实现路径长度赋值）
        }
    }
    return ans;
}


#endif //PROJECT7_HUFFMANTREE_H
