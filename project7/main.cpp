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
    auto * huffmanTreeNode = new HuffmanTree_node[num];
    HuffmanTree huffmanTree;
    huffmanTree.BuildTree(huffmanTreeNode,arr,num);
    ans = huffmanTree.PrintWPL(huffmanTreeNode,num);
    cout<<ans<<endl;
    return 0;
}