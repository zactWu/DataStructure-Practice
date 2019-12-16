#include <iostream>
#include "HuffmanTree.h"
using namespace std;

int main() {
    int arr[10000];
    int num,ans;
    cin>>num;
    for (int i = 0; i < num; ++i) {
        cin>>arr[i];
    }
    if(num == 1){
        cout<<arr[0]<<endl;
        system("pause");
        return 0;
    }
    if(num == 0){
        cerr<<"输入不能为0！"<<endl;
        return 0;
    }
    auto * huffmanTreeNode = new HuffmanTree_node[num];
    HuffmanTree huffmanTree;
    huffmanTree.BuildTree(huffmanTreeNode,arr,num);
    ans = huffmanTree.PrintWPL(huffmanTreeNode,num);
    cout<<ans<<endl;
    system("pause");
    return 0;
}